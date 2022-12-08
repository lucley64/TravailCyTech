#include "cartes.h"

ListCarte *initCartes()
{
    ListCarte *cartes;

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