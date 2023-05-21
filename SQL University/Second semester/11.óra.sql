/*ÖNÁLLÓ FELADAT #21: írjunk függvényt, amely a paraméterül kapott alkalmazott ID (EmployeeID) alapján
visszaadja az illető eddigi rendeléseinek a számát! Teszteljük a függvényt SELECT lekérdezéssel!*/


GO
create FUNCTION fel21fgv (@empid int) returns int as
BEGIN
    DECLARE @rendelesszam int 
        
    select @rendelesszam = count(*)
    from Orders
    where EmployeeID = @empid

    RETURN @rendelesszam
END
GO



GO
create or alter FUNCTION fel21fgvm (@empid int) returns int as
BEGIN
    DECLARE @rendelesszam int , @van int
    
    -- ellenőrzés: van-e ilyen számú ügynök
    SELECT @van = EmployeeID
    from Employees
    where EmployeeID = @empid


    if @van is null
        set @rendelesszam = -1
    else 
    BEGIN
        -- megvan az ügynök, rendelésszámlálás
        select @rendelesszam = count(*)
        from Orders
        where EmployeeID = @empid
    END

    RETURN @rendelesszam
END
GO


--teszt

SELECT COUNT(*) from Orders where EmployeeID = 5 --> 

SELECT dbo.fel21fgv(5) -->
SELECT dbo.fel21fgv(100) --> 0

-- második fgv teszt 
declare @eredmeny int 
set @eredmeny=  dbo.fel21fgvm(100) 

if(@eredmeny = -1)
PRINT('Nincs ilyen ID')
else
select @eredmeny 

--- > Nincs ilyen ID


/* ÖNÁLLÓ FELADAT #24: írjunk függvényt, amely egy táblában visszaadja a paraméterként kapott
azonosítójú alkalmazotthoz tartozó területek nevét és régióját (RegionDescription és TerritoryDescription mezők)!*/

go 

create FUNCTION fel24fgv(@empid int)
returns TABLE AS
RETURN
(
    SELECT RegionDescription, TerritoryDescription
    from EmployeeTerritories ET join Territories T on et.TerritoryID = t.TerritoryID join Region R on r.RegionID = t.RegionID
    WHERE EmployeeID = @empid

)


go 





