// tri par insertion

Preconditions: tab initialisé
Postconditions: tableau trié
Fonction TriParInsertion(tab: tableau d'Entier): tableau d'Entier
Variables
    tab: tableau d'Entier
    last, i, j, temp: Entier
Debut
    last ← tab[1]                           1
    Pour i de 2 à taille(tab)               n - 2 
    Faire  
        Si tab[i] < last                    n - 2
        Alors
            Pour j de i a 2                 (n - 2)²
            Faire
                Si tab[j] < tab[j-1]        (n - 2)²
                Alors
                    temp ← tab[j-1]         (n - 2)²
                    tab[j-1] ← tab[j]       (n - 2)²
                    tab[j] ← temp           (n - 2)²
                FinSi
            FinPour
        FinSi
        last ← tab[i]                       n - 2
    FinPour
    renvoie(tab)                            1
Fin

/*
    T(n) = 2 + 3(n-2) + 5(n-2)²
         = 2 + 3n - 6 + 5n² - 20n + 4
         = 5n² - 17n
*/

// tri par sélection

Preconditions: tab initialisé, max(tab, taille) renvoie la position du maximum d'un tableau
Postconditions: tab trié par insertion
Fonction triSelection(tab: tableau d'Entier): tableau d'Entier
Variables
    tab: tableau d'Entier
    i, n, max, temp: Entier
Debut
    n ← taille(tab)             1
    Pour i de 1 a taille(tab)   n-1
    Faire
        max ← max(tab, n)       n (2 + 3(n-1)) = 2n + 3n(n-1) = 2n + 3n² - 2n = 3n²
        temp ← tab[n]           n-1
        tab[n] ← tab[max]       n-1
        tab[max] ← temp         n-1
        n ← n - 1               n-1
    FinPour
Fin

Preconditions: listeEntree initialisé
Postconditions: le maximum
Fonction max(listeEntree: chaine Reel, n: Reel):Reel
Variables
    max, i: Reel
Debut
    max ← 1                                                 // 1
    Pour i de 1 a n                                         // n-1
    Faire
        Si listeEntree[i] > listeEntree[max]                // n-1
        Alors
            max ← i                                         // n-1
        FinSi
    FinPour
    retourner(max)                                          // 1
Fin

/*
    T(n) = 1 + 5(n-1) + 3n²
         = 1 + 5n - 5 + 3n²
         = 3n² + 5n - 4
*/