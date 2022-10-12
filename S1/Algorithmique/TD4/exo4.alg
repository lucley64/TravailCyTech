7.

Preconditions: A est initialisé et créé
Postconditions: zéros au-dessus du pivot choisi
Procedure zerosSurPivot(A (E/S): tableau de tableau, i: Entier)
Variables
    j: Entier
Debut
    Si i ≠ 1
    Alors
        Pour j de 1 a i-1
        Faire
            transvection(A, j, i, -1)
        FinPour
    FinSi
Fin