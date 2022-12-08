/**
 \file typesCartes.h
 \author Luc Leydert
 \brief Fichier corespondant à tout les types utilisés
 \version 0.1
 \date 08/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef TYPES_CARTES_H
#define TYPES_CARTES_H

/// @brief Enum représantant les valeurs de cartes
typedef enum
{
    AS = 1,
    DEUX = 2,
    TROIS = 3,
    QUATRE = 4,
    CINQ = 5,
    SIX = 6,
    SEPT = 7,
    HUIT = 8,
    NEUF = 9,
    DIX = 10,
    VALET = 11,
    DAME = 12,
    ROI = 13
} Carte;

typedef enum
{
    PIQUE,
    COEUR,
    CARREAU,
    TREFLE
} CarteColor;

typedef struct
{
    Carte carte;
    CarteColor carte_color;
} sCarte;

/**
 \brief Un item de la liste
 \
 */

typedef struct itemCarte
{
    struct itemCarte *prev; /* Pointeur sur le précédent élément*/
    sCarte value;            /*  La valeur de l'item */
    struct itemCarte *next; /* Pointeur sur le prochain *item*/
} ItemCarte;

/**
 \brief La liste en elle-même
 \
 */
typedef struct
{
    ItemCarte *first; /* pointeur sur le premier element de la liste*/
    ItemCarte *last;  /* pointeur sur le dernier élement de la liste*/
} ListCarte;

#endif // TYPES_CARTES_H