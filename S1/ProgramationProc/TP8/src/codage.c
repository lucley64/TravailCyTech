/**
 \file codage.c
 \author Luc Leydert
 \brief
 \version 0.1
 \date 07/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include "codage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

/**
 \brief Demande à l'utilisateur le décalage
 \
 \return int Le décalage saisit
 */
int askDecal();

/**
 \brief Demande à l'utilisateur la clé
 \
 \return char* La clé saisie
 */
char *askCle();

/**
 \brief Éffectu le décalage de décal sur le chr
 \
 \param chr le caractère à décaler
 \param decal le nombre de fois quil faut décaler
 \return char le caractère une fois décalé
 */
char decalChar(char chr, int decal);

/**
 \brief Détermine la clé en int
 \
 \param cle La clé en chaine de char
 \return int* La clé en int
 */
void determinerCle(const char *cle, int *tint_cle, size_t *len);

void cesar(const char *decal, char *message)
{
    int int_decal; // Le nombre de fois qu'il faut décaler en int

    // Détermine le décalage
    if (decal == NULL)
    {
        int_decal = askDecal();
    }
    else
    {
        int_decal = atoi(decal);
    }

    // Éffectue le décalage
    for (size_t int_i = 0; int_i < strlen(message); int_i++)
    {
        message[int_i] = decalChar(message[int_i], int_decal);
    }
}

int askDecal()
{
    int int_decal;
    int int_verif;
    char char_verif;

    printf("Aucun décalage entré, veuillez entrez la valeur du décalage : ");
    int_verif = scanf("%d", &int_decal);
    scanf("%c", &char_verif);

    if (int_verif == 0 || char_verif != '\n')
    {
        do
        {
            scanf("%c", &char_verif);
        } while (char_verif != '\n');

        do
        {
            printf("Veuillez saisir une entrée valide.\n");
            int_verif = scanf("%d", &int_decal);
            scanf("%c", &char_verif);
        } while (int_verif == 0 || char_verif != '\n');
    }

    return int_decal;
}

char *askMessage()
{
    char *str_message = NULL;
    size_t int_size = 0;

    printf("Aucun message detécté, Veuillez entrer le message : \n");
    getline(&str_message, &int_size, stdin);

    for (int int_i = 0; int_i < int_size; int_i++)
    {
        if (str_message[int_i] == '\n')
        {
            str_message[int_i] = '\0';
            break;
        }
    }

    return str_message;
}

char *askCle()
{
    char *str_cle = NULL;
    size_t int_size = 0;

    printf("Aucune clé detécté, Veuillez entrer la clé : \n");
    getline(&str_cle, &int_size, stdin);

    for (int int_i = 0; int_i < int_size; int_i++)
    {
        if (str_cle[int_i] == '\n')
        {
            str_cle[int_i] = '\0';
            break;
        }
    }

    return str_cle;
}

char decalChar(char chr, int decal)
{
    if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z'))
    {
        if (isupper(chr))
        {
            chr = (chr - 'A' + decal) % ('Z' - 'A' + 1) + 'A';
        }
        else
        {
            chr = (chr - 'a' + decal) % ('z' - 'a' + 1) + 'a';
        }
    }
    return chr;
}

void determinerCle(const char *cle, int *tint_cle, size_t *len)
{
    *len = 0;

    for (size_t int_i = 0; int_i < strlen(cle); int_i++)
    {
        if ((cle[int_i] >= 'A' && cle[int_i] <= 'Z') || (cle[int_i] >= 'a' && cle[int_i] <= 'z'))
        {
            if (isupper(cle[int_i]))
            {
                tint_cle[int_i] = cle[int_i] - 'A';
            }
            else
            {
                tint_cle[int_i] = cle[int_i] - 'a';
            }
            *len += 1;
        }
    }
}

void vigene(const char *cle, char *message)
{
    int *tint_cle = NULL;
    size_t int_cleSize;

    if (cle == NULL)
    {
        cle = askCle();
    }

    tint_cle = malloc(strlen(cle) * sizeof(int));
    determinerCle(cle, tint_cle, &int_cleSize);

    for (size_t int_i = 0; int_i < strlen(message); int_i++)
    {
        if (int_cleSize > 0)
            message[int_i] = decalChar(message[int_i], tint_cle[int_i % int_cleSize]);
    }

    free(tint_cle);
}
void scytale(char **message)
{
    assert(*message != NULL && strlen(*message) > 0);
    size_t size_lenMessage;
    char **ttchar_tabMessage;
    size_t size_offset;

    size_lenMessage = strlen(*message);

    while (round(sqrt((double)size_lenMessage)) != sqrt((double)size_lenMessage))
    {
        size_lenMessage += 1;
    }

    size_offset = (size_t)sqrt((double)size_lenMessage);

    ttchar_tabMessage = (char **)malloc(size_offset * sizeof(char *));
    for (size_t i = 0; i < size_offset; i++)
    {
        ttchar_tabMessage[i] = (char *)malloc(size_offset * sizeof(char));
    }

    for (size_t i = 0; i < size_offset; i++)
    {
        for (size_t j = 0; j < size_offset; j++)
        {
            if (i * size_offset + j < strlen(*message))
            {
                ttchar_tabMessage[i][j] = (*message)[i * size_offset + j];
            }
            else{
                ttchar_tabMessage[i][j] = ' ';
            }
        }
    }

    free(*message);
    *message = (char *)malloc(sizeof(char) * size_lenMessage);

    for (size_t i = 0; i < size_offset; i++)
    {
        for (size_t j = 0; j < size_offset; j++)
        {
            (*message)[i * size_offset + j] = ttchar_tabMessage[j][i];
        }
    }
}