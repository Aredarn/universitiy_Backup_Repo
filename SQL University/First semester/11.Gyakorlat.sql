INSERT INTO ugyfel(nev)
    VALUES('Vincs Eszter')

SELECT * FROM ugyfel


--HA nem létezik a tábla -- >HIBA
INSERT INTO szgk(rendszam, gyarto, tipus, ar)
VALUES('ABC123', 'Trabant', 'Combi', 1000)

SELECT * FROM szgk 

--HA létezik a tábla -- > HIBA
SELECT * INTO Teszt
from db1..szgk
WHERE 2022-evjarat <= 5

SELECT * from Teszt7


-- CSAK ÍGY LEHET SET UPDATE TOPOT

UPDATE szgk
SET ar = ar * 0.9
WHERE rendszam IN (
    SELECT TOP(3) with ties rendszam 
    from szgk
    ORDER by ar ASC     
) 


UPDATE szgk
set ugyfel = stragg
from szgk s join
(SELECT rendszam , STRING_AGG(nev, ',') as stragg
                FROM kolcsonzes k 
                join ugyfel u ON k.ugyfelID = u.ugyfelID
                GROUP by rendszam, nev
) agg ON agg.rendszam = s.rendszam




DELETE ugyfel 
    WHERE ugyfelID in (SELECT kolcsonzes.ugyfelID FROM kolcsonzes)