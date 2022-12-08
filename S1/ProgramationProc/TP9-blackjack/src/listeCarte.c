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

void ajouterAvant(ListCarte *list, Carte item)
{
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    itemCarte->value = item;
    itemCarte->next = list->first;
    itemCarte->next->prev = itemCarte;
    list->first = itemCarte;
}

void ajouterApres(ListCarte* list, Carte item){
    ItemCarte *itemCarte = malloc(sizeof(ItemCarte));

    itemCarte->value = item;
    itemCarte->prev = list->last;
    list->last->next = itemCarte;
    list->last = itemCarte;
}

Carte enleverAvant(ListCarte* list){
    ItemCarte* itemCarte = list->first;
    list->first = itemCarte->next;

    Carte item = itemCarte->value;

    free(itemCarte);

    return item;
}

Carte enleverApres(ListCarte* list){
    ItemCarte* itemCarte = list->last;
    list->last = itemCarte->prev;

    Carte item = itemCarte->value;

    free(itemCarte);

    return item;
}