/**
 \file joueur.h
 \author Luc Leydert
 \brief Fichier pour la gestion des joueur
 \version 0.1
 \date 16/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "typesJoueur.h"

/// @brief initialise la liste des joueurs
/// @param joueurs la liste des joueurs
/// @param nbJoueurs le nombre de joueurs
void initListJoueur(listJoueur *joueurs);

/// @brief Ajoute un joueur au debut de la liste
/// @param joueurs la liste des joueurs
/// @param j le joueur à ajouter
void ajouterAvantJoueur(listJoueur *joueurs, Joueur j);

/// @brief Ajoute un joueur a la fin de la liste
/// @param joueurs la liste des joueurs
/// @param j le joueur à ajouter
void ajouterApresJoueur(listJoueur *joueurs, Joueur j);

/// @brief Retire un joueur au debut de la liste
/// @param joueurs la liste des joueurs
/// @return le joueur retiré
Joueur enleverAvantJoueur(listJoueur *joueurs);

/// @brief Retire un joueur a la fin de la liste
/// @param joueurs la liste des joueurs
/// @return le joueur retiré
Joueur enleverApresJoueur(listJoueur *joueurs);

/// @brief Renvoie la taille de la liste
/// @param  listJoueur* La liste
/// @return La taille de la liste
int listJoueurSize(const listJoueur *joueurs);

/// @brief Converti la liste en tableau
/// @param  listJoueur* La liste
/// @param Joueur** Le tableau des joueurs
/// @param int La taille du tableau
void listJoueurToArray(listJoueur *joueurs, Joueur **tabJoueur, int *taille);

/// @brief Converti un tableau de joueurs en liste
/// @param  listJoueur* La liste
/// @param  Joueur** Le tableau des joueurs
/// @param  int La taille du tableau
void arrayToListJoueur(listJoueur *joueurs, Joueur **tabJoueur, int taille);
