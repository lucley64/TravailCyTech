#include "listeCarte.h"

#include <stdlib.h>

void creerListeCarte(ListCarte *list)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    list->first = itemCarte;
    list->last = itemCarte + 1;
    list->first->next = list->last;
}

void ajouterAvantCarte(ListCarte *list, sCarte item)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    itemCarte->value = item;
    if (list->first->value.carte == 0)
    {
        free(list->first);
        list->first = itemCarte;
        list->last = itemCarte + 1;
        itemCarte->next = list->last;
        itemCarte->prev = list->first;
    }
    else
    {
        itemCarte->next = list->first;
        itemCarte->next->prev = itemCarte;
        list->first = itemCarte;
    }
}

void ajouterApresCarte(ListCarte *list, sCarte item)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    itemCarte->value = item;
    if (list->first->value.carte == 0)
    {
        free(list->first);
        list->last = itemCarte + 1;
        list->first = itemCarte;
        itemCarte->prev = list->first;
        itemCarte->next = list->last;
    }
    else
    {
        itemCarte->prev = list->last - 1;
        (list->last - 1)->next = itemCarte;
        list->last = itemCarte + 1;
        itemCarte->next = list->last;
    }
}

sCarte enleverAvantCarte(ListCarte *list)
{
    ItemCarte *itemCarte = list->first;
    list->first = itemCarte->next;

    sCarte item = itemCarte->value;

    free(itemCarte);

    return item;
}

sCarte enleverApresCarte(ListCarte *list)
{
    ItemCarte *itemCarte = list->last - 1;
    list->last = itemCarte->prev + 1;

    sCarte item = itemCarte->value;

    free(itemCarte);

    return item;
}

int listCarteSize(const ListCarte *list)
{
    ItemCarte *itemCarte = list->first;
    int size = 0;

    while (itemCarte != list->last)
    {
        size++;
        itemCarte = itemCarte->next;
    }
    return size;
}

void listCarteToArray(ListCarte *list, sCarte **tabCarte, int *size)
{
    sCarte elem;

    *size = listCarteSize(list);
    if (*size > 0)
    {
        *tabCarte = malloc(sizeof(sCarte) * *size);
        for (int i = 0; i < *size; i++)
        {
            elem = enleverApresCarte(list);
            (*tabCarte)[i] = elem;
        }
    }
}

void arrayToListCarte(ListCarte *list, sCarte **tabCarte, int size)
{
    creerListeCarte(list);
    for (int i = 0; i < size; i++)
    {
        ajouterApresCarte(list, (*tabCarte)[i]);
    }
    free(*tabCarte);
}

int getValeurTotale(const ListCarte *cartes)
{
    int valeur;
    ItemCarte *carte;

    carte = cartes->first;
    valeur = 0;

    while (carte != cartes->last)
    {
        if (carte->value.carte == VALET || carte->value.carte == DAME || carte->value.carte == ROI)
        {
            valeur += 10;
        }
        else
        {
            valeur += carte->value.carte;
        }

        carte = carte->next;
    }

    return valeur;
}

char *getValeurCarte(const sCarte *carte)
{

    switch (carte->carte)
    {
    case AS:
        return "AS";
        break;
    case DEUX:
        return "DEUX";
        break;
    case TROIS:
        return "TROIS";
        break;
    case QUATRE:
        return "QUATRE";
        break;
    case CINQ:
        return "CINQ";
        break;
    case SIX:
        return "SIX";
        break;
    case SEPT:
        return "SEPT";
        break;
    case HUIT:
        return "HUIT";
        break;
    case NEUF:
        return "NEUF";
        break;
    case DIX:
        return "DIX";
        break;
    case VALET:
        return "VALET";
        break;
    case DAME:
        return "DAME";
        break;
    case ROI:
        return "ROI";
        break;
    default:
        break;
    }

    return NULL;
}

char *getCouleurCarte(const sCarte *carte)
{
    switch (carte->carte_color)
    {
    case PIQUE:
        return "PIQUE";
        break;
    case COEUR:
        return "COEUR";
        break;
    case TREFLE:
        return "TREFLE";
        break;
    case CARREAU:
        return "CARREAU";
        break;
    default:
        break;
    }
    return NULL;
}
