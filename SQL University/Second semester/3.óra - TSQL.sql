GO
-- Fibonacci-számok 1000ig

DECLARE @a int = 1,  @b int = 1, @eredmeny int

print @a
PRINT @b 
    WHILE @a + @b < 1000 BEGIN

        Set @eredmeny = @b
        SET @b = @a + @b 
        SET @a= @eredmeny

        PRINT @b
    END
GO

-- Önálló feladat 14/#5
-- kapott nevű termék termék kategóriája

Select * from Products
DECLARE @nev VARCHAR(40) = 'Aniseed%', @kategoria INT

--Termék megkeresése egy kategóriaazonosító elmentése egy változban

SELECT CategoryID
FROM Products 
WHERE ProductName LIKE @nev
If @kategoria IS NOT NULL
    PRINT 'A talált kategória: ' + CAST(@kategoria AS VARCHAR(3))
ELSE
    print 'Nincs ilyen termék'
-- Teszt: aniseed esetém:
-- a talált kategoria : 2
