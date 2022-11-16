/**
 \file racine2.c
 \author Luc Leydert
 \brief Fonctions pour l'aproximation de la racine de 2
 \version 0.1
 \date 15/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "racine2.h"

void racine2Menu()
{

    int int_choix;       // Variable représentant le choix de l'utilisateur
    int int_verif;       // Variable qui vérifie si l'utilisateur à bien saisi quelque chose
    char char_verif;     // Variable qui vérifie le buffer
    int int_n;           // Le nombre de points à tirer pour le choix 1
    float float_racine2; // La valeur de racine de 2 retourné par chaque fonctions

    // On affiche le menu
    printf("Choix de la méthode d'approximation de racine de 2 : \n1: Isaac Newton\n2: Edmund Halley\n3: Théon de Smyrne\n\nVotre choix : ");
    int_verif = scanf("%d", &int_choix);

    // Verifie si la saisie est correcte
    if (int_verif == 0)
    {
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
    }

    scanf("%c", &char_verif);
    if (char_verif != '\n')
    {
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
    }

    switch (int_choix)
    {
    case 1:
        printf("Isaac Newton. \nVeuillez saisir la précision : ");
        int_verif = scanf("%d", &int_n);
        // Verifie si la saisie est correcte
        if (int_verif == 0)
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%c", &char_verif);
        if (char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }
        float_racine2 = newton(int_n);
        printf("La valeur de racine de 2 est : %f\n", float_racine2);
        break;
    case 2:
        printf("Edmund Halley.\nVeuillez saisir la précision : ");
        int_verif = scanf("%d", &int_n);
        // Verifie si la saisie est correcte
        if (int_verif == 0)
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%c", &char_verif);
        if (char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }
        float_racine2 = halley(int_n);
        printf("La valeur de racine de 2 est : %f\n", float_racine2);
        break;
    case 3:
        printf("Théon de Smyrne.\nVeuillez saisir la précision : ");
        int_verif = scanf("%d", &int_n);
        // Verifie si la saisie est correcte
        if (int_verif == 0)
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%c", &char_verif);
        if (char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }
        float_racine2 = smyrne(int_n);
        printf("La valeur de racine de 2 est : %f\n", float_racine2);
        break;

    default:
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
        break;
    }
}

float newton(int int_n)
{
    float float_racine2; // Valeur de la racine de 2
    float_racine2 = 1;

    for (int int_i = 1; int_i < float_racine2; int_i++)
    {
        float_racine2 = (float_racine2 / 2) + (1 / float_racine2);
    }

    return (float_racine2);
}

float halley(int int_n)
{
    float float_racine2; // Valeur de la racine de 2

    float_racine2 = 1;

    for (int int_i = 1; int_i < int_n; int_i++)
    {
        float_racine2 = float_racine2 * ((pow(float_racine2, 2) + 6) / (3 * pow(float_racine2, 2) + 2));
    }

    return (float_racine2);
}

float smyrne(int int_n)
{
    float float_racine2; // Valeur de la racine de 2
    int int_pn;          // suite pn
    int int_qn;          // suite qn

    int_pn = 1;
    int_qn = 1;

    for (int int_i = 1; int_i < int_n; int_i++)
    {
        int_pn = int_pn + 2 * int_qn;
        int_qn = int_qn + int_qn;
    }

    float_racine2 = (float) int_pn / int_qn;

    return (float_racine2);
}