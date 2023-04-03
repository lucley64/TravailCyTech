<!DOCTYPE html>
<html lang="fr" xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta name="description" content="rien" />
    <meta name="keywords" content="rien" />
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="./css/contactStyle.css" />
    <title>Accueil</title>
</head>

<body>
    <h1>Nous contacter</h1>
    <form action="" method="post" id="formContact">
        <label for="nomContact">Nom
            <input type="text" name="nomContact" id="nomContact" required />
        </label>
        <label for="prenomContact">Prénom
            <input type="text" name="prenomContact" id="prenomContact" required />
        </label>
        <label for="mailContact">Email
            <input type="email" name="mailContact" id="mailContact" required />
        </label>
        <label id="genreContactLabel" for="genreContact">Genre
            <label for="homme">Homme
                <input type="radio" name="genreContact" id="homme" required />
            </label>
            <label for="femme">Femme
                <input type="radio" name="genreContact" id="femme" required />
            </label>
            <label for="autre">Autre
                <input type="radio" name="genreContact" id="autre" required />
            </label>

        </label>
        <label for="dateNaiss">Date de Naissance
            <input type="date" name="dateNaiss" id="dateNaiss" tyle="resize: none;" required />
        </label>
        <label for="fonctionContact">Fonction
            <select name="fonctionContact" id="fonctionContact">
                <option value="enseignant">Enseignant</option>
                <option value="eleve">Éleve</option>
                <option value="autre">Autre</option>
            </select>
        </label>
        <label for="sujetContact">Sujet
            <input type="text" name="sujetContact" id="sujetContact" required />
        </label>
        <label for="contenuContact">Contenu
            <textarea name="contenuContact" id="contenuContact" spellcheck="true" style="resize: none; height: 250px;" required></textarea>
        </label>
        <button id="submitBtn">Envoyer</button>
    </form>
</body>
<script src="./js/contact.js"></script>

</html>