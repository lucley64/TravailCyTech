//4.
Enregistrement Étudiant
    numéro: Entier
    nom: chaîne
    prénom: chaîne
    promo: chaîne
    groupe: chaîne
FinEnregistrement

Annuaire: Map<Entier> de Étudiant

//5.
Preconditions: Annuaire créé et initialisé
Postconditions: ajouter un nouvel étudiant dans l'ensemble
Fonction ajoutÉtud(annuaire: Map<Entier> de Étudiant, numéroÉtud: Entier, nom: chaîne, prénom: chaîne, promo: chaîne, groupe: chaîne): Booleen
Variables
    étudiant: Étudiant
Debut
    Si (NON clefExiste(annuaire, numéroÉtud)) 
        ET (promo = "CPI1" OU promo = "CPI2" OU promo = "ING1" OU promo = "ING2" OU promo = "ING3") 
        ET (groupe = "A" OU groupe = "B" OU groupe = "C" OU groupe = "D" OU groupe = "E")
    Alors
        étudiant.numéro  ← numéroÉtud
        étudiant.nom     ← nom
        étudiant.prénom  ← prénom
        étudiant.promo   ← promo
        étudiant.groupe  ← groupe
        stocker(annuaire, numéroÉtud, étudiant)
    Sinon
        retourner(faux)
    FinSi
Fin

//6.
Preconditions: Annuaire créé et initialisé
Postconditions: supprimer un étudiant dans l'ensemble
Procedure nom(annuaire: Map<Entier> de Étudiant, étudiant: Étudiant)
Variables
Debut
    Si clefExiste(annuaire, étudiant.numéro)
    Alors
        supprimer(annuaire, étudiant.numéro)
    FinSi
Fin

//7.
Preconditions: Annuaire créé et initialisé
Postconditions: rechercher un étudiant en fonction de son nom
Fonction nom(annuaire: Map<Entier> de Étudiant, nom: chaîne):Entier
Variables
    nums: Liste de Entier
    numéroÉtud: Entier
    nbMatch: Entier
Debut
    creerListe(nums)
    listeClefs(annuaire, nums)
    nbMatch ← 0

    TantQue NON estVide(nums)
    Faire
        Si valeurDe(annuaire, tête(nums)).nom = nom
        Alors
            nbMatch ← nbMatch + 1
            numéroÉtud ← tête(nums)
        FinSi
        nums ← reste(nums)
    FinTantQue

    Selon nbMatch
    Cas 0
        retourner(-1)
    Cas 1
        retourner(numéroÉtud)
    Defaut
        retourner(0)
    FinSelon
Fin

//8.
Preconditions: Annuaire créé et initialisé
Postconditions: recherche un numéro d'étudiant dans l'ensemble et qui affiche soit le nom, le prénom, la promo et le groupe
Procedure rechercherDans(annuaire: Map<Entier> de Étudiant, numéroÉtud: Entier)
Variables
    find: Étudiant
Debut
    Si clefExiste(annuaire, numéroÉtud)
    Alors
        find ← valeurDe(annuaire, numéroÉtud)
        afficher("Nom : ", find.nom, ", Prénom : ", find.prénom, ", Promo : ", find.promo, ", Groupe : ", find.groupe)
    Sinon
        afficher("Étudiant inexistant!")
    FinSi
Fin

//9.
Preconditions: Annuaire créé et initialisé
Postconditions: afficher le nombre d'étudiants
Procedure nbÉtud(annuaire: Map<Entier> de Étudiant)
Variables
Debut
    afficher("Nombre d'étudiants : ", cardinalite(annuaire))
Fin

//10.

Preconditions: Annuaire créé et initialisé
Postconditions: postcond
Procedure nom(annuaire: Map<Entier> de Étudiant)
Variables
    nbCPI1: Entier  
    nbCPI2: Entier  
    nbING1: Entier  
    nbING2: Entier  
    nbING3: Entier 
    listeClefs: Liste de Entier
Debut
    creerListe(listeClefs)
    nbCPI1 ← 0
    nbCPI2 ← 0
    nbING1 ← 0
    nbING2 ← 0
    nbING3 ← 0
    listeClefs(annuaire, listeClefs)

    TantQue NON estVide(listeClefs)
    Faire
        Selon valeurDe(annuaire, tête(listeClefs)).promo
        Cas "nbCPI1"
            nbCPI1 ← nbCPI1 + 1
        Cas "nbCPI2"
            nbCPI2 ← nbCPI2 + 1
        Cas "nbING1"
            nbING1 ← nbING1 + 1
        Cas "nbING2"
            nbING2 ← nbING2 + 1
        Cas "nbING3"
            nbING3 ← nbING3 + 1
        Defaut
            
        FinSelon
    FinTantQue

    afficher("Nombre de CPI1 : ", nbCPI1, ", Nombre de CPI2 : ", nbCPI2, ", Nombre de ING1 : ", nbING1, ", Nombre de ING2 : ", nbING2, ", Nombre de ING3 : ", nbING3)

Fin

//11.
