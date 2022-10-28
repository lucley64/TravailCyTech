/**
 \file produitNombre.c
 \author Luc Leydert
 \brief Produit de deux nombres
 \version 0.1
 \date 27/10/2022
 */

// inclusion de bibliothèques C standard
#include <stdio.h>
#include <stdlib.h>

/**
 \brief  demande deux nombres à l’utilisateur et l’informe ensuite si leur produit est négatif ou positif
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_A;       // Déclaration d'une variable du produit
    int int_B;       // Déclaration d'une variable du produit
    int int_retour;  // Déclaration de la variable chargée de récupérer le retour des fonction
    char char_verif; // Déclaration du caractère de vérification de la saisie

    // On demande la saisie des variables
    printf("Entrer les variables du produit : \n");

    // On lit A
    int_retour = scanf("%d", &int_A);
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
    // On lit B
    int_retour = scanf("%d", &int_B);
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

    // On test si l'une seulement une des deux variables est négative
    if ((int_A >= 0 && int_B < 0) || (int_A < 0 && int_B >= 0))
    {
        printf("Le produit est négatif.\n");
    }
    else
    {
        printf("Le produit est positif.\n");
    }
    
    

    return (0);
}
