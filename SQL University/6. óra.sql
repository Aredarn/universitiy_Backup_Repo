EXEC db1..sp_CreateTables

-- 43. feladat

select u.nev, u.ugyfelID, COUNT(kolcsID)
from ugyfel u left JOIN kolcsonzes k ON u.ugyfelID = k.ugyfelID
GROUP by u.ugyfelID, u.nev
ORDER by COUNT(kolcsID) DESC


-- 44. feladat

select nev, COUNT(kolcsID) as db
from ugyfel
join kolcsonzes ON ugyfel.ugyfelID = kolcsonzes.ugyfelID
GROUP by nev, ugyfel.ugyfelID
HAVING COUNT(kolcsID) >= 15


-- 45. feladat

Select nev, gyarto, COUNT(kolcsID) as darab
FROM ugyfel u 
LEFT JOIN kolcsonzes k on u.ugyfelID = k.ugyfelID
LEFT JOIN szgk s ON s.rendszam = k.rendszam
GROUP by nev, u.ugyfelID, gyarto
ORDER BY nev,darab DESC


-- 46. feladat

select gyarto, tipus, COUNT(kolcsdij) as osszeg, SUM(kolcsdij + potdij) Bevetel
from szgk s 
left join kolcsonzes k ON s.rendszam = k.rendszam
GROUP by gyarto, tipus
ORDER by Bevetel DESC

-- 47. feladat

SELECT TOP(1) with ties gyarto, COUNT(rendszam)
from szgk 
where szemelyek = 7
GROUP by gyarto
ORDER by COUNT(rendszam) DESC

-- 48. feladat
SELECT top(1) with ties szgk.rendszam, szgk.gyarto, COUNT(kolcsID) darab
from szgk
LEFT JOIN kolcsonzes k ON szgk.rendszam = k.rendszam
GROUP by szgk.rendszam, gyarto, tipus
ORDER by COUNT(kolcsID) desc



-- 49. feladat
SELECT nev, lakcim, SUBSTRING(lakcim, 1,4) as Iranyitoszam
FROM ugyfel


-- 50.feladat
SELECT nev, len(nev) as hossz
from ugyfel


-- 51. feladat
SELECT nev, 2022-YEAR(szuldat), YEAR(GETDATE()) - YEAR(szuldat), DATEDIFF(YEAR, szuldat, GETDATE())
from ugyfel



-- 52. feladat
SELECT nev, DATEDIFF(YEAR, szuldat, GETDATE())
from ugyfel
ORDER by szuldat ASC

-- 53. feladat
SELECT nev, DATEDIFF(YEAR, szuldat, GETDATE()) kor
from ugyfel
ORDER by kor desc, nev asc

-- 54. feladat
SELECT distinct MONTH(szuldat) szulihonap 
from ugyfel


-- 55.feladat
SELECT nev, DATEDIFF(MONTH, szuldat, GETDATE()), FORMAT(szuldat, 'yyyy.MMMM.dd')
from ugyfel

--56. feladat
SELECT nev, szuldat hivatalos, DATEADD(DAY, -120, szuldat)
from ugyfel 
WHERE nev = 'Kovács Elek'

-- 57. feladat
SELECT * 
from ugyfel
WHERE lakcim like '%Veszprém%'

-- 58. feladat
SELECT *
from szgk
where rendszam like 'G%'


-- 59. feladat
SELECT nev, neme, 
    case neme
        when 'n' then 'no'
        when 'f' then 'ferfi'
    end as simpCASE
from ugyfel

-- 60. feladat, 63-81-95

SELECT nev, szuldat,
    case
        when year(szuldat) >=1995 then 'Z'
        when year(szuldat) >=1981 then 'Y'
        when year(szuldat) >=1960 then 'X'
        else 'Other'
    end as generacio
from ugyfel 

-- 61. feladat

SELECT generacio, count(kolcsID)
from kolcsonzes
RIGHT JOIN
(
    SELECT ugyfelID,
        case
            when year(szuldat) >=1995 then 'Z'
            when year(szuldat) >=1981 then 'Y'
            when year(szuldat) >=1960 then 'X'
            else 'Other'
        end as generacio
    FROM ugyfel
) as gen on gen.ugyfelID = kolcsonzes.ugyfelID
GROUP by gen.generacio


-- 62. format
SELECT FORMAT(kidat, 'yyyy-MM'), count(kolcsID) as darab
from kolcsonzes
GROUP by FORMAT(kidat, 'yyyy-MM')
