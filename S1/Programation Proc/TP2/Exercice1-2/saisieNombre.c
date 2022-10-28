/**
 \file saisieNombre.c
 \author Luc Leydert
 \brief Saisissez un nombre entier depuis l’entrée standard, puis affichez-le.
 \version 0.1
 \date 27/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>
#include <stdlib.h>

/**
 \brief Saisissez un nombre entier depuis l’entrée standard, puis affichez-le.
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_nb;     // déclaration du nombre à saisir
    int int_retour; // déclaration de la variable chargée de récupérer le retour des fonction

    // on demande la saisie du nombre puis on le lit
    printf("Veuillez saisir un nombre : \n");
    int_retour = scanf("%d", &int_nb);

    // on vérifie que la saisie s'est bien passée
    // si le nombre saisit est un caractère, une chaine de caractère ou un réél le scanf ne va rien lire et renvoyer 0
    if (int_retour == 0)
    {
        printf("Problème de saisie\n");
        exit(-1);
    }

    // on affiche le nombre saisit
    printf("%d\n", int_nb);

    return (0);
}
