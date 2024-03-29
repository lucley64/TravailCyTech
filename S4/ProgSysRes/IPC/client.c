#include "clsrv.h"

int main(int argc, char **argv) {
	key_t cle;
	int msgid, i;
	requete req;
	reponse rep;
	// On recherche la file de message
	if ((cle = ftok(SERVEUR, '0')) == -1) {
		fprintf(stderr, "Obtention de la cle impossible. Fin du serveur.\n");
		exit(EXIT_FAILURE);
	}
	if ((msgid = msgget(cle, 0)) == -1) {
		fprintf(stderr, "Erreur: file inconnue. Fin du client.\n");
		exit(EXIT_FAILURE);
	}
	//
	printf("Client operationnel\n");
	req.type = 1L;
	req.signature = getpid();
	while(1) {
		printf("--> ");
		fgets(req.chaine, TAILLE_REP, stdin);
		req.chaine[strlen(req.chaine)-1]='\0';
		if (strlen(req.chaine) == 0) continue;
		if (strcmp(req.chaine, "exit") == 0) {
			printf("Au revoir !\n");
			exit(EXIT_SUCCESS);
		}
		printf("Requete de %d envoyee: ->%s<-\n", req.signature, req.chaine);
		if (msgsnd(msgid, &req, TAILLE_REQ, 0) == -1) {
			fprintf(stderr, "%d: erreur d'envoi de la requete %s au serveur\n", req.signature, req.chaine);
			fprintf(stderr, "Fin du client %d.\n", req.signature);
			exit(EXIT_FAILURE);
		}
		if (msgrcv(msgid, &rep, TAILLE_REP, (long) req.signature, 0) == -1) {
			fprintf(stderr, "%d: erreur de reception de la reponse du serveur.\n", req.signature);
			fprintf(stderr, "Fin du client %d.\n", req.signature);
			exit(EXIT_FAILURE);
		}
		printf("%d: reponse du serveur ->%s<-\n", req.signature, rep.chaine);
	}
	return 0;
}
		