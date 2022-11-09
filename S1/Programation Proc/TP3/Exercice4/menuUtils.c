/**
 \file menuUtils.c
 \author Luc Leydert
 \brief propose, via un menu, des actions
 \version 0.1
 \date 09/11/2022
 */

#include <stdio.h>
#include <stdlib.h>

// Pour calculer des puissances
#include <math.h>

/**
 \brief affiche un triangle isocèle sur le terminal
 \
 \param n la hauteur du triangle
 */
void affichageTriangle(int int_n);

/**
 \brief afficher la table de multiplication de n
 \
 \param n nombre de qui on veut la table
 */
void tableMultiplication(int int_n);

/**
 \brief défini si un nombre est un nombre d’Armstrong
 \
 \param n le nombre en question
 */
void estArmstrong(int int_n);

/**
 \brief affiche et propose le menu
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    int int_choix;   // Variable représentant le choix de l'utilisateur
    int int_verif;   // Variable qui vérifie si l'utilisateur à bien saisi quelque chose
    char char_verif; // Variable qui vérifie le buffer
    int int_n;       // Variable correspondant à la saisie nécessaire pour chaque fonctions

    // On affiche le menu
    printf("Bonjour, voici les options disponibles : \n 1: Affichage d'un triangle \n 2: Table de multiplication \n 3: Nombre d'Armstrong \n \n Votre choix : ");
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

    // On determine la fonction à executer
    switch (int_choix)
    {
    case 1:
        printf("Affichage d'un triangle isocèle. \nSaisir la hauteur du triangle : ");
        int_verif = scanf("%d", &int_n);
        // Verifie si la saisie est correcte
        if (int_verif == 0)
        {
            fprintf(stderr, "Erreur veuillez saisir un entier.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%c", &char_verif);
        if (char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier.\n");
            exit(EXIT_FAILURE);
        }

        affichageTriangle(int_n);
        break;

    case 2:
        printf("Affichage de la table de multiplication de n. \nSaisir n : ");
        int_verif = scanf("%d", &int_n);
        // Verifie si la saisie est correcte
        if (int_verif == 0)
        {
            fprintf(stderr, "Erreur veuillez saisir un entier.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%c", &char_verif);
        if (char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier.\n");
            exit(EXIT_FAILURE);
        }

        tableMultiplication(int_n);
        break;

    case 3:
        printf("Nombre d'Armstrong. \nSaisir n : ");
        int_verif = scanf("%d", &int_n);
        // Verifie si la saisie est correcte
        if (int_verif == 0)
        {
            fprintf(stderr, "Erreur veuillez saisir un entier.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%c", &char_verif);
        if (char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier.\n");
            exit(EXIT_FAILURE);
        }

        estArmstrong(int_n);
        break;

    default:
        fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
        exit(EXIT_FAILURE);
        break;
    }

    return (0);
}

void affichageTriangle(int int_n)
{
    for (int int_i = 0; int_i < int_n; int_i++)
    {
        for (int int_j = 0; int_j < int_n - 1 - int_i; int_j++)
        {
            printf(" ");
        }
        for (int int_j = 0; int_j < int_i * 2 + 1; int_j++)
        {
            printf("*");
        }
        for (int int_j = 0; int_j < int_n - 1 - int_i; int_j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void tableMultiplication(int int_n)
{
    printf("Table de multiplication de %d : ", int_n);
    for (int int_i = 1; int_i <= 10; int_i++)
    {
        printf("%d × %d = %d\n", int_i, int_n, int_i * int_n);
    }
}

void estArmstrong(int int_n)
{
    int int_p;   // Correspond désigne le nombre de chiffres de n
    int int_acc; // somme des puissances p-ièmes de n
    int int_n2;  // copie de n
    int_n2 = int_n;

    // on détermine le nombre de chiffres de n
    int_p = 1;
    while (int_n / (int)pow(10, int_p) != 0)
    {
        int_p++;
    }

    // calcul de a somme des puissancesp-ièmes des chiffres de n
    int_acc = 0;
    for (int int_i = 1; int_i <= int_p; int_i++)
    {
        int_acc = int_acc + pow(int_n2 % 10, int_p);
        int_n2 = int_n2 / 10;
    }

    // On verifie si somme des puissances p-ièmes de n est égale à n
    if (int_acc == int_n)
    {
        printf("%d est un nombre d'armstrong.\n", int_n);
    }
    else
    {
        printf("%d n'est pas un nombre d'armstrong.\n", int_n);
    }
}