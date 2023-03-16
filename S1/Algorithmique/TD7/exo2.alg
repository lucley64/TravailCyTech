//1.

Preconditions: 
Postconditions: suite de fibonacci
Fonction fibonacciRT(n: Entier, acc1: Entier, acc2: Entier):Entier
Variables
Debut
    Si n ≤ 1
    Alors
        retourner(acc1)
    Sinon
        retourner(fibonacciRT(n - 1, acc1 + acc2, acc1))
    FinSi
Fin

Preconditions: 
Postconditions: suite de fibonacci
Fonction fibonacciRT(n: Entier):Entier
Variables
Debut
    retourner(fibonacciRT(n, 1, 0))
Fin



//2.
Preconditions: 
Postconditions: Approximation du nombre πpar la formule d'Euler non terminale
Fonction pi(precis: Entier):Reel
Variables
    
Debut
    Si precis ≤ 0
    Alors
        retourner(0)
    Sinon
        retourner(pi(precis - 1) + 1 / (precis * precis))
    FinSi
Fin

Preconditions: 
Postconditions: Approximation du nombre πpar la formule d'Euler terminale
Fonction piRT(precis: Entier, acc: Reel):Reel
Variables
    
Debut
    Si precis ≤ 0
    Alors
        retourner(acc)
    Sinon
        retourner(pi(precis - 1, (1 / (precis * precis)) + acc))
    FinSi
Fin

Preconditions: 
Postconditions: Approximation du nombre πpar la formule d'Euler terminale
Fonction piRT(precis: Entier):Reel
Variables
    
Debut
    retourner(pi(precis, 0))
Fin