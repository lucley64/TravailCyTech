//1.

Preconditions: rien
Postconditions: rien
Algorithme Minimum et Maximum
Variables
    min, max: Reel
    listeEntree: chaine de Reel
    nombreDEntree, i: Reel
Debut
    ecrire("Entrer le nombre d'entrées")                    // 1
    lire(nombreDEntree)                                     // 1
    Pour i de 1 a nombreDEntree                             // n-1
    Faire
        ecrire("saisir le ", i, " nombre")                  // n-1
        lire(listeEntree[i])                                // n-1
    FinPour
    min ← findMin(listeEntree)                              // 3n-1
    max ← findMax(listeEntree)                              // 3n-1
    ecrire("Le minimum est", min, "et le maximum", max)     // 1
Fin

Preconditions: listeEntree initialisé
Postconditions: le maximum
Fonction findMax(listeEntree: chaine Reel):Reel
Variables
    max, i: Reel
Debut
    max ← listeEntree[1]                                    // 1
    Pour i de 1 a longueur(listeEntree)                     // n-1
    Faire
        Si listeEntree[i] > max                             // n-1
        Alors
            max ← listeEntree[i]                            // n-1
        FinSi
    FinPour
    retourner(max)                                          // 1
Fin

// T(n) = 3 + 3 * (n - 1) + 2 * (3n - 1) = 3 + 3n - 3 + 6n - 2 = 9n - 2



// 2.

Preconditions: A & B init
Postconditions: renvoie A*B
Procedure produitMatriciel(A, B: tableau de tableau d'Entier, C: tableau de tableau d'Entier(S))
Variables
    i, j, k, n, m, p: Entier
Debut
    n ← longeur(A)
    m ← longeur(B)
    p ← longeur(B[1])
    affecterLongeur(C, n)
    Pour i de 1 a n 
    Faire
        affecterLongeur(C[i], p)
    FinPour
    Pour i de 1 a n 
    Faire
        Pour j de 1 a p 
        Faire
            C[i, j] ← 0
            Pour k de 1 a m 
            Faire
                C[i, j] ← C[i, j] + A [i, k] + B[k, j]
            FinPour
        FinPour
    FinPour
Fin