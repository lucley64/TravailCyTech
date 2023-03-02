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
        <label for="nomContact">Nom</label>
        <input type="text" name="nomContact" id="nomContact" required/>
        <label for="prenomContact">Prénom</label>
        <input type="text" name="prenomContact" id="prenomContact" required/>
        <label for="mailContact">Email</label>
        <input type="email" name="mailContact" id="mailContact" required/>
        <label for="genreContact">Genre</label>
        <div id="genreContactDiv">
            <input type="radio" name="genreContact" id="homme" required/>
            <label for="homme">Homme</label>
            <input type="radio" name="genreContact" id="femme" required/>
            <label for="femme">Femme</label>
            <input type="radio" name="genreContact" id="autre" required/>
            <label for="autre">Autre</label>
        </div>
        <input type="hidden" name="genreContact" id="genreContact">
        <label for="dateNaiss">Date de Naissance</label>
        <input type="date" name="dateNaiss" id="dateNaiss" tyle="resize: none;" required/>
        <label for="fonctionContact">Fonction</label>
        <select name="fonctionContact" id="fonctionContact">
            <option value="enseignant">Enseignant</option>
            <option value="eleve">Éleve</option>
            <option value="autre">Autre</option>
        </select>
        <label for="sujetContact">Sujet</label>
        <input type="text" name="sujetContact" id="sujetContact" required/>
        <label for="contenuContact">Contenu</label>
        <textarea name="contenuContact" id="contenuContact" spellcheck="true" style="resize: none; height: 250px;" required></textarea>
        <button id="submitBtn">Envoyer</button>
    </form>
    <div id=ErrorContainer>
        <?php
        foreach ($_POST as $key => $value) {
            if ($_POST[$key] == "") {
                echo "<p name=$key>Ce champ est requis</p>";
                break;
            }
        }
        ?>
    </div>
</body>
<script src="./js/contact.js"></script>

</html>