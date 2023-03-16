# Modèle de langage de données

Ville(id, nom)
      ——

Implémenté(date, #idVille, #idBoulangerie)
                 ————————————————————————

Boulangerie(id, téléphone, latitude, longitude)
            ——

Propose(#idBoulangerie, #idPatisserie)
        —————————————————————————————

Pâtisserie(id, nom, prix)
           ——

Nécessite(quantité, #idPâtisserie, #idIngrédient)
                    ————————————————————————————

Ingrédient(id, nom)
           ——

Possede(quantite, #idBoulangerie, #idIngrédient)
                  —————————————————————————————
