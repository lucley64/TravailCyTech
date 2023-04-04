<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta name="description" content="a" />
    <meta name="keywords" content="a" />
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>login</title>
</head>
<body>
    <h1>Se login</h1>
    <form action="" method="post" id="login">
        <label for="login"> Login
            <input type="text" name="login" id="loginInp">
        </label>
        <label for="mdp"> Mot de passe
            <input type="text" name="mdp" id="mdpInp">
        </label>
        <button type="submit" >Login</button>
    </form>
    <button onclick="window.location.href='./signin.php'">Creer compte</button>
</body>
</html>
