INSERT INTO ugyfel(nev) 
VALUEs('Vincs Eszter')

Select *
from ugyfel
where nev = 'Vincs Eszter'



INSERT INto szgk(rendszam,gyarto,tipus,ar)
VALUES('ABC123','Trabant','Combi', 1000)


INSERT INTO szgk(rendszam, gyarto, tipus, ar,evjarat)
VALUES ('ABC124', 'Trabant', 'Combi', 1000, 1979)

SELECT *
INTO orszag2
from orszag 

drop TABLE if EXISTS orszag2

SELECT *
INTO szgk2
from szgk 
WHERE 2022-evjarat <=5  

drop table szgk2

SELECT * 
from szgk2

SELECT * 
INTO NEPSZERU 
FROM szgk
WHERE gyarto LIKE 'Toyota'

SELECT * FROM NEPSZERU

INSERT INTO NEPSZERU
SELECT *
FROM szgk
WHERE gyarto = 'Mazda'


UPDATE szgk 
SET ar = ar*09
WHERE rendszam IN (Select top(3) with ties rendszam 
                    from szgk
                    order by ar desc)


update ugyfel
set lakcim = orszag
from ugyfel u join orszag o ON u.orszagID = o.orszagID



-- 1 MAGYAROSZAG TÁBLA

CREATE TABLE Magyarorszag
(
    id INT PRIMARY KEY IDENTITY,
    megye VARCHAR(30) not NULL,
    nepsuruseg VARCHAR(3) DEFAULT 'L' CHECK (nepsuruseg IN ('S','M','L','XL','XXL')),
    felsooktatas FLOAT,
    fo int not null CHECK(fo > 0)
)

ALTER table Magyarorszag
ADD szekhely VARCHAR(50)

ALTER TABLE Magyarorszag
drop COLUMN fo 



create table OSZTALY 
(
    OsztalyID int PRIMARY KEY,
    Osztaly VARCHAR(50) UNIQUE not null
)

CREATE TABLE DOLGOZO
(
    DolgozoID int IDENTITY(1,1) PRIMARY key,
    Nev VARCHAR(50) not null,
    Szuldat DATE,
    Nem VARCHAR(1) DEFAULT 'F',
    Fizetes int CHECK(fizetes > 200000),
    Jutalom AS Fizetes * 0.1,
    OsztalyID INT REFERENCES Osztaly
        ON UPDATE CASCADE
        ON DELETE SET NULL
)

CREATE TABLE KULCSPROBA
(
    Mezo1 VARCHAR(20),
    Mezo2 INT PRIMARY key(Mezo1,mezo2),
    mezo3 int
)

ALTER TABLE OSZTALY 
ADD Osztnev int 

ALTER table OSZALY 
ADD CONSTRAINT fk_osztvez FOREIGN KEY (Osztnev) REFERENCES Dolgozo

