// ReSharper disable CppDFAEndlessLoop
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clsrv.h"

int msgid;

void end_srv(int n) {
    fprintf(stderr, "\rTerminaison du serveur.\n");
    msgctl(msgid, IPC_RMID, NULL);
    exit(EXIT_SUCCESS);
}

void exercice_1_client() {
}


void exercice_1_server() {
    key_t key;
    struct sigaction action;
    action.sa_handler = end_srv;
    for (int i = 1; i < NSIG; i++) sigaction(i, &action, NULL); // installation du handler de fin pour tous les signaux
    if ((key = ftok(SERVEUR, '0')) == -1) {
        fprintf(stderr, "Obtention de la cle impossible. Fin du serveur.\n");
        exit(EXIT_FAILURE);
    }
    if ((msgid = msgget(key, IPC_CREAT | IPC_EXCL | DROITS)) == -1) {
        fprintf(stderr, "Creation de la file impossible. Fin du serveur.\n");
        exit(EXIT_FAILURE);
    }
    // attente d'une requete a l'infini...
    while (1) {
        requete req;
        reponse rep;
        if (msgrcv(msgid, &req, TAILLE_REQ, 1L, 0) == -1) {
            fprintf(stderr, "Serveur: Erreur de reception de requete\n");
            continue;
        }
        printf("Serveur: requete ->%s<- du processus %d\n", req.chaine, req.signature);
        // construction de la reponse
        rep.type = req.signature;
        const int nb_numbers = strlen(req.chaine);
        printf("Serveur: number of numbers=%d\n", nb_numbers);
        for (int i = 0; i < nb_numbers; i++) {
            rep.chaine[i] = req.chaine[nb_numbers - i - 1];
        }
        rep.chaine[nb_numbers] = '\0';
        printf("Serveur: rep.chaine ->%s<-\n", rep.chaine);
        // envoi de la reponse
        if (msgsnd(msgid, &rep, TAILLE_REP, 0) == -1) {
            fprintf(stderr, "Serveur: Erreur d'envoi d'une réponse a %d\n", req.signature);
        } else {
            printf("Serveur: reponse envoyee a %d\n", req.signature);
        }
    }
}


int main(const int argc, const char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <no_ex> <client|server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "1") == 0) {
        if (strcmp(argv[2], "client") == 0) {
            exercice_1_client();
        } else if (strcmp(argv[2], "server") == 0) {
            exercice_1_server();
        } else {
            printf("Please enter client or server.\n");
        }
    } else if (strcmp(argv[1], "2") == 0) {
        if (strcmp(argv[2], "client") == 0) {
        } else if (strcmp(argv[2], "server") == 0) {
        } else {
            printf("Please enter client or server.\n");
        }
    } else {
        printf("Exercice number %s not found\n", argv[1]);
    }


    exit(EXIT_SUCCESS);
}
