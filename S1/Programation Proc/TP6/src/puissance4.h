/**
 \file puissance4.h
 \author Luc Leydert
 \brief 
 \version 0.1
 \date 29/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef PUISSANCE_4_H
#define PUISSANCE_4_H

/**
 \brief nombre de lignes et de colones
 \
 */
#define OFFSET 5

/**
 \brief nombre de pions à alligner
 \
 */
#define LONGUEUR_GAGNE 4

/**
 \brief initialise la grille
 \
 \param ttint_plateau la grille en question
 */
void init(int ttint_plateau[OFFSET][OFFSET]);

/**
 \brief affiche l'état du jeu
 \
 \param ttint_plateau la grille du jeu
 */
void affichage(int ttint_plateau[OFFSET][OFFSET]);

/**
 \brief jouer dans une colonne spécifique
 \
 \param ttint_plateau la grille du jeu
 \param int_joueur le joueur
 \param int_x la colone
 \return int 
 */
int jouer(int ttint_plateau[OFFSET][OFFSET], int int_joueur, int int_x);

/**
 \brief indique si un joueur a gagné
 \
 \param ttint_plateau la grille du jeu
 \return int soit le numéro du joueur gagnant, soit 0 si c’est match nul, soit -1 si la partie n’est pas terminée
 */
int aGagne(int ttint_plateau[OFFSET][OFFSET]);

/**
 \brief fait jouer les joueurs chacun leur tour, jusqu’à la fin de la partie
 \
 \param ttint_plateau la grille du jeu
 */
void tourDeJeu(int ttint_plateau[OFFSET][OFFSET]);

#endif // !PUISSANCE_4_H