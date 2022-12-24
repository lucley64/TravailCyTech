#include "cartes.h"

#include "listeCarte.h"

#include "stdlib.h"
#include "time.h"

ListCarte *initCartes()
{
    // Initialise l'aléatoire pour le mélange des cartes
    srand((u_int)time(NULL));

    ListCarte *listCartes_cartes; // Représente la nouvelle liste cartes

    // Alloue de la memoire à la nouvelle liste
    listCartes_cartes = (ListCarte *)malloc(sizeof(ListCarte));

    // Créé la nouvelle liste cartes
    creerListeCarte(listCartes_cartes);

    // Ajoute les cartes couleur par couleur
    initParCouleur(listCartes_cartes, PIQUE);
    initParCouleur(listCartes_cartes, CARREAU);
    initParCouleur(listCartes_cartes, TREFLE);
    initParCouleur(listCartes_cartes, COEUR);

    return (listCartes_cartes);
}

void melangerCartes(ListCarte *listCarte)
{
    sCarte *tabsCare_cartes; // Tableau de cartes pour faciliter le mélange
    int int_size; // Taille du tableau de cartes
    int int_arrIndice1; // Indice de la première carte à échanger
    int int_arrIndice2; // Indice de la deuxième carte à échanger
    sCarte sCarte_temp; // Variable temporaire pour l'échange des cartes

    // Converti la liste de cartes en tableau 
    listCarteToArray(listCarte, &tabsCare_cartes, &int_size);

    // On parcours le tableau et on échange deux carte aléatoire
    for (size_t i = 0; i < int_size; i++)
    {
        int_arrIndice1 = rand() % int_size;
        int_arrIndice2 = rand() % int_size;

        sCarte_temp = tabsCare_cartes[int_arrIndice1];
        tabsCare_cartes[int_arrIndice1] = tabsCare_cartes[int_arrIndice2];
        tabsCare_cartes[int_arrIndice2] = sCarte_temp;
    }

    // Reconverti le tableau en liste
    arrayToListCarte(listCarte, &tabsCare_cartes, int_size);
}

sCarte createCarte(Carte carte, CarteColor color)
{
    sCarte sCarte_newCarte; // La nouvelle carte crée

    // Affecte les atributs à cette nouvelle carte
    sCarte_newCarte.carte_color = color;
    sCarte_newCarte.carte = carte;

    return (sCarte_newCarte);
}

void initParCouleur(ListCarte *listCarte, CarteColor color)
{
    ajouterApresCarte(listCarte, createCarte(AS, color));
    ajouterApresCarte(listCarte, createCarte(DEUX, color));
    ajouterApresCarte(listCarte, createCarte(TROIS, color));
    ajouterApresCarte(listCarte, createCarte(QUATRE, color));
    ajouterApresCarte(listCarte, createCarte(CINQ, color));
    ajouterApresCarte(listCarte, createCarte(SIX, color));
    ajouterApresCarte(listCarte, createCarte(SEPT, color));
    ajouterApresCarte(listCarte, createCarte(HUIT, color));
    ajouterApresCarte(listCarte, createCarte(NEUF, color));
    ajouterApresCarte(listCarte, createCarte(DIX, color));
    ajouterApresCarte(listCarte, createCarte(VALET, color));
    ajouterApresCarte(listCarte, createCarte(DAME, color));
    ajouterApresCarte(listCarte, createCarte(ROI, color));
}
