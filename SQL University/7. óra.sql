-- 63. feladat
update szgk
    set ar = ar *
    case gyarto
        when 'BMW' then 1.2
        when 'Opel' then 1.1
        else 1.05
    end 


-- 65. feladat

SELECT rendszam, kidat 
from kolcsonzes
WHERE rendszam IN(Select top(3) with ties rendszam 
                from szgk
                ORDER by rendszam asc)
ORDER by rendszam, kidat

--66.
SELECT nev,szuldat, DATEDIFF(YEAR, szuldat, GETDATE()) as kora, (Select AVG(1.0*DATEDIFF(YEAR, szuldat, GETDATE())) from ugyfel) as atlag
from ugyfel


--67.
SELECT *
from ugyfel
EXCEPT
SELECT *
from ugyfel
WHERE ugyfelID in (Select ugyfelID from kolcsonzes as k JOIN szgk as s on k.rendszam = s.rendszam WHERE gyarto = 'BWM')

-- 68.
SELECT *
from ugyfel u 
join kolcsonzes k ON k.ugyfelID = u.ugyfelID
join szgk s ON s.rendszam = k.rendszam
GROUP by u.ugyfelID
having COUNT(kolcsID) <=30
and COUNT(distinct gyarto) > 6


--69 
Select s.*
from szgk s
join kolcsonzes k ON s.rendszam = k.rendszam
where s.evjarat = YEAR(k.kidat)

-- 69 másik fajta megoldás
select *
from szgk 
where EXISTS(
    select 1
    from kolcsonzes
    where kolcsonzes.rendszam = szgk.rendszam
    and year(kolcsonzes.kidat) = szgk.evjarat
)


-- 70 
select *
from ugyfel 
WHERE NOT EXISTS(
    select 1
        from kolcsonzes
        where kolcsonzes.ugyfelID = ugyfel.ugyfelID
        and YEAR(kidat) = 2000
)


-- 71. f

SELECT *
from szgk
where gyarto = 'Opel'
and ar < ( select avg(1.0*ar) 
            from szgk
            where gyarto = 'Opel')


with opelek as 
(
    select *
    from szgk
    where gyarto = 'Opel'
)
Select *
from opelek
where ar < (Select avg(1.0*ar) from opelek)





-- 73. 
Select *
from kolcsonzes 
where rendszam IN (SELECT rendszam from szgk WHERE gyarto = 'BMW')


select kolcsonzes.*
    from kolcsonzes 
    join szgk on szgk.rendszam = kolcsonzes.rendszam
    WHERE gyarto = 'BMW'

GO
-- 74.

create VIEW v_ferfiak AS
    select ugyfelID, nev, szuldat, neme 
    from ugyfel
    where neme = 'f'

GO

SELECT *from v_ferfiak




