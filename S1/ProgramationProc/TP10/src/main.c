/**
    @file main.c
    @author Luc Leydert
    @brief
    @version 0.1
    @date 06/01/2023

    @copyright Copyright (c) 2023

 */
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <math.h>

#include "types/restaurant.h"

int getNbLines(FILE *file);
Restaurant parseRestaurant(char *restaurant);
Adresse parseAdresse(char *adresse);
void getRestoFromFile(const char *fileName, Restaurant **restos, size_t *size);
int getMethod();
void restoPau(Restaurant *restaurants, size_t size, const char *path);
void restoPaCher(const Restaurant *restaurants, size_t size, const char *path);
void restruct(const Restaurant *restaurants, size_t size, const char *path);
char *restorantToCSV(const Restaurant *restaurant);
void freeResto(Restaurant **resto, size_t size);

int main(int argc, char *argv[])
{
    Restaurant *restos;
    const char *dir;
    size_t size;

    if (argv[1] != NULL)
    {
        getRestoFromFile(argv[1], &restos, &size);
        dir = dirname(argv[1]);
        switch (getMethod())
        {
        case 1:
            printf("Restaurants à Pau\n");
            restoPau(restos, size, dir);
            break;
        case 2:
            printf("Restaurants pas trop cher\n");
            restoPaCher(restos, size, dir);
            break;
        case 3:
            printf("Restructurer le fichier\n");
            restruct(restos, size, dir);
            break;
        default:
            break;
        }
        // free(restos);
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    return (0);
}

int getNbLines(FILE *file)
{
    int nb_lines = 0;
    char *buf = NULL;
    size_t size;
    while (getline(&buf, &size, file) != -1)
    {
        nb_lines++;
    }
    return nb_lines;
}

Restaurant parseRestaurant(char *restaurant)
{
    Restaurant resto;
    char *ptr;

    ptr = strtok_r(restaurant, ";", &restaurant);
    resto.str_nom = malloc(strlen(ptr));
    memcpy(resto.str_nom, ptr, strlen(ptr));
    ptr = strtok_r(restaurant, ";", &restaurant);
    resto.adresse = parseAdresse(ptr);
    ptr = strtok_r(restaurant, ";", &restaurant);
    resto.int_prix = atoi(ptr);
    ptr = strtok_r(restaurant, ";", &restaurant);
    resto.dbl_note = strtod(ptr, NULL);

    return resto;
}

Adresse parseAdresse(char *adresse)
{
    Adresse adr;
    char const *ptr = adresse;

    if (!(ptr[0] - '0' < 0 || ptr[0] - '0' > 9))
    {
        ptr = strtok_r(adresse, " ", &adresse);
        adr.numero = malloc(strlen(ptr));
        memcpy(adr.numero, ptr, strlen(ptr));
    }
    else if (!strcmp(ptr, "Adresse"))
    {
        adr.nom = malloc(strlen(ptr));
        memcpy(adr.nom, ptr, strlen(ptr));
        return adr;
    }
    else
    {
        adr.numero = malloc(1);
        adr.numero = "";
    }
    ptr = strtok_r(adresse, ",", &adresse);
    adr.nom = malloc(strlen(ptr));
    memcpy(adr.nom, ptr, strlen(ptr));
    ptr = strtok_r(adresse, " ", &adresse);
    adr.codePostal = malloc(strlen(ptr));
    memcpy(adr.codePostal, ptr, strlen(ptr));
    ptr = strtok_r(adresse, " ", &adresse);
    adr.ville = malloc(strlen(ptr));
    memcpy(adr.ville, ptr, strlen(ptr));

    return adr;
}

void getRestoFromFile(const char *fileName, Restaurant **restos, size_t *size)
{
    FILE *file;
    char *buf = NULL;
    size_t lsize;
    int nbLines;
    *restos = NULL;
    size_t i;
    file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Can't open file\n");
    }
    else
    {
        nbLines = getNbLines(file);
        fseek(file, 0, SEEK_SET);
        if (nbLines > 0)
        {
            *size = nbLines;
            *restos = malloc(nbLines * sizeof(Restaurant));
            i = 0;
            while (getline(&buf, &lsize, file) != -1 && i < nbLines)
            {
                (*restos)[i] = parseRestaurant(buf);
                i++;
            }
        }
        fclose(file);
    }
}

int getMethod()
{
    int method = 0;
    int intVerif;
    char charVerif;

    printf("Voici les differentes possibilités : \n%s\n%s\n%s\n",
           "1 - Restaurants à Pau",
           "2 - Restaurants pas trop cher",
           "3 - Restructurer le fichier");

    intVerif = scanf("%d", &method);
    scanf("%c", &charVerif);
    while (intVerif == 0 || charVerif != '\n' || method <= 0 || method > 3)
    {
        printf("Veuillez entrer quelque chose de valide\n");
        while (charVerif != '\n')
        {
            scanf("%c", &charVerif);
        }
        intVerif = scanf("%d", &method);
    }

    return method;
}

void restoPau(Restaurant *restaurant, size_t size, const char *path)
{
    char *filename;
    FILE *file;
    char *csv;

    filename = malloc(strlen(path) + strlen("/resto-pau.csv"));

    sprintf(filename, "%s/resto-pau.csv", path);

    file = fopen(filename, "w+");

    free(filename);

    if (file == NULL)
    {
        printf("Can't open file\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            if (!strcmp(restaurant[i].adresse.ville, "Pau"))
            {
                csv = restorantToCSV(&(restaurant[i]));
                fprintf(file, "%s\n", csv);
                free(csv);
            }
        }
        fclose(file);
    }
    freeResto(&restaurant, size);
}

void restoPaCher(const Restaurant *restaurant, size_t size, const char *path)
{
}

void restruct(const Restaurant *restaurant, size_t size, const char *path)
{
}

char *restorantToCSV(const Restaurant *restaurant)
{
    char *ret;

    char *prix;
    char *note;
    size_t len;

    len = (size_t)((ceil(log10(restaurant->int_prix)) + 1));

    prix = malloc(len);
    sprintf(prix, "%d", restaurant->int_prix);

    len = 3;
    note = malloc(len);
    sprintf(note, "%f", restaurant->dbl_note);

    ret = malloc(sizeof(char) * (strlen(restaurant->str_nom) +
                                 strlen(restaurant->adresse.codePostal) +
                                 strlen(restaurant->adresse.nom) +
                                 strlen(restaurant->adresse.numero) +
                                 strlen(restaurant->adresse.ville) +
                                 strlen(prix) +
                                 strlen(note) +
                                 strlen("; ,  ;;")));

    sprintf(ret, "%s;%s %s, %s %s;%s;%s",
            restaurant->str_nom,
            restaurant->adresse.numero,
            restaurant->adresse.nom,
            restaurant->adresse.codePostal,
            restaurant->adresse.ville,
            prix,
            note);

    free(prix);
    free(note);

    return ret;
}

void freeResto(Restaurant **rest, size_t sizeo)
{
    Restaurant *restaurant;
    for (size_t i = 1; i < sizeo; i++)
    {
        restaurant = &(*rest)[i];
        free(restaurant->adresse.codePostal);
        free(restaurant->adresse.nom);
        if (restaurant->adresse.numero != NULL)
            free(restaurant->adresse.numero);
        free(restaurant->adresse.ville);
        free(restaurant->str_nom);
    }
    free(*rest);
}
