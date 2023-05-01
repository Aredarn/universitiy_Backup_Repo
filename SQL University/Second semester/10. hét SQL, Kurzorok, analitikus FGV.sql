-- Adott egy tábla, amely az alkalmazottak rendeléseinek összegét tartalmazza

SELECT EmployeeID, OrderDate, CAST(SUM((1-Discount)*UnitPrice*Quantity) as money) as [Value]
into #tmp
from Orders o JOIN [Order Details] od ON o.OrderID = od.OrderID
where o.EmployeeID is not null
GROUP by o.EmployeeID, o.OrderID, o.OrderDate

GO
SELECT * from #tmp ORDER by EmployeeID, OrderDate
GO
-- Az ügynököknek mi volt a legnagyobb értékű rendelésük, 
-- és mikor érték el azt?
SELECT EmployeeID, Max([Value])
from #tmp
GROUP by EmployeeID


-- így már kiiratódik a dátum is
SELECT *
FROM #tmp
WHERE CONCAT(EmployeeID,' : ' ,[Value]) In
( 
    Select COncat( EmployeeID,' : ' , Max([Value])) 
    from #tmp
    GROUP by EmployeeID
)


-- ablakozó függvénnyel

-- kiiírja hogy az azott Ügynök mikor keresett a legtöbbet és legkevesebbet.
Select Distinct EmployeeID ,
    FIRST_VALUE(OrderDate) OVER (PARTITION BY EmployeeID
                                   ORDER by [Value] DESC ) as MaxDate,
                                
    FIRST_VALUE([Value]) OVER (PARTITION BY EmployeeID
                                   ORDER by [Value] DESC ) as MaxValue,
    FIRST_VALUE(OrderDate) OVER (PARTITION BY EmployeeID
                                   ORDER by [Value]) as MinDate,
    FIRST_VALUE([Value]) OVER (PARTITION BY EmployeeID
                                    ORDER by [Value]) as MinValue
from #tmp

-- Egy ügynök (pl. EmployeeID = 2) által kötött rendelések esetébenelő, hogy két kis értékű rendelés (<200$) közvetlenül követte egymást?MINTÁZAT KERESÉSE
--Egy rekord bizonyos környezetében egy mintázatot keresünk.kötött rendelések esetében mikor fordultkötött rendelések esetében mikor fordult(<200$) közvetlenül követte egymást?

Select * 
FROM #tmp
Where EmployeeId = 2

-- az aktuális és az előző rekordot nézi az analitikus fgv. az OVERben
-- megnézi melyik a nagyobb és ha a nagyobb is kisebb mint 200 akkor jó.
SELECT OrderDate, maxi
from (
    Select OrderDate, [Value], 
        MAX([Value]) OVER(ORDER BY OrderDate ROWS BETWEEN 1 PRECEDING AND CURRENT ROW) AS maxi   ,
    ROW_NUMBER() OVER (ORDER BY OrderDate) as Sorszam
    FROM #tmp
    WHERE EmployeeID = 2
) as F 
where F.maxi <200 and Sorszam > 1


-- /////////////////////TRANZAKCIÓ/////////////////////////////

-- 18. feladat 31. oldalon

Begin TRY
    DECLARE @nev VARCHAR(40),@kategoria int 
    Set @nev = 'Próba'
    Set @kategoria = 7


    DECLARE @id INT , @db int
        -- Tranzakció elindítása.
    BEGIN TRAN

        INSERT into Products(ProductName,CategoryID)
        VALUES(@nev,@kategoria)

        SET @id = @@IDENTITY -- utolsó beszúrt insert után létrehozott elsődleges kulcs értéke
        -- ha 10 nél több ilyen kategóriájú termék van van akkor...
        Select @db = COUNT(*)
        from Products
        Where CategoryID = @kategoria

        IF @db > 10 BEGIn 
            ROLLBACK TRAN 
            PRINT 'Nem sikerült a termék felvitele darabszám miatt. - 10nél több termék van '
        END 
        ELSE BEGIN
            UPDATE Products
            SEt UnitsInStock = 100 
            Where ProductID = @id
            Commit TRAN
            Print 'TERMÉK SIKERESEN FELVÉVE'
        END


end try 
BEgin catch 
    Print ERROR_MESSAGE()
    ROLLBACK TRAN 
    PRINT 'Tranzakció visszagörgetése hiba miatt!'
end catch 

-- ELLENŐRZÉS:
Select COUNT(*)
From Products
-- Where CategoryID = 1 -- 12 termék
Where CategoryID = 7 -- 5 termék

-- Script kimenete :
    -- Ha 1 a CategoryID:
-- (1 row affected) --Nem sikerült a termék felvitele darabszám miatt. - 10nél több termék van 
    -- HA 7 a CategoryID:
--(1 row affected) --(1 row affected)-- TERMÉK SIKERESEN FELVÉVE