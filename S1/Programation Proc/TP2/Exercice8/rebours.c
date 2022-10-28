/**
 \file rebours.c
 \author Luc Leydert
 \brief Compte à rebours
 \version 0.1
 \date 28/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>
#include <stdlib.h>

/**
 \brief Effectue un compte à rebours
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_n;       // Déclaration du nombre à décompter
    int int_i;       // Déclaration de l'indice de boucle
    int int_retour;  // Déclaration de la variable chargée de récupérer le retour des fonction
    char char_verif; // Déclaration du caractère de vérification de la saisie

    // On lit le nombre à décompter
    int_retour = scanf("%d", &int_n);
    // On vérifie que scanf a bien lu quelquechose
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }
    // On vérifie que l'utilisateur n'a rien saisi après la saisie
    int_retour = scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On effectue le décompte
    for (int_i = int_n; int_i >= 0; int_i--)
    {
        printf("%d\n", int_i);
    }

    return (0);
}
