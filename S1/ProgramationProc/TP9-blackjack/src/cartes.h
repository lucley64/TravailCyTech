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

#ifndef CARTES_H
#define CARTES_H

#include "typesCartes.h"

/// @brief Initialise la pioche des cartes
/// @return La pioche
ListCarte *initCartes();

/// @brief Mélange la pioche
/// @param ListCarte* pioche
void melangerCartes(ListCarte *listCarte);

#endif // CARTES_H
