/**
 \file liste.h
 \author Luc Leydert
 \brief Se charge de gerer une liste
 \version 0.1
 \date 08/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef LISTE_CARTE_H
#define LISTE_CARTE_H

#include "typesCartes.h"


/**
 \brief Créé et initialise une liste de Carte
 \
 */
void creerListe(ListCarte *);

/**
 \brief Ajoute un élément au début de la liste
 \
 */
void ajouterAvant(ListCarte *, sCarte);

/**
 \brief Ajoute un élément en fin de liste
 \
 */
void ajouterApres(ListCarte *, sCarte);

/**
 \brief Retire le premier élément
 \
 */
sCarte enleverAvant(ListCarte *);

/**
 \brief Retire le dernier élément
 \
 */
sCarte enleverApres(ListCarte *);

/// @brief Renvoie la taille de la liste
/// @param  ListCarte* La liste
/// @return La taille de la liste
int listSize(const ListCarte *);

/// @brief Converti la liste en tableau
/// @param  ListCarte* La liste
/// @param sCarte** Le tableau des cartes
/// @param int La taille du tableau
void listToArray(ListCarte *, sCarte **, int *);

/// @brief Converti un tableau de cartes en liste
/// @param  ListCarte* La liste
/// @param  sCarte** Le tableau des cartes
/// @param  int La taille du tableau
void arrayToList(ListCarte *, sCarte **, int);

#endif // LISTE_CARTE_H
