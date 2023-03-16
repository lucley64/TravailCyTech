/**
 \file liste.h
 \author Luc Leydert
 \brief Se charge de gerer une liste
 \version 0.1
 \date 08/12/2022
 \
 \copyright Copyright (c) 2022
 \
 */

#ifndef LISTE_CARTE_H
#define LISTE_CARTE_H

#include "typesCartes.h"

/**
 \brief Créé et initialise une liste de Carte
 \
 */
void creerListeCarte(ListCarte *);

/**
 \brief Ajoute un élément au début de la liste
 \
 */
void ajouterAvantCarte(ListCarte *, sCarte);

/**
 \brief Ajoute un élément en fin de liste
 \
 */
void ajouterApresCarte(ListCarte *, sCarte);

/**
 \brief Retire le premier élément
 \
 */
sCarte enleverAvantCarte(ListCarte *);

/**
 \brief Retire le dernier élément
 \
 */
sCarte enleverApresCarte(ListCarte *);

/// @brief Renvoie la taille de la liste
/// @param  ListCarte* La liste
/// @return La taille de la liste
int listCarteSize(const ListCarte *);

/// @brief Converti la liste en tableau
/// @param  ListCarte* La liste
/// @param sCarte** Le tableau des cartes
/// @param int La taille du tableau
void listCarteToArray(ListCarte *, sCarte **, int *);

/// @brief Converti un tableau de cartes en liste
/// @param  ListCarte* La liste
/// @param  sCarte** Le tableau des cartes
/// @param  int La taille du tableau
void arrayToListCarte(ListCarte *, sCarte **, int);

/// @brief Retourne la valeur totale des cartes de la liste
/// @param cartes Pointeur sur la liste de cartes
/// @return valeur totale des cartes de la liste
int getValeurTotale(const ListCarte *cartes);

/// @brief Retourne La figure de la carte
/// @param carte Pointeur sur la carte
/// @return Une chaine de char Pour la fichure
char* getValeurCarte(const sCarte *carte);

/// @brief Retourne la couleur de la carte
/// @param carte Pointeur sur la carte
/// @return Une chaine de char Pour la couleur
char* getCouleurCarte(const sCarte *carte);



#endif // LISTE_CARTE_H
