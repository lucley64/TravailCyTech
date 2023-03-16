-- Active: 1664894854045@@127.0.0.1@3306@Pokemon2

--1.

SELECT * FROM `Apparition` ORDER BY horaire DESC LIMIT 1;

--2.

SELECT
    `Pokemon`.*,
    COUNT(`idPokemon`) AS "Nombre d'apparitions"
FROM `Pokemon`
    LEFT JOIN `Apparition` ON id = `idPokemon`
GROUP BY id;

--3.

SELECT
    `Pokemon`.*,
    COUNT(`idPokemon`) AS `Nombre d'apparitions`
FROM `Pokemon`
    LEFT JOIN `Apparition` ON id = `idPokemon`
GROUP BY id
HAVING
    `Nombre d'apparitions` >= (
        SELECT AVG(count)
        FROM (
                SELECT
                    COUNT(A.`idPokemon`) AS count
                FROM
                    `Pokemon` P
                    LEFT JOIN `Apparition` A ON P.id = A.`idPokemon`
                GROUP BY
                    P.id
            ) AS counts
    );

--4.

SELECT
    J.*,
    COUNT(P.id) AS `Nombre de pokemon`
FROM `Joueur` J
    LEFT JOIN `Pokemon` P ON J.`idJoueur` = P.`idJoueur`
GROUP BY J.`idJoueur`;

--5.

SELECT P.*
FROM `Pokemon` P
    JOIN `Apparition` A ON P.id = A.`idPokemon`
GROUP BY P.id
HAVING
    COUNT(A.`idEmplacement`) = (
        SELECT count(*)
        FROM `Emplacement`
    );

--6.

SELECT J.*
FROM `Joueur` J
    JOIN `Pokemon` P ON P.`idJoueur` = J.`idJoueur`
GROUP BY J.`idJoueur`
HAVING
    count(DISTINCT P.espece) = (
        SELECT
            count(DISTINCT P.espece)
        FROM `Pokemon` P
    );

--7.

SELECT
    COUNT(DISTINCT P.`idJoueur`)
FROM `Pokemon` P
    JOIN `Apparition` A ON P.id = A.`idPokemon`
    JOIN `Emplacement` E ON E.`idEmplacement` = A.`idEmplacement`
WHERE E.latitude = (
        SELECT
            MAX(E.latitude)
        FROM `Emplacement` E
    );

--8.

SELECT *
FROM `Equipe` E
WHERE E.id = (
        SELECT D.`idEquipe`
        FROM `Defense` D
        GROUP BY D.`idEquipe`
        HAVING
            count(D.`idArene`) = (
                SELECT
                    MAX(count)
                FROM (
                        SELECT
                            count(*) as count
                        FROM
                            `Defense` D
                        GROUP BY
                            D.`idEquipe`
                    ) counts
            )
        LIMIT 1
    );

--9.

SELECT
    MIN(A.horaire),
    MAX(A.horaire)
FROM `Pokemon` P
    JOIN `Joueur` J ON J.`idJoueur` = P.`idJoueur`
    JOIN `Apparition` A ON A.`idPokemon` = P.id
WHERE J.`idEquipe` = (
        SELECT E.id
        FROM `Equipe` E
        WHERE E.id = (
                SELECT
                    D.`idEquipe`
                FROM
                    `Defense` D
                GROUP BY
                    D.`idEquipe`
                HAVING
                    count(D.`idArene`) = (
                        SELECT
                            MAX(count)
                        FROM (
                                SELECT
                                    count(*) as count
                                FROM
                                    `Defense` D
                                GROUP BY
                                    D.`idEquipe`
                            ) counts
                    )
                LIMIT 1
            )
    );

--10.

SELECT J.*
FROM `Joueur` J
    JOIN (
        SELECT
            MAX(J.niveau) as maxi,
            J.`idEquipe`
        FROM `Joueur` J
        GROUP BY
            J.`idEquipe`
    ) mpe ON mpe.`idEquipe` = J.`idEquipe`
    and mpe.maxi = J.niveau;

--11

SELECT *
FROM `Pokemon` P
    JOIN (
        SELECT
            P.`idJoueur`,
            AVG(P.`pointCombat`) AS avgPc
        FROM `Pokemon` P
        GROUP BY
            P.`idJoueur`
    ) avgPcpJ ON avgPcpJ.`idJoueur` = P.`idJoueur`
WHERE
    P.`pointCombat` > avgPcpJ.avgPc;