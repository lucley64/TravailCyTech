#include "interface.h"

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

char *demanderNom()
{
    char *str_nom;
    size_t size_size;

    size_size = 0;

    printf("Veuillez saisir votre nom : \n");
    getline(&str_nom, &size_size, stdin);

    for (size_t i = 0; i < size_size; i++)
    {
        if (str_nom[i] == '\n')
        {
            str_nom[i] = '\0';
            break;
        }
    }

    return str_nom;
}

int demanderMise(const char *nom)
{
    char *str_mise;
    size_t size_size;
    long int int_mise;

    size_size = 0;

    printf("%s veuillez saisir votre mise : ", nom);
    getline(&str_mise, &size_size, stdin);
    for (size_t i = 0; i < size_size; i++)
    {
        if (str_mise[i] == '\n')
        {
            str_mise[i] = '\0';
            break;
        }
    }

    int_mise = strtol(str_mise, NULL, 0);

    if (errno == EINVAL)
    {
        printf("Erreur la mise saisie est invalide.\n");
        exit(EXIT_FAILURE);
    }

    return (int)int_mise;
}

int demanderContinuer()
{
    char char_choix;
    int int_verif;
    printf("Continuer de jouer ? [O/n]\n");

    int_verif = scanf("%c", &char_choix);

    if (int_verif == 0 || char_choix == 'n' || char_choix == 'N')
    {
        while (char_choix != '\n')
        {
            scanf("%c", &char_choix);
        }
        return (0);
    }
    else
    {
        while (char_choix != '\n')
        {
            scanf("%c", &char_choix);
        }
        return (1);
    }
}

int continuer()
{
    char char_choix;
    int int_verif;
    int int_choix;
    printf("Carte ? [O/n]\n");

    int_verif = scanf("%c", &char_choix);

    if (int_verif == 0 || char_choix == 'n' || char_choix == 'N')
    {
        int_choix = 0;
    }
    else
    {
        int_choix = 1;
    }

    while (char_choix != '\n')
    {
        scanf("%c", &char_choix);
    }

    return int_choix;
}

void annoncerCartes(const ListCarte *cartes)
{
    ItemCarte *carte;

    printf("Voici vos cartes \n");

    carte = cartes->first;

    printf("%s de %s", getValeurCarte(&carte->value), getCouleurCarte(&carte->value));
    carte = carte->next;
    while (carte != cartes->last)
    {
        printf(", %s de %s", getValeurCarte(&carte->value), getCouleurCarte(&carte->value));
        carte = carte->next;
    }
    printf("\n");
    sleep(1);
}

void annoncerTour(const char *nom)
{
    printf("%s, C'est votre tour de tirer vos cartes.\n", nom);
    sleep(1);
}

void annoncerEtat(const Joueur *joueur)
{
    switch (joueur->etat)
    {
    case DEPASSE:
        printf("Vous avez depassé 21\n");
        break;
    case DESSOUS:
        printf("Vous êtes en dessous de 21\n");
        break;
    case VINGT_ET_UN:
        printf("Vous avez fait 21\n");
        break;
    case BLACKJACK:
        printf("Vous avez fait blackjack\n");
        break;
    default:
        break;
    }
    sleep(1);
}

void annoncerScore(const Joueur *joueur)
{
    printf("%s Votre score est de %i\n", joueur->name, joueur->score);
    sleep(1);
}

void annoncerCartesToutLeMonde(const listJoueur *joueurs)
{
    ItemJoueur *joueur;

    joueur = joueurs->first;

    printf("Voici les cartes en jeu : \n");

    while (joueur != joueurs->last)
    {
        printf("%s : \n", joueur->value.name);
        annoncerCartes(&joueur->value.hand);
        joueur = joueur->next;
    }
    sleep(1);
}

void annoncerEtatJeu(const char *nomJoueur, EtatDeJeu etat)
{
    switch (etat)
    {
    case SAUTE:
        printf("%s, Vous avez sauté\n", nomJoueur);
        break;
    case REMPORTE:
        printf("%s, Vous avez remporté votre mise\n", nomJoueur);
        break;
    case EGALITE:
        printf("%s, Vous avez fait égalité\n", nomJoueur);
        break;
    case BATU:
        printf("%s, Vous avez été batu \n", nomJoueur);
        break;
    case ETAT_BLACKJACK:
        printf("%s, Vous avez fait blackjacks\n", nomJoueur);
        break;
    default:
        break;
    }
    sleep(1);
}
