#include "listeCarte.h"

#include <stdlib.h>

void creerListe(ListCarte *list)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    list->first = itemCarte;
    list->last = itemCarte;
    list->first->next = list->last;
    list->last->prev = list->first;
}

void ajouterAvant(ListCarte *list, sCarte item)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    itemCarte->value = item;
    // if (list->first->value == 0)
    // {
    //     free(list->first);
    //     list->first = itemCarte;
    //     list->last = itemCarte;
    //     itemCarte->next = list->last;
    //     itemCarte->prev = list->first;
    // }
    // else
    // {
        itemCarte->next = list->first;
        itemCarte->next->prev = itemCarte;
        list->first = itemCarte;
    // }
}

void ajouterApres(ListCarte *list, sCarte item)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    itemCarte->value = item;
    // if (list->last->value == 0)
    // {
    //     free(list->last);
    //     list->last = itemCarte;
    //     list->first = itemCarte;
    //     itemCarte->prev = list->first;
    //     itemCarte->next = list->last;
    // }
    // else
    // {
        itemCarte->prev = list->last;
        list->last->next = itemCarte;
        list->last = itemCarte;
    // }
}

sCarte enleverAvant(ListCarte *list)
{
    ItemCarte *itemCarte = list->first;
    list->first = itemCarte->next;

    sCarte item = itemCarte->value;

    free(itemCarte);

    return item;
}

sCarte enleverApres(ListCarte *list)
{
    ItemCarte *itemCarte = list->last;
    list->last = itemCarte->prev;

    sCarte item = itemCarte->value;

    free(itemCarte);

    return item;
}

int listSize(const ListCarte *list)
{
    ItemCarte *itemCarte = list->first;
    int size = 0;

    while (itemCarte != list->last)
    {
        size++;
        itemCarte = itemCarte->next;
    }
    return size + 1;
}

void listToArray(ListCarte *list, sCarte **tabCarte, int *size)
{
    sCarte elem;

    *size = listSize(list);
    if (*size > 0)
    {
        *tabCarte = malloc(sizeof(sCarte) * *size);
        for (int i = 0; i < *size; i++)
        {
            elem = enleverApres(list);
            (*tabCarte)[i] = elem;
        }
    }
}

void arrayToList(ListCarte *list, sCarte **tabCarte, int size)
{
    creerListe(list);
    for (int i = 0; i < size; i++)
    {
        ajouterApres(list, (*tabCarte)[i]);
    }
    free(*tabCarte);
}
