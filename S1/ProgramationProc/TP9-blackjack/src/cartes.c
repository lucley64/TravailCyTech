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

    ajouterApres(cartes, createCarte(AS, PIQUE));
    ajouterApres(cartes, createCarte(DEUX, PIQUE));
    ajouterApres(cartes, createCarte(TROIS, PIQUE));
    ajouterApres(cartes, createCarte(QUATRE, PIQUE));
    ajouterApres(cartes, createCarte(CINQ, PIQUE));
    ajouterApres(cartes, createCarte(SIX, PIQUE));
    ajouterApres(cartes, createCarte(SEPT, PIQUE));
    ajouterApres(cartes, createCarte(HUIT, PIQUE));
    ajouterApres(cartes, createCarte(NEUF, PIQUE));
    ajouterApres(cartes, createCarte(DIX, PIQUE));
    ajouterApres(cartes, createCarte(VALET, PIQUE));
    ajouterApres(cartes, createCarte(DAME, PIQUE));
    ajouterApres(cartes, createCarte(ROI, PIQUE));

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
