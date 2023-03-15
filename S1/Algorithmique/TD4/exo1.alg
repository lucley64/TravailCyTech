//1.

Preconditions: A est crée est initialisé
Postconditions: retourne la matrice après l'operation Li ← kLi
Procedure dilatation(A (E/S): tableau de tableau, i: Entier, k: Reel)
Variables
    j: Entier
Debut
    Pour j de 1 a taille(A[i])
    Faire
        A[i][j] ← k * A[i][j]
    FinPour
Fin

//2.

Preconditions: A est créé est initialisé et taille(A[i]) = taille(A[j])
Postconditions: retourne la matrice après l'operation Li ←→ Lj
Procedure permutation(A (E/S): tableau de tableau, i: Entier, j: Entier)
Variables
    k: Entier
    temp: type de valeur de A
Debut
    Pour k de 1 a taille(A[i])
    Faire
        temp ← A[i][k]
        A[i][k] ← A[j][k]
        A[i][k] ← temp
    FinPour
Fin

//3.

Preconditions: A est créé est initialisé taille(A[i]) = taille(A[j])
Postconditions: retourne la matrice après l'operation Li ← Li + kLj
Procedure transvection(A (E/S): tableau de tableau, i: Entier, j: Entier, k: Reel)
Variables
    k: Entier
Debut
    Pour k de 1 a taille(A[i]) 
    Faire
        A[i][k] ← A[i][k] + dilatation(A, j, k)
    FinPour
Fin