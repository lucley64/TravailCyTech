/**
 \file tab1D.h
 \author Luc Leydert
 \brief
 \version 0.1
 \date 29/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef TAB_1D_H
#define TAB_1D_H

#define TAILLE_TAB 20

/**
 \brief inverse les éléments d’un tableau d'entiers
 \
 \param tab le tableau en question (Entrée/Sortie)
 */
void invertion(int tab[TAILLE_TAB]);

/**
 \brief somme les éléments de deux tableaux dans un troisième
 \
 \param tab1 tableau 1
 \param tab2 tableau 2
 \param tabResultat résultat
 */
void additionnerTab(int tab1[TAILLE_TAB], int tab2[TAILLE_TAB], int tabResultat[TAILLE_TAB]);

/**
 \brief détermine si un tableau est traversable
 \
 \param tab1 le tableau en question
 \param max le nombre max de tour de boucle
 \return int 1 si oui 0 sinon
 */
int traversabilite(int tab1[TAILLE_TAB], int max);

/**
 \brief affiche les valeurs d'un tableau
 \
 \param tab le tableau en question
 */
void afficherTab(int tab[TAILLE_TAB]);

/**
 \brief remplit un tableau de manière aléatoire
 \
 \param tab le tableau en question
 */
void remplirAlea(int tab[TAILLE_TAB]);

/**
 \brief Demande de remplir un tableau
 \
 \param tab le tableau en question
 */
void remplir(int tab[TAILLE_TAB]);

/**
 \brief Demande d'écrire une phase
 \
 \param str La chaine de char
 */
void remplirStr(char str[TAILLE_TAB]);

/**
 \brief Vérifie si la chaine est un palindrome
 \
 \param str La chaine en question
 \return int 1 si oui 0 sinon
 */
int verifPalindrome(char str[TAILLE_TAB]);

#endif // !TAB_1D_H