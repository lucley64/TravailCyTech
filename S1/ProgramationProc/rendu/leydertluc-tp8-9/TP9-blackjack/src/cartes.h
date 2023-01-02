/// @file cartes.h
/// @author Luc Leydert
/// @brief Fichier correspondant à l'entête la getion des cartes
/// @version 0.1
/// @date 08/12/2022

#pragma once

#include "typesCartes.h"

/// @brief Initialise la pioche des cartes en lui alouan de la memoire
/// @return Une liste de cartes représantant une pioche des cartes
ListCarte *initCartes();

/// @brief Mélange la pioche
/// @param ListCarte pioche
void melangerCartes(ListCarte *listCarte);

/// @brief créé une carte
/// @param carte la figure de la carte
/// @param color la couleur de la carte
/// @return La nouvelle carte créé
sCarte createCarte(Carte carte, CarteColor color);

/// @brief Initialise la list pour une couleur donné
/// @param listCarte La liste de cartes
/// @param color la couleur de la carte
void initParCouleur(ListCarte *listCarte, CarteColor color);
