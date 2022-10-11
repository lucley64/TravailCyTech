1.
precondition : finction initZero qui initialise toutes les variables dun tableau à zéro
postcondition : un vecteur resultat du produit du vecteur par la matrice
Algorithme produit matrice x vecteur
Variables 
    i, j, longVec, longMat : entier
    matrice : tableau[][] de entier
    vecteur : tableau[] de entier
    resultat : tableau[] de entier
Début
    écrire("Saisir la longeur du vecteur (et par conséquent la hauteur de la matrice) : ")
    lire(longVec)
    affecterLongeur(vecteur, longVec)
    
    écrire("Saisir la longeur de la matrice : ")
    lire(longMat)
    affecterLongeur(matrice, longMat)
    affecterLongeur(resultat, longMat)


    Pour i de 1 à taille(matrice)
    Faire
        affecterLongeur(matrice[i], longVec)
        Pour j de 1 à taille(matrice[i])
        Faire
            écrire("Saisir la case ", i, " ", j, "de la matrice")
            lire(matrice[i][j])
        FinPour
    FinPour

    Pour i de 1 à taille(vecteur)
    Faire
        écrire("Saisir la ", i, "ème valeur du vecteur")
        lire(vecteur[i])
    FinPour

    initZero(resultat)

    Pour i de 1 à taille(matrice)
    Faire
        Pour j de 1 à taille(vecteur)
        Faire
            resultat[i] <- resultat[i] + matrice[i][j] * vecteur[j]
        FinPour
    FinPour


    écrire("Le résultat est : (")
    Pour i de 1 à taille(resultat) - 1
    Faire
        écrire(resultat[i], ", ")
    FinPour
    écrire(resultat[taille(resultat)], ")")
Fin

2. #TODO 
precondition : finction initZeroZero qui initialise toutes les variables dun tableau multidim à zéro et affecterLongeur qui affecte la longeur a un tableau
postcondition : un vecteur resultat du produit du vecteur par la matrice
Algorithme produit matrice x vecteur
Variables 
    i, j, k, longMat1, longMat2 : entier
    matrice1 : tableau[][] de entier
    matrice2 : tableau[][] de entier
    resultat : tableau[][] de entier
Début
    écrire("Saisir la longeur de la matrice1 (et par conséquent la hauteur de la matrice2) : ")
    lire(longMat1)
    affecterLongeur(matrice1, longVec)
    
    écrire("Saisir la longeur de la matrice2 : ")
    lire(longMat2)
    affecterLongeur(matrice2, longMat2)


    Pour i de 1 à taille(matrice1)
    Faire
        affecterLongeur(matrice1[i], longMat2)
        Pour j de 1 à taille(matrice1[i])
        Faire
            écrire("Saisir la case ", i, " ", j, "de la matrice")
            lire(matrice1[i][j])
        FinPour
    FinPour

    Pour i de 1 à taille(matrice2)
    Faire
        affecterLongeur(matrice2[i], longMat1)
        Pour j de 1 à taille(matrice2[i])
        Faire
            écrire("Saisir la case ", i, " ", j, "de la matrice")
            lire(matrice2[i][j])
        FinPour
    FinPour


    initZeroZero(resultat)

    Pour i de 1 à taille(matrice2)
    Faire
        Pour j de 1 à taille(matrice2)
        Faire
            Pour k de 1 à taille(matrice1)


    écrire("Le résultat est : ")
    écrire("(")
    Pour i de 1 à taille(resultat) - 1
    Faire
        écrire(resultat[i], ", ")
    FinPour
    écrire(resultat[taille(resultat)], ")")
Fin