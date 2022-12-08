/**
 \file cartes.h
 \author Luc Leydert
 \brief Fichier correspondant à la getion des cartes
 \version 0.1
 \date 08/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#pragma once

#include "listeCarte.h"

/// @brief Enum représantant les valeurs de cartes
typedef enum
{
    AS = 1,
    DEUX = 2,
    TROIS = 3,
    QUATRE = 4,
    CINQ = 5,
    SIX = 6,
    SEPT = 7,
    HUIT = 8,
    NEUF = 9,
    DIX = 10,
    VALET = 10,
    DAME = 10,
    ROI = 10
} Carte;

/// @brief Initialise la pioche des cartes
/// @return La pioche
ListCarte *initCartes();
