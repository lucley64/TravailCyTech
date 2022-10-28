-- Active: 1666962743154@@127.0.0.1@3306

DROP DATABASE IF EXISTS Pokemon2;

CREATE DATABASE Pokemon2;

USE Pokemon2;

CREATE TABLE
    Equipe(
        id INT PRIMARY KEY,
        nom VARCHAR(9),
        couleur VARCHAR(5)
    );

CREATE TABLE
    Joueur(
        idJoueur INT PRIMARY KEY,
        pseudonyme VARCHAR(30),
        sexe CHAR(1),
        niveau SMALLINT DEFAULT 0 NOT NULL,
        idEquipe INT,
        FOREIGN KEY fk_equipe(idEquipe) REFERENCES Equipe(id) ON DELETE CASCADE
    );

CREATE TABLE
    Pokemon(
        id INT PRIMARY KEY,
        nom VARCHAR(30),
        espece VARCHAR(20),
        pointCombat INT,
        idJoueur INT,
        FOREIGN KEY fk_joueur(idJoueur) REFERENCES Joueur(idJoueur) ON DELETE CASCADE
    );

CREATE TABLE
    Emplacement(
        idEmplacement INT PRIMARY KEY,
        latitude DECIMAL(12, 10) NOT NULL,
        longitude DECIMAL(13, 10) NOT NULL,
        CONSTRAINT check_latitude CHECK (
            latitude BETWEEN -90 AND 90
        ),
        CONSTRAINT check_longitude CHECK (
            longitude BETWEEN -180 AND 180
        )
    );

CREATE TABLE
    Apparition(
        idPokemon INT,
        idEmplacement INT,
        horaire DATE,
        duree INT,
        CONSTRAINT pk_Apparition PRIMARY KEY (idPokemon, idEmplacement),
        FOREIGN KEY fk_pokemon(idPokemon) REFERENCES Pokemon(id) ON DELETE CASCADE,
        FOREIGN KEY fk_emplacement(idEmplacement) REFERENCES Emplacement(idEmplacement)
    );

CREATE TABLE
    Arene(
        id INT PRIMARY KEY,
        nom VARCHAR(30),
        idEmplacement INT,
        FOREIGN KEY fk_emplacement2(idEmplacement) REFERENCES Emplacement(idEmplacement)
    );

CREATE TABLE
    Defense(
        idEquipe INT,
        idArene INT,
        dateControle DATE,
        CONSTRAINT pk_Defense PRIMARY KEY (
            idEquipe,
            idArene,
            dateControle
        ),
        FOREIGN KEY fk_equipe2(idEquipe) REFERENCES Equipe(id),
        FOREIGN KEY fk_arene(idArene) REFERENCES Arene(id)
    );

-- Enregistrements

INSERT INTO Equipe VALUES (1, 'Intuition', 'Jaune');

INSERT INTO Equipe VALUES (2, 'Sagesse', 'Bleu');

INSERT INTO Equipe VALUES (3, 'Bravoure', 'Rouge');

INSERT INTO Joueur VALUES (1,'Shadow', 'F', 10, 1);

INSERT INTO Joueur VALUES (2,'Elise', 'F', 20, 2);

INSERT INTO Joueur VALUES (3,'Bob54', 'M', 1, 1);

INSERT INTO Pokemon VALUES (1, 'Bulbizarre', 'Graine', 1071, 1);

INSERT INTO Pokemon VALUES (25, 'Pikachu', 'Souris', 887, 2);

INSERT INTO Pokemon VALUES (107, 'Tygnon', 'Puncheur', 204, 1);

INSERT INTO Pokemon VALUES (103, 'Noadkoko', 'Fruitpalme', 190, 3);

INSERT INTO Pokemon VALUES (150, 'Mewtwo', 'Génétique', 4144, 2);

INSERT INTO Pokemon VALUES (151, 'Raichu', 'Souris', 887, 2);

INSERT INTO Pokemon VALUES (155, 'Goupix', 'Renard', 650, 3);

INSERT INTO Pokemon VALUES (160, 'Sabelette', 'Souris', 350, 3);

INSERT INTO Emplacement VALUES (1, 49.0350369, 2.0696998);

INSERT INTO Emplacement VALUES (2, 48.857848, 2.295253);

INSERT INTO Emplacement VALUES (3, -74.0445, 40.6892);

INSERT INTO Apparition VALUES (1, 2, '2022-10-05', 10);

INSERT INTO Apparition VALUES (25, 1, '2022-09-01', 20);

INSERT INTO Apparition VALUES (107, 3, '2022-10-02', 5);

INSERT INTO Apparition VALUES (103, 1, '2022-10-04', 15);

INSERT INTO Apparition VALUES (25, 3, '2022-10-04', 3);

INSERT INTO Apparition VALUES (160, 1, '2022-10-15', 18);

INSERT INTO Apparition VALUES (107, 1, '2022-10-16', 5);

INSERT INTO Arene VALUES (1, 'Liberte', 3);

INSERT INTO Arene VALUES (2, 'CyTech', 1);

INSERT INTO Arene VALUES (3, 'Star', 2);

INSERT INTO Defense VALUES (1, 1, '2022-10-04');

INSERT INTO Defense VALUES (1, 2, '2022-09-01');

-- 1.

SELECT * FROM `Apparition` ORDER BY horaire DESC LIMIT 1;

--2.

SELECT *
FROM `Pokemon`
WHERE idJoueur = (
        SELECT idJoueur
        FROM `Pokemon`
        WHERE
            nom = "Pikachu"
    )
    AND pointCombat = (
        SELECT pointCombat
        FROM `Pokemon`
        WHERE nom = "Pikachu"
    );

