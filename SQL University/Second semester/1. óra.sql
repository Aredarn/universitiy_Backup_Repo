SELECT *
from Products

-- 1. feladat
-- melyik termékkategóriában hány termék van?
-- legyen darabszám szerint csökkenő


SELECT c.CategoryID, CategoryName, COUNT(*) db
FROM Categories c JOIN Products p ON c.CategoryID = p.CategoryID 
GROUP BY c.CategoryID, c.CategoryName
ORDER BY db DESC

-- Egyes rendelések értéke
SELECT UnitPrice*Quantity*(1-Discount) ertek
from [Order Details]


-- MEnnyi volt az egyes rendelések értéke, azonosítóval és dátummal

SELECT o.OrderID, OrderDate, SUM(UnitPrice*Quantity*(1-Discount)) ertek
FROM [Order Details] od JOIN [Orders] o ON od.OrderID = o.OrderID
GROUP by o.OrderID, o.OrderDate

-- Egyes ügynökök milyen összértékű rendelést kötöttek? EZeket hány rendelésből?

SELECT e.EmployeeID, e.LastName, COUNT(o.OrderID), SUM(UnitPrice*Quantity*(1-Discount)) ertek
From [Order Details] od JOIN [Orders] o ON od.OrderID = o.OrderID JOIN Employees e ON e.EmployeeID = o.EmployeeID
Group by e.EmployeeID, LastName
Order BY ertek DESC


-- Mezőorientált modell --> rekordorientált modell

SELECT EmployeeID,LastName,Title,City
INTO EmployeeField 
from northwind..Employees


-- törzstábla létrehozása

CREATE TABLE Attributes_(
    AttribID INT PRIMARY KEY,
    AttribName NVARCHAR(100),
    AttribType NVARCHAR(100)
)


-- törzstábla feltöltése: milyen attribútumokat tárolunk?

INSERT into Attributes_
VALUES(1, 'LASTNAME', 'text'), (2, 'Title', 'text'), (3, 'valami', 'text')


-- Rekord orientált tábla létrehozása

CREATE TABLE EmployeeRecord_(
    EmployeeID INT not NULL,
    AttribId int not NULL REFERENCES Attributes_,
    AttribValue NVARCHAR(500),
    PRIMARY KEY(EmployeeID,AttribId)
)

-- EmployeeRecord feltöltése

SELECT EmployeeID,1, LastName
FROm EmployeeField
WHERE LastName is not NULL

UNION

SELECT EmployeeID,2, LastName
FROm EmployeeField
WHERE Title is not NULL

UNION

SELECT EmployeeID,3, LastName
FROm EmployeeField
WHERE City is not NULL