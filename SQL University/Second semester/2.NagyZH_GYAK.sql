/*
1A: Készítsen olyan felhasználói függvényt a Northwind adatbázisban, mely a paraméterként kapott
vásárló-azonosítóhoz és kezdeti dátumhoz megkeresi és visszaadja azt a termékkategória-azonosítót,
mely az illető vásárló rendeléseiben a legnagyobb összeggel szerepelt a kezdeti dátum óta. Ha nem
található a vásárló, vagy nem volt rendelése, a visszaadott érték NULL.
*/

go
CREATE FUNCTION minta2_fgv(@vevoid char(5) , @datum DATETIME) RETURNS INT
as BEGIN
    DECLARE @kategoriaID INT 

    select top 1 @kategoriaID = CategoryID
        from [Order Details] od join Orders o on o.OrderID = od.orderID
        join Products p on p.ProductID = od.ProductID
        WHERE CustomerID = @vevoid AND OrderDate >= @datum
        GROUP BY CategoryID
        ORDER by sum((Quantity * od.UnitPrice * (1-Discount))) DESC

    RETURN @kategoriaID
    END
go


-- TESZT 1A

SELECT * from Customers

SELECT dbo.minta2_fgv('Lamai','1997-05-10') -->6
SELECT dbo.minta2_fgv('Lamai','1998-05-10') --> NULL 


/*2A: Írjon egy tárolt eljárást, mely paraméterként egy vásárló-azonosítót és egy kezdeti dátumot kap, és az
alkalmazottak munkáját segíti az alábbiak szerint.
Ha a kapott vásárló nem amerikai vagy nem található, hibaüzenettel kilép.
    • Kiszámítja, hogy a specifikált vásárló 1. feladat szerinti legnagyobb volumenű termék-
kategóriájában melyik alkalmazott kötötte a legnagyobb összértékű üzletet, akárhány
rendelésből, dátumtól függetlenül. A legnagyobb volumenű termék-kategória meghatározásához
az 1. feladat függvényét használja!
    • Ellenőrzi, hogy az előző pont szerinti alkalmazott dolgozik-e a specifikált vásárló területén.
Segítség: a dolgozók és területek összerendelését az EmployeeTerritories tábla tartalmazza, a
vásárló területét pedig a Customers.territory_id mező.
    • Ha az alkalmazott jelenleg még nem dolgozik a kérdéses területen, hozzárendeli.
    • Az eljárás tranzakciót futtat. Ha bármilyen hiba történik, az eljárás kiírja a hibakódot és arendszertől származó angol nyelvű hibaüzenetet
*/

go 

CREATE PROCEDURE minta2_elj (@vevoid char(5), @datum DATETIME)
AS 
BEGIN TRY
    -- TRANZAKCIÓ ELINDÍT
    BEGIN TRAN

    -- Ellőrzés hgy amerikai-e
    DECLARE @nemzet VARCHAR(15), @category INT, @empid INT, @terid VARCHAR(20), @empterrid int

    SELECT @nemzet = Country, @terID = TerritoryID
    from Customers 
    WHERE CustomerID = @vevoid


    IF @nemzet IS NULL 
    BEGIN
        PRINT 'Nincs ilyen vásárló'
        ROLLBACK TRAN
    END
    ELSE IF @nemzet != 'USA'
    BEGIN 
        PRINT 'NEM AMERIKAI!'
        ROLLBACK TRAN
    END
    ELSE 
        BEGIN
            -- ELőző fgv használata
            SELECT @category = dbo.minta2_fgv(@vevoid, @datum)

            -- SELECT KELL MERT ÍGY A FELHASZNÁLÓ IS LÁTJA, PRINT CSAK DEBUG
            SELECT 'A legnagyobb volumenü termékkategoria: ', @category

            -- ebben a kategóriában ki kötötte a legnagyobb összegű rendelést


            SELECT @empID = EmployeeID
            from Orders o join [Order Details] od on o.OrderID = od.OrderID join Products p on p.ProductID = od.ProductID
            WHERE CategoryID = @category
            GROUP BY EmployeeID
            ORDER by SUM(Quantity*od.UnitPrice*(1-Discount)) DESC

            -- Spec alkalmazott dolgozik-e a vásárló területén
            SELECT @empterrid = TerritoryID
            FROM EmployeeTerritories
            WHERE EmployeeID = @empid and TerritoryID = @terid

            IF @empterrid IS NOT NULL
            BEGIN
                SELECT 'Már dolgozik a területen'
                ROLLBACK TRAN
            END

            BEGIN
                PRINT 'Még nem dolgozik a területen!!'
               
               INSERT into EmployeeTerritories
               VALUES(@empid,@terid)

               SELECT 'Az ügynököt hozzárendeltük a területhez!', @terid as [Terület], @empid as [Ügynök]
                COMMIT TRAN
            END
        END

END TRY
BEGIN CATCH
    PRINT CONCAT('Egyéb hiba', error_number(), ' - ', error_message())

    -- itt rollbackeljük a Tranzakciót, bármilyen hiba esetén
    ROLLBACK
END CATCH

GO


SELect * from Customers
ALTer TABLE Customers ADD TerritoryID VARCHAR(20)