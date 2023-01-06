/**
    @file restaurant.h
    @author Luc Leydert
    @brief Fichier qui définit le type Restaurant
    @version 0.1
    @date 06/01/2023
    
    @copyright Copyright (c) 2023
    
 */

#pragma once

#include "adresse.h"

/// @brief Représente un réstaurant
typedef struct{
    /// @brief Le nom du resto
    char* str_nom;
    /// @brief son adresse
    Adresse adresse;
    /// @brief son prix
    int int_prix;
    /// @brief sa note
    double dbl_note;
} Restaurant;