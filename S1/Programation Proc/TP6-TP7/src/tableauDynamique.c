/**
 \file tableauDynamique.c
 \author Luc Leydert
 \brief
 \version 0.1
 \date 30/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "tableauDynamique.h"

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

void afficherTabDyna(int *tab, int taille)
{
    int *pint_i;

    pint_i = tab;

    printf("[%i", *pint_i);

    pint_i++;

    for (; pint_i <= &tab[taille - 1]; pint_i++)
    {
        printf(", %i", *pint_i);
    }
    printf("]\n");
}

void remplissageTabDynaAlea(int *tab, int taille)
{
    for (int *pint_i = tab; pint_i <= &tab[taille - 1]; pint_i++)
    {
        *pint_i = rand() % 100;
    }
}

void remplissageTabDyna(int *tab, int taille)
{
    for (int *pint_i = tab; pint_i <= &tab[taille - 1]; pint_i++)
    {
        scanf("%d", pint_i);
    }
}

void triInsertion(int *tab, int taille)
{
    int *int_dernier; // Valeur la plus grande de la parie que l'on trie
    int int_temp;     // Variable pour réaliser l'échange

    for (int int_j = 0; int_j < taille; int_j++)
    {
        // On considere que la première est la plus grande
        int_dernier = &tab[0];

        // On fait glisser la plus grande valeur à la fin du tableau
        for (int int_i = 1; int_i < taille - int_j; int_i++)
        {
            // Si la valeur actuelle est plus grande on fait un échange
            if (tab[int_i] < *int_dernier)
            {
                int_temp = tab[int_i];
                tab[int_i] = *int_dernier;
                *int_dernier = int_temp;
            }
            int_dernier = &tab[int_i];
        }
    }
}

int *copierSousTableau(int *src, int debut, int fin)
{
    int *tint_dest;     // Tableau destination
    int int_tailledest; // Taille de ce tableau

    // On calcule la taille du tableau
    int_tailledest = fin - debut;

    // On créé le tableau
    tint_dest = malloc(int_tailledest);

    // On copie les variables de deb à fin dans dest
    for (int int_i = debut; int_i <= fin; int_i++)
    {
        tint_dest[int_i] = src[int_i];
    }

    // On retourne dest
    return (tint_dest);
}

void fusion(int *tab1, int taille1, int *tab2, int taille2, int *tabRes)
{
    int int_tailleTabRes;
    int* pint_valTab1;
    int* pint_valTab2;

    int_tailleTabRes = taille1 + taille2;
    pint_valTab1 = tab1;
    pint_valTab2 = tab2;
    tabRes = malloc(int_tailleTabRes);


    for (int int_i = 0; int_i < int_tailleTabRes; int_i++)
    {
        if (*pint_valTab1 < pint_valTab2)
        {
            /* code */
        }
        
    }
    
}

void triFusion(int *tab, int taille) {}
void minMaxTableau(int *tab, int taille, int *min, int *max) {}
void histogramme(int *tab, int taille, int *histo, int tailleH, int min) {}
void triDenombrement(int *tab, int taille) {}