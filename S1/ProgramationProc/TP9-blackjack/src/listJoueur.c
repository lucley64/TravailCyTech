#include "listJoueur.h"

#include <stdlib.h>

void initListJoueur(listJoueur *joueurs)
{
    ItemJoueur *croupier = (ItemJoueur *)malloc(sizeof(ItemJoueur));

    croupier->value.name = "Croupier";
    croupier->value.etat = CROUPIER;
    croupier->next = croupier + 1;
    creerListeCarte(&croupier->value.hand);

    joueurs->first = croupier;
    joueurs->last = croupier + 1;
}

void ajouterAvantJoueur(listJoueur *joueurs, Joueur j)
{
    ItemJoueur *item = (ItemJoueur *)malloc(sizeof(ItemJoueur));

    item->value = j;

    item->next = joueurs->first;
    joueurs->first->prev = item;
    joueurs->first = item;
}

void ajouterApresJoueur(listJoueur *joueurs, Joueur j)
{
    ItemJoueur *item = (ItemJoueur *)malloc(sizeof(ItemJoueur));

    item->value = j;

    item->prev = joueurs->last;
    joueurs->last->next = item;
    joueurs->last = item;
}

Joueur enleverAvantJoueur(listJoueur *joueurs)
{
    ItemJoueur *item = joueurs->first;
    Joueur j;

    joueurs->first = item->next;
    joueurs->first->prev = NULL;

    j = item->value;

    free(item);

    return j;
}

Joueur enleverApresJoueur(listJoueur *joueurs)
{
    ItemJoueur *item = joueurs->last;
    Joueur j;

    joueurs->last = item->prev;
    joueurs->last->next = NULL;

    j = item->value;

    free(item);

    return j;
}

int listJoueurSize(const listJoueur *joueurs)
{
    ItemJoueur *item = joueurs->first;
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
        *tabJoueur = (Joueur *)malloc(sizeof(Joueur) * *taille);
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
    for (int i = 0; i < taille; i++)
    {
        ajouterApresJoueur(joueurs, (*tabJoueur)[i]);
    }
    free(*tabJoueur);
}

void changerEtatJoueur(Joueur *joueur)
{
    const sCarte *as;
    const sCarte *buche;
    ItemCarte *carte;
    int int_valeur;

    as = NULL;
    buche = NULL;
    if (listCarteSize(&joueur->hand) == 2)
    {
        carte = joueur->hand.first;

        while (carte != joueur->hand.last)
        {
            switch (carte->value.carte)
            {
            case AS:
                as = &carte->value;
                break;
            case DIX:
            case VALET:
            case DAME:
            case ROI:
                buche = &carte->value;
                break;
            default:
                break;
            }

            carte = carte->next;
        }
        if (as != NULL && buche != NULL)
        {
            joueur->etat = BLACKJACK;
        }
    }
    else
    {
        int_valeur = getValeurTotale(&joueur->hand);
        if (int_valeur > 21)
        {
            joueur->etat = DEPASSE;
        }
        else if (int_valeur == 21)
        {
            joueur->etat = VINGT_ET_UN;
        }
    }
}

char *getEtatJoueur(const Joueur *joueur)
{
    switch (joueur->etat)
    {
    case BLACKJACK:
        return "Blackjack";
        break;
    case VINGT_ET_UN:
        return "21";
        break;
    case DEPASSE:
        return "Depassé";
        break;
    case DESSOUS:
        return "Dessous";
        break;
    case CROUPIER:
        return "Crouper";
        break;
    default:
        break;
    }

    return NULL;
}

EtatJoueur getEtatCroupier(const Joueur *croupier)
{
    const sCarte *as;
    const sCarte *buche;

    ItemCarte *carte;

    as = NULL;
    buche = NULL;
    if (listCarteSize(&croupier->hand) == 2)
    {
        carte = croupier->hand.first;
        while (carte != croupier->hand.last)
        {
            switch (carte->value.carte)
            {
            case AS:
                as = &carte->value;
                break;
            case DIX:
            case VALET:
            case DAME:
            case ROI:
                buche = &carte->value;
                break;
            default:
                break;
            }

            carte = carte->next;
        }
        if (as != NULL && buche != NULL)
        {
            return BLACKJACK;
        }
        else
        {
            return DESSOUS;
        }
    }
    else if (getValeurTotale(&croupier->hand) > 21)
    {
        return DEPASSE;
    }
    else if (getValeurTotale(&croupier->hand) < 21)
    {
        return DESSOUS;
    }
    else if (getValeurTotale(&croupier->hand) == 21)
    {
        return VINGT_ET_UN;
    }
    return DESSOUS;
}
