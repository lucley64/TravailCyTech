
# RS.tgz
Peio LOUBIÈRE - <plo@eisti.eu>

## Détail du contenu de l'archive

L'archive *RS.tgz* contient:

* Le fichier `RSTSP.py` contient le script python du recuit-simulé pour traiter le TSP;
* Le fichier `requirements.txt` contient les modules nécessaires à importer;
* Les fichiers `*.tsp` contiennent les instances du problème sous la forme: `num_ville x y`;
* Les fichiers `*.opt.tour` contiennent le chemin optimal connu pour le problème.

## Exécution du programme
	
	python RSTSP.py NUMERO_INSTANCE.tsp

## Fichier RSTSP.py

### La représentation du problème
* Les données sont chargées depuis le fichier texte dans un tableau de coordonnées `(x,y)`;
* Une **solution** du problème est représentée par une séquence (liste) d'ordre de parcours des villes (identifiées par leur numéro);
* `best_trajet` et `best_dist` sauvegardent la meilleure solution rencontrée et son évaluation.

### Les fonctions notables  

* `distance` et `energieTotale` permettent de calculer la longueur d'une tournée (en fermant le cycle);
* `fluctuationDeux` génère une nouvelle solution en inversant deux villes de la tournée;
* `metropolis` retourne une solution. Applique le critère d'acceptance dans le cas d'une solution dégradante ou bien retourne la nouvelle solution dans le cas d'une solution améliorante;
* La boucle principale exécute l'algorithme du recuit simulé;
* `affRes` réalise un affichage console;
* `dessine*` affichent les fenêtres de chemin et de bilan.


