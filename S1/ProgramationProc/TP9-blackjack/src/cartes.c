#include "cartes.h"

#include "listeCarte.h"

#include "stdlib.h"
#include "time.h"

ListCarte *initCartes()
{
    srand((u_int)time(NULL));

    ListCarte *cartes;

    cartes = (ListCarte *)malloc(sizeof(ListCarte));
    creerListeCarte(cartes);

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

    listCarteToArray(listCarte, &cartes, &size);

    for (size_t i = 0; i < size; i++)
    {
        arrIndice1 = rand() % size;
        arrIndice2 = rand() % size;

        temp = cartes[arrIndice1];
        cartes[arrIndice1] = cartes[arrIndice2];
        cartes[arrIndice2] = temp;
    }

    arrayToListCarte(listCarte, &cartes, size);
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
