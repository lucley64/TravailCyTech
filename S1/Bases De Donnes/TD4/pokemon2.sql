-- Active: 1664894854045@@127.0.0.1@3306@Pokemon

INSERT INTO `Equipe` VALUES (1, "Intuition", "Jaune");

INSERT INTO `Equipe` VALUES (2, "Sagesse", "Bleu");

INSERT INTO `Equipe` VALUES (3, "Bravoure", "Rouge");

INSERT INTO `Joueur` VALUES (1, "Shadow", 'F', 10, 1);

INSERT INTO `Joueur` VALUES (2, "Elise", 'F', 20, 2);

INSERT INTO `Joueur` VALUES (3, "Bob54", 'M', 1, 1);

INSERT INTO `Pokemon` VALUES (1, "Bulbizarre", "Graine", 1071, 1);

INSERT INTO `Pokemon` VALUES (25, "Pikachu", "Souris", 887, 2);

INSERT INTO `Pokemon` VALUES (107, "Tygnon", "Puncheur", 204, 1);

INSERT INTO `Pokemon` VALUES (103, "Noadkoko", "Fruitpalme", 190, 3);

INSERT INTO `Pokemon` VALUES (150, "Mewtwo", "Génétique", 4144, 2);

INSERT INTO `Emplacement` VALUES (1, 49.0350369, 2.0696998);

INSERT INTO `Emplacement` VALUES (2, 48.857848, 2.295253);

INSERT INTO `Emplacement` VALUES (3, -74.0445, 40.6892);

INSERT INTO `Apparition` VALUES (1, 2, "2022-10-05", 10);

INSERT INTO `Apparition` VALUES (25, 1, "2022-09-01", 20);

INSERT INTO `Apparition` VALUES (107, 3, "2022-10-02", 5);

INSERT INTO `Apparition` VALUES (103, 1, "2022-10-04", 15);

INSERT INTO `Apparition` VALUES (25, 3, "2022-10-04", 3);

UPDATE `Joueur` SET niveau = 15 WHERE sexe = 'F';

DELETE FROM `Pokemon` WHERE espece LIKE "%fruit%";

DELETE FROM `Joueur` WHERE pseudonyme = "Bob54";

SELECT count(*) FROM Equipe;

SELECT * FROM Pokemon WHERE nom LIKE "p%";

SELECT * FROM Joueur WHERE pseudonyme NOT LIKE "%a%";

SELECT * FROM Pokemon ORDER BY pointCombat DESC;

SELECT horaire
FROM Apparition
    JOIN Pokemon ON Apparition.idPokemon = Pokemon.idPokemon
WHERE nom = "Tygnon";

SELECT AVG(duree) FROM Apparition;

SELECT count(*) FROM `Apparition` where month(horaire) = 10 AND year(horaire) = 2022;

SELECT *
FROM `Pokemon`
WHERE pointCombat = (
        SELECT
            MAX(pointCombat)
        FROM `Pokemon`
    );

UPDATE `Joueur` SET niveau = niveau + 2 WHERE pseudonyme = "Shadow";

SELECT distinct Pokemon.*
FROM `Pokemon`
    JOIN `Apparition` ON Pokemon.idPokemon = Apparition.idPokemon
WHERE MONTH(horaire) = 9;

