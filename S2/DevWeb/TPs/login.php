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
    <title>login</title>
</head>

<body>
    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $db = "ProduitsScience";
        $host = "localhost";
        $user = "user";
        $passworddb = "password";
        $errEmpty = "Veuillez remplir ce champ.";
        $login = $_POST['login'];
        $password = $_POST['mdp'];
        if (empty($login)) {
            $loginErr = $errEmpty;
        }
        if (empty($password)) {
            $passwordErr = $errEmpty;
        }
        if (!(isset($loginErr) || isset($passwordErr))) {
            $dbConnect = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
            $request = $dbConnect->query("select login from user where login = '$login'");
            $fetch = $request->fetch();
            if (!isset($fetch[0])) {
                $loginErr = "Le login est invalide.";
            } else {
                $request = $dbConnect->query("select * from user u JOIN role r on r.Id = u.role where u.login = '$login' and u.password = '$password'");
                $fetch = $request->fetch();
                if (!isset($fetch[0])) {
                    $loginErr = "Le mot de passe est invalide.";
                } else {
                    session_start();
                    $_SESSION["login"] = $login;
                    $_SESSION["role"] = $fetch["Niveau"];
                    $_SESSION["id"] = $fetch["Id"];
                    $_SESSION["panier"] = json_decode($fetch["Panier"], true);
                    header('location: index.php');
                }
            }
        }
    }
    ?>
    <div id="container">
    <button onclick="window.history.back()" class="nav">Retour</button>
        <h1>Se login</h1>
        <form action="" method="post" id="login">
            <label for="login"> Login
                <input <?php if (isset($loginErr)) {
                            echo $invalid;
                        } ?> type="text " name="login" id="loginInp">
                <span class="error <?php if (isset($loginErr)) {
                                        echo "active";
                                    } ?>" aria-live="polite"><?php echo $loginErr ?></span>
            </label>
            <label for="mdp"> Mot de passe
                <input <?php if (isset($passwordErr)) {
                            echo $invalid;
                        } ?> type="password" name="mdp" id="mdpInp">
                <span class="error <?php if (isset($passwordErr)) {
                                        echo "active";
                                    } ?>" aria-live="polite"><?php echo $passwordErr ?></span>
            </label>
        </form>
        <button class="val" onclick="login()">Login</button>
        <span class="no">Pas de compte ? <a href="./signin.php">Creer un compte</a></span>
    </div>
</body>

</html>