/**
 \file jeu.c
 \author Luc Leydert
 \brief 
 \version 0.1
 \date 24/12/2022
 \
 \copyright Copyright (c) 2022
 \
 */
#include "jeu.h"

#include <string.h>
#include <stdbool.h>

#include "interface.h"

/// @brief Distribue les cartes au joueurs
/// @param jeu Pointeur sur la partie
void distribuerCartes(Jeu *jeu);
/// @brief Donne une carte de la pioche au joueur
/// @param joueur Pointeur sur un joueur
/// @param cartes Pointeur sur la liste de cartes (pioche)
void donnerCarte(Joueur *joueur, ListCarte *cartes);
/// @brief Créé un joueur en lui demandant son nom
/// @return Le nouveau joueur
Joueur creeJoueur();
/// @brief Fait miser les joueurs
/// @param jeu Pointeur sur la partie
/// @return La mise totale
int miser(Jeu *jeu);
/// @brief Reinitialise le jeu
/// @param jeu pointeur sur le jeu
void reinitialiserJeu(Jeu *jeu);
/// @brief Disrtibu le score au joueurs
/// @param jeu pointeur su la partie
void distribuerScore(Jeu *jeu);
/// @brief Fait se dérouler un la partie
/// @param jeu Pointeur sur le jeu
void deroulerPartie(Jeu *jeu);
/// @brief Vide la main d'un joueur
/// @param joueur Pointeur sur un joueur
/// @param cartes Pointeur sur la liste de cartes
void viderMain(Joueur *joueur, ListCarte *cartes);
/// @brief Donne les cartes a un joueur tant que celui-ci le veuille
/// @param joueur Pointeur sur un joueur
/// @param cartes Pointeur sur la liste de cartes
void donnerCartes(Joueur *joueur, ListCarte *cartes);

void initialiserJeu(Jeu *jeu, int nbJoueur)
{
    Joueur joueur; // Un joueur

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
    int continu; // 1 si on continu de joueur 0 sinon

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
    ItemJoueur *ite_joueur; // Iterateur de joueur

    ite_joueur = jeu->listJoueur.first;
    while (ite_joueur != jeu->listJoueur.last)
    {
        if (ite_joueur->value.etat != CROUPIER)
        {
            donnerCarte(&ite_joueur->value, &jeu->cartes);
            donnerCarte(&ite_joueur->value, &jeu->cartes);
            ite_joueur->value.etat = DESSOUS;
        }
        else
        {
            donnerCarte(&ite_joueur->value, &jeu->cartes);
        }

        ite_joueur = ite_joueur->next;
    }
}

void donnerCarte(Joueur *joueur, ListCarte *cartes)
{
    sCarte carte; // La carte à donner

    carte = enleverAvantCarte(cartes);

    ajouterAvantCarte(&joueur->hand, carte);
}

Joueur creeJoueur()
{
    Joueur joueur; // Le nouveau joueur

    joueur.name = demanderNom();
    creerListeCarte(&joueur.hand);
    joueur.score = 0;

    return (joueur);
}

int miser(Jeu *jeu)
{
    int int_miseTotale; // La mise totale
    int int_mise; // La mise d'un joueur
    ItemJoueur *ite_joueur; // Iterateur de joueur

    ite_joueur = jeu->listJoueur.first;
    int_miseTotale = 0;
    while (ite_joueur != jeu->listJoueur.last && ite_joueur->value.etat != CROUPIER)
    {
        int_mise = demanderMise(ite_joueur->value.name);

        int_miseTotale += int_mise;
        ite_joueur->value.mise = int_mise;

        ite_joueur = ite_joueur->next;
    }

    return (int_miseTotale);
}

void reinitialiserJeu(Jeu *jeu)
{
    ItemJoueur *ite_joueur; // Iterateur de joueur

    ite_joueur = jeu->listJoueur.first;

    while (ite_joueur != jeu->listJoueur.last)
    {

        ite_joueur->value.mise = 0;

        viderMain(&ite_joueur->value, &jeu->cartes);

        ite_joueur = ite_joueur->next;
    }
    melangerCartes(&jeu->cartes);
}

void distribuerScore(Jeu *jeu)
{
    ItemJoueur *ite_joueur; // Iterateur de joueur
    const ItemJoueur *ite_croupier; // pointeur sur un item joueur représantant le croupier
    EtatJoueur etatCroupier; // État du croupier
    int int_valeurJoueur; // Valeur des cartes d'un joueur
    int int_valeurCroupier; // Valeur des cartes du croupier

    ite_croupier = jeu->listJoueur.last - 1;
    etatCroupier = getEtatCroupier(&ite_croupier->value);
    if (etatCroupier == DESSOUS)
    {
        int_valeurCroupier = getValeurTotale(&ite_croupier->value.hand);
    }
    else
    {
        int_valeurCroupier = 0;
    }

    ite_joueur = jeu->listJoueur.first;

    while (ite_joueur != jeu->listJoueur.last - 1)
    {
        int_valeurJoueur = getValeurTotale(&ite_joueur->value.hand);
        if (ite_joueur->value.etat < etatCroupier || (etatCroupier == DESSOUS && ite_joueur->value.etat == DESSOUS && int_valeurJoueur < int_valeurCroupier))
        {
            if (ite_joueur->value.etat == DEPASSE)
            {
                annoncerEtatJeu(ite_joueur->value.name, SAUTE);
            }
            else
            {
                annoncerEtatJeu(ite_joueur->value.name, BATU);
            }
            ite_joueur->value.score -= ite_joueur->value.mise;
        }
        else if (ite_joueur->value.etat > etatCroupier || (etatCroupier == DESSOUS && ite_joueur->value.etat == DESSOUS && int_valeurJoueur > int_valeurCroupier))
        {
            if (ite_joueur->value.etat == BLACKJACK)
            {
                annoncerEtatJeu(ite_joueur->value.name, ETAT_BLACKJACK);
                ite_joueur->value.score += ite_joueur->value.mise * 2;
            }
            else
            {
                annoncerEtatJeu(ite_joueur->value.name, REMPORTE);
                ite_joueur->value.score += ite_joueur->value.mise;
            }
        }
        else
        {
            annoncerEtatJeu(ite_joueur->value.name, EGALITE);
        }
        annoncerScore(&ite_joueur->value);

        ite_joueur = ite_joueur->next;
    }
}

void deroulerPartie(Jeu *jeu)
{
    ItemJoueur *ite_joueur; // Iterateur de joueur

    ite_joueur = jeu->listJoueur.first;

    annoncerCartesToutLeMonde(&jeu->listJoueur);

    while (ite_joueur != jeu->listJoueur.last)
    {
        annoncerTour(ite_joueur->value.name);

        donnerCartes(&ite_joueur->value, &jeu->cartes);

        ite_joueur = ite_joueur->next;
    }
}

void viderMain(Joueur *joueur, ListCarte *cartes)
{
    sCarte carte; // La carte enlevé de la main

    while (listCarteSize(&joueur->hand) > 0)
    {
        carte = enleverAvantCarte(&joueur->hand);

        ajouterAvantCarte(cartes, carte);
    }

    creerListeCarte(&joueur->hand);
}

void donnerCartes(Joueur *joueur, ListCarte *cartes)
{
    sCarte carte; // La carte à donner
    int int_continuer; // 1 Si le croupier continue de poicher 0 sinon

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
