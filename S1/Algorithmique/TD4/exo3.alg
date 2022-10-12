5.

Preconditions: A est créé est initialisé
Postconditions: A sous forme triangulaire
Procedure formeTriangulaire(A (E/S): tableau de tableau)
Variables
    i: Entier
Debut
    Pour i de 0 a longueur(A) 
    Faire
        zerosSousPivot(A, i)
    FinPour
Fin

6.

Preconditions: A est créé est initialisé
Postconditions: A sous forme triangulaire
Procedure formeTriangulaire2(A: tableau de tableau)
Variables
    i: Entier
    inversible: Booleen
Debut
    inversible ← VRAI
    Pour i de 0 a longueur(A) 
    Faire
        j ← i
        TantQue j ≤ longueur(A[i]) ET A[i][i] = 0
        Faire
            permutation(A, i, j)
            j ← j + 1
        FinTantQue
        Si A[i][i] = 0
        Alors
            inversible ← FAUX
        FinSi
    FinPour
    Si inversible = VRAI
    Alors
        Pour i de 0 a longueur(A) 
        Faire
            zerosSousPivot(A, i)
        FinPour
    FinSi
Fin