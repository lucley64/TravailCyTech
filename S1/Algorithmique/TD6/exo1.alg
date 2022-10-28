//1)
//1.
Preconditions: abs(A: Entier): Entier, qui renvoi la valeur absolue de A
Postconditions: Divition euclidiene par methode des soustractions
Algorithme DivisionEuclidienne
Variables
    A, B, R, i: Entier
Debut
    ecrire("Saisir le nombre à diviser")
    lire(A)
    ecrire("Saisir le diviseur")
    lire(B)
    Si B ≠ 0
    Alors
        i ← 0
        B ← abs(B)
        R ← A
        Si A ≥ B
        Alors
            TantQue R ≥ B
            Faire
                R ← R - B
                i ← i + 1
            FinTantQue
        Sinon
            TantQue R ≤ B
            Faire
                R ← R + B
                i ← i + 1
            FinTantQue
        FinSi
        ecrire("Le cotient est ", i, " et le reste est ", R)
    FinSi
Fin

// Initialisation   : i = 0 et R = A, d'où Bi + R = B0 + A = A
// Conservation     : Bi'+R' = B(i+1) + (R-B) = Bi + B + R - B = Bi + R
// Terminaison      : 0 ≤ R ≤ B et A = Bi + R
// La propriété est la même dans le cas où A ≤ B, avec une addition à la place de la soustraction.


//2.

Preconditions: 
Postconditions: Calcul iteratif de la factorielle
Algorithme Factorielle
Variables
    A, i, R: Entier
Debut
    ecrire("Saisir le nombre la factorielle")
    lire(A)
    Si A ≥ 0
    Alors
        R ← 1
        Pour i de 2 a A 
        Faire
            R ← R × i
        FinPour
        ecrire("Le resultat est A! = ", R)
    FinSi
Fin

// Initialisation : i = 2 et R = 1 
// Conservation   : R' = R × i = (i-1)! * i = i!
// Terminaison    : on sort lorsque i = A+1 d'où R = ((n+1)-1)! = A!