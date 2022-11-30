#include <stdio.h>
#include "puissance4.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 \brief Fonction de debug
 \
 */
#define DEBUG(format, ...) printf(ANSI_COLOR_BLUE " DEBUG : "ANSI_COLOR_RESET"" format "\n", __VA_ARGS__)

/**
 \brief Fonction de debug
 \
 */
#define PAUSE scanf("%c")

void init(int ttint_plateau[OFFSET][OFFSET])
{
    // On parcours toutes les cases pour les initialiser à -1
    for (int int_i = 0; int_i < OFFSET; int_i++)
    {
        for (int int_j = 0; int_j < OFFSET; int_j++)
        {
            ttint_plateau[int_i][int_j] = -1;
        }
    }
}

void affichage(int ttint_plateau[OFFSET][OFFSET])
{
    // On affiche toutes les cases correctement
    // Parcours de toutes les lignes
    for (int int_i = -1; int_i < OFFSET; int_i++)
    {
        // Parcours de toutes les colones
        for (int int_j = -1; int_j < OFFSET; int_j++)
        {
            if (int_i == -1 && int_j != -1)
            {
                // On affiche le nom des colones
                printf(ANSI_COLOR_GREEN "  %i " ANSI_COLOR_RESET, int_j);
            }
            else if (int_i == -1 && int_j == -1)
            {
                printf("   ");
            }
            else if (int_i != -1 && int_j == -1)
            {
                // On affiche le nom des lignes
                printf(ANSI_COLOR_GREEN" %i "ANSI_COLOR_RESET"|", int_i);
            }
            else if (int_i != -1 && int_j != -1)
            {
                // On affiche la valeur des cases
                switch (ttint_plateau[int_i][int_j])
                {
                case -1:
                    printf("   |");
                    break;
                case 1:
                    printf(ANSI_COLOR_BLUE " X "ANSI_COLOR_RESET"|");
                    break;
                case 2:
                    printf(ANSI_COLOR_RED" O "ANSI_COLOR_RESET"|");
                    break;
                default:
                    break;
                }
            }
        }
        printf("\n");
        // On sépare des lignes
        for (int int_j = -1; int_j < OFFSET; int_j++)
        {
            if (int_j != -1)
            {
                printf("---+");
            }
            else if (int_j == -1)
            {
                printf("   +");
            }
        }
        printf("\n");
    }
}

int jouer(int ttint_plateau[OFFSET][OFFSET], int int_joueur, int int_x)
{
    // On vérifie si la colone est pleine
    if (ttint_plateau[0][int_x] != -1)
    {
        return (0);
    }
    else
    {
        // On place le pion
        ttint_plateau[0][int_x] = int_joueur;
    }

    // On fait tomber le pion
    for (int int_i = 0; int_i < OFFSET - 1; int_i++)
    {
        if (ttint_plateau[int_i + 1][int_x] != -1)
        {
            return (1);
        }
        else
        {
            ttint_plateau[int_i + 1][int_x] = ttint_plateau[int_i][int_x];
            ttint_plateau[int_i][int_x] = -1;
        }
    }
    return (1);
}

