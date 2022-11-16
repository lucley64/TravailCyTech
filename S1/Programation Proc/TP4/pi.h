/**
 \file pi.h
 \author Luc Leydert
 \brief Fonction pour l'aproximation de pi
 \version 0.1
 \date 15/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */
#ifndef PI_H
#define PI_H


#include <stdio.h>
#include <stdlib.h>

#include <math.h>

/**
 \brief Affiche un menu qui propose les différents fonctions
 \
 */
void piMenu();

/**
 \brief Effectue une approximation de pi en calculant le nombre de point n satisfesant la condition : sqrt(x²+y²) ≤ r dans un cercle de rayon r
 \
 \param n Le nombre de points à tirer
 \return float la valeur de pi
 */
float aireDisqueParQuadrillage(int int_n);

/**
 \brief Effectue une approximation de pi via la serie de Madhava
 \
 \param int_n Précision
 \return float pi
 */
float madhava(int int_n);


/**
 \brief Effectue une approximation de pi via la serie de  John Walli
 \
 \param int_n Précision
 \return float pi
 */
float wallis(int int_n);

#endif // !PI_H