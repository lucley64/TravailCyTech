/**
 \file hello.c
 \author Luc Leydert
 \version 0.1 premier jet
 \date 18/10/2022
 \brief Premier programme hello world
 */

/* inclusion de la biblioteque standard d'entrees sorties*/
#include <stdio.h>

/**
 \fn int main(int argc, char const *argv[])
 \version 0.1 premier jet
 \date 18/10/2022
 \brief Affiche hello world
 \
 \param argc nombre d'arguments
 \param argv tableau des arguments
 \return int 0 si tout s'est bien passé
 */
int main(int argc, char const *argv[])
{
    /* Affichage d'un message */
    printf("Hello\t\v Wo\brld\r! \n This is my f\first pro\'gram.\n \77 \x10");
    /* Fin du programme : tout est OK*/
    return (0);
}