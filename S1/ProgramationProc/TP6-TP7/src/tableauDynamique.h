/**
 \file tableauDynamique.h
 \author Luc Leydert
 \brief Correspond au TP7 b
 \version 0.1
 \date 30/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef TABLEAU_DYNAMIQUE_H
#define TABLEAU_DYNAMIQUE_H

/// REMPLISSAGE DE TABLEAU

/**
 \brief Affiche un tableau dynamique
 \
 \param tab (Entrée) Le tebleau
 \param taille La taille du tableau
 */
void afficherTabDyna(const int *tab, int taille);

/**
 \brief Remplit un tableau dynamique aléatoirement
 \
 \param tab (Entrée/Sortie) Le tebleau
 \param taille La taille du tableau
 */
void remplissageTabDynaAlea(int *tab, int taille);

/**
 \brief Remplit un tableau dynamique
 \
 \param tab (Entrée/Sortie) Le tebleau
 \param taille La taille du tableau
 */
void remplissageTabDyna(int *tab, int taille);

/// TRI PAR INSERTION

/**
 \brief trie un tableau d’entier en utilisant la méthode du tri insertion
 \
 \param tab (Entrée / Sortie) Le tableau à trier
 \param taille (Entrée) La taille du tableau
 */
void triInsertion(int *tab, int taille);

/// TRI FUSION

/**
 \brief copie dans un tableau dest les valeurs du tableau src allant de l’indice debut à l’indice fin
 \
 \param src (Entrée) le tableau source
 \param debut (Entrée) L'indice de début
 \param fin (Entrée) L'indice de fin
 \return int* le tableau destination
 */
int *copierSousTableau(int *src, int debut, int fin);

/**
 \brief fusionner deux tableaux triés de façon croissante tab1 et tab2 dans un tableau résultat tabRes qui sera lui aussi trié de façon croissante
 \
 \param tab1 (Entrée) Le premier tableau
 \param taille1 (Entrée) la taille du premier tableau
 \param tab2 (Entrée) le deuxième tableau
 \param taille2 (Entrée) la taille du deuxième tableau
 \param tabRes (Sortie) le résultat de leur fustion
 */
void fusion(const int *tab1, int taille1, const int *tab2, int taille2, int *tabRes);

/**
 \brief trie un tableau de façon croissante
 \
 \param tab (Entrée/Sortie) Le tableau à trier
 \param taille (Entrée) La taille du tableau
 */
void triFusion(int *tab, int taille);

/// TRI DÉNOMBREMENT

/**
 \brief recherche les valeurs minimum et maximum du tableau tab
 \
 \param tab (Entrée) le tableau concérné par la recherche
 \param taille (Entrée) La taille du tableau
 \param min (Sortie) Le minimum trouvé
 \param max (Sortie) Le maximum trouvé
 */
void minMaxTableau(int *tab, int taille, int *min, int *max);

/**
 \brief détermine la fréquence d’apparition de chaque élément du tableau tab
 \
 \param tab (Entrée) le tableau
 \param taille (Entrée) La taille du tableau
 \param histo
 \param tailleH
 \param min
 */
void histogramme(int *tab, int taille, int *histo, int tailleH, int min);

/**
 \brief Effectue le tri par dénombrement
 \
 \param tab (Entrée/Sortie) le tableau
 \param taille (Entrée) la taille du tableau
 */
void triDenombrement(int *tab, int taille);

#endif // !TABLEAU_DYNAMIQUE_H