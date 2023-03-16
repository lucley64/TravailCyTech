/**
 \file pointeurs.c
 \author Luc Leydert
 \brief
 \version 0.1
 \date 30/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include <stdio.h>

#include "pointeurs.h"

void exerciceInutile()
{
    int int_i;
    int *pint_p;

    int_i = 69;
    pint_p = &int_i;

    printf("Valeur de i = %i.\n", int_i);

    *pint_p = 42;

    printf("Nouvelle valeur de i = %i.\n", int_i);
}

void pointeurDePointeur()
{
    /*
        Ma Réponse :
            a = 1
            b = 1
            p = addresse de a
            pp = addresse de p
    */
    int int_a;
    int int_b;
    int *pint_p;
    int **ppint_pp;

    int_a = 0;
    int_b = 1;
    pint_p = &int_a;
    int_a += int_b;
    ppint_pp = &pint_p;

    printf("Addresse de a : %p, a = %i\n", &int_a, int_a);
    printf("Addresse de b : %p, b = %i\n", &int_b, int_b);
    printf("Addresse de p : %p, p = %p\n", &pint_p, pint_p);
    printf("Addresse de pp : %p, pp = %p\n", &ppint_pp, ppint_pp);
}

void pointeurSurTableau()
{
    /*
        Ma Réponse :
            1. *p+2                 = tab[2] + 2 = 14 + 2 = 16
            2. *(p+2)               = tab[4]     = 56
            3. tab+3                = &tab[3]    = addresse de tab[3]
            4. &tab[7]-&tab[1]      = la taille entre tab[7] et tab[1] = 6
            5. &tab[7]-p            = la taille entre tab[7] et tab[2] = 5
            6. p+(*p-10)            = &tab[0] + (14 - 10) = &tab[0] + 4 = &tab[6]
            7. *(p+*(p+6)-tab[7])   = *(p+*(&tab[2]+6)-tab[7]) = *(p+*(&tab[8])-tab[7]) = *(p+tab[8]-tab[7]) = *(p+89-92) = tab[5] = 67
    */

    int tint_tab[] = {12, 23, 14, 45, 56, 67, 78, 89, 92};
    int *pint_p;

    pint_p = &tint_tab[2];

    printf("Addresse de tab : %p, tab = {12, 23, 14, 45, 56, 67, 78, 89, 92}\n", &tint_tab);
    printf("Addresse de p : %p, p = %p\n", &pint_p, pint_p);

    printf("1. *p+2                 = %i\n", *pint_p + 2);
    printf("2. *(p+2)               = %i\n", *(pint_p + 2));
    printf("3. tab+3                = %p    , addresse de tab[3] = %p\n", tint_tab + 3, &tint_tab[3]);
    printf("4. &tab[7]-&tab[1]      = %li\n", &tint_tab[7] - &tint_tab[1]);
    printf("5. &tab[7]-p            = %li\n", &tint_tab[7] - pint_p);
    printf("6. p+(*p-10)            = %p    , addresse de tab[6] = %p\n", pint_p + (*pint_p - 10), &tint_tab[6]);
    printf("7. *(p+*(p+6)-tab[7])   = %i\n", *(pint_p + *(pint_p + 6) - tint_tab[7]));
}

void unPeutMoinsFacile()
{
    int tint_tab[10] = {42, 69, 24, 0, 99, 0, 15, 0, 0, 22};

    for (const int *int_i = tint_tab; int_i <= tint_tab + 9; int_i++)
    {
        if (*int_i != 0)
        {
            printf("Indice : %li\n", int_i - tint_tab);
        }
    }
}