/**
 \file codage.h
 \author Luc Leydert
 \brief
 \version 0.1
 \date 07/12/2022
 \
 \@copyright Copyright (c) 2022
 \
 */
#ifndef CODAGE_H
#define CODAGE_H

/**
 \brief Encode message en suivant la méthode de César
 \
 \param decal Le décalage à effecuer
 \param message Le message à encoder
 */
void cesar(const char *decal, char *message);

/**
 \brief Encode message en suivant la méthode de Vigene
 \
 \param cle La clé d'encodage
 \param message Le message à encoder
 */
void vigene(const char* cle, char *message);

/**
 \brief Encode message en suivant la méthode de Scytale
 \
 \param message Le message à encoder
 */
void scytale(char **message);

/**
 \brief Demande à l'utilisateur le message
 \
 \return char* Le message saisit
 */
char *askMessage();

#endif // !CODAGE_H