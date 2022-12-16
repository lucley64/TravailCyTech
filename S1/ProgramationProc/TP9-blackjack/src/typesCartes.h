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
    /** Carte de valeur AS ( 1 ou 11 )*/
    AS = 1, 
    /** Carte de valeur DEUX*/
    DEUX = 2, 
    /** Carte de valeur TROIS*/
    TROIS = 3, 
    /** Carte de valeur QUATRE*/
    QUATRE = 4,
    /** Carte de valeur CINQ*/
    CINQ = 5,
    /** Carte de valeur SIX*/ 
    SIX = 6, 
    /** Carte de valeur SEPT*/
    SEPT = 7, 
    /** Carte de valeur HUIT*/
    HUIT = 8, 
    /** Carte de valeur NEUF*/
    NEUF = 9, 
    /** Carte de valeur DIX*/
    DIX = 10, 
    /** Carte de valeur VALET (10)*/
    VALET = 11,
    /** Carte de valeur DAME (10) */ 
    DAME = 12, 
    /** Carte de valeur ROI (10) */
    ROI = 13 , 
} Carte;

/// @brief Représente la couleur de la carte
typedef enum
{
    /** Carte de type PIQUE*/
    PIQUE, 
    /** Carte de type COEUR*/
    COEUR, 
    /** Carte de type CARREAU*/
    CARREAU, 
    /** Carte de type TREFLE*/
    TREFLE , 
} CarteColor;

/// @brief Structure représantant une carte
typedef struct
{
    /** La valeur de la carte*/
    Carte carte; 
    /** La couleur de la carte*/
    CarteColor carte_color; 
} sCarte;

/**
 \brief Un item de la liste
 \
 */

typedef struct itemCarte
{
    /** Pointeur sur le précédent élément*/
    struct itemCarte *prev; 
    /**  La valeur de l'item */
    sCarte value;           
    /** Pointeur sur le prochain *item*/ 
    struct itemCarte *next; 
} ItemCarte;

/**
 \brief La liste en elle-même
 \
 */
typedef struct
{
    /** pointeur sur le premier element de la liste*/
    ItemCarte *first; 
    /** pointeur sur le dernier élement de la liste*/
    ItemCarte *last;  
} ListCarte;

#endif // TYPES_CARTES_H