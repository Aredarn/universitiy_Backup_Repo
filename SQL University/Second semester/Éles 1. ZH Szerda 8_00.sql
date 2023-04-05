SELECT p.ProductName as Név, CompanyName as Cég, SUM(Quantity) as Darab from
Shippers s join Orders o On s.ShipperID = o.ShipVia
join [Order Details] od ON od.OrderID = o.OrderID
JOIN Products p ON od.ProductID = p.ProductID
WHERE ProductName like 'A%'
GROUP BY ProductName,CompanyName
ORDER by Darab


--Aniseed Syrup    Speedy Express     70
--Aniseed Syrup    United Package     128
--Aniseed Syrup    Federal Shipping 130
--Alice Mutton    Federal Shipping 217
--Alice Mutton    Speedy Express    345
--Alice Mutton    United Package    416


-- 1. B

SELECT *
from (
SELECT p.ProductName as Nev, CompanyName as Ceg, SUM(Quantity) as Darab from
Shippers s join Orders o On s.ShipperID = o.ShipVia
join [Order Details] od ON od.OrderID = o.OrderID
JOIN Products p ON od.ProductID = p.ProductID
WHERE ProductName like 'A%'
GROUP BY ProductName,CompanyName
) as TABLA
PIVOT ( Sum(Darab) FOR Ceg IN ([Speedy Express],[United Package], [Federal Shipping])  ) as PT

--Alice Mutton    345    416    217
--Aniseed Syrup    70    128    130


-- 2

    -- TESZT SELECTEK
    Select COUnt(o.OrderID)
    from  Shippers s join Orders o On s.ShipperID = o.ShipVia
    join [Order Details] od ON od.OrderID = o.OrderID
    JOIN Products p ON od.ProductID = p.ProductID
    WHERE CategoryID = 100


    SELECT TOP(1) SUM(Quantity*od.UnitPrice*(1-Discount)), e.EmployeeID
    FROM Employees e join Orders o ON e.EmployeeID = o.EmployeeID
    join [Order Details] od ON o.OrderID = od.OrderID
    join Products p ON p.ProductID = od.ProductID
    GROUP by e.EmployeeID
    ORDER by SUM(Quantity*od.UnitPrice*(1-Discount)) Desc




GO
Begin TRY
    
    DECLARE @CategoryID INT, @VoltERendeles INT, @ugynokID INT, @bevetel INT, @fizelott INT
    SET @CategoryID = 10
    SET @VoltERendeles = 0


    Select @VoltERendeles = COUNT(o.OrderID)
    from  Shippers s join Orders o On s.ShipperID = o.ShipVia
    join [Order Details] od ON od.OrderID = o.OrderID
    JOIN Products p ON od.ProductID = p.ProductID
    WHERE CategoryID = @CategoryID  

    if @VoltERendeles = 0
        PRINT CONCAT('Nincs ilyen rendelés azonosító: ', @CategoryID)
    ELSE BEGIN

        SELECT @bevetel = SUM(od.Quantity*od.UnitPrice*(1-Discount)),@ugynokID = e.EmployeeID
        FROM Employees e join Orders o ON e.EmployeeID = o.EmployeeID
        join [Order Details] od ON o.OrderID = od.OrderID
        join Products p ON p.ProductID = od.ProductID
        WHERE  CategoryID = @CategoryID
        GROUP by e.EmployeeID
        ORDER by SUM(Quantity*od.UnitPrice*(1-Discount)) ASC

        -- ASC mert így a legutolsót fogja a változóba beletenni

        if @ugynokID = 0
            PRINT 'Nincs ehhez a kategóriához ügynök rendelve'
        ELSE BEGIN

            Select @fizelott = Salary
            FROM Employees
            Where EmployeeID = @ugynokID

            IF @bevetel > 30000
                UPDATE Employees SET Salary = Salary + 200 WHERE EmployeeID = @ugynokID
            ELSE
                UPDATE Employees SET Salary = Salary + 100 WHERE EmployeeID = @ugynokID

            DECLARE @fizutan INT
            Select @fizutan = Salary
            FROM Employees
            Where EmployeeID = @ugynokID

            PRINT CONCAT('Kategória: ', @CategoryID)
            PRINT CONCAT('Ugynok: ', @ugynokID)
            PRINT CONCAT('Forgamlom: ', @bevetel)
            PRINT CONCAT('Fizetes: ', @fizelott, ' ---> ', @fizutan )
        END
    END

END TRY
BEGIN CATCH
    PRINT CONCAT('Végrehajtási hiba: ', ERROR_NUMBER(), ' - ', ERROR_MESSAGE())
END CATCH
GO

-- 10-es értékre : Nincs ilyen rendelés azonosító: 10

-- 1-8ig lefut Példa:

-- Kategória: 6
-- Forgalom: 30867
-- Fizetés: 1200 ---> 1400 (Pár teszt után)

-- Kategória: 5
-- Forgalom: 22579
-- Fizetés: 1400 ---> 1500 (Pár teszt után)