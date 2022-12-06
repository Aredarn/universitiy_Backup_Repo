CREATE TABLE Mufaj(
    Mufaj_ID int IDENTITY(1,1) PRIMARY KEY,
    Mufaj_cim VARCHAR(50) not NULL

)


CREATE TABLE Szerzo(
    Szerzo_ID int IDENTITY(1,1) PRIMARY KEY,
    Nev VARCHAR(50) not NULL

)


CREATE TABLE Konyv
(
    Konyv_ID INT IDENTITY(1,1) PRIMARY KEY,
    Szerzo_ID INT REFERENCES Szerzo(Szerzo_ID)
                ON UPDATE SET NULL
                ON DELETE SET NULL,
    Cim VARCHAR (50) NOT null,
    Mufaj_ID INT REFERENCES Mufaj(Mufaj_ID)
                ON UPDATE SET NULL
                ON DELETE SET NULL,
    Ar int CHECK (Ar Between 1000 and 25000)

)

CREATE TABLE Vevo(
    Vevo_ID int IDENTITY(1,1) PRIMARY KEY,
    Nev VARCHAR(50) not NULL,
    Szuldat DATE,
    Lakcim VARCHAR(50),
    Telefon VARchar(12),
    Tartozas FLOAT DEFAULT 0.0
)



Create table Megrendeles_v1(
    Konyv_ID INT REFERENCEs Konyv(Konyv_ID),
    Vevo_ID int REFERENCES Vevo(Vevo_ID),
    Datum DATE DEFAULT GETDATE() PRIMARY KEY(Konyv_ID,Vevo_ID,Datum),
    Db int not null,
    kedvezmeny AS CASE 
            when Db >=5 then 0.1 
            else 0 
        END
)


Create table Megrendeles_v2(
    Megrendeles_ID INT IDENTITY(1,1) PRIMARY key,
    
    Konyv_ID INT REFERENCEs Konyv(Konyv_ID)
                ON UPDATE SET NULL
                ON DELETE SET NULL,

    Vevo_ID int REFERENCES Vevo(Vevo_ID)
                ON UPDATE SET NULL
                ON DELETE SET NULL,
    Datum DATE DEFAULT GETDATE(),
    Db int not null,
    kedvezmeny AS CASE 
            when Db >=5 then 0.1 
            else 0 
        END
)



INSERT INTO Mufaj
VALUES('Dráma'), ('Krimi'), ('Ifjúsági'),('Sci-fi')

INSERT INTO Szerzo
VALUES ('Gardonyi Geza'), ('Arany Janos'), ('Petofi Sandor'), ('Ady Endre')

SELECT * from Mufaj


-- 3
INSERT INTO Vevo(Nev,Szuldat, Lakcim, Telefon)
    SELECT nev, Szuldat,Lakcim,Telefon
    FROM db1..ugyfel

-- 4
INSERT into Konyv(Szerzo_ID,Cim, Mufaj_ID,Ar)
 VALUES(1, 'Egri csillagok',1,2500),(4, 'Ady osszes', 2,4000)

 INSERT INTO Megrendeles_v1(Konyv_ID,Vevo_ID,Db)
  VALUES(1,1,7),(2,5,2)


--5

UPDATE Vevo 
    SET tartozas = 
    From Vevo
    JOIN(
        SELECT Vevo_ID, SUM(Db * ar * (1-kedvezmeny)) As Osszeg
        FROM Megrendeles_v1 m
        JOIN konyv k ON k.Konyv_ID = m.Konyv_ID 
        GROUP by Vevo_ID

    )
