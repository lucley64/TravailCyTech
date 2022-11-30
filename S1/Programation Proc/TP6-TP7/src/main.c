/**
 \file main.c
 \author Luc Leydert
 \brief
 \version 0.1
 \date 29/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "puissance4.h"
#include "tab1D.h"
#include "pointeurs.h"

#define TAILLE_TAB_TEST 20

int main(int argc, char const *argv[])
{
    int tint_tab1[TAILLE_TAB_TEST];            // Le premier tableau 1D
    int tint_tab2[TAILLE_TAB_TEST];            // Le deuxieme tableau 1D
    int tint_tab3[TAILLE_TAB_TEST];            // Le troisième tableau 1D
    char tchar_tabChar[TAILLE_TAB_TEST];       // La chaine de caractères pour la palindrome
    int int_choix;                             // Choix de la méthode à utiliser
    char char_choix;                           // Choix de modification du premier tableau
    int int_verif;                             // Verification de la saisie
    char char_verif;                           // Varification de la saisie
    int tint_grillePuissance4[OFFSET][OFFSET]; // La grille du puissance 4

    printf("Choisir entre : \n%s%s%s",
           " 1- Méthodes du tableau 1D\n",
           " 2- Puissance 4\n",
           " 3- Pointeurs\n");
    int_verif = scanf("%d", &int_choix);
    scanf("%c", &char_verif);
    if (int_verif == 0 || char_verif != '\n')
    {
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
    }

    switch (int_choix)
    {
    case 1:
        // Remplissage des tableau
        srand(time(NULL));
        remplirAlea(tint_tab1);
        remplirAlea(tint_tab2);

        // Affichage des tableau
        printf("Tableau 1 : ");
        afficherTab(tint_tab1);
        printf("Tableau 2 : ");
        afficherTab(tint_tab2);

        printf("Choisir entre les différentes possibilités : \n%s%s%s%s",
               " 1- Invertion du 1er tableau\n",
               " 2- Somme des élémente des deux tableau\n",
               " 3- Vérif si tab 1 est traversable\n",
               " 4- Vérifier si palindrome\n");

        int_verif = scanf("%d", &int_choix);
        scanf("%c", &char_verif);
        if (int_verif == 0 || char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }

        switch (int_choix)
        {
        case 1: // Tableaux
            invertion(tint_tab1);
            afficherTab(tint_tab1);
            break;

        case 2:
            additionnerTab(tint_tab1, tint_tab2, tint_tab3);
            afficherTab(tint_tab3);
            break;

        case 3:
            printf("Changer les valeurs du tableau ? [N/y] \n");
            int_verif = scanf("%c", &char_choix);
            if (int_verif != 0 && (char_choix == 'y' || char_choix == 'Y'))
            {
                remplir(tint_tab1);
            }
            afficherTab(tint_tab1);

            if (traversabilite(tint_tab1, 100))
            {
                printf("Le tableau est taversable\n");
            }
            else
            {
                printf("Le tableau n'est pas taversable\n");
            }
            break;
        case 4:
            remplirStr(tchar_tabChar);
            if (verifPalindrome(tchar_tabChar))
            {
                printf("Le mot est un palindrome\n");
            }
            else
            {
                printf("Le mot n'est pas un palindrome\n");
            }

            break;
        default:
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case 2: // Puissance 4
        // On initialise le jeu
        init(tint_grillePuissance4);

        // On démarre le jeu
        tourDeJeu(tint_grillePuissance4);

        break;

    case 3: // Pointeurs
        printf("Choisir entre les différentes possibilités : \n%s%s%s%s",
               " 1- Exercice inutile\n",
               " 2- Pointeur de pointeur\n",
               " 3- Pointeur sur tableau\n", 
               " 4- Un peut moins facile\n");

        int_verif = scanf("%d", &int_choix);
        scanf("%c", &char_verif);
        if (int_verif == 0 || char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }

        switch (int_choix)
        {
        case 1:
            exerciceInutile();
            break;

        case 2:
            pointeurDePointeur();
            break;

        case 3:
            pointeurSurTableau();
            break;

        case 4:
            unPeutMoinsFacile();
            break;
            
        default:
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
            break;
        }
        break;
    default:
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
        break;
    }

    return (0);
}
