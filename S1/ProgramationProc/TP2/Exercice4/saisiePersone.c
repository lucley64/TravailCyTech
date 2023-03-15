/**
 \file saisiePersone.c
 \author Luc Leydert
 \brief Saisie d'une personne
 \version 0.1
 \date 27/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>

/**
 \brief Permet de saisir le nom, prénom, date de naissance d'une personne
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    char str_nom[29];    // Déclaration du nom
    char str_prenom[29]; // Déclaration du prénom
    int int_jour;        // Déclaration du jour de naissance
    char str_mois[9];    // Déclaration du mois de naissance
    int int_annee;       // Déclaration de l'année de naissance
    int int_retour;      // Déclaration de la variable chargée de récupérer le retour des fonction

    // On demande la saisi du nom et on le lit
    printf("Entrez votre nom : ");
    int_retour = scanf("%s", str_nom);
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On demande la saisi du prénom et on le lit
    printf("Entrez votre prénom : ");
    int_retour = scanf("%s", str_prenom);
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On demande la saisi de la date de naissance et on la lit jour, puis mois, puis année
    printf("Entrez votre date de naissance (format JJ mois AAAA): ");
    int_retour = scanf("%d", &int_jour);
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }
    int_retour = scanf("%s", str_mois);
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }
    int_retour = scanf("%d", &int_annee);
    if (int_retour == 0)
    {
        printf("Erreur lors de la saisie.\n");
        exit(-1);
    }

    // On affiche les saisit
    printf("Voici ce que vous avez entré : \n");
    printf("Nom : %s\n", str_nom);
    printf("Prenom : %s\n", str_prenom);
    printf("Date de naissance : %d %s %d\n", int_jour, str_mois, int_annee);

    return (0);
}