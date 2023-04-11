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
    <?php
    $invalid = "class = \"invalid\"";
    function testInput(string $data): string
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        if (empty($_POST['nomContact'])) {
            $nomErr = "Erreur, le nom est requis";
        } else {
            $nom = testInput($_POST['nomContact']);
        }
        if (empty($_POST['prenomContact'])) {
            $prenomErr = "Erreur, le prenom est requis";
        } else {
            $prenom = testInput($_POST['prenomContact']);
        }
        if (empty($_POST['mailContact'])) {
            $mailErr = "Erreur, le mail est requis";
        } else {
            $mail = testInput($_POST['mailContact']);
            if (!preg_match("/^[a-zA-Z0-9.!#$%&'*+\/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/", $mail)) {
                $mailErr = "L'adresse mail est invalide";
            }
        }
        if (empty($_POST['dateNaiss'])) {
            $dateNaissErr = "Erreur, la date de naissande est requise";
        } else {
            $dateNaiss = testInput($_POST['dateNaiss']);
            if ($dateNaiss > date("Y-m-d")) {
                $dateNaissErr = "Erreur, la date de naissance doit être inferieure à aujourd'hui";
            }
        }
        if (empty($_POST['sujetContact'])) {
            $sujetErr = "Erreur, le sujet est requis";
        } else {
            $sujet = testInput($_POST['sujetContact']);
        }
        if (empty($_POST['contenuContact'])) {
            $contenuErr = "Erreur, le contenu est requis";
        } else {
            $contenu = testInput($_POST['contenuContact']);
        }

        if (empty($_POST['genreContact'])) {
            $genreErr = "Erreur, le genre est requis";
        } else {
            $genre = testInput($_POST['genreContact']);
            if (!preg_match("/(homme|femme|autre)/", $genre)) {
                $genreErr = "Le genre est invalide";
            }
        }

        if (empty($_POST['fonctionContact'])) {
            $fonctionErr = "Erreur, le fonction est requis";
        } else {
            $fonction = testInput($_POST['fonctionContact']);
            if (!preg_match("/(eleve|enseignant|autre)/", $fonction)) {
                $fonctionErr = "La fonction est invalide";
            }
        }
    }


    if (!(isset($nomErr) || isset($prenomErr) || isset($mailErr) || isset($dateNaissErr) || isset($sujetErr) || isset($contenuErr) || isset($genreErr) || isset($fonctionErr))) {
        $file = fopen('./json/contacts.json', "r+");
        if ($file == null) {
            $file = fopen('./json/contacts.json', "w+");
        }
        if ($file) {
            fseek($file, 0, SEEK_END);
            if (ftell($file) > 0) {
                fseek($file, -1, SEEK_END);
                fwrite($file, ',', 1);
                fwrite($file, json_encode($_POST) . ']');
            } else {
                fwrite($file, json_encode(array($_POST)));
            }
            fclose($file);
        }
    }

    ?>
    <form action="" method="post" id="formContact">
        <label for="nomContact">Nom
            <input <?php if (isset($nomErr)) {
                        echo $invalid;
                    } ?> type="text" name="nomContact" id="nomContact" value="<?php echo $nom ?>" required />
            <span class="error <?php if (isset($nomErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $nomErr ?></span>
        </label>
        <label for="prenomContact">Prénom
            <input <?php if (isset($prenomErr)) {
                        echo $invalid;
                    } ?> type="text" name="prenomContact" id="prenomContact" value="<?php echo $prenom ?>" required />
            <span class="error <?php if (isset($prenomErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $prenomErr ?></span>
        </label>
        <label for="mailContact">Email
            <input <?php if (isset($mailErr)) {
                        echo $invalid;
                    } ?> type="email" name="mailContact" id="mailContact" value="<?php echo $mail ?>" required />
            <span class="error <?php if (isset($mailErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $mailErr ?></span>
        </label>
        <label id="genreContactLabel" for="genreContact">Genre
            <label for="homme">Homme
                <input type="radio" name="genreContact" id="homme" value="homme" <?php if (isset($genre) && $genre == "homme") {
                                                                                        echo "checked";
                                                                                    } ?> required />
            </label>
            <label for="femme">Femme
                <input type="radio" name="genreContact" id="femme" value="femme" <?php if (isset($genre) && $genre == "femme") {
                                                                                        echo "checked";
                                                                                    } ?> required />
            </label>
            <label for="autre">Autre
                <input type="radio" name="genreContact" id="autre" value="autre" <?php if (isset($genre) && $genre == "autre") {
                                                                                        echo "checked";
                                                                                    } ?> required />
            </label>
        </label>
        <label for="dateNaiss">Date de Naissance
            <input <?php if (isset($dateNaissErr)) {
                        echo $invalid;
                    } ?> type="date" name="dateNaiss" id="dateNaiss" tyle="resize: none;" value="<?php echo $dateNaiss ?>" required />
            <span class="error <?php if (isset($dateNaissErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $dateNaissErr ?></span>
        </label>
        <label for="fonctionContact">Fonction
            <select name="fonctionContact" id="fonctionContact">
                <option value="enseignant" <?php if (isset($fonction) && $fonction == "enseignant") {
                                                echo "selected";
                                            } ?>>Enseignant</option>
                <option value="eleve" <?php if (isset($fonction) && $fonction == "eleve") {
                                            echo "selected";
                                        } ?>>Éleve</option>
                <option value="autre" <?php if (isset($fonction) && $fonction == "autre") {
                                            echo "selected";
                                        } ?>>Autre</option>
            </select>
            <span class="error <?php if (isset($fonctionErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $fonctionErr ?></span>
        </label>
        <label for="sujetContact">Sujet
            <input <?php if (isset($sujetErr)) {
                        echo $invalid;
                    } ?> type="text" name="sujetContact" id="sujetContact" value="<?php echo $sujet ?>" required />
            <span class="error <?php if (isset($sujetErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $sujetErr ?></span>
        </label>
        <label for="contenuContact">Contenu
            <textarea <?php if (isset($contenuErr)) {
                            echo $invalid;
                        } ?> name="contenuContact" id="contenuContact" spellcheck="true" style="resize: none; height: 250px;" required><?php echo $contenu ?></textarea>
            <span class="error <?php if (isset($contenuErr)) {
                                    echo "active";
                                } ?>" aria-live="polite"><?php echo $contenuErr ?></span>
        </label>
        <button id="submitBtn">Envoyer</button>
    </form>
</body>
<script src="./js/contact.js"></script>

</html>