#include "clsrv.h"

int msgid;

void fin(int n) {
	fprintf(stderr, "Terminaison du serveur.\n");
	msgctl(msgid, IPC_RMID, NULL);
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	key_t cle;
	struct sigaction action;
	requete req;
	reponse rep;
	int sig, i, tmp;
	
	// on commence par prevoir la terminaison sur signal du serveur
	action.sa_handler = fin;
	for(i=1; i<NSIG; i++) sigaction(i, &action, NULL);	// installation du handler de fin pour tous les signaux
	// creation de la file de message
	if ((cle = ftok(SERVEUR, '0')) == -1) {
		fprintf(stderr, "Obtention de la cle impossible. Fin du serveur.\n");
		exit(EXIT_FAILURE);
	}
	if ((msgid = msgget(cle, IPC_CREAT|IPC_EXCL|DROITS)) == -1) {
		fprintf(stderr, "Creation de la file impossible. Fin du serveur.\n");
		exit(EXIT_FAILURE);
	}
	// attente d'une requete a l'infini...
	while(1) {
		if (msgrcv(msgid, &req, TAILLE_REQ, 1L, 0) == -1) {
			fprintf(stderr, "Serveur: Erreur de reception de requete\n");
			continue;
		}
		printf("Serveur: requete ->%s<- du processus %d\n", req.chaine, req.signature);
		// construction de la reponse
		rep.type = req.signature;
		tmp = strlen(req.chaine);
		printf("Serveur: tmp=%d\n", tmp);
		for(i=0; i<tmp; i++) {
			rep.chaine[i] = req.chaine[tmp-i-1];
		}
		rep.chaine[tmp] = '\0';
		printf("Serveur: rep.chaine ->%s<-\n", rep.chaine);
		// envoi de la reponse
		if (msgsnd(msgid, &rep, TAILLE_REP, 0) == -1) {
			fprintf(stderr, "Serveur: Erreur d'envoi d'une réponse a %d\n", req.signature);
		}
		else {
			printf("Serveur: reponse envoyee a %d\n", req.signature);
		}
	}
	return 0;
}