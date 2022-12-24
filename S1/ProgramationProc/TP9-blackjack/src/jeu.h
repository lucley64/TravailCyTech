/**
 \file jeu.h
 \author Luc Leydert
 \brief Fichier concernan la gestion du jeu
 \version 0.1
 \date 16/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#pragma once

#include "listJoueur.h"
#include "cartes.h"

/// @brief Structure contenant tout le jeu
typedef struct {
    listJoueur listJoueur;
    ListCarte cartes;
} Jeu;

void initialiserJeu(Jeu* jeu, int nbJoueurs);

void gameLoop(Jeu* jeu);