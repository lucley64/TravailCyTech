/**
 \file racine2.h
 \author Luc Leydert
 \brief Fonctions pour l'aproximation de la racine de 2
 \version 0.1
 \date 15/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef RACINE_2_H
#define RACINE_2_H

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

/**
 \brief Affiche un menu proposant les différents fonctions
 \
 */
void racine2Menu();

/**
 \brief Approximation de la racine de 2 via la méthode de Isaac Newton
 \
 \param int_n précision
 \return float racine de 2
 */
float newton(int int_n);

/**
 \brief Approximation de la racine de 2 via la méthode de Edmund Halley
 \
 \param int_n précision
 \return float racine de 2 
 */
float halley(int int_n);

/**
 \brief Approximation de la racine de 2 via la méthode de Théon de Smyrne
 \
 \param int_n précision
 \return float racine de 2 
 */
float smyrne(int int_n);

/**
 \brief Fonction newton en recurcif
 \
 \param int_n précision
 \return float racine de 2 
 */
float newtonRec(int int_n);



#endif // !RACINE_2_H