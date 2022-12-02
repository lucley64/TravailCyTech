#include "tab1D.h"

#include <stdio.h>
#include <stdlib.h>

void invertion(int tab[TAILLE_TAB])
{
    int int_temp;

    for (unsigned long ul_i = 0; ul_i < TAILLE_TAB / 2; ul_i++)
    {
        int_temp = tab[ul_i];
        tab[ul_i] = tab[TAILLE_TAB - 1 - ul_i];
        tab[TAILLE_TAB - 1 - ul_i] = int_temp;
    }
}

void afficherTab(int tab[TAILLE_TAB])
{

    for (unsigned long ul_i = 0; ul_i < TAILLE_TAB; ul_i++)
    {
        printf("%i, ", tab[ul_i]);
    }

    printf("\n");
}

void remplirAlea(int tab[TAILLE_TAB])
{
    for (int int_i = 0; int_i < TAILLE_TAB; int_i++)
    {
        tab[int_i] = rand() % 100;
    }
}

void additionnerTab(int tab1[TAILLE_TAB], int tab2[TAILLE_TAB], int tabResultat[TAILLE_TAB])
{
    for (int int_i = 0; int_i < TAILLE_TAB; int_i++)
    {
        tabResultat[int_i] = tab1[int_i] + tab2[int_i];
    }
}

int traversabilite(int tab1[TAILLE_TAB], int max)
{
    int int_i;
    int int_nbIter;

    int_i = 0;
    int_nbIter = 0;

    while (int_i < TAILLE_TAB && int_i >= 0 && int_nbIter < max)
    {
        printf("%i\n", int_i);
        if (int_i == TAILLE_TAB - 1)
        {
            return (1);
        }
        else
        {
            int_i = int_i + tab1[int_i];
        }
        int_nbIter++;
    }
    return (0);
}

void remplir(int tab[TAILLE_TAB])
{
    int int_verif;
    char char_verif;
    int int_saisie;
    for (int int_i = 0; int_i < TAILLE_TAB; int_i++)
    {
        int_verif = scanf("%d", &int_saisie);
        scanf("%c", &char_verif);
        if (int_verif == 0 || char_verif != '\n')
        {
            fprintf(stderr, "Erreur veuillez saisir un entier correspondant aux choix.\n");
            exit(EXIT_FAILURE);
        }
        tab[int_i] = int_saisie;
    }
}

void remplirStr(char str[TAILLE_TAB])
{
    printf("Renseigner la chaine de caractères : ");
    scanf("%s", str);
}

int verifPalindrome(char str[TAILLE_TAB])
{
    int int_taille;
    char char_lu;

    int_taille = 0;
    char_lu = str[int_taille];

    while (char_lu != '\0')
    {
        int_taille++;
        char_lu = str[int_taille];
    }

    for (int int_i = 0; int_i < int_taille / 2; int_i++)
    {
        if (str[int_i] != str[int_taille - 1 - int_i])
        {
            return (0);
        }
    }
    return (1);
}