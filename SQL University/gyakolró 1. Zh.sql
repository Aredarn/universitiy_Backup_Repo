CREATE TABLE KONYVEK 
(
    Kod int,
    Cim varchar(50), 
    Szerzo varchar(50),
    Kiadas_eve int,
    Kiado varchar(50),
    Illusztralt varchar(1),
    Ar money
);

SELECT * FROM KONYVEK

INSERT INTO KONYVEK VALUES
(
    1,
     'Az SQL példákon keresztül',
    'Bródy Bence', 
    2019 ,
    'Jedlik Oktatási Stúdió Kft',
    'i', 
     2500
)

Select *from KONYVEK

UPDATE KONYVEK
SET Ar =  Ar-300 , Szerzo = 'Lajos'

DELETE from KONYVEK

Delete KONYVEK



---------------------------------------//
EXEC db1..sp_CreateTables

Select * from szgk

Select gyarto, tipus,ar, szemelyek from szgk 

SELECT gyarto 
FROM szgk
GROUP BY gyarto

SELECT tipus, gyarto 
from szgk
GROUP by tipus, gyarto

SELECT gyarto + ' ' + tipus as szemtipus, CAST(ar as varchar) + 'Ft' as napidij 
from szgk


Select nev, szuldat
from ugyfel
ORDER by szuldat ASC

Select TOP(5) WITH TIES *
FROM szgk
ORDER BY AR DESC

SELECT top(10) PERCENT WITH TIES gyarto, tipus, ar
FROM szgk
ORDER by ar asc




