/* 1. heti óra befejező része: */

/* Record-orientált táblából mező-orientált tábla készítése */
/* Minimumot/maximumot kell alkalmazni a CASE-eken, mivel
kell egy aggregáló függvény a GROUP BY miatt. */

SELECT EmployeeId,
    MIN(CASE WHEN AttribId = 1
        THEN AttribValue
        ELSE NULL
    END) AS Lastname,
    MIN(CASE WHEN AttribId = 2
        THEN AttribValue
        ELSE NULL
    END) AS Title,
    MIN(CASE WHEN AttribId = 3
        THEN AttribValue
        ELSE NULL
    END) AS City
FROM EmployeeRecord2023
GROUP BY EmployeeId;



/* 2. heti óra: */

/* Pivot függvény */
/* Órai háttéranyagok / peldak ora2 
https://oktatas.mik.uni-pannon.hu/pluginfile.php/67334/mod_resource/content/0/peldak_ora2.sql */

--táblák létrehozása
drop table if exists csapat
CREATE TABLE [dbo].[csapat] (
    [csapat_id] [int] NOT NULL primary key,
    [csapat_nev] [nvarchar] (50) NOT NULL
)
drop table if exists gyumolcs
CREATE TABLE [dbo].[gyumolcs] (
    [gyumolcs_id] [int] NOT NULL primary key,
    [gyumolcs_nev] [nvarchar] (50) NOT NULL
)
drop table if exists nap
CREATE TABLE [dbo].[nap] (
    [nap_id] [int] NOT NULL primary key,
    [nap_nev] [nvarchar] (50) NOT NULL
)
go
drop table if exists eredm
CREATE TABLE [dbo].[eredm] (
	eredm_id int identity (1,1) primary key,
    [csapat_id] [int] NOT NULL references csapat (csapat_id),
    [nap_id] [int] NOT NULL  references nap (nap_id),
	gyumolcs_id int not null  references gyumolcs (gyumolcs_id),
    [leadott_lada] [int] NOT NULL
)

--táblafeltöltés
insert csapat (csapat_id, csapat_nev) values (1, 'Szorgos'),(2, 'Lusta')
insert gyumolcs (gyumolcs_id, gyumolcs_nev) values (1, 'alma'),(2, 'szilva')
insert nap (nap_id, nap_nev) values (1, 'hétfő'),(2, 'kedd'),(3, 'szerda')
insert eredm (csapat_id, nap_id, gyumolcs_id, leadott_lada) values
	(1,1,1,50), (1,2,1,60), (1,3,1,70), (1,1,2,100), (1,2,2,120), (1,3,2,140),
	(2,1,1,5), (2,2,1,6), (2,3,1,7), (2,1,2,10), (2,2,2,12), (2,3,2,14)
select * from eredm

--Az egyszerűség kedvéért legyen egyetlen szöveges kiinduló táblánk:
drop table eredm_pivot
select cs.csapat_nev, n.nap_nev, gy.gyumolcs_nev, e.leadott_lada
into eredm_pivot
from eredm e 
inner join csapat cs on cs.csapat_id=e.csapat_id 
inner join nap n on n.nap_id=e.nap_id
inner join gyumolcs gy on gy.gyumolcs_id=e.gyumolcs_id
go



SELECT * FROM eredm_pivot;



--ÍME A PIVOT: oszlopokban a gyümölcsök
select csapat_nev, nap_nev, pt.alma, pt.szilva
from eredm_pivot 
	pivot (sum(leadott_lada) for gyumolcs_nev in (alma, szilva)) as pt 
		--a SUM azért kell, mert lehetnének egyező sorok 
order by csapat_nev, nap_nev

/* Módosítsa az előző lekérdezést úgy, hogy csapat szerint pivotáljon!
Hány rekord lesz? (Válasz: 6 rekord) */

SELECT gyumolcs_nev, nap_nev, pt.Lusta, pt.Szorgos
FROM eredm_pivot
PIVOT (SUM(leadott_lada) FOR csapat_nev IN (Lusta, Szorgos)) AS pt
ORDER BY gyumolcs_nev, nap_nev;

/* Mi lett volna, ha a napot pivotáljuk. (Válasz: 4 rekord) */

SELECT csapat_nev, gyumolcs_nev, pt.[Hétfő], pt.kedd, pt.szerda
FROM eredm_pivot
PIVOT (SUM(leadott_lada) FOR nap_nev IN ([hétfő], kedd, szerda)) AS pt
ORDER BY csapat_nev, gyumolcs_nev;



--most összesítünk: a napok nem érdekesek
--csapatok teljesítménye gyümölcsönként: sorokban a csapatok, oszlopokban a gyümölcsök
select pt.csapat_nev, pt.alma, pt.szilva
from (select csapat_nev, gyumolcs_nev, sum(leadott_lada) as leadott_lada 
		from eredm_pivot group by csapat_nev, gyumolcs_nev) as forras --az alias szintaktikai okból kell
	pivot (sum(leadott_lada) for gyumolcs_nev in ([alma], [szilva])) as pt



select gyumolcs_nev, pt.Lusta, pt.Szorgos
from (select csapat_nev, gyumolcs_nev, sum(leadott_lada) as leadott_lada 
		from eredm_pivot group by csapat_nev, gyumolcs_nev) as forras --az alias szintaktikai okból kell
	pivot (sum(leadott_lada) for csapat_nev in ([Lusta], [Szorgos])) as pt



/* T-SQL */

/**************************
SQL utasításkötegek (batch)
***************************/

--demo: kötegtulajdonságok
--drop table pelda
create table pelda (szam int)
insert pelda values (44)
SELECT * FROM pelda

go
--1. kísérlet
update pelda set szam=21
go
selec * from pelda --szintaktikai hiba
go
select * from pelda --eredmeny 21, mert az első batch sikerult
go
--2. kísérlet: ugyanez egy kötegben
update pelda set szam=22
selec * from pelda --szintaktikai hiba
update pelda set szam=23
go
select * from pelda --eredmény: 21
--mert szintaktikai hiba esetén az egész batchból semmi sem hajtódik végre
--3. kísérlet
--ha az objektumnév hibás (nem szintaktikai hiba), akkor a hiba előtti rész végrehajtódik
go
update pelda set szam=22
select * from plda --Invalid object name
update pelda set szam=23 --ez már nem hajtódik végre
go
select * from pelda --eredmény: 22
go
--4. kísérlet: speciális hibák (nullával osztás, külső kulcs kényszer)
update pelda set szam=23
select 1/0 --division by zero
update pelda set szam=24 --végrehajtódik 
go
select * from pelda --eredmény: 24
go
update pelda set szam=25
delete employees --The DELETE statement conflicted with the REFERENCE constraint
update pelda set szam=26 --végrehajtódik
go
select * from pelda --eredmény: 26