<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta name="description" content="a" />
    <meta name="keywords" content="a" />
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="./css/loginsignin.css">
    <script src="./js/loginsignin.js"></script>
    <title>signin</title>
</head>

<body>
    <?php
    function testInput(string $data): string
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    include "./php/bdd.php";
    $db = getBdd();
    $host = getHost();
    $user = getLogin();
    $passworddb = getPassword();
    $invalid = "class = \"invalid\"";
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $login = $_POST['login'];
        $mail = $_POST['mail'];
        $password = $_POST['mdp'];
        $passwordConfirm = $_POST['mdp2'];

        $errEmpty = "Veuillez remplir ce champ.";

        if (empty($login)) {
            $loginErr = $errEmpty;
        }
        if (empty($mail)) {
            $mailErr = $errEmpty;
        }
        if (empty($password)) {
            $passwordErr = $errEmpty;
        }
        if ($password != $passwordConfirm) {
            $passwordConfirmErr = "Le mot de passe doit être identique";
        }
        if (!preg_match("/^[a-zA-Z0-9.!#$%&'*+\/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/", $mail)) {
            $mailErr = "L'adresse mail est invalide";
        }

        if (!(isset($loginErr) || isset($mailErr) || isset($passwordConfirmErr) || isset($passwordErr))) {
            $dbConnect = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
            $res = $dbConnect->query("select * from user where login = '$login'");
            if (!$res->fetch()) {
                $res = $dbConnect->prepare("Insert into `user` (`mail`, `login`, `password`, `role`) values (?, ?, ?, ?)");
                $res->execute([$mail, $login, $password, 3]);
                session_start();
                $res = $dbConnect->query("select * from user where login = '$login' and password = '$password'");
                $fetch = $res->fetch();
                $_SESSION["login"] = $login;
                $_SESSION["role"] = 1;
                $_SESSION["id"] = $fetch["Id"];
                header('location: index.php');
            } else {
                $loginErr = "Erreur cet utilisateur existe déjà";
            }
        }
    }
    ?>
    <div id="container">
        <button onclick="window.location='./'" class="nav">Retour</button>
        <h1>Creer un compte</h1>
        <form action="" method="post" id="signin">
            <label for="login"> Login
                <input <?php if (isset($loginErr)) {
                            echo $invalid;
                        }
                        if (isset($login)) {
                            echo " value=" . $login;
                        } ?> type="text " name="login" id="loginInp">
                <span class="error <?php if (isset($loginErr)) {
                                        echo "active";
                                    } ?>" aria-live="polite"><?php echo $loginErr ?></span>
            </label>
            <label for="mail"> Email
                <input <?php if (isset($mailErr)) {
                            echo $invalid;
                        }
                        if (isset($mail)) {
                            echo " value=" . $mail;
                        }  ?> type="mail" name="mail" id="mailInp">
                <span class="error <?php if (isset($mailErr)) {
                                        echo "active";
                                    } ?>" aria-live="polite"><?php echo $mailErr ?></span>
            </label>
            <label for="mdp"> Mot de passe
                <input <?php if (isset($passwordErr)) {
                            echo $invalid;
                        }?> type="password" name="mdp" id="mdpInp">
                <span class="error <?php if (isset($passwordErr)) {
                                        echo "active";
                                    } ?>" aria-live="polite"><?php echo $passwordErr ?></span>
            </label>
            <label for="mdp2"> Repeter mot de passe
                <input <?php if (isset($passwordConfirmErr)) {
                            echo $invalid;
                        }?> type="password" name="mdp2" id="mdp2Inp">
                <span class="error <?php if (isset($passwordConfirmErr)) {
                                        echo "active";
                                    } ?>" aria-live="polite"><?php echo $passwordConfirmErr ?></span>
            </label>
        </form>
        <button onclick="signin()" class="val">Creer compte</button>
        <span class="no">Déjà un compte ? <a href="./login.php">Se connecter</a></span>
    </div>
</body>

</html>
