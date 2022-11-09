// 1.

Preconditions: 
Postconditions: suite de fibonacci
Fonction fibonacci(n: Entier):Entier
Variables
    
Debut
    Si ≤ 1
    Alors
        retourner(n)
    Sinon
        retourner(fibonacci(n - 1) + fibonacci(n - 2))
    FinSi
Fin

// 2.
Preconditions: t est initialisé
Postconditions: invertion des elements d'un tableau
Procedure inverserTab((E/S) t: tableau)
Variables
Debut
    inverserTab(t, 1)
Fin


Preconditions: t est initialisé
Postconditions: invertion des elements d'un tableau
Procedure inverserTab((E/S) t: tableau, n: Entier)
Variables
    temp: Entier
Debut
    Si n < taille(t) mod 2
    Alors
        temp ← t[n]
        t[n] ← t[taille(t) + 1 - n]
        t[taille(t) + 1 - n] ← t[n]
        inverserTab(t, n + 1)
    FinSi
Fin

//3.

Preconditions: t est initialisé
Postconditions: recherche dans un tab non trié
Fonction chercheNonTrie(t: tableau d'Entier, r: Entier):Entier
Variables
Debut
    retourner(chercheNonTrie(t, r, 1))
Fin


Preconditions: t est initialisé
Postconditions: recherche dans un tab non trié
Fonction chercheNonTrie(t: tableau d'Entier, r: Entier, i: Entier):Entier
Variables
    
Debut
    Si i ≤ taille(t)
    Alors
        Si t[i] = r
        Alors
            retourner(i)
        Sinon
            retourner(chercheNonTrie(t, i + 1))
        FinSi
    Sinon
        retourner(0)
    FinSi
Fin

//4. 

Preconditions: t est initialisé
Postconditions: recherche dans un tab trié
Fonction chercheTrie(t: tableau d'Entier, r: Entier):Entier
Variables
Debut
    retourner(chercheTrie(t, r, 1, taille(t)))
Fin


Preconditions: t est initialisé
Postconditions: recherche dans un tab trié
Fonction chercheTrie(t: tableau d'Entier, r: Entier, deb: Entier, fin: Entier):Entier
Variables
    mid: Entier
Debut
    mid ← (fin - deb) mod 2
    Si mid = 0
    Alors
        retourner(0)
    Sinon
        Si r = t[mid]
        Alors
            retourner(mid)
        Sinon
            Si r < t[mid]
            Alors
                retourner(chercheTrie(t, r, deb, mid))
            Sinon
                retourner(chercheTrie(t, r, mid, fin))
            FinSi
        FinSi
    FinSi
Fin

