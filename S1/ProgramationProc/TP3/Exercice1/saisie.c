/**
 \file saisie.c
 \author Luc Leydert
 \brief Saisie sûre d’un nombre
 \version 0.1
 \date 09/11/2022
 */

#include <stdio.h>
#include <stdlib.h>

/**
 \brief Permet de saisir un entier
 \return int l'entier saisit
 */
int saisieEntier();

/**
 \brief effectue la saisie / vérif d’un nombre entier.
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_nb; // L'entier à saisir

    int_nb = saisieEntier();

    printf("Entier saisit : %d\n", int_nb);

    return (0);
}

int saisieEntier()
{
    int int_n;             // L'entier saisit par l'utilisateur et à vérifier
    int int_verif;         // La variable chargée de récupérer le retour de la saisie
    char char_verifSaisie; // La variable qui va vérifier si l'utilisateur à uniquement saisit un entier et rien après

    // On lit la variable saisie par l'utilisateur
    printf("Saisir un entier : ");
    int_verif = scanf("%d", &int_n);

    if (int_verif == 0)
    {
        fprintf(stderr, "Erreur, veuillez saisir un entier. \n");
        exit(EXIT_FAILURE);
    }

    scanf("%c", &char_verifSaisie);
    if (char_verifSaisie != '\n')
    {
        fprintf(stderr, "Erreur, veuillez saisir uniquement un entier. \n");
        exit(EXIT_FAILURE);
    }

    return (int_n);
}