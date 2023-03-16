/**
 \file toto.c
 \author Luc Leydert
 \brief montre les passage des valeurs
 \version 0.1
 \date 09/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include <stdio.h>
#include <stdlib.h>

/**
 \brief Procedure echange qui échange les valeurs de deux nombre
 \param int_nb1 nombre 1
 \param int_nb2 nombre 2
 */
void echange(int int_nb1, int int_nb2);

/**
 \brief programme toto
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_nb1; // Premier nombre
    int int_nb2; // Deuxième nombre

    // initialisation des valeurs
    int_nb1 = 5;
    int_nb2 = 7;

    printf("Avant appel de la fonction : \n");

    printf("Nb1 = %d\n", int_nb1);
    printf("Nb2 = %d\n", int_nb2);

    printf("Appel de la fonction échange.\n");
    echange(int_nb1, int_nb2);

    printf("Après appel de la fonction : \n");

    printf("Nb1 = %d\n", int_nb1);
    printf("Nb2 = %d\n", int_nb2);

    return (0);
}

void echange(int int_nb1, int int_nb2)
{
    int int_tmp; // Permet de réaliser l'échange

    printf("Avant échange : \n");

    printf("Nb1 = %d\n", int_nb1);
    printf("Nb2 = %d\n", int_nb2);

    // Échange des valeurs
    int_tmp = int_nb1;
    int_nb1 = int_nb2;
    int_nb2 = int_tmp;

    printf("Après échange : \n");

    printf("Nb1 = %d\n", int_nb1);
    printf("Nb2 = %d\n", int_nb2);
}