--3.

SELECT *
FROM `Joueur`
WHERE
    CHAR_LENGTH(pseudonyme) = (
        SELECT
            MIN(CHAR_LENGTH(pseudonyme))
        FROM `Joueur`
    );

--4.

SELECT dateControle, horaire FROM `Defense`, `Apparition`;

--5.

SELECT DISTINCT horaire
FROM `Apparition`, `Defense`
WHERE horaire = dateControle;

--6.

SELECT *
FROM `Joueur`
WHERE (
        pseudonyme LIKE "B%"
        OR pseudonyme LIKE "S%"
    )
    AND pseudonyme NOT LIKE "Bob%";

--7.

SELECT *
FROM `Pokemon`
WHERE idJoueur = (
        SELECT idJoueur
        FROM `Joueur`
        WHERE
            pseudonyme = "Bob54"
    );

--8.

SELECT *
FROM `Joueur`
WHERE idJoueur NOT IN (
        SELECT idJoueur
        FROM `Pokemon`
        WHERE
            espece = "souris"
    );

--9.

SELECT Equipe.*
FROM `Equipe`
WHERE id = (
        SELECT idEquipe
        FROM `Joueur`
        WHERE
            pseudonyme = "Shadow"
    );

--10.

SELECT id, nom
FROM `Pokemon`
WHERE id NOT IN (
        SELECT idPokemon
        FROM `Apparition`
    );

--11.

SELECT latitude, longitude
FROM `Emplacement`
WHERE idEmplacement IN (
        SELECT idEmplacement
        FROM `Apparition`
        WHERE
            horaire = "2022-10-04"
            AND idPokemon IN (
                SELECT id
                FROM
                    `Pokemon`
                WHERE
                    espece = "Fruitpalme"
            )
    );

--12.

SELECT *
FROM `Pokemon`
WHERE pointCombat > (
        SELECT
            MAX(`pointCombat`)
        FROM pokemon
            NATURAL JOIN joueur
            JOIN equipe ON equipe.id = `idEquipe`
        WHERE
            couleur = "Jaune"
    )
    AND id NOT IN(
        SELECT pokemon.id
        FROM pokemon
            NATURAL JOIN joueur
            JOIN equipe ON equipe.id = `idEquipe`
        WHERE
            couleur = "Jaune"
    );

--13.

SELECT COUNT(*)
FROM `Pokemon`
    JOIN `Apparition` ON id = idPokemon
    JOIN `Emplacement` ON `Apparition`.idEmplacement = `Emplacement`.idEmplacement
    JOIN `Arene` ON `Emplacement`.idEmplacement = `Arene`.idEmplacement
WHERE `Arene`.nom = "CyTech";

--14.

SELECT COUNT(*)
FROM `Defense`
    JOIN `Equipe` ON id = idEquipe
WHERE nom = "Intuition";

--15.

SELECT horaire
FROM `Apparition`
    JOIN `Pokemon` ON id = idPokemon
WHERE nom = "Tygnon"
ORDER BY horaire
LIMIT 1;

--16.

SELECT espece, AVG(pointCombat) FROM `Pokemon` GROUP BY espece;

--17.

SELECT pseudonyme, COUNT(*)
FROM `Joueur`
    JOIN `Pokemon` ON `Joueur`.idJoueur = `Pokemon`.idJoueur
GROUP BY pseudonyme;

--18.

SELECT
    pseudonyme,
    `Equipe`.nom,
    COUNT(*)
FROM `Joueur`
    JOIN `Pokemon` ON `Joueur`.idJoueur = `Pokemon`.idJoueur
    JOIN `Equipe` ON `Equipe`.id = `Joueur`.idEquipe
GROUP BY
    pseudonyme,
    `Equipe`.nom;

--19.

SELECT nom, SUM(duree)
FROM `Pokemon`
    JOIN `Apparition` ON id = idPokemon
GROUP BY nom;

--20.

SELECT
    nom,
    espece,
    COUNT(*) as `Nombre d'apparitions`
FROM `Pokemon`
    JOIN `Apparition` ON id = idPokemon
GROUP BY nom, espece
HAVING
    `Nombre d'apparitions` >= 2;

--21.

SELECT
    nom,
    espece,
    duree,
    COUNT(*) as `Nombre d'apparitions`
FROM `Pokemon`
    JOIN `Apparition` ON id = idPokemon
GROUP BY nom, espece
HAVING
    `Nombre d'apparitions` >= 2
    AND duree > 5;

--22

SELECT
    nom,
    espece,
    SUM(duree) AS `durée totale d'apparition`
FROM pokemon
    LEFT JOIN apparition ON id = `idPokemon`
WHERE `pointCombat` >= 1000
GROUP BY nom, espece
HAVING
    `durée totale d'apparition` >= 10;

--23

SELECT AVG(duree) AS `temps moyen d'apparition des pokémons appartenant aux joueurs de l'équipe ayant contrôlé le plus d'arènes`
FROM pokemon
    JOIN apparition ON pokemon.id = apparition.`idPokemon`
    NATURAL JOIN joueur
WHERE joueur.`idEquipe` = (
        SELECT equipe.id
        FROM equipe
            JOIN defense ON equipe.id = defense.`idEquipe`
        GROUP BY equipe.id
        HAVING COUNT(*) = (
                SELECT COUNT(*) as c
                FROM equipe
                    JOIN defense ON equipe.id = defense.`idEquipe`
                GROUP BY equipe.id
                ORDER BY c
                LIMIT 1
            )
    )