int aGagne(int ttint_plateau[OFFSET][OFFSET])
{
    int int_dernierJoueur;  // Indique le joueur qui possede l'allignement
    int bool_ligneGagnant;  // Indique si il y a un gagnant sur une ligne
    int bool_coloneGagnant; // Indique si il y a un gagnant sur une colone
    int bool_diag1Gagnant;  // Indique si il y a un gagnant sur une diagonale
    int bool_diag2Gagnant;  // De même mais pour l'autre sens
    int bool_egalitie;      // Indique si il y a égalité

    // Determine si il y a un gagnant sur une ligne et renvoit qui si oui
    for (int int_i = 0; int_i < OFFSET; int_i++)
    {
        for (int int_k = 0; int_k < OFFSET % (LONGUEUR_GAGNE - 1); int_k++)
        {
            if (ttint_plateau[int_i][int_k] != -1)
            {
                bool_ligneGagnant = 1;
                for (int int_j = int_k; int_j < OFFSET - (OFFSET % (LONGUEUR_GAGNE - 1) - int_k); int_j++)
                {
                    bool_ligneGagnant = bool_ligneGagnant && (ttint_plateau[int_i][int_j] == ttint_plateau[int_i][int_j + 1]);
                    int_dernierJoueur = ttint_plateau[int_i][int_j];
                }
                if (bool_ligneGagnant)
                {
                    return (int_dernierJoueur);
                }
            }
        }
    }

    // Determine si il y a un gagnant sur une colone et renvoit qui si oui
    for (int int_i = 0; int_i < OFFSET; int_i++)
    {
        for (int int_k = 0; int_k < OFFSET % (LONGUEUR_GAGNE - 1); int_k++)
        {
            if (ttint_plateau[int_k][int_i] != -1)
            {
                bool_coloneGagnant = 1;
                for (int int_j = int_k; int_j < OFFSET - (OFFSET % (LONGUEUR_GAGNE - 1) - int_k); int_j++)
                {
                    bool_coloneGagnant = bool_coloneGagnant && (ttint_plateau[int_j][int_i] == ttint_plateau[int_j + 1][int_i]);
                    int_dernierJoueur = ttint_plateau[int_j][int_i];
                }
                if (bool_coloneGagnant)
                {
                    return (int_dernierJoueur);
                }
            }
        }
    }

    // Determine si il y a un gagnant sur une diagonale et renvoit qui si oui
    for (int int_i = 0; int_i < (OFFSET % (LONGUEUR_GAGNE - 1)); int_i++)
    {
        for (int int_j = 0; int_j < (OFFSET % (LONGUEUR_GAGNE - 1)); int_j++)
        {
            // DEBUG("Case : %i, %i = %i", int_i, int_j, ttint_plateau[int_i][int_j]);
            if (ttint_plateau[int_i][int_j] != -1)
            {
                bool_diag1Gagnant = 1;
                for (int int_k = 0; int_k < LONGUEUR_GAGNE - 1; int_k++)
                {
                    bool_diag1Gagnant = bool_diag1Gagnant && (ttint_plateau[int_i + int_k][int_j + int_k] == ttint_plateau[int_i + (1 + int_k)][int_j + (1 + int_k)]);
                    int_dernierJoueur = ttint_plateau[int_i][int_j];
                }
                if (bool_diag1Gagnant)
                {
                    return (int_dernierJoueur);
                }
            }
        }
    }

    // Determine si il y a un gagnant sur l'autre diagonale et renvoit qui si oui
    for (int int_i = OFFSET - 1; int_i >= LONGUEUR_GAGNE - 1; int_i--)
    {
        for (int int_j = 0; int_j < (OFFSET % (LONGUEUR_GAGNE - 1)); int_j++)
        {
            if (ttint_plateau[int_i][int_j] != -1)
            {
                bool_diag2Gagnant = 1;
                for (int int_k = 0; int_k < LONGUEUR_GAGNE - 1; int_k++)
                {
                    bool_diag2Gagnant = bool_diag2Gagnant && (ttint_plateau[int_i - int_k][int_j + int_k] == ttint_plateau[int_i - (1 + int_k)][int_j + (1 + int_k)]);
                    int_dernierJoueur = ttint_plateau[int_i][int_j];
                }
                if (bool_diag2Gagnant)
                {
                    return (int_dernierJoueur);
                }
            }
        }
    }

    // Determine si il y a égalité
    bool_egalitie = 1;
    for (int int_i = 0; int_i < OFFSET; int_i++)
    {
        bool_egalitie = bool_egalitie && ttint_plateau[0][int_i] != -1;
    }
    if (bool_egalitie)
    {
        return (0);
    }

    return (-1);
}

void tourDeJeu(int ttint_plateau[OFFSET][OFFSET])
{
    int int_vainqueur; // Indique si il y a un vainqueur et lequel
    int int_joueur;    // Indique le joueur qui joue
    int int_colone;    // Indique la colone dans laquelle le joueur veux jouer
    int int_aJoue;     // Indique si le joueur a bien joué
    int int_verif;     // Vérifie si le joueur a saisit un nombre
    char char_verif;   // Vérifie si le joueur a saisit uniquement un nombre

    // On affiche le plateau initial
    affichage(ttint_plateau);

    // On initialise le vainqueur
    int_vainqueur = aGagne(ttint_plateau);

    // On initialise le joueur qui joue
    int_joueur = 1;

    // Game loop
    while (int_vainqueur == -1)
    {
        // On fait jouer le joueur
        int_aJoue = 0;
        printf("Joueur %i, entrer la colone où vous voullez mettre votre pion [0 - %i] : ", int_joueur, OFFSET - 1);
        while (int_aJoue == 0)
        {
            // On demande au joueur la colone dans laquelle il veut mettre son pion
            int_verif = 0;
            while (int_verif == 0 || char_verif != '\n' || int_colone < 0 || int_colone > OFFSET - 1)
            {
                int_verif = scanf("%d", &int_colone);

                // On vérifie si la saisie est correcte
                scanf("%c", &char_verif);
                if (int_verif == 0 || char_verif != '\n' || int_colone < 0 || int_colone > OFFSET - 1)
                {
                    printf("Veuiller entrer uniquement un entier comprit dans l'intervale\n");
                    while (char_verif != '\n')
                    {
                        scanf("%c", &char_verif);
                    }
                }
            }

            // On effectue l'action
            int_aJoue = jouer(ttint_plateau, int_joueur, int_colone);
            if (int_aJoue == 0)
            {
                printf("Une erreur est survenue \n");
            }
        }

        // Affichage de l'état du jeu
        affichage(ttint_plateau);

        // On vérifie si il y a un vaiqueur
        int_vainqueur = aGagne(ttint_plateau);

        // On change de joueur
        int_joueur = (((int_joueur + 1) - 1) % 2) + 1;
    }

    // On affiche le vaiqueur
    if (int_vainqueur == 0)
    {
        printf("C'est une égualité\n");
    }
    else
    {
        printf("Le joueur %i est le vaiqueur\n", int_vainqueur);
    }
}