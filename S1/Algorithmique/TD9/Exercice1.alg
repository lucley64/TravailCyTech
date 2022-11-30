//1.
Preconditions: fonction sqrt, fonction ent retourne la partie entiere
Postconditions: fonction de hachage
Fonction hashage1(k: Reel):Reel
Variables
    A: Reel
    ret: Reel
    m : Entier
Debut
    A ← (sqrt(5) - 1) / 2
    m ← 1000
    ret ← ent(m × (k × A - ent(k × A)))

    retourner(ret)
Fin



//2.

Preconditions: procédure convertir qui prend chaîne de caractères en un tableau d'entiers
Postconditions: postcond
Fonction hashTel(num: chaîne):Entier
Variables
    tabNum: tebleau de caractères
    sum: Entier
Debut
    convertir(num, tabNum)
    sum ← 0
    Pour i de 1 a taille(tabNum)
    Faire
        sum ← sum + tabNum[i]
    FinPour

    sum ← sum mod 10

    retourner(sum)
Fin

1 + 1 + 1 + 10 * ( 1 + 1 + 1 + 1) + 1 + 1 = 45