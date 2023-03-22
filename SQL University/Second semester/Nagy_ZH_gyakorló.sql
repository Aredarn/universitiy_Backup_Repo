-- 1.A

SELECT CategoryName as Kategória, Year(OrderDate) AS Ev, SUM(quantity) as mennyiseg   
from [Order Details] od join Orders o on od.OrderID = o.OrderID JOIN Products p ON od.ProductID = p.ProductID join Categories c ON p.CategoryID = c.CategoryID
WHERE p.UnitPrice >90
GROUP by  c.CategoryID, Year(OrderDate), CategoryName
--Order by YEAR(OrderDate), CategoryName

-- 1.B PIVOT Kategória értékkészletét tudjuk Pivotálni, így ezek oszlopok lesznek, de akár a dátum szerint is lehet

-- katórgia szerinti forgatás

SELECT *
from (
    SELECT CategoryName as Kategória, Year(OrderDate) AS Ev, SUM(quantity) as mennyiseg   
    from [Order Details] od join Orders o on od.OrderID = o.OrderID JOIN Products p ON od.ProductID = p.ProductID join Categories c ON p.CategoryID = c.CategoryID
    WHERE p.UnitPrice >90
    GROUP by  c.CategoryID, Year(OrderDate), CategoryName) as FORRAS --AS kötelező 
PIVOT (SUM(mennyiseg) FOR Kategória IN([Beverages], [Meat/Poultry])) as PT  --AS kötelező || hogy melyik sorokból legyen oszlop IN([Beverages], [Meat/Poultry]) ||MIDNIG KELL AGGREGÁLÓ FVG a PIVOTON BELÜL


-- Év szerinti forgatás

SELECT *
from (
    SELECT CategoryName as Kategória, Year(OrderDate) AS Ev, SUM(quantity) as mennyiseg   
    from [Order Details] od join Orders o on od.OrderID = o.OrderID JOIN Products p ON od.ProductID = p.ProductID join Categories c ON p.CategoryID = c.CategoryID
    WHERE p.UnitPrice >90
    GROUP by  c.CategoryID, Year(OrderDate), CategoryName) as FORRAS --AS kötelező 
PIVOT (SUM(mennyiseg) FOR Ev IN([1996], [1997], [1998])) as PT  --AS kötelező || hogy melyik sorokból legyen oszlop IN([Beverages], [Meat/Poultry]) ||MIDNIG KELL AGGREGÁLÓ FVG a PIVOTON BELÜL


-- 2. 
-- előzetes tesztek
-- kinek hány területe van
SELECT EmployeeId, count(*) from EmployeeTerritories GROUP by EmployeeID

--ID 1: 2db field, ID 2:7 Field
-- A 7 field már sok, max 5 lehet

-- Van e szabad terület??
SELECT *
from Territories
Where TerritoryID  NOT IN (Select TerritoryID from EmployeeTerritories)

-- ABC-ben az első

SELECT top(1) *
from Territories
Where TerritoryID  NOT IN (Select TerritoryID from EmployeeTerritories)
Order by TerritoryDescription


-- SZKRIPT


BEGIN TRY
    -- SELECT 1/0 -- Csak teszt hogy megy e a catch ág.
    DECLARE @empID INT  -- BEMENŐ paraméter
    SET @empID = 1

    -- Hány területe van? 
    DECLARE @teruletszam INT, @teruletazonosito VarChar(20), @teruletLeiras CHAR(50)

    SELECT @teruletszam = count(*) 
    from EmployeeTerritories 
    Where EmployeeID = @empID

    --Ha ötnél több -- > HIBAÜZENET

    IF @teruletszam > 5 
        PRINT '5-nél több területe van!!!  ' + cast(@teruletszam AS varchar(3))
    ELSE BEGIN-- kevesebb mint 5
        -- Szabad terület meghatározása (1. találat ABC szerint)
        SELECT top(1) @teruletazonosito = TerritoryID, @teruletLeiras = TerritoryDescription
        from Territories
        Where TerritoryID  NOT IN (Select TerritoryID from EmployeeTerritories)
        Order by TerritoryDescription

        -- Ha nincs ilyen terület
        if @teruletazonosito IS NULL
            PRINT 'NINCS SZABAD TERÜLET!'
        ELSE BEGIN -- Ha van szabad hely
            --Alkalmazott rendelés
            INSERT INTO EmployeeTerritories 
            VALUES(@empID,@teruletazonosito)
            -- alkalmazott fizetésemelése
            UPDATE Employees
            SET Salary = Salary * 1.25
            WHERE EmployeeID = @empID

            -- adatok visszaírása
            PRINT CONCAT('A(z) ', @empID, ' alkalmazotthoz hozzárendeltük a következő területet: ', @teruletazonosito, ' -- ', @teruletLeiras)

        END
    END

END TRY
BEGIN CATCH
    PRINT CONCAT('Hiba: ', ERROR_NUMBER(), ' - ', ERROR_MESSAGE())
END CATCH



-- TESZT
-- SELECT 1/0 : HIBA 8134 - Hibaüzenet
-- @empid = 2 : 5-nél több terület.
-- @empid = 1 : A(z) 1 alkalmazotthoz hozzárendeltük a következő területet: 78759 -- Austin , Salary: 100, futtatás után: 125
