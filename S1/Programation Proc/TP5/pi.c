/**
 \file pi.c
 \author Luc Leydert
 \brief Fonction pour l'aproximation de pi
 \version 0.1
 \date 15/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "pi.h"

void piMenu()
{
    int int_choix;   // Variable représentant le choix de l'utilisateur
    int int_verif;   // Variable qui vérifie si l'utilisateur à bien saisi quelque chose
    char char_verif; // Variable qui vérifie le buffer
    int int_n;       // Le nombre de points à tirer pour le choix 1
    float float_pi;  // La valeur de pi retourné par chaque fonctions

    // On affiche le menu
    printf("Choix de la méthode d'approximation de pi : \n1: Aire d'un disque par quadrillage\n2: Madhava de Sangamagrama\n3: John Wallis\n\nVotre choix : ");
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
        printf("Aire d'un disque par quadrillage.\nVeuillez saisir le nombre de points à tirer : ");
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
        float_pi = aireDisqueParQuadrillage(int_n);
        printf("La valeur de pi est : %f\n", float_pi);
        break;
    case 2:
        printf("Madhava de Sangamagrama.\nVeuillez saisir la précision : ");
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
        float_pi = madhava(int_n);
        printf("La valeur de pi est : %f\n", float_pi);
        break;
    case 3:
        printf(" John Wallis.\nVeuillez saisir la précision : ");
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
        float_pi = wallis(int_n);
        printf("La valeur de pi est : %f\n", float_pi);
        break;

    default:
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
        break;
    }
}

float aireDisqueParQuadrillage(int int_n)
{
    int int_rayon;  // Rayon du cercle
    float float_x;  // Coordoné x du point tiré
    float float_y;  // Coordoné y du point tiré
    int int_count;  // Nombre de points dans le cercle
    float float_pi; // La valeur de pi obtenue

    // Génére un rayon aléatoire pour le cercle
    int_rayon = 10;

    // initalise le compteur
    int_count = 0;

    // Cherche parmis un n nombre de point combients sont contenus dans le cercle
    for (int int_i = 0; int_i < int_n; int_i++)
    {
        // Génére des coordonées aléatoires dans le carré de coté rayon * 2
        float_x = ((float)rand() / RAND_MAX) * int_rayon;
        float_y = ((float)rand() / RAND_MAX) * int_rayon;
        if (sqrt(pow(float_x, 2) + pow(float_y, 2)) <= int_rayon)
        {
            int_count++;
        }
    }

    float_pi = ((float)int_count / int_n) * pow(int_rayon * 2, 2) / pow(int_rayon, 2);

    return (float_pi);
}

float madhava(int int_n)
{
    float float_pi;  // La valeur de pi
    float float_sum; // L'accumilateur de la somme

    // initialise l'accumulateur
    float_sum = 0;

    // Calcule la somme
    for (int int_i = 0; int_i < int_n; int_i++)
    {
        float_sum = float_sum + (pow(-1, int_i) / (2 * int_i + 1));
    }

    // Calcul de pi
    float_pi = 4 * float_sum;

    return (float_pi);
}

float wallis(int int_n)
{
    float float_pi;   // La valeur de pi
    float float_mult; // L'accumilateur de la multiplication

    float_mult = 1;
    for (int int_i = 1; int_i < int_n; int_i++)
    {
        float_mult = float_mult * (pow(2 * int_i, 2) / (pow(2 * int_i, 2) - 1));
    }

    float_pi = float_mult * 2;

    return (float_pi);
}