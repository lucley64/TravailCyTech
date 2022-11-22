// 1.
Preconditions: 
Postconditions: Affiche le nom de tous les étudiants ainsi que leur moyenne
Algorithme afficherMoyennes
Variables
    mapMoyennes: Map<chaîne> de Reel
    listeÉtudiant: Liste de chaîne
    moyenneG: Reel
Debut
    creerMap(mapMoyennes)
    calculMoyenne(mapMoyennes)
    creerListe(listeÉtudiant)

    listeÉtudiant ← listeClefs(mapMoyennes)
    moyenneG ← 0

    Pour i de 0 a taille(listeÉtudiant)
    Faire
        afficher("L'étudiant ", listeÉtudiant[i], " a pour moyenne ", valeurDe(mapMoyennes, listeÉtudiant[i]))
        moyenneG ← moyenneG + valeurDe(mapMoyennes, listeÉtudiant[i])/cardinalite(mapMoyennes)
    FinPour

    afficher("La moyenne générale est ", moyenneG)

Fin

//2.
Preconditions: mapReels créé et initialisé, procadure trier que trie une liste 
Postconditions: trouve la valeur assoc a une clé ou de celle la plus proche
Fonction valeurAprox(mapReels: Map<Entier> de Reel, clé: Entier):Reel
Variables
    clés: Liste de Entier
Debut
    clés ← listeClefs(mapReels)
    trier(clés)

    

Fin