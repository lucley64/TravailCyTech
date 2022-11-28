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

    TantQue NON estVide(listeÉtudiant)
    Faire
        afficher("L'étudiant ", tête(listeÉtudiant), " a pour moyenne ", valeurDe(mapMoyennes, tête(listeÉtudiant)))
        moyenneG ← moyenneG + valeurDe(mapMoyennes, tête(listeÉtudiant)) / cardinalite(mapMoyennes)
        listeÉtudiant ← reste(listeÉtudiant)
    FinTantQue

    afficher("La moyenne générale est ", moyenneG)

Fin

//2.
Preconditions: mapReels créé et initialisé, procadure trier que trie une liste 
Postconditions: trouve la valeur assoc a une clé ou de celle la plus proche
Fonction valeurAprox(mapReels: Map<Entier> de Reel, clé: Entier):Reel
Variables
    clés: Liste de Entier
    trouvé: Booleen
    cléAprox: Entier
Debut
    clés ← listeClefs(mapReels)
    trier(clés)

    trouvé ← faux
    cléAprox ← tête(clés)
    TantQue (NON trouvé) ET (NON estVide(clés))
    Faire
        Si clé ≥ tête(clés)
        Alors
            trouvé ← vrai
            Si tête(clés) - clé < clé - cléAprox
            Alors
                cléAprox ← tête(clés)
            FinSi
        Sinon
            cléAprox ← tête(clés)
            clés ← reste(clés)
        FinSi
    FinTantQue
    retourner(valeurDe(mapReels, cléAprox))
Fin

//3.
Preconditions: mapQuelconque créé et initialisé
Postconditions: recherche la valeur minimale dans une map d'entiers
Fonction elemMin(mapQuelconque: Map<Élement> de Entier):type
Variables
    listeClefs: Liste de Élement
    min: Entier
Debut
    listeClefs ← listeClefs(mapQuelconque)

    min ← valeurDe(mapQuelconque, tête(listeClefs))

    TantQue NON estVide(listeClefs)
    Faire
        Si tête(listeClefs) < min
        Alors
            min ← tête(listeClefs)
        FinSi
        listeClefs ← reste(listeClefs)
    FinTantQue

    retourner(valeurDe(mapQuelconque, min))
Fin