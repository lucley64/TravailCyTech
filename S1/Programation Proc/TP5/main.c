/**
 \file main.c
 \author Luc Leydert
 \brief Aproximation de pi et racine de 2
 \version 0.1
 \date 15/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include <stdio.h>
#include <stdlib.h>

#include "pi.h"
#include "racine2.h"

/**
 \brief affiche et propose le menu
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_choix;   // Variable représentant le choix de l'utilisateur
    int int_verif;   // Variable qui vérifie si l'utilisateur à bien saisi quelque chose
    char char_verif; // Variable qui vérifie le buffer

    // On affiche le menu
    printf("Bonjour, voici les options disponibles : \n 1: Approximation de pi \n 2: Appriximation de racine de 2\n \nVotre choix : ");
    int_verif = scanf("%d", &int_choix);

    // Verifie si la saisie est correcte
    if (int_verif == 0)
    {
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
    }

    scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
    }

    // On determine la fonction à executer
    switch (int_choix)
    {
    case 1:
        printf("Approximation de pi : \n");
        piMenu();
        break;

    case 2:
        printf("Approximation de racine de 2 : \n");
        racine2Menu();
        break;

    default:
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
        break;
    }
    return (0);
}
