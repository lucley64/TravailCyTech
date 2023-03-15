/**
    @file adresse.h
    @author Luc Leydert
    @brief Fichier relatif à l'adresse dun resto
    @version 0.1
    @date 06/01/2023
    
    @copyright Copyright (c) 2023
    
 */

#pragma once

typedef struct{
    char* numero;
    char *nom;
    char* codePostal;
    char* ville;
} Adresse;