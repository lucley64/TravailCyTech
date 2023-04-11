-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mar. 11 avr. 2023 à 15:55
-- Version du serveur : 8.0.32-0ubuntu0.22.04.2
-- Version de PHP : 8.1.2-1ubuntu2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `ProduitsScience`
--

-- --------------------------------------------------------

--
-- Structure de la table `Categorie`
--

CREATE TABLE `Categorie` (
  `Id` int NOT NULL,
  `Nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `Categorie`
--

INSERT INTO `Categorie` (`Id`, `Nom`) VALUES
(1, 'Experimental'),
(2, 'Utilitaires'),
(3, 'Inteligences artificielles');

-- --------------------------------------------------------

--
-- Structure de la table `Produit`
--

CREATE TABLE `Produit` (
  `Image` varchar(255) NOT NULL,
  `Nom` varchar(255) NOT NULL,
  `Prix` int NOT NULL,
  `Stock` int NOT NULL,
  `Id` int NOT NULL,
  `Categorie` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `Produit`
--

INSERT INTO `Produit` (`Image`, `Nom`, `Prix`, `Stock`, `Id`, `Categorie`) VALUES
('img/Aperture_Science_Handheld_Portal_Device_Portal.webp', 'Aperture Science Quantum Tunneling Device', 125000, 25, 1, 1),
('img/P2_afp.webp', 'Plaque de foie aérienne d\'Aperture Science', 60000, 25, 2, 1),
('img/400px-Excursion_Funnel.jpeg', 'Tunnel D\'éxcurtion d\'Aperture Science', 250000, 10, 3, 1),
('img/Early_Grill.jpg', 'Grille d\'émencipation matérielle d\'Aperture Science', 60000, 50, 4, 1),
('img/200px-Puzzle_Creator_-_Hard_Light_Bridge.png', 'Ponts de lumière tangible d\'Aperture Science', 160000, 58, 5, 1),
('img/tumblr_m9nbkkBi1Z1rnrq03o1_1280.webp', 'Aperture Science Long Fall Boots', 25000, 155, 6, 2),
('img/85.2_FM.webp', 'Aperture Science Radio', 100, 5000, 7, 2),
('img/Weighted_Storage_Cube_p2.webp', 'Cube de stockage d\'Aperture Science', 500, 660, 8, 2),
('img/Portal2_Turret_Standard.webp', 'Tourelle automatique d\'Aperture Science', 150000, 50, 9, 3),
('img/Crap_turret.webp', 'Tourelle automatique au rabais d\'Aperture Science', 20000, 150, 10, 3),
('img/Wheatley_model.webp', 'Cœur de personalité d\'Aperture Science', 200000, 2, 11, 3),
('img/Companion_Cube_p2.webp', 'Cube de stockage lesté d\'Aperture Science', 1000000, 395, 12, 3),
('img/Potatos.webp', 'PotatOS', 1000000, 1, 13, 3);

-- --------------------------------------------------------

--
-- Structure de la table `role`
--

CREATE TABLE `role` (
  `Id` int NOT NULL,
  `Nom` text NOT NULL,
  `Niveau` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `role`
--

INSERT INTO `role` (`Id`, `Nom`, `Niveau`) VALUES
(1, 'Admin', 99),
(3, 'user', 1);

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

CREATE TABLE `user` (
  `Id` int NOT NULL,
  `mail` text,
  `login` text NOT NULL,
  `password` text NOT NULL,
  `role` int DEFAULT NULL,
  `Panier` json NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `user`
--

INSERT INTO `user` (`Id`, `mail`, `login`, `password`, `role`, `Panier`) VALUES
(1, 'admin@admin.root', 'admin', 'password', 1, '{\"Tourelle automatique d\'Aperture Science\": 1, \"Aperture Science Quantum Tunneling Device\": 2, \"Plaque de foie aérienne d\'Aperture Science\": 2}'),
(8, NULL, 'test', 'testtest', 3, 'null');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Categorie`
--
ALTER TABLE `Categorie`
  ADD PRIMARY KEY (`Id`);

--
-- Index pour la table `Produit`
--
ALTER TABLE `Produit`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `FKCat` (`Categorie`);

--
-- Index pour la table `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`Id`);

--
-- Index pour la table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `FKrole` (`role`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Produit`
--
ALTER TABLE `Produit`
  MODIFY `Id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT pour la table `role`
--
ALTER TABLE `role`
  MODIFY `Id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `user`
--
ALTER TABLE `user`
  MODIFY `Id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Produit`
--
ALTER TABLE `Produit`
  ADD CONSTRAINT `FKCat` FOREIGN KEY (`Categorie`) REFERENCES `Categorie` (`Id`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Contraintes pour la table `user`
--
ALTER TABLE `user`
  ADD CONSTRAINT `FKrole` FOREIGN KEY (`role`) REFERENCES `role` (`Id`) ON DELETE RESTRICT ON UPDATE RESTRICT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
