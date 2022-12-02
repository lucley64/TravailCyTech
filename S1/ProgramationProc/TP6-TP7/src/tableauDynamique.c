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

void afficherTabDyna(const int *tab, int taille)
{
    const int *pint_i;

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

    if (int_tailledest > 0)
    {
        // On créé le tableau
        tint_dest = malloc(int_tailledest * sizeof(int));

        // On copie les variables de deb à fin dans dest
        for (int int_i = debut; int_i < fin; int_i++)
        {
            tint_dest[int_i - debut] = src[int_i];
        }

        // On retourne dest
        return (tint_dest);
    }
    else
    {
        return (src);
    }
}

void fusion(const int *tab1, int taille1, const int *tab2, int taille2, int *tabRes)
{
    int int_tailleTabRes;    // Taille du tableau destination
    const int *pint_valTab1; // Pointeur sur le tableau 1
    const int *pint_valTab2; // Pointeur sur le tableau 2

    int_tailleTabRes = taille1 + taille2;
    pint_valTab1 = tab1;
    pint_valTab2 = tab2;

    for (int int_i = 0; int_i < int_tailleTabRes; int_i++)
    {
        if (pint_valTab1 > &tab1[taille1 - 1] && pint_valTab2 <= &tab2[taille2 - 1])
        {
            tabRes[int_i] = *pint_valTab2;
            pint_valTab2++;
        }
        else if (pint_valTab2 > &tab2[taille2 - 1] && pint_valTab1 <= &tab1[taille1 - 1])
        {
            tabRes[int_i] = *pint_valTab1;
            pint_valTab1++;
        }
        else if (pint_valTab1 <= &tab1[taille1 - 1] && pint_valTab2 <= &tab2[taille2 - 1])
        {
            if (*pint_valTab1 < *pint_valTab2)
            {
                tabRes[int_i] = *pint_valTab1;
                pint_valTab1++;
            }
            else
            {
                tabRes[int_i] = *pint_valTab2;
                pint_valTab2++;
            }
        }
    }
}

void triFusion(int *tab, int taille)
{
    afficherTabDyna(tab, taille);
    int *tint_soutab1;
    int *tint_soutab2;
    int int_tailleSousTab1;
    int int_tailleSousTab2;
    if (taille >= 2)
    {
        int_tailleSousTab1 = taille / 2;
        int_tailleSousTab2 = taille - taille / 2;
        tint_soutab1 = copierSousTableau(tab, 0, int_tailleSousTab1);
        afficherTabDyna(tint_soutab1, int_tailleSousTab1);
        triFusion(tint_soutab1, int_tailleSousTab1);
        tint_soutab2 = copierSousTableau(tab, taille / 2, taille);
        afficherTabDyna(tint_soutab2, int_tailleSousTab2);
        triFusion(tint_soutab2, int_tailleSousTab2);
        fusion(tint_soutab1, int_tailleSousTab1, tint_soutab2, int_tailleSousTab2, tab);
        afficherTabDyna(tab, taille);
        free(tint_soutab1);
        free(tint_soutab2);
    }
}

void minMaxTableau(int *tab, int taille, int *min, int *max) {}
void histogramme(int *tab, int taille, int *histo, int tailleH, int min) {}
void triDenombrement(int *tab, int taille) {}