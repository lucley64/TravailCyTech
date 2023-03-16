/**
 \file joueur.h
 \author Luc Leydert
 \brief Fichier pour la gestion des type pour les joueurs
 \version 0.1
 \date 16/12/2022
 \
 \copyright Copyright (c) 2022
 \
 */

#pragma once

#include "listeCarte.h"

/// @brief Les différents états du joueur
typedef enum
{
    /** Le joueur a dépassé 21*/
    DEPASSE,
    /** Le joueur est en dessous de 21*/
    DESSOUS,
    /** Le joueur a fait 21*/
    VINGT_ET_UN,
    /** Le joueur a fait blackjack*/
    BLACKJACK,
    /** Le joueur represente le croupier*/
    CROUPIER,
} EtatJoueur;

/// @brief Structure représantant un joueur
typedef struct
{
    /** Le nom du joueur*/
    char *name;
    /** La mise du joueur*/
    int mise;
    /** Le score du joueur*/
    int score;
    /** La main du joueur*/
    ListCarte hand;
    /** L'état de jeu du joueur*/
    EtatJoueur etat;
} Joueur;

typedef struct itemJoueur
{
    struct itemJoueur *prev;
    Joueur value;
    struct itemJoueur *next;
} ItemJoueur;

typedef struct
{
    ItemJoueur *first;
    ItemJoueur *last;
} listJoueur;