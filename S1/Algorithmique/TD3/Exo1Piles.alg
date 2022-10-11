(piles)
1.
precond: on suppose que la pile p est cree et initialisee
postcond: fonction qui retourne une copie de p
Fonction copierPile(p: pile): pile
Variables
    temp: delement de la pile p
    tempPile: pile
    retour: pile
Debut
    TantQue NON estVide(p)
    Faire
        temp <- sommet(p)
        depiler(p)
        empiler(tempPile, p)
    FinTantQue
    TantQue NON estVide(tempPile)
    Faire
        temp <- sommet(tempPile)
        depiler(tempPile)
        empiler(retour, temp)
    FinTantQue
    retourner(retour)
Fin


precond: on suppose que la pile p est cree et initialisee
postcond: procedure qui inverse les elements de p
Procedure inverserPile(E/S p: pile)
Variables
    tempPile: pile de type delement de la pile p
    temp: type delement de la pile p
Debut
    tempPile <- copierPile(p)
    creerPile(p)
    TantQue NON estVide(tempPile)
    Faire
        temp <- sommet(tempPile)
        depiler(tempPile)
        empiler(p, temp)
    FinTantQue
Fin

2.
precond: on suppose que la pile p est cree et initialisee
postcond: fonction qui retourne la taille de p
Fonction taille(E p: pile): entier
Variables
    size: entier
Debut
    size <- 0
    TantQue NON estVide(p)
    Faire
        depiler(p)
        size <- size + 1
    FinTantQue
    retourner(size)
Fin

3. 
precond: on suppose que la pile p est cree et initialisee
postcond: procedure qui insere un element e à la position pos dans la pile p
Procedure inserer(E/S p: pile, e: type delement de la pile, pos: entier)
Variables
    tempPile: pile de type delement de la pile p
    temp: type delement de la pile
    i: entier
Debut
    tempPile <- copierPile(p)
    creerPile(p)
    i <- 1
    TantQue NON estVide(tempPile)
    Faire
        Si i = pos
        Alors
            empiler(p, e)
        Sinon
            temp <- sommet(tempPile)
            depiler(tempPile)
            empiler(p, temp)
        FinSi
        i <- i + 1
    FinTantQue
    inverserPile(p)
Fin

4. 
precond: on suppose que la pile p est cree et initialisee
postcond: procedure qui retire l element de la pile p a la position pos
Procedure supprimer(E/S p: pile, pos: entier)
Variables
    tempPile: pile de type delement de la pile p
    temp: type delement de la pile
    i: entier
Debut
    i <- 1
    TantQue NON i = pos
    Faire
        temp <- sommet(p)
        depiler(p)
        empiler(tempPile, temp)
        i <- i + 1
    FinTantQue
    depiler(p)
    TantQue NON estVide(tempPile)
    Faire
        temp <- sommet(tempPile)
        depiler(tempPile)
        empiler(p, temp)
    FinTantQue
Fin

5. 
precond: on suppose que la pile p est cree et initialisee
postcond: fonction indique la presence de l element e dans la pile p
Fonction trouver(p: pile, e: type delement de la pile): booleen
Variables
    retour: booleen

Debut
retour <- faux
    TantQue (NON estVide(p) ET NON retour)
    Faire
        Si sommet(p) = e
            retour = vrai
        Sinon
            depiler(p)
        FinSi
    FinTantQue
    retourner(retour)
Fin