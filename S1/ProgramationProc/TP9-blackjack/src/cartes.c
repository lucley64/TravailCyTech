#include "cartes.h"

#include "listeCarte.h"

#include "stdlib.h"
#include "time.h"

ListCarte *initCartes()
{
    srand((u_int)time(NULL));

    ListCarte *cartes;

    cartes = (ListCarte *)malloc(sizeof(ListCarte));
    creerListe(cartes);

    initParCouleur(cartes, PIQUE);
    initParCouleur(cartes, CARREAU);
    initParCouleur(cartes, TREFLE);
    initParCouleur(cartes, COEUR);

    return cartes;
}

void melangerCartes(ListCarte *listCarte)
{
    sCarte *cartes;
    int size;
    int arrIndice1;
    int arrIndice2;
    sCarte temp;

    listToArray(listCarte, &cartes, &size);

    for (size_t i = 0; i < size; i++)
    {
        arrIndice1 = rand() % size;
        arrIndice2 = rand() % size;

        temp = cartes[arrIndice1];
        cartes[arrIndice1] = cartes[arrIndice2];
        cartes[arrIndice2] = temp;
    }

    arrayToList(listCarte, &cartes, size);
}

sCarte createCarte(Carte carte, CarteColor color)
{
    sCarte newCarte;

    newCarte.carte_color = color;
    newCarte.carte = carte;

    return newCarte;
}

void initParCouleur(ListCarte *listCarte, CarteColor color)
{
    ajouterApres(listCarte, createCarte(AS, color));
    ajouterApres(listCarte, createCarte(DEUX, color));
    ajouterApres(listCarte, createCarte(TROIS, color));
    ajouterApres(listCarte, createCarte(QUATRE, color));
    ajouterApres(listCarte, createCarte(CINQ, color));
    ajouterApres(listCarte, createCarte(SIX, color));
    ajouterApres(listCarte, createCarte(SEPT, color));
    ajouterApres(listCarte, createCarte(HUIT, color));
    ajouterApres(listCarte, createCarte(NEUF, color));
    ajouterApres(listCarte, createCarte(DIX, color));
    ajouterApres(listCarte, createCarte(VALET, color));
    ajouterApres(listCarte, createCarte(DAME, color));
    ajouterApres(listCarte, createCarte(ROI, color));
}
