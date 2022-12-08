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

    ajouterApres(cartes, AS);
    ajouterApres(cartes, DEUX);
    ajouterApres(cartes, TROIS);
    ajouterApres(cartes, QUATRE);
    ajouterApres(cartes, CINQ);
    ajouterApres(cartes, SIX);
    ajouterApres(cartes, SEPT);
    ajouterApres(cartes, HUIT);
    ajouterApres(cartes, NEUF);
    ajouterApres(cartes, DIX);
    ajouterApres(cartes, VALET);
    ajouterApres(cartes, DAME);
    ajouterApres(cartes, ROI);

    return cartes;
}

void melangerCartes(ListCarte *listCarte)
{
    Carte *cartes;
    int size;
    int arrIndice1;
    int arrIndice2;
    Carte temp;

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
