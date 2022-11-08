// 1.

Preconditions: 
Postconditions: suite de fibonacci
Fonction fibonacci(n: Entier):Entier
Variables
    
Debut
    Selon n
    Cas 0
        retourner(0)
    Cas 1
        retourner(1)
    Defaut
        retourner(fibonacci(n - 1) + fibonacci(n - 2))
    FinSelon
Fin

// 2.
Preconditions: 
Postconditions: invertion des elements d'un tableau
Procedure inverserTab((E/S) t: tableau)
Variables
    n: Entier
Debut
    n ← taille(t)
    
Fin