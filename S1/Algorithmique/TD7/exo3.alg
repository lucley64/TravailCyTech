//1.

// L’algorithme peut donc s’écrire de la manière suivante :
Algorithme Algo-triRapide
Debut
    n ← taille(A)
    TriRapide(A, 1, n)
Fin

Procedure TriRapide(E/S A : Tableau d'élément, p : Entier, r : Entier)
Variables
    q : Entier
Debut
    Si (p <r) Alors
        q = Partition(A, p, r)
        triRapide(A, p, q-1)
        triRapide(A, q+1, r)
    FinSi
Fin

Fonction Partition(E/S A : Tableau d'élément, p : Entier, r : Entier) :Entier
Variables
    x : élément
    i,j : Entier
Debut
    x = A[r ]
    i = p - 1
    Pour j de p à r-1
    Faire
        Si A[ j ] ≤x 
        Alors
            i = i + 1
            permuter( A[i ], A[ j ])
        FinSi
    FinPour
    permuter( A[i +1], A[r ])
    Retourner (i + 1)
Fin

//1
A = {2, 8, 7, 1, 3, 5, 6, 4}
TriRapide()
    A = {2, 8, 7, 1, 3, 5, 6, 4}
    p = 1
    r = 8
