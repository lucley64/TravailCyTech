-- Active: 1664894854045@@127.0.0.1@3306@Cours

CREATE TABLE
    Personne (
        id_personne INT PRIMARY KEY AUTO_INCREMENT,
        nom VARCHAR(50),
        prenom VARCHAR(50),
        telephone VARCHAR(10)
    );

CREATE TABLE
    Etudiant (
        id_personne INT PRIMARY KEY,
        num_etudiant VARCHAR(10),
        classe VARCHAR(10),
        Foreign Key (id_personne) REFERENCES Personne(id_personne)
    );

CREATE TABLE
    Enseignant(
        id_personne INT PRIMARY KEY,
        Foreign Key (id_personne) REFERENCES Personne(id_personne)
    );

CREATE TABLE
    Cours(
        id_cours INT PRIMARY KEY AUTO_INCREMENT,
        nom VARCHAR(50),
        id_endeignant INT,
        Foreign Key (id_endeignant) REFERENCES Enseignant(id_personne)
    );

--1

SELECT num_etudiant FROM `Etudiant` WHERE classe = "ING1";

--2

CREATE TABLE
    SuitCours(
        id_etudiant INT,
        id_cours INT,
        note INT,
        Foreign Key (id_etudiant) REFERENCES Etudiant(id_personne),
        Foreign Key (id_cours) REFERENCES Cours(id_cours),
        PRIMARY KEY (id_etudiant, id_cours)
    );

--3

DELETE FROM `Cours` WHERE nom = "Commandes UNIX";

--4

UPDATE `Personne`
SET telephone = "0123456789"
WHERE
    nom = "Tronche"
    AND prenom = "Gertrude";

--5

SELECT count(*) FROM `Enseignant`;

--6

SELECT P.nom, P.prenom
FROM `Personne` P
    JOIN `Cours` C ON C.id_endeignant = P.id_personne
WHERE
    C.nom = "Bases de données";

--7

SELECT S.note
FROM `SuitCours` S
    JOIN `Personne` P ON P.id_personne = S.id_etudiant
    JOIN `Cours` C ON C.id_cours = S.id_cours
WHERE
    P.nom = "Kévin"
    AND P.prenom = "Dubert"
    AND C.nom = "Maths";

--8

SELECT AVG(S.note)
FROM `SuitCours` S
    JOIN `Cours` C ON C.id_cours = S.id_cours
WHERE C.nom = "Programmation";

--9

SELECT p.nom, p.prenom FROM `Personne` p
JOIN `SuitCours` S ON S.id_etudiant = p.id_personne
JOIN `Cours` C ON S.id_cours = C.id_cours
WHERE C.nom = "Anglais" AND S.note > (
    SELECT AVG(S.note) FROM `SuitCours` S
    JOIN `Cours` C ON C.id_cours = S.id_cours
    WHERE C.nom = "Espagnol"
);

--10
SELECT P.nom, P.prenom, C.nom FROM `Personne` P
JOIN `Enseignant` E ON E.id_personne = P.id_personne
LEFT JOIN `Cours` C ON C.id_endeignant = E.id_personne;

--11
SELECT E.classe FROM `Etudiant` E
JOIN `SuitCours` S ON S.id_etudiant = E.id_personne
JOIN `Cours` C ON C.id_cours = S.id_cours
WHERE C.nom = "Francais"
GROUP BY E.classe
HAVING AVG(S.note) > 15;
