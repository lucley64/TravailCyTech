#include "jeu.h"

#include <string.h>
#include <stdbool.h>

#include "interface.h"

void distribuerCartes(Jeu *jeu);
void donnerCarte(Joueur *joueur, ListCarte *cartes);
Joueur creeJoueur();
int miser(Jeu *jeu);
void reinitialiserJeu(Jeu *jeu);
void distribuerScore(Jeu *jeu);
void deroulerPartie(Jeu *jeu);
void viderMain(Joueur *joueur, ListCarte *cartes);
void donnerCartes(Joueur *joueur, ListCarte *cartes);

void initialiserJeu(Jeu *jeu, int nbJoueur)
{
    Joueur joueur;

    jeu->cartes = *initCartes();
    melangerCartes(&jeu->cartes);
    initListJoueur(&jeu->listJoueur);

    for (int i = 0; i < nbJoueur; i++)
    {
        joueur = creeJoueur();
        ajouterAvantJoueur(&jeu->listJoueur, joueur);
    }
}

void gameLoop(Jeu *jeu)
{
    int continu;

    continu = 1;
    while (continu)
    {
        miser(jeu);

        distribuerCartes(jeu);

        deroulerPartie(jeu);

        distribuerScore(jeu);
        reinitialiserJeu(jeu);
        continu = demanderContinuer();
    }
}

void distribuerCartes(Jeu *jeu)
{
    ItemJoueur *joueur;

    joueur = jeu->listJoueur.first;
    while (joueur != jeu->listJoueur.last)
    {
        if (joueur->value.etat != CROUPIER)
        {
            donnerCarte(&joueur->value, &jeu->cartes);
            donnerCarte(&joueur->value, &jeu->cartes);
            joueur->value.etat = DESSOUS;
        }
        else
        {
            donnerCarte(&joueur->value, &jeu->cartes);
        }

        joueur = joueur->next;
    }
}

void donnerCarte(Joueur *joueur, ListCarte *cartes)
{
    sCarte carte;

    carte = enleverAvantCarte(cartes);

    ajouterAvantCarte(&joueur->hand, carte);
}

Joueur creeJoueur()
{
    Joueur joueur;

    joueur.name = demanderNom();
    creerListeCarte(&joueur.hand);
    joueur.score = 0;

    return joueur;
}

int miser(Jeu *jeu)
{
    int miseTotale;
    int mise;
    ItemJoueur *joueur;

    joueur = jeu->listJoueur.first;
    miseTotale = 0;
    while (joueur != jeu->listJoueur.last && joueur->value.etat != CROUPIER)
    {
        mise = demanderMise(joueur->value.name);

        miseTotale += mise;
        joueur->value.mise = mise;

        joueur = joueur->next;
    }

    return miseTotale;
}

void reinitialiserJeu(Jeu *jeu)
{
    ItemJoueur *joueur;

    joueur = jeu->listJoueur.first;

    while (joueur != jeu->listJoueur.last)
    {

        joueur->value.mise = 0;

        viderMain(&joueur->value, &jeu->cartes);

        joueur = joueur->next;
    }
    melangerCartes(&jeu->cartes);
}

void distribuerScore(Jeu *jeu)
{
    ItemJoueur *joueur;
    const ItemJoueur *croupier;
    EtatJoueur etatCroupier;
    int int_valeurJoueur;
    int int_valeurCroupier;

    croupier = jeu->listJoueur.last - 1;
    etatCroupier = getEtatCroupier(&croupier->value);
    if (etatCroupier == DESSOUS)
    {
        int_valeurCroupier = getValeurTotale(&croupier->value.hand);
    }
    else
    {
        int_valeurCroupier = 0;
    }

    joueur = jeu->listJoueur.first;

    while (joueur != jeu->listJoueur.last - 1)
    {
        int_valeurJoueur = getValeurTotale(&joueur->value.hand);
        if (joueur->value.etat < etatCroupier || (etatCroupier == DESSOUS && int_valeurJoueur < int_valeurCroupier))
        {
            if (joueur->value.etat == DEPASSE)
            {
                annoncerEtatJeu(joueur->value.name, SAUTE);
            }
            else
            {
                annoncerEtatJeu(joueur->value.name, BATU);
            }
            joueur->value.score -= joueur->value.mise;
        }
        else if (joueur->value.etat > etatCroupier || (etatCroupier == DESSOUS && int_valeurJoueur > int_valeurCroupier))
        {
            if (joueur->value.etat == BLACKJACK)
            {
                annoncerEtatJeu(joueur->value.name, ETAT_BLACKJACK);
                joueur->value.score += joueur->value.mise * 2;
            }
            else
            {
                annoncerEtatJeu(joueur->value.name, REMPORTE);
                joueur->value.score += joueur->value.mise;
            }
        }
        else
        {
            annoncerEtatJeu(joueur->value.name, EGALITE);
        }
        annoncerScore(&joueur->value);

        joueur = joueur->next;
    }
}

void deroulerPartie(Jeu *jeu)
{
    ItemJoueur *joueur;

    joueur = jeu->listJoueur.first;

    annoncerCartesToutLeMonde(&jeu->listJoueur);

    while (joueur != jeu->listJoueur.last)
    {
        annoncerTour(joueur->value.name);

        donnerCartes(&joueur->value, &jeu->cartes);

        joueur = joueur->next;
    }
}

void viderMain(Joueur *joueur, ListCarte *cartes)
{
    sCarte carte;

    while (listCarteSize(&joueur->hand) > 0)
    {
        carte = enleverAvantCarte(&joueur->hand);

        ajouterAvantCarte(cartes, carte);
    }

    creerListeCarte(&joueur->hand);
}

void donnerCartes(Joueur *joueur, ListCarte *cartes)
{
    sCarte carte;
    int int_continuer;

    int_continuer = 1;

    while (int_continuer)
    {
        annoncerCartes(&joueur->hand);
        if (joueur->etat == CROUPIER)
        {
            if (getValeurTotale(&joueur->hand) <= 16 && getEtatCroupier(joueur) != BLACKJACK)
            {
                carte = enleverAvantCarte(cartes);
                ajouterApresCarte(&joueur->hand, carte);
            }
            else
            {
                int_continuer = 0;
            }
        }
        else
        {
            changerEtatJoueur(joueur);

            if (joueur->etat != DESSOUS || !continuer())
            {
                annoncerEtat(joueur);
                break;
            }

            carte = enleverAvantCarte(cartes);
            ajouterApresCarte(&joueur->hand, carte);
        }
    }
}
