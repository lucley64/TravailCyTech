/**
    @file listeCarte.c
    @author Luc Leydert
    @brief 
    @version 0.1
    @date 24/12/2022
    
    @copyright Copyright (c) 2022
    
 */
#include "listeCarte.h"

#include <stdlib.h>

void creerListeCarte(ListCarte *list)
{
    ItemCarte *ite_itemCarte; // Premier item de la liste

    ite_itemCarte = malloc(sizeof(ItemCarte));

    list->first = ite_itemCarte;
    list->last = ite_itemCarte + 1;
    list->first->next = list->last;
}

void ajouterAvantCarte(ListCarte *list, sCarte item)
{
    ItemCarte *ite_itemCarte; // Un nouvel item de la liste

    ite_itemCarte = malloc(sizeof(ItemCarte));

    ite_itemCarte->value = item;
    if (list->first->value.carte == 0)
    {
        free(list->first);
        list->first = ite_itemCarte;
        list->last = ite_itemCarte + 1;
        ite_itemCarte->next = list->last;
        ite_itemCarte->prev = list->first;
    }
    else
    {
        ite_itemCarte->next = list->first;
        ite_itemCarte->next->prev = ite_itemCarte;
        list->first = ite_itemCarte;
    }
}

void ajouterApresCarte(ListCarte *list, sCarte item)
{
    ItemCarte *ite_itemCarte; // un nouvel item de la list

    ite_itemCarte = malloc(sizeof(ItemCarte));

    ite_itemCarte->value = item;
    if (list->first->value.carte == 0)
    {
        free(list->first);
        list->last = ite_itemCarte + 1;
        list->first = ite_itemCarte;
        ite_itemCarte->prev = list->first;
        ite_itemCarte->next = list->last;
    }
    else
    {
        ite_itemCarte->prev = list->last - 1;
        (list->last - 1)->next = ite_itemCarte;
        list->last = ite_itemCarte + 1;
        ite_itemCarte->next = list->last;
    }
}

sCarte enleverAvantCarte(ListCarte *list)
{
    ItemCarte *ite_itemCarte; // L'item à retirer
    sCarte carte_item; // La carte retirée

    ite_itemCarte = list->first;

    list->first = ite_itemCarte->next;

    carte_item = ite_itemCarte->value;

    free(ite_itemCarte);

    return (carte_item);
}

sCarte enleverApresCarte(ListCarte *list)
{
    ItemCarte *ite_itemCarte; // L'item à retirer
    sCarte carte_item; // La carte retirée

    ite_itemCarte = list->last - 1;

    list->last = ite_itemCarte->prev + 1;

    carte_item = ite_itemCarte->value;

    free(ite_itemCarte);

    return (carte_item);
}

int listCarteSize(const ListCarte *list)
{
    ItemCarte *ite_itemCarte; // Iterateur sur les cartes
    ite_itemCarte = list->first;
    int size = 0;

    while (ite_itemCarte != list->last)
    {
        size++;
        ite_itemCarte = ite_itemCarte->next;
    }
    return (size);
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
    int int_valeur; // La valeur totale
    ItemCarte *ite_carte; // Iterateur sur les cartes

    ite_carte = cartes->first;
    int_valeur = 0;

    while (ite_carte != cartes->last)
    {
        if (ite_carte->value.carte == VALET || ite_carte->value.carte == DAME || ite_carte->value.carte == ROI)
        {
            int_valeur += 10;
        }
        else
        {
            int_valeur += ite_carte->value.carte;
        }

        ite_carte = ite_carte->next;
    }

    return (int_valeur);
}

char *getValeurCarte(const sCarte *carte)
{

    switch (carte->carte)
    {
    case AS:
        return ("AS");
        break;
    case DEUX:
        return ("DEUX");
        break;
    case TROIS:
        return ("TROIS");
        break;
    case QUATRE:
        return ("QUATRE");
        break;
    case CINQ:
        return ("CINQ");
        break;
    case SIX:
        return ("SIX");
        break;
    case SEPT:
        return ("SEPT");
        break;
    case HUIT:
        return ("HUIT");
        break;
    case NEUF:
        return ("NEUF");
        break;
    case DIX:
        return ("DIX");
        break;
    case VALET:
        return ("VALET");
        break;
    case DAME:
        return ("DAME");
        break;
    case ROI:
        return ("ROI");
        break;
    default:
        break;
    }

    return (NULL);
}

char *getCouleurCarte(const sCarte *carte)
{
    switch (carte->carte_color)
    {
    case PIQUE:
        return ("PIQUE");
        break;
    case COEUR:
        return ("COEUR");
        break;
    case TREFLE:
        return ("TREFLE");
        break;
    case CARREAU:
        return ("CARREAU");
        break;
    default:
        break;
    }
    return (NULL);
}
