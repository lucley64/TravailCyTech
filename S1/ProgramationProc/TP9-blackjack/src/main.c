/**
 \file main.c
 \author Luc Leydert
 \brief Fichier principal pour le blackjack
 \version 0.1
 \date 08/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "cartes.h"

/**
 \brief Programme principal
 \
 \param argc 
 \param argv 
 \return int 
 */
int main(int argc, char const *argv[])
{
    ListCarte *cartes;


    cartes = initCartes();

    melangerCartes(cartes);


    return (0);
}
