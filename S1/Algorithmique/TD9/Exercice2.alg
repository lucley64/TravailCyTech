Enregistrement Contact
    téléphone:chaîne
    nomPrénom:chaîne
FinEnregistrement


//3.
Preconditions: precond
Postconditions: postcond
Procedure ajoutNum(contact: Contact, annuaire: tableau de liste de Contact)
Variables
    indice: Entier
Debut
    indice ← hashTel(contact.téléphone)

    ajouter(annuaire[indice], contact)
Fin

//4.

Preconditions: precond
Postconditions: postcond
Fonction cherchPers(num: Chaîne, listeCherch: liste de Contact):Chaîne
Variables
Debut
    TantQue NON estVide(listeCherch)
    Faire
        Si tête(listeCherch) = num
        Alors
            retourner(tête(listeCherch).nomPrénom)
        FinSi
        listeCherch ← reste(listeCherch)
    FinTantQue
    retourner("")
Fin

//5.
Preconditions: precond
Postconditions: postcond
Fonction cherchPers(num: Chaîne, annuaire: tableau de liste de Contact):Chaîne
Variables
    indice: Entier
Debut
    indice ← hashTel(num)

    retourner(cherchPers(num, annuaire[indice]))
Fin

//6.
//1. 
hashTel = 45
cherchPers /*4*/ = (n/10) * (1 + 1) + 1 = 2(n/10)+1
cherchPers /*5*/ = 45 + 2(n/10) + 1 + 1 = 2(n/10) + 47

//3 la méthode sarait 10 × plus couteuse

//7.
Enregistrement Elem
    indice:Entier
    donné: Element
FinEnregistrement

Preconditions: precond
Postconditions: postcond
Fonction cardinalité(m: tableau de liste de Elem):Entier
Variables
    n: Entier
Debut
    n ← 0
    Pour i de 1 a taille(m)
    Faire
        n ← n + taille(m[i])
    FinPour
    retourner(n)
Fin

Preconditions: precond
Postconditions: postcond
Procedure stocker(m: tableau de liste de Elem, elem: Elem)
Variables
    indice: Entier
Debut
    indice ← hachage(elem.indice)

    ajouter(m[indice], elem)
Fin

Preconditions: precond
Postconditions: postcond
Fonction valeurDe(m: tableau de liste de Elem, indice: Entier):Element
Variables
    ind: Entier
    listeCherch: liste de Elem
Debut
    ind ← hachage(indice)
    listeCherch ← m[indice]

    TantQue NON estVide(listeCherch)
    Faire
        Si tête(listeCherch).indice = indice
        Alors
            retourner(tête(listeCherch).donné)
        FinSi
        listeCherch ← reste(listeCherch)
    FinTantQue
Fin

Preconditions: precond
Postconditions: postcond
Procedure supprimer(m: tableau de liste de Elem, indice: Entier)
Variables
    ind: Entier
    listeCherch: liste de Elem
    trouvé: Booleen
Debut
    ind ← hachage(indice)
    listeCherch ← m[indice]
    trouvé ← faux

    TantQue NON estVide(listeCherch) ET NON trouvé
    Faire
        Si tête(listeCherch).indice = indice
        Alors
            tête(listeCherch) ← rien
            trouvé ← vrai
        FinSi
        listeCherch ← reste(listeCherch)
    FinTantQue
Fin

Preconditions: precond
Postconditions: postcond
Fonction cléExiste(m: tableau de liste de Elem, indice: Entier):Booleen
Variables
    ind: Entier
    listeCherch: liste de Elem
Debut
    ind ← hachage(indice)
    listeCherch ← m[indice]

    TantQue NON estVide(listeCherch)
    Faire
        Si tête(listeCherch).indice = indice
        Alors
            retourner(vrai)
        FinSi
        listeCherch ← reste(listeCherch)
    FinTantQue
Fin