SELECT * 
FROM db1..kolcsonzes
SELECT * INTO kolcsonzes
FROM db1..kolcsonzes

SELECT * 
FROM db1..szgk
SELECT * INTO szgk
FROM db1..szgk

SELECT * FROM
db1..ugyfel
SELECT * INTO ugyfel 
from db1..ugyfel

SELECT *FROM
db1..orszag
SELECT * into orszag FROM
db1..orszag



-- 2. 
-- DATEDIFF - el nem megoldható mert az evjarat egy INT

Select gyarto, year(GETDATE()) - MIN(evjarat) 
FROM szgk
GROUP by gyarto


-- 3. 
-- COUNT(*) visszaadja a sorok számát

SELECT len(CONCAT(gyarto, ' ', tipus)), count(*)
from szgk
GROUP by len(CONCAT(gyarto, ' ', tipus))

-- 4. 
SELECT gyarto, tipus, ar, 
    CASE
        WHEN ar <6000 then 'Budget'
        WHEN ar > 11000 then 'Luxury'
        else 'normal'
    END  
from szgk

GO
-- 5. 
-- Piros aláhúzás nem baj, GO utasítás kell ha zavar
CREATE VIEW v_toyota AS
SELECT * from szgk 
where gyarto = 'Toyota'
with CHECK OPTION
GO

-- 6.
CREATE UNIQUE INDEX idx_unique_orszag
ON orszag(orszag)
-- ()-ben az oszlop 

-- 7. 
-- AVG NÉL SZOROZD MEG 1.0VAL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- NEV is group by kell, ami a selectbe van mindig muszáj mert akkor agregált lesz
select nev ,COUNT(kolcsID) AS DB
from kolcsonzes K 
JOIN ugyfel U ON k.ugyfelID = u.ugyfelID 
GROUP by k.ugyfelID, nev
HAVING AVG(1.0 * Datediff(DAY, kidat, hatdat)) > 6


-- 8


SELECT nev
from ugyfel
WHERE ugyfelID in
(
SELECT ugyfelID 
from kolcsonzes k  
join szgk s ON k.rendszam = s.rendszam
WHERE gyarto = 'Chevrolet'

INTERSECT

SELECT ugyfelID 
from kolcsonzes k  
join szgk s ON k.rendszam = s.rendszam
WHERE gyarto = 'BMW'
)


--9
WITH utolsok as (
    SELECT ugyfelID, MAX(kidat) utolso
    from kolcsonzes 
    GROUP by ugyfelID
)
SELECT DISTINCT nev from kolcsonzes k 
join szgk s ON k.rendszam = s.rendszam
join ugyfel u ON u.ugyfelID = k.ugyfelID 
where gyarto = 'Opel'
and EXISTS(
    Select 1 
    from utolsok
    WHERE utolsok.ugyfelID = k.ugyfelID
    and utolsok.utolso = k.kidat
)


SELECT DISTINCT nev from kolcsonzes k 
join szgk s ON k.rendszam = s.rendszam
join ugyfel u ON u.ugyfelID = k.ugyfelID 
where gyarto = 'Opel'
and EXISTS(
    Select 1 
    from kolcsonzes k2
    GROUP by k2.ugyfelID
    HAVING MAX(k2.kidat) = k.kidat
    and k2.ugyfelID = k.ugyfelID
)


--10

SELECT s.rendszam, gyarto, tipus,DATEDIFF(MONTH,MIN(kidat), GETDATE()) as elso
FROM kolcsonzes k 
JOIN szgk s ON s.rendszam = k.rendszam
GROUP by s.rendszam, gyarto, tipus


select * from kolcsonzes
drop table szgk
drop TABLE kolcsonzes