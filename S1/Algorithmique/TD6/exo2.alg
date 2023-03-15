//2)

Preconditions: tab est initialisé
Postconditions: tab est trié
Fonction triBulle(tab: tableau de Reel):tableau de Reel
Variables
    i, j: Entier
    temp: Reel
Debut
    Pour i de 1 a taille(tab) 
    Faire
        Pour j de 1 a taille(tab) - i 
        Faire
            Si tab[j] > tab[j+1]
            Alors
                temp ← tab[j]
                tab[j] ← tab[j+1]
                tab[j+1] ← temp
            FinSi
        FinPour
    FinPour
    retouner(tab)
Fin

// 