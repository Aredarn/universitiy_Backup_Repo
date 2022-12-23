EXEC db1..sp_CreateTables


Select *
from szgk
--12
Select gyarto,tipus,ar,szemelyek
from szgk
--13
SELECT distinct gyarto 
from szgk
--14
SELECT distinct gyarto, tipus 
from szgk

--16

Select gyarto as marka,tipus as modell,ar,szemelyek
from szgk


--17
Select gyarto  + ' ' + tipus as [Szemelygepkocsi tipusa], Cast(ar as varchar) + 'Ft' as napidij,szemelyek
from szgk


-- 18 
SELECT *
FROM ugyfel
ORDER by szuldat Asc

SELECT top(5) with ties *
from szgk
order by ar DESC

SELECT top(10) percent with ties gyarto, tipus, ar
from szgk 
order by ar asc

--22 
Select * 
from szgk 
where ar <=6000 AND kolcsonozheto = 1


-- 24 tuningolva

SELECT *
FROM szgk
WHERE rendszam IN(
SELECT Distinct rendszam
from kolcsonzes
where kidat BETWEEN '2019-01-01' and '2019-01-31'
)


-- 26
Select *
from szgk
WHERE gyarto in ('BMW','Toyota') 

--27

Select *
from szgk
WHERE gyarto NOT in ('BMW','Toyota') 

-- 28 
SELECT *
from ugyfel
WHERE lakcim LIKE '%Veszprém,%'


-- 29 ??
CREATE Table konyv
(
    Kod int primary KEY,
    Cim varchar(50),
    Szerzo Varchar(50),
    Kiadas_Eve SMALLINT,
    Kiado VARCHAR(50),
    Illusztralt CHAR(1),
    Ar money
)

drop table if EXISTS konyv

SELECT *
FROM konyv

INSERT into konyv 
VALUES(1,'Az SQL','Bródy Bence', 2019, 'JOSK','I',2500),
(2,'Az SQL Perf','Markus Winand', 2011, 'Markus Winand','N',12500)


Update konyv 
set Ar = Ar-300

UPDATE konyv
set Szerzo = 'Bódy Bence'
WHERE Szerzo = 'Bródy Bence'


-- 29 
Select *
from ugyfel
where telefon is NULL or telefon = ''

-- 32 
Select nev, orszag
from ugyfel u JOIN orszag o ON u.orszagID = o.orszagID
ORDER by orszag, nev

--34 
SELECT nev, kidat, s.rendszam
from ugyfel u join kolcsonzes k on u.ugyfelID = k.ugyfelID JOIN szgk s ON s.rendszam = k.rendszam
WHERE s.gyarto IN ('BMW', 'Fiat')


-- 35  

SELECT *
from ugyfel
Where ugyfelID IN 
(
    Select ugyfelID
    from kolcsonzes
    where ugyfelID is null
)

SELECT u.*, k.kidat
FROM ugyfel AS u
LEFT JOIN kolcsonzes AS k ON u.ugyfelID = k.ugyfelID
WHERE k.kolcsID IS NULL


SELECT Count(*)
FROM ugyfel
GROUP by orszagID

SELECT neme, avg(2022 - YEAR(szuldat) *1.0) as [Atlag eletkor]
From ugyfel
WHERE lakcim like '%Veszprém,%'
GROUP BY neme

SELECT gyarto, COUNT(distinct tipus) as db
From szgk
GROUP by gyarto
HAVING COUNT(distinct tipus) > 1


SELECT COUNT(distinct gyarto) as [KocsikSzama]
from szgk

SELECT COUNT(*) as [Diesel Kocsik], SUM(szemelyek) as [Osszes szemely]
from szgk
WHERE uzemanyag like 'diesel'

SELECT AVG(YEAR(GETDATE()) - evjarat *1.0) as [Atlageletkor]
from szgk
WHERE uzemanyag like 'diesel'


-- 40
Select gyarto,COUNT(rendszam)
FROM szgk
GROUP by gyarto
ORDER by COUNT(rendszam) DESC

-- 41 
Select gyarto, STRING_AGG(rendszam, ';') as [rendszamok]
from szgk
GROUP by gyarto 

-- 42
Select count(k.ugyfelID) as [Kolcsonzes szama]
from ugyfel u left join kolcsonzes k ON u.ugyfelID = k.ugyfelID
GROUP by k.ugyfelID
ORDER by [Kolcsonzes szama] DESC

-- 43
Select nev, COUNT(k.ugyfelID)
from ugyfel u left JOIN kolcsonzes k ON u.ugyfelID = k.ugyfelID
GROUP BY k.ugyfelID, nev
Having COUNT(k.ugyfelID) > 15
ORDER by COUNT(k.ugyfelID) DESC


-- 45 
Select u.ugyfelID, nev, s.gyarto, COUNT(kolcsID)
from ugyfel u join kolcsonzes k ON u.ugyfelID = k.ugyfelID join szgk s ON s.rendszam = k.rendszam 
GROUP by nev , s.gyarto , u.ugyfelID
ORDER by nev, COUNT(kolcsID) DESC


-- 46 
SELECT gyarto, tipus,
SUM(kolcsDij) AS [Bevétel],
COUNT(KolcsID) AS [Kölcsönzések száma (db)]
FROM kolcsonzes AS k
JOIN szgk a ON a.rendszam = k.rendszam
GROUP BY gyarto, tipus
ORDER BY 'Bevétel' DESC


