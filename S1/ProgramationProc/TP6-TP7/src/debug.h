/**
 \file debug.h
 \author Luc Leydert
 \brief Contien des fonctions de debug
 \version 0.1
 \date 30/11/2022
 \
 \@copyright Copyright (c) 2022
 \
 */

#ifndef DEBUG_H
#define DEBUG_H

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

#endif //!DEBUG_H