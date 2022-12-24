/**
 \file jeu.h
 \author Luc Leydert
 \brief Fichier concernan la gestion du jeu
 \version 0.1
 \date 16/12/2022
 \
 \copyright Copyright (c) 2022
 \
 */

#pragma once

#include "listJoueur.h"
#include "cartes.h"

/// @brief Structure contenant tout le jeu
typedef struct {
    /// @brief La liste des joueurs
    listJoueur listJoueur;
    /// @brief La liste des cartes
    ListCarte cartes;
} Jeu;

/// @brief Initialise la partie
/// @param jeu Pointeur sur le jeu
/// @param nbJoueurs Le nombre de joueurs
void initialiserJeu(Jeu* jeu, int nbJoueurs);

/// @brief Boucle de jeu principale
/// @param jeu Pointeur sur le jeu
void gameLoop(Jeu* jeu);