-- 47 
Select gyarto, Count(rendszam)
from szgk
WHERE szemelyek = 7
GROUP by gyarto

-- 48 
SELECT TOP (1) WITH TIES rendszam
FROM kolcsonzes 
GROUP BY rendszam
ORDER BY COUNT(rendszam) DESC



-- 49 
Select nev, SUBSTRING(lakcim,1,4)
from ugyfel

--50
Select nev, len(nev) as Hossza
FROM ugyfel


--51
SELECT nev , DATEDIFF(YEAR,szuldat,GETDATE()) as [Év]
from ugyfel

--52
SELECT nev , DATEDIFF(YEAR,szuldat,GETDATE()) as [Év]
from ugyfel
ORDER by [Év] DESC

--52
SELECT nev , DATEDIFF(YEAR,szuldat,GETDATE()) as [Év]
from ugyfel
ORDER by [Év] DESC, nev asc

-- 53 
Select DISTINCT(MONTH(szuldat)) as [Szulihonap]
from ugyfel

SELECT nev,
szuldat AS [Hivatalos szüldat],
DATEADD(day, -120, szuldat) AS [Valós]
FROM ugyfel
WHERE nev = 'Kovács Elek'


-- 58 

Select *
from szgk
WHERE rendszam like 'G%'


-- 59 
SELECT nev, 
    case neme
        when 'f' then 'ferfi'
        when 'n' then 'no'
        end nem
FROM ugyfel

-- 61
SELECT nev, szuldat,
case 
        when Year(szuldat) > 1995  then 'Z'
        when Year(szuldat) > 1981 THEN 'Y'
        when Year(szuldat) > 1963 THEN 'X'
        else 'IDK'
    end generacio
from ugyfel
ORDER by szuldat

SELECT YEAR(kidat) as YEAR , MONTH(kidat) as MONTH, COUNT(kidat) as darab
from kolcsonzes
GROUP by YEAR(kidat), MONTH(kidat)
ORDER by YEAR(kidat), MONTH(kidat)


UPDATE szgk
SET ar = 
Case 
    when gyarto like 'OPEL' then ar* 1.1
    when gyarto like 'BMW' then ar* 1.2
    else ar * 1.05
END


-- 66 

SELECT nev, szuldat, DATEDIFF(YEAR, szuldat, GETDATE()) as eletkor, 
(SELECT AVG(DATEDIFF(YEAR, szuldat, GETDATE()) * 1.0) from ugyfel)
from ugyfel 

-- 67

SELECT *
from ugyfel 
WHERE ugyfelID NOT IN 
(Select ugyfelID
from kolcsonzes k join szgk s ON k.rendszam = s.rendszam
WHERE s.gyarto like 'BMW')


SELECT *
FROM ugyfel
EXCEPT
SELECT *
FROM ugyfel
WHERE ugyfelID IN (SELECT ugyfelID
FROM kolcsonzes AS k
JOIN szgk AS s ON k.rendszam = s.rendszam
WHERE gyarto = 'BMW')


-- 71

SELECT * 
from szgk 
where gyarto = 'Opel' and ar <
(
Select avg(ar) 
from szgk 
where gyarto = 'Opel')


-- 74 
go
CREATE VIEW V_ferfiak
AS 
SELECT ugyfelID,nev,szuldat,neme 
from ugyfel
where neme = 'f'
go

-- 80 
CREATE NONCLUSTERED INDEX idx_ ON ugyfel(nev) 

DROP INDEX IF EXISTS idx_ ON ugyfel




-- ZH

-- 1. 

Select *
into kolcs
from kolcsonzes

SELECT * 
into szg
from szgk

Select * 
into ugyf
from ugyfel

SELECT *
into orsz 
from orszag


-- 2. 
SELECT gyarto,year(GETDATE()) - MIN(evjarat)
from szgk
GROUP by gyarto


-- 3
SELECT COUNT(*), LEN(gyarto + ' ' + tipus)
from szgk
GROUP by LEN(gyarto + ' ' + tipus)

-- 4

SELECT gyarto,tipus, ar ,

Case 
    when ar > 11000 then 'Luxury'
    when ar < 6000 then 'Budget'
    else 'Normal'  
end Kategoria 
from szgk


-- 5 
go
CREATE VIEW v_toyotak AS
SELECT *
from szgk
WHERE gyarto = 'Toyota'
With CHECK OPTION

GO

-- 6
Create UNIQUE INDEX idx_unique_orszag On orszag(orszag) 

-- 7
SELECT nev, COUNT(k.kolcsID)
from ugyfel u join kolcsonzes k ON u.ugyfelID=k.ugyfelID
GROUP by k.ugyfelID, nev
HAVING AVG(1.0 * Datediff(DAY, kidat, hatdat)) >6


-- 8
SELECT *
from ugyfel
where ugyfelID IN 
(
    Select ugyfelID
    FROM  kolcsonzes k join szgk s on k.rendszam = s.rendszam
    WHERE s.gyarto = 'BMW'

    INTERSECT

    Select ugyfelID
    FROM  kolcsonzes k join szgk s on k.rendszam = s.rendszam
    WHERE s.gyarto = 'Chevrolet'
)


-- 10 
SELECT s.rendszam, gyarto, tipus, DATEDIFF(MONTH,MIN(kidat), GETDATE())
from szgk s join kolcsonzes k ON s.rendszam = k.rendszam
GROUP by s.rendszam,gyarto,tipus


