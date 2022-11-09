/**
 \file saisie.c
 \author Luc Leydert
 \brief Montre la durrée le vie des variables
 \version 0.1
 \date 09/11/2022
 */

#include <stdio.h>
#include <stdlib.h>

/**
 \brief Procedure bidon
 */
void bidon();

/**
 \brief saisie
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_n;

    printf("%d\n", int_n);

    scanf("%d", &int_n);

    printf("%d\n", int_n);

    bidon();

    printf("%d\n", int_n);

    return (0);
}

void bidon()
{
    int int_n;

    printf("%d\n", int_n);

    scanf("%d", &int_n);

    printf("%d\n", int_n);
}