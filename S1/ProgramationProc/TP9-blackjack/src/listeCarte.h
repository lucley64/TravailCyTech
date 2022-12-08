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

#pragma once

#include "cartes.h"

/**
 \brief Un item de la liste
 \
 */
typedef struct itemCarte{
    struct itemCarte* prev; /* Pointeur sur le précédent élément*/
    Carte value; /*  La valeur de l'item */
    struct itemCarte *next; /* Pointeur sur le prochain *item*/
} ItemCarte;

/**
 \brief La liste en elle-même
 \
 */
typedef struct {
    ItemCarte* first; /* pointeur sur le premier element de la liste*/
    ItemCarte* last; /* pointeur sur le dernier élement de la liste*/
} ListCarte;

/**
 \brief Créé et initialise une liste de Carte
 \
 */
void creerListe(ListCarte*);

/**
 \brief Ajoute un élément au début de la liste
 \
 */
void ajouterAvant(ListCarte*, Carte);

/**
 \brief Ajoute un élément en fin de liste
 \
 */
void ajouterApres(ListCarte*, Carte);

/**
 \brief Retire le premier élément
 \
 */
Carte enleverAvant(ListCarte*);

/**
 \brief Retire le dernier élément
 \
 */
Carte enleverApres(ListCarte*);
