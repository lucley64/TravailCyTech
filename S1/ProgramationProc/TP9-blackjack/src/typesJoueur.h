/**
 \file joueur.h
 \author Luc Leydert
 \brief Fichier pour la gestion des type pour les joueurs
 \version 0.1
 \date 16/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "listeCarte.h"

/// @brief Les différents états du joueur
typedef enum
{
    /** Le joueur a fait blackjack*/
    BLACKJACK,
    /** Le joueur a fait 21*/
    VINGT_ET_UN,
    /** Le joueur a dépassé 21*/
    DEPASSE,
    /** Le joueur est en dessous de 21*/
    DESSOUS,
} EtatJoueur;

/// @brief Structure représantant un joueur
typedef struct
{
    /** Le nom du joueur*/
    char *name;
    /** La mise du joueur*/
    int mise;
    /** La main du joueur*/
    ListCarte hand;
    /** L'état de jeu du joueur*/
    EtatJoueur etat;
} Joueur;

typedef struct itemJoueur
{
    itemJoueur *prev;
    Joueur value;
    itemJoueur *next;
} itemJoueur;

typedef struct
{
    itemJoueur *first;
    itemJoueur *last;
} listJoueur;