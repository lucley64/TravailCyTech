/**
 \file divisionEntiers.c
 \author Luc Leydert
 \brief Division d’entier
 \version 0.1
 \date 27/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>
#include <stdlib.h>

/**
 \brief Permet d'effectuer une division de deux entiers saisits
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_n;       // Déclaration du numérateur
    int int_d;       // Déclaration du dénominateur
    int int_retour;  // Déclaration de la variable chargée de récupérer le retour des fonction
    char char_verif; // Déclaration du caractère de vérification de la saisie

    // On demande la saisie des variables
    printf("Veuillez saisir le numérateur et le dénominateur : \n");

    // On lit le numérateur
    int_retour = scanf("%d", &int_n);

    // On vérifie que scanf a bien lu quelquechose
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On vérifie que l'utilisateur n'a rien saisi après le numérateur
    int_retour = scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On lit le dénominateur
    int_retour = scanf("%d", &int_d);
    // On vérifie que scanf a bien lu quelquechose
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On vérifie que l'utilisateur n'a rien saisi après le dénominateur
    int_retour = scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On test si la division est possible
    if (int_d != 0)
    {
        // On affiche le résultat
        printf("%d / %d = %d\n", int_n, int_d, int_n / int_d);
    }
    else
    {
        printf("Division impossible\n");
    }

    return (0);
}
