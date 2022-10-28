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
    int int_jour;
    int int_mois;
    int int_annee;
    int int_retour;  // Déclaration de la variable chargée de récupérer le retour des fonction
    char char_verif; // Déclaration du caractère de vérification de la saisie

    printf("Saisir le jour : ");
    int_retour = scanf("%d", &int_jour);

    printf("Saisir le mois : ");
    int_retour = scanf("%d", &int_mois);

    printf("Saisir l'année : ");
    int_retour = scanf("%d", &int_annee);

    switch (int_mois)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
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
        if (int_jour == 30)
        {
            int_jour = 1;
            int_mois++;
        }
        else
        {
            int_jour++;
        }

    case 2:
        if (int_annee % 4 == 0)
        {
            if (int_jour == 29)
            {
                int_mois++;
                int_jour = 1;
            }
            else
            {
                int_jour++;
            }
        }
        else
        {
            if (int_jour == 28)
            {
                int_mois++;
                int_jour = 1;
            }
            else
            {
                int_jour++;
            }
        }

        break;
    case 12:
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

    printf("Dans un jour, on sera le %d/%d/%d\n", int_jour, int_mois, int_annee);

    return (0);
}
