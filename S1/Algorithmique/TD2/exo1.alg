1. 
Enregistrement Etudiant
    nom : chaine de caractères
    prénom : chaine de caractères
    moyenne : réel
FinEnregistrement

2. 
precondition : fonction taille déjà existante
postcondition : chaque étudiant à un nom, prénom et une moyenne
Algorithme calcul de moyennes
Variables
    nbNotes, i, j : entier
    notes, uneNote : réel
    etudiants : tableau[1..20] de Etudiant
Début
    Pour i de 1 à taille(etudiants)
    Faire
        écrire("Étudiant n° ", i, " : ")
        écrire("Saisir le nom de l'étudiant")
        lire(etudiants[i].nom)
        écrire("Saisir le prénom de l'étudiant")
        lire(etudiants[i].prénom)
        écrire("Saisir le nombre de notes de l'étudiant")
        lire(nbNotes)
        notes <- 0
        Pour j de 1 à nbNotes
        Faire
            écrire("Saisir la ", j, "note : ")
            lire(uneNote)
            notes <- notes + uneNote
        FinPour
        etudiants[i].moyenne <- notes / nbNotes
    FinPour

    Pour i de 1 à taille(etudiants)
        écrire("Étudiant n°", i, " : ", etudiants[i].nom, " ", etudiants[i].prénom, " moyenne : ", etudiants[i].moyenne)
    FinPour
Fin
