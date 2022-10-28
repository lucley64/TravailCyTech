/**
 \file prediction.c
 \author Luc Leydert
 \brief Prédiction
 \version 0.1
 \date 27/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>
#include <stdlib.h>

/**
 \brief  ira au clavier le numéro du jour, le numéro du mois et l’année, et il affichera la date qu’il sera un jour plus tard
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_jour;    // Déclaration du jour
    int int_mois;    // Déclaration du mois
    int int_annee;   // Déclaration de l'année
    int int_retour;  // Déclaration de la variable chargée de récupérer le retour des fonction
    char char_verif; // Déclaration du caractère de vérification de la saisie

    // On demande la saisie du jour puis on le lit
    printf("Saisir le jour : ");
    int_retour = scanf("%d", &int_jour);

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

    // On demande la saisie du mois puis on le lit
    printf("Saisir le mois : ");
    int_retour = scanf("%d", &int_mois);

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

    // On demande la saisie de l'année puis on le lit
    printf("Saisir l'année : ");
    int_retour = scanf("%d", &int_annee);

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

    // On étudie le mois pour déterminer combien de jours il possede
    switch (int_mois)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        // Cas où le mois à 31 jours
        if (int_jour == 31)
        {
            int_jour = 1;
            int_mois++;
        }
        else
        {
            int_jour++;
        }

        break;
    case 4:
    case 6:
    case 9:
    case 11:
        // Cas où le mois à 30 jours
        if (int_jour == 30)
        {
            int_jour = 1;
            int_mois++;
        }
        else
        {
            int_jour++;
        }
        break;
    case 2:
        // Cas du Févrié où il faut déterminer si c'est une année bissextile
        if (int_jour == 29 && (int_annee % 4 == 0 && (int_annee % 100 != 0 || int_annee % 400 == 0)))
        {
            int_mois++;
            int_jour = 1;
        }
        else if (int_jour == 28)
        {
            int_mois++;
            int_jour = 1;
        }
        else
        {
            int_jour++;
        }

        break;
    case 12:
        // Cas de descembre où il faut changer l'année en plus
        if (int_jour == 31)
        {
            int_annee++;
            int_mois = 1;
            int_jour = 1;
        }
        else
        {
            int_jour++;
        }

        break;
    default:
        break;
    }

    // On affiche le résultat
    printf("Dans un jour, on sera le %d/%d/%d\n", int_jour, int_mois, int_annee);

    return (0);
}
