#include "listJoueur.h"

#include <stdlib.h>

void initListJoueur(listJoueur *joueurs)
{
    itemJoueur *croupier = (itemJoueur *)malloc(sizeof(itemJoueur));

    croupier->value.name = "Croupier";

    joueurs->first = croupier;
    joueurs->last = croupier;
}

void ajouterAvantJoueur(listJoueur *joueurs, Joueur j)
{
    itemJoueur *item = (itemJoueur *)malloc(sizeof(itemJoueur));

    item->value = j;

    item->next = joueurs->first;
    joueurs->first->prev = item;
    joueurs->first = item;
}

void ajouterApresJoueur(listJoueur *joueurs, Joueur j)
{
    itemJoueur *item = (itemJoueur *)malloc(sizeof(itemJoueur));

    item->value = j;

    item->prev = joueurs->last;
    joueurs->last->next = item;
    joueurs->last = item;
}

Joueur enleverAvantJoueur(listJoueur *joueurs)
{
    itemJoueur *item = joueurs->first;
    Joueur j;

    joueurs->first = item->next;
    joueurs->first->prev = NULL;

    j = item->value;

    free(item);

    return j;
}

Joueur enleverApresJoueur(listJoueur *joueurs)
{
    itemJoueur *item = joueurs->last;
    Joueur j;

    joueurs->last = item->prev;
    joueurs->last->next = NULL;

    j = item->value;

    free(item);

    return j;
}

int listJoueurSize(const listJoueur *joueurs)
{
    itemJoueur *item = joueurs->first;
    int size = 1;

    while (item != joueurs->last)
    {
        size++;
        item = item->next;
    }

    return size;
}

void listJoueurToArray(listJoueur *joueurs, Joueur **tabJoueur, int *taille)
{
    Joueur j;

    *taille = listJoueurSize(joueurs);

    if (*taille > 0)
    {
        *tabJoueur = (itemJoueur *)malloc(sizeof(itemJoueur) * *taille);
        for (int i = 0; i < *taille; i++)
        {
            j = enleverApresJoueur(joueurs);
            (*tabJoueur)[i] = j;
        }
    }
}

void arrayToListJoueur(listJoueur *joueurs, Joueur **tabJoueur, int taille)
{
    initListJoueur(joueurs);
    for(int i = 0; i < taille; i++){
        ajouterApresJoueur(joueurs, (*tabJoueur)[i]);
    }
    free(*tabJoueur);
}
