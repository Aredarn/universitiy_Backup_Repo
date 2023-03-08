SELECT * From ugyfel 
ORDER BY szuldat ASC, neme ASC, lakcim DESC

-- 19. feladat

SELECT top(5) * FROM szgk
ORDER by ar DESC

-- 20. feladat

SELECT top(5) WITH ties * FROM szgk
ORDER by ar DESC

-- 21. feladat

SELECT TOP(10) PERCENT gyarto, tipus,ar FROM szgk
ORDER by ar DESC

-- 22. FELADAT

SELECT *FROM szgk
WHERE ar <6000
And kolcsonozheto = 1

-- 23. 
SELECT *FROM kolcsonzes
where kidat BETWEEN '2019-01-01' and '2019-01-31'

-- 24.


SELECT rendszam DICTINCT FROM kolcsonzes
where kidat BETWEEN '2019-01-01' and '2019-01-31'


--25.

SELECT *FROM kolcsonzes
where not kidat BETWEEN '2019-01-01' and '2019-01-31'


--26

Select * FROM szgk
Where gyarto = 'Toyota' or gyarto = 'BMW'

-- 27

Select * FROM szgk
Where NOT gyarto = 'Toyota' AND NOT gyarto = 'BMW'

-- 28

Select * from ugyfel 
Where lakcim like '%Veszprém,%'


-- 29

SELECT * from ugyfel
where  telefon is NULL OR telefon = ''   


SELECT * from ugyfel 
Where LEN(telefon) =0


-- 30 

Select * from ugyfel 
WHERE telefon is not null 

-- 31
UPDATE ugyfel 
SET telefon = NULL
WHERE LEN(telefon) <= 1 

-- 32

Select orszag, nev 
 from orszag 
 join ugyfel ON orszag.orszagID = ugyfel.orszagID 
 ORDER BY orszag, nev



-- 34
select nev, kidat, s.rendszam
FROM kolcsonzes k JOIN ugyfel u ON k.ugyfelID = u.ugyfelID
JOIN szgk s ON s.rendszam = k.rendszam
where gyarto in ('BMW', 'FIAT')

