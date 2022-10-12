4. 

Preconditions: A est créé est initialisé et A[i][i] ≠ 0
Postconditions: met des zéros au-dessous du pivot choisi
Procedure zerosSousPivot(A (E/S): tableau de tableau, i: Entier)
Variables
    j: Reel
Debut
    Si A[i][i] ≠ 1
    Alors
        dilatation(A, i, 1/a[i][i])
    FinSi

    Si i ≠ longueur(A[i])
    Alors
        Pour j de i+1 a longueur(A[i]) 
        Faire
            transvection(A, j, i, -1)
        FinPour
    FinSi
Fin

(2, 1, 0)
(1, 2, 3)
(2, 3, 3)