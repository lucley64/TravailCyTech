/**
 \file interface.h
 \author Luc Leydert
 \brief Gestion de l'interface et l'interaction avec le(s) joueur(s)
 \version 0.1
 \date 16/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */
#pragma once

#include "listeCarte.h"
#include "listJoueur.h"

#include <stdlib.h>

/// @brief Represente l'état du joueur par rapport au croupier
typedef enum
{
    /// @brief Le joueur à sauté (fait plus de 21)
    SAUTE,
    /// @brief Le joueur à fait égalité avec le croupier
    EGALITE,
    /// @brief Le joueur remporte sa mise
    REMPORTE,
    /// @brief Le joueur à fait blackjack (le croupier non)
    ETAT_BLACKJACK,
    /// @brief Le joueur à été batu par le croupier
    BATU,
} EtatDeJeu;

/// @brief Demande le nom au joueur avec la fonction getline
/// @return Le nom du joueur
char *demanderNom();

/// @brief Demande au joueur sa mise
/// @param nom Le nom du joueur
/// @return La mise du joueur
int demanderMise(const char *nom);

/// @brief Demande aux joueurs s'ils veullent continuer de jouer
/// @return 1 si oui, 0 sinon
int demanderContinuer();

/// @brief Demande au joueur s'il veu une autre carte
/// @return 1 si oui, 0 sinon
int continuer();

/// @brief Affiche les cartes d'une liste
/// @param cartes La liste de cartes
void annoncerCartes(const ListCarte *cartes);

/// @brief Annonce au joueur que c'est son tour
/// @param nom Le nom du joueur
void annoncerTour(const char *nom);

/// @brief Affiche l'état du joueur
/// @param joueur Pointeur sur le joueur
void annoncerEtat(const Joueur *joueur);

/// @brief Affiche le score d'un joueur
/// @param joueur Pointeur sur le joueur
void annoncerScore(const Joueur *joueur);

/// @brief Affiche les cartes d'une liste de joueurs
/// @param joueurs La liste de joueurs
void annoncerCartesToutLeMonde(const listJoueur *joueurs);

/**
 *@brief Affiche létat d'un joueur par rapport au croupier
 *@param nomJoueur Le nom du joueur
 *@param etat Un énum représantant cet état. \n
 *           SAUTE si Le joueur à sauté (fait plus de 21) \n
 *           EGALITE si Le joueur à fait égalité avec le croupier \n
 *           REMPORTE si Le joueur remporte sa mise \n
 *           ETAT_BLACKJACK si Le joueur à fait blackjack (le croupier non) \n
 *           BATU si Le joueur à été batu par le croupier
 */
void annoncerEtatJeu(const char *nomJoueur, EtatDeJeu etat);