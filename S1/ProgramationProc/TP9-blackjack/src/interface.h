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

typedef enum
{
    SAUTE,
    EGALITE,
    REMPORTE,
    ETAT_BLACKJACK,
    BATU,
} EtatDeJeu;

char *demanderNom();

int demanderMise(const char *nom);

int demanderContinuer();

int continuer();

void annoncerCartes(const ListCarte *cartes);

void annoncerTour(const char *nom);

void annoncerEtat(const Joueur *joueur);

void annoncerScore(const Joueur *joueur);

void annoncerCartesToutLeMonde(const listJoueur *joueurs);

void annoncerEtatJeu(const char* nomJoueur, EtatDeJeu etat);