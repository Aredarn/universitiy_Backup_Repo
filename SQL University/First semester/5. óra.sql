EXEC db1..sp_CreateTables

Select orszag, neme, COUNT(ugyfelID) as Darab 
from orszag o 
left join ugyfel u on o.orszagId = u.orszagID
GROUP by orszag, neme

SELECT *
from ugyfel

Select AVG(Year(GETDATE())-Year(szuldat)*1.0) , neme
from ugyfel
WHERE lakcim LIKE '%Veszprém,%'
GROUP by neme

Select gyarto, COUNT(tipus)
from szgk
GROUP by gyarto
HAVING COUNT(tipus) > 1

-- 36. feladat

SELECT COUNT(distinct rendszam)
from szgk

-- 37. feladat

SELECT Count(distinct gyarto)
FROM szgk

-- 38. feladat
SELECT count(*), SUM(szemelyek)
from szgk
WHERE uzemanyag = 'diesel'

-- 39. feladat
SELECT avg(YEAR(GETDATE())-evjarat *1.0)
from szgk
WHERE uzemanyag = 'diesel'

--40. feladat

Select gyarto, count(gyarto)
from szgk
GROUP by gyarto
ORDER by count(gyarto) DESC

-- 41. feladat

SELECT gyarto, STRING_AGG(rendszam, ';') as rendszamok
from szgk
GROUP by gyarto

-- 42. feladat

SELECT gyarto, 
STRING_AGG(rendszam, ';') WITHIN GROUP(ORDER by rendszam) as rendszamok
from szgk
GROUP by gyarto

-- 43. feladat

select u.nev, u.ugyfelID, COUNT(kolcsID)
from ugyfel u left JOIN kolcsonzes k ON u.ugyfelID = k.ugyfelID
GROUP by u.ugyfelID, u.nev
ORDER by COUNT(kolcsID) DESC