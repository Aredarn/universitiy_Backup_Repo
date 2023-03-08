Update Products
set UnitsInStock = -10
where ProductID = 2
GO

-- Nullával való osztás. Kiírja mi okozta a hibát az error ami előtte történt.
SELECT 1/0 print @@error

--ha nullával osztunk (8134-es a hibakódja) akkor kiírja magyarul mi a gond
select 1/0 
if @@ERROR = 8134
    print '0-val való osztás'
ELSE
    PRINT @@error


-- Hibakezelés
BEGIN TRY
    Update Products
    set UnitsInStock = -10
    where ProductID = 2
    selECT  1/0
END TRY

Begin CATCH
    SELECT ERROR_NUMBER() AS NUMBER,
    ERROR_LINE() AS line,
    ERROR_MESSAGE() as message,
    ERROR_PROCEDURE() as [procedure],
    ERROR_SEVERITY() as severity,
    ERROR_STATE() as state   
END CATCH


-- Ületi folyamat szerver oldali megvalósítása
-- telefonos rendelésleadás:
-- adott. terméknév, mennyiség, vevőazonosító

SELECT * from Products
SELECT *FROM Customers
SELECT * FROM Orders
SELECT *FROM [Order Details]

--öTLET:
 
-- START
-- 1. Változók, paraméterek beállítása.
-- 2. Lekérés terméknév alapján
-- 3. 1 találat van? (ott egy IF ág van)
-- 3.1(Nem) Ki: HIBA
-- 3.2(igen) ár raktárkészlet lekérdezése
-- 4 HA a kért mennyiség < mennyiség raktáron
-- 4.1 igen KI: HIBA
-- 4.2 nem: egyenleg lekérése
-- 5. HA Egyenleg < amennyibe kerül a termék
-- 5.1 IGEN: KI HIBA
-- 5.2 NEM. tranzakció végrehajtása.
-- 6 Egyén hiba?
-- 6.1 és 6.2 KI hiba vagy összeg.


--teszteléshez beállítjuk a paramétereket
set nocount off
update products set unitsInStock = 900 where productid=40
update customers set balance=1000 where CustomerID='AROUT'
delete [Order Details] where OrderID in (select orderid from Orders where CustomerID='AROUT'
and EmployeeID is null)
delete Orders where CustomerID='AROUT' and EmployeeID is null
--most futtatjuk a scriptet, utána ellenőrzés:
select * from Customers where CustomerID='AROUT'
select * from Products where productid=40
select top 3 * from Orders where CustomerID='arout' order by OrderDate desc

-- bemeneti pramaéterekk
DECLARE @termek_nev VARCHAR(40), @mennyiseg INT, @vevo_id char(5), @termek_id INT, @ar MONEY, @raktarlt INT

-- egyéb változók
DECLARE @statusz INT, @statusz_szoveg VARCHAR(50), @db INT, @egyenleg MONEY,  @rendeles_id INT

-- bemeneti paraméter értékadás.
SET @termek_nev = 'boston'
SET @mennyiseg = 1
SET @vevo_id = 'AROUT'

BEGIN TRY
    -- hány olyan termék van aminek a neve tartalmazza a BOSTON kifejezést
    -- nyilván ha több mint 1 van nem tudjuk pontosan mit akart rendelni ezért hiba
    SELECT @db = COUNT(*)
    from Products
    WHERE ProductName LIKE '%' + @termek_nev +'%'

    IF(@db != 1)
        BEGIN
            SET @statusz = 1
            SET @statusz_szoveg = 'HIBA, több ilyen termék van'
        END
    ELSE BEGIN -- ha pontosan 1 termék van
        SELECT @termek_id = ProductID, @ar = UnitPrice, @raktarlt = UnitsInStock
        FROM Products
        WHERE ProductName LIKE '%' + @termek_nev +'%'    

        -- RAktárkészlet ellenőrzése
        IF @raktarlt < @mennyiseg BEGIN
            SET @statusz = 2
            SET @statusz_szoveg = 'Nincs ennyi ebből a termékből raktáron'
        END
        ELSE BEGIN -- van elég raktáron akkor: vevő egyenleg ellenőrzése

            SELECT @egyenleg = Balance
            FROM Customers
            WHERE CustomerID = @vevo_id
            -- egyenleg fedezi-e a rendelést???
            -- ár * mennyiséggel mert lehet több darab is
            IF (@ar * @mennyiseg > @egyenleg) BEGIN
                SET @statusz = 3
                SET @statusz_szoveg = 'Egyenleg túl alacsony vagy a vásárló nem található'

            END
            ELSE BEGIN
                -- tranzakció végrehajtása
                --1. vásárló egyenlegének frissítése
                UPDATE Customers
                Set Balance = Balance - (@ar * @mennyiseg)
                WHERE CustomerID = @vevo_id

                --2. rendelésfelvétel az orders és Order details táblához
                INSERT INTO Orders (CustomerID, OrderDate) 
                    VALUES (@vevo_id,GETDATE())
                SET @rendeles_id = @@IDENTITY -- utolsó insert identity értéke
                INSERT INTO [Order Details](OrderID,ProductID,Quantity,UnitPrice)
                    VALUES (@rendeles_id,@termek_id,@mennyiseg,@ar)

                SET @statusz = 0
                SET @statusz_szoveg = CONCAT(@rendeles_id, '. számú rendelés felvéve a rendszerbe')

            END
        END
    END

    print @statusz_szoveg

END TRY

BEGIN CATCH
    PRINT 'Egyéb hiba: '+ error_number()+ ' - '+ error_message() 
END CATCH