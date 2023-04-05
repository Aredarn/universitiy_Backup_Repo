-- #11: készítsünk olyan scriptet, amely az amerikai vásárlók (customers tábla, country mező) rekordjain iterál és kiírja minden vásárló nevét, és hogy eddig hány rendelése volt

DECLARE amerikai CURSOR FOR 
SELECT CustomerID, CompanyName
FROM Customers WHERE Country = 'USA'
ORDER BY CompanyName

DECLARE @cid CHAR(5), @cname VARCHAR(40) , @rendelesSZAM INT

OPEN amerikai
FETCH NEXT FROM amerikai into @cid, @cname
WHILE @@FETCH_STATUS = 0
    BEGIN
    -- Hány rendelése volt az aktuálus vevőnek?
    SELECT @rendelesSZAM = COUNT(OrderID)
    FROM Orders
    WHERE CustomerID = @cid

    PRINT CONCAT(@cname, ' : ', @rendelesSZAM, ' orders')

-- KELL ide is az előző sor, mert így ugrik vissza a while elejére
    FETCH NEXT FROM amerikai into @cid, @cname
    END    

CLOSE amerikai

DEALLOCATE amerikai


-- EZZEL LEHET VISSZAÁLLÍTANI
EXEC northwind..sp_CreateTables




-- #12:  (szorgalmi): az előző feladatot fejlesszük tovább úgy, hogy egy beágyazott kurzorral írassuk ki az illető vásárló rendeléseinek a dátumait is (leprogramozzuk az INNER JOIN műveletet)
GO
DECLARE amerikai CURSOR DYNAMIC FOR 
SELECT CustomerID, CompanyName
FROM Customers WHERE Country = 'USA'
ORDER BY CompanyName

DECLARE @cid CHAR(5), @cname VARCHAR(40) , @rendelesSZAM INT, @datum DATE 

OPEN amerikai
FETCH NEXT FROM amerikai into @cid, @cname

WAITFOR DELAY '00:00:10'

WHILE @@FETCH_STATUS = 0
    BEGIN
    -- Hány rendelése volt az aktuálus vevőnek?
    SELECT @rendelesSZAM = COUNT(OrderID)
    FROM Orders
    WHERE CustomerID = @cid

    PRINT CONCAT(@cname, ' : ', @rendelesSZAM, ' orders')


    -- /////////////////////////////////////--
    -- --------------BEÁGYAZOTT CURSOR--------
    DECLARE datumok CURSOR FOR 
    SELECT OrderDate
    FROM Orders 
    WHERE CustomerID = @cid

    OPEN datumok 

        FETCH NEXT FROM datumok INTO @datum
        WHILE @@FETCH_STATUS = 0
        BEGIN

            PRINT '  ' + CAST(@datum as VARCHAR(20))
            FETCH NEXT FROM datumok INTO @datum
        END


    CLOSE datumok
    DEALLOCATE datumok

    -- CURSOR VÉGE--------------------------

-- KELL ide is az előző sor, mert így ugrik vissza a while elejére
    FETCH NEXT FROM amerikai into @cid, @cname
    END    

CLOSE amerikai

DEALLOCATE amerikai

GO











-- SORSZÁMOZÁS, ANALITIKUS FGV, Szétválogatja kategóriaID alapján

SELECT ROW_NUMBER() OVER(PARTITION by c.CategoryID ORDER BY UnitPrice) as Sorszam1,
    ProductName, CategoryName, UnitPrice
    FROm Products p join Categories c ON p.CategoryID = c.CategoryID


SELECT RANK() OVER(PARTITION by c.CategoryID ORDER BY UnitPrice) as Sorszam2 ,
    ProductName, CategoryName, UnitPrice
    FROm Products p join Categories c ON p.CategoryID = c.CategoryID

    

SELECT DENSE_RANK() OVER(PARTITION by c.CategoryID ORDER BY UnitPrice) as Sorszam3 ,
    ProductName, CategoryName, UnitPrice
    FROm Products p join Categories c ON p.CategoryID = c.CategoryID



