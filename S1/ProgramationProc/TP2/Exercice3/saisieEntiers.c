/**
 \file saisieEntiers.c
 \author Luc Leydert
 \brief Saisie de deux entiers
 \version 0.1
 \date 27/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>
#include <stdlib.h>

/**
 \brief Saisissez deux entiers depuis l’entrée standard, puis affichez les
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{

    int int_nb1;     // Déclaration du premier réél à saisir
    int int_nb2;     // Déclaration du deuxième réél à saisir
    int int_retour;  // Déclaration de la variable chargée de récupérer le retour des fonction
    char char_verif; // Déclaration de la variable chargée de récupérer le dernier caractère saisi par l'utilisateur

    // On demande de saisir le premier réél et on le lit
    printf("Saisissez le premier entier : \n");
    int_retour = scanf("%d", &int_nb1);

    // On vérifie si scanf à bien lu un entier et on renvoi une erreur sinon
    if (int_retour == 0)
    {
        printf("Erreur lors de la première saisie.\n");
        exit(-1);
    }

    // On vérifie si l'utilisateur n'a pas saisi d'autres caractères après l'entier
    int_retour = scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        printf("Erreur lors de la première saisie.\n");
        exit(-1);
    }

    // On demande de saisir le deuxième réél et on le lit
    printf("Saisissez le deuxième entier : \n");
    scanf("%d", &int_nb2);

    // On vérifie si scanf à bien lu un entier et on renvoi une erreur sinon
    if (int_retour == 0)
    {
        printf("Erreur lors de la deuxième saisie.\n");
        exit(-1);
    }

    // On vérifie si l'utilisateur n'a pas saisi d'autres caractères après l'entier
    int_retour = scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        printf("Erreur lors de la deuxième saisie.\n");
        exit(-1);
    }

    // On affiche les deux entiers saisi
    printf("Premier entier : %d, deuxième entier : %d.\n", int_nb1, int_nb2);

    return (0);
}
