Algorithme ACM (analyse des comparaisons multiples)
tq: la premiere a K1 modalite: {1,-,K1}
    les modalites de la seconde variable: {1,2,-,K2}

On note K = (sigma)Kj le nombre total de modalites
L'ensemble des modalites possibles est:  {1,2,-,K}

→ on considere le tableau disjonctif complet X associe aux donnees a I lignes et K colones: 
tq: Xij =   {1 si l'individu i a la modalite j
            {0 sinon

→ on pose   Z  = 1/K × X
            R  = le vecteur: somme des lignes de Z
            C  = _____________________ colones ___
            Dr = diag(R)
            Dc = diag(C)

→ on realise une decomposition en valaur singuliere de la matrice 
         -1/2      T  -1/2
    M = D   (Z - RC )D
         R            C

de sorte que: 
                   T
    M = P (delta) Q
    où P et Q sont des matrices unitaires
    (delta) = matrice contenant les valeurs singulieres

coordonees des individus: 
         -1/2
    F = D   P(delta)
         R

_______________ variables: 
         -1/2       T
    G = D   Q(delta)
         C