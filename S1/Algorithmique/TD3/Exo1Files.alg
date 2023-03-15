//1.

precond: on suppose que la file f est cree et initialisee
postcond: procedure qui inverse les elements de f
Procedure inverserfile(E/S f: file)
Variables
tempPile: file de type delement de la file f
temp: type delement de la file f
Debut
creerPile(tempPile)
TantQue NON estVide(f)
Faire
temp <- premier(f)
defiler(f)
empiler(tempPile, temp)
FinTantQue
TantQue NON estVide(tempPile)
Faire
temp <- sommet(tempPile)
depiler(tempPile)
enfiler(f, temp)
FinTantQue
Fin

//2.
precond: on suppose que la file f est cree et initialisee
postcond: fonction que retourne le nombre d elements de la file f
Fonction taille(f: file): entier
Variables
    retour: entier
Debut
    retour <- 0
    TantQue NON estVide(f)
    Faire
        defiler(f)
        retour <- retour + 1
    FinTantQue
    retourner(retour)
Fin

//3.
