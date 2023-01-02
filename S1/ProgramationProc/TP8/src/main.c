/**
 \file main.c
 \author Luc Leydert
 \brief
 \version 0.1
 \date 07/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "codage.h"

/**
 \brief Affiche l'aide pour l'utilisation
 \
 */
void printHelp();

void getArgs(char **str_methode, char **str_decal, char **str_cle, char **str_message, int argc, const char **argv);

/**
 \brief Main corresondant au tp8 et 9
 \
 \param argc compte d'arguments
 \param argv tableau des arguments
 \return int 0 si tout c'est bien passé
 */
int main(int argc, char const *argv[])
{
    char *str_methode = NULL; // Le nom de la méthode à utiliser
    char *str_decal = NULL;   // Nombre de décalage pour la méthode cesar
    char *str_cle = NULL;     // La clé à utiliser pour la méthode vigene
    char *str_message = NULL; // Le message à encoder

    // Vérifi si l'utilisateur à besoin d'aide
    if (argc < 2 || !strcmp(argv[1], "--help"))
    {
        printHelp();
    }
    else
    {
        // Récupère les différents arguments
        getArgs(&str_methode, &str_decal, &str_cle, &str_message, argc, argv);

        if (str_message == NULL)
        {
            str_message = askMessage();
        }

        // Évalu les arguments saisits et détérmine la fonction à executer
        if (str_methode == NULL)
        {
            printHelp();
        }
        else if (!strcmp(str_methode, "cesar"))
        {
            cesar(str_decal, str_message);
        }
        else if (!strcmp(str_methode, "vigene"))
        {
            vigene(str_cle, str_message);
        }
        else if (!strcmp(str_methode, "scytale"))
        {
            scytale(&str_message);
        }
        else
        {
            printHelp();
        }
    }

    printf("Le Méssage encodé avec la méthode de %s donne : %s\n", str_methode, str_message);

    // Libère la memoire aloué aux chaines de caractères
    if (str_methode != NULL)
    {
        free(str_methode);
    }
    if (str_decal != NULL)
    {
        free(str_decal);
    }
    if (str_cle != NULL)
    {
        free(str_cle);
    }
    if (str_message != NULL)
    {
        free(str_message);
    }

    return (0);
}

void printHelp()
{
    printf("Usage: \n %s \n %s \n %s \n %s \n %s \n",
           "--help : affiche ceci",
           "-c <nom_methode> : méthode de chiffrement (cesar, vigene, scytale)",
           "-d <decalage> : valeur du décalage, uniquement pour le chiffrement de César",
           "-k <cle> : mot clé, uniquement pour le chiffrement de Vigenère",
           "-m <message> : message à chiffrer");
}

void getArgs(char **str_methode, char **str_decal, char **str_cle, char **str_message, int argc, const char **argv)
{
    for (int int_i = 0; int_i < argc - 1; int_i++)
    {
        if (argv[int_i] != NULL && !strcmp(argv[int_i], "-c") && argv[int_i + 1] != NULL)
        {
            *str_methode = strdup(argv[int_i + 1]);
        }
        else if (argv[int_i] != NULL && !strcmp(argv[int_i], "-d") && argv[int_i + 1] != NULL)
        {
            *str_decal = strdup(argv[int_i + 1]);
        }
        else if (argv[int_i] != NULL && !strcmp(argv[int_i], "-k") && argv[int_i + 1] != NULL)
        {
            *str_cle = strdup(argv[int_i + 1]);
        }
        else if (argv[int_i] != NULL && !strcmp(argv[int_i], "-m") && argv[int_i + 1] != NULL)
        {
            *str_message = strdup(argv[int_i + 1]);
        }
    }
}
