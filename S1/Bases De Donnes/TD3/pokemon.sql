-- Active: 1664894854045@@127.0.0.1@3306@Pokemon

CREATE DATABASE IF NOT EXISTS Pokemon;

CREATE TABLE
    Equipe(
        idEquipe INT PRIMARY KEY,
        nom CHAR(255),
        couleur CHAR(16)
    );

CREATE TABLE
    Joueur(
        idJoueur INT PRIMARY KEY,
        pseudonyme CHAR(255),
        sexe CHAR(1),
        niveau INT,
        idEquipe INT,
        Foreign Key (idEquipe) REFERENCES Equipe(idEquipe)
    );

CREATE TABLE
    Pokemon(
        idPokemon INT PRIMARY KEY,
        nom CHAR(255),
        espece CHAR(255),
        pointCombat INT,
        idJoueur INT,
        Foreign Key (idJoueur) REFERENCES Joueur(idJoueur)
    );

CREATE TABLE
    Emplacement(
        idEmplacement INT PRIMARY KEY,
        latitude FLOAT(12),
        longitude FLOAT(12)
    );

CREATE TABLE
    Apparition(
        idPokemon INT,
        idEmplacement INT,
        date DATE,
        duree INT,
        PRIMARY KEY (idPokemon, idEmplacement),
        Foreign Key (idPokemon) REFERENCES Pokemon(idPokemon) ON DELETE CASCADE,
        Foreign Key (idEmplacement) REFERENCES Emplacement(idEmplacement) ON DELETE CASCADE
    );

ALTER TABLE `Apparition` RENAME COLUMN date TO horaire;

ALTER TABLE `Apparition` ALTER horaire SET DEFAULT (SYSDATE());

ALTER TABLE `Joueur` ALTER niveau SET DEFAULT (0);

ALTER TABLE `Joueur` MODIFY COLUMN niveau INT NOT NULL;

ALTER TABLE `Emplacement` MODIFY COLUMN latitude FLOAT(12) NOT NULL;

ALTER TABLE `Emplacement` MODIFY COLUMN longitude FLOAT(12) NOT NULL;

ALTER TABLE `Joueur` MODIFY COLUMN pseudonyme CHAR(255) UNIQUE;

ALTER TABLE `Pokemon` ADD CONSTRAINT checkPC CHECK(pointCombat>=0);

ALTER TABLE `Emplacement`
ADD
    CONSTRAINT checklatitude CHECK (
        latitude >= -90
        AND latitude <= 90
    );

ALTER TABLE `Emplacement`
ADD
    CONSTRAINT checklongitude CHECK (
        longitude >= -90
        AND longitude <= 90
    );

ALTER TABLE `Joueur` MODIFY COLUMN pseudonyme CHAR(255);