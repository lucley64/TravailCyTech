<!DOCTYPE html>
<html lang="fr" xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta name="description" content="a" />
    <meta name="keywords" content="a" />
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="./css/style.css" />
    <title>Magasin de la science Aperture</title>
    <script src="./js/main.js"></script>
</head>

<body>
    <div id="logo">
        <a href="."><img src="./img/1200px-Aperture_Science_Logo.svg.png" alt="Aperture science logo" height="100px" width="100px" /></a>
    </div>
    <header>
        <h1>Magasin de la science Aperture</h1>
    </header>
    <div id="menu">
        <button id="navBtn" onclick="toggleNav(this.nextElementSibling)"><img src="./img/56763.png" alt="nav" height="12px" width="12px"></button>
        <div id="navCont" hidden>
            <div id="users">
                <?php
                session_start();
                if (isset($_SESSION['login'])) {
                    echo "<button class=\"nav\" onclick=\"window.location.href='logout.php'\">Se Déconnecter</button>";
                } else {
                    echo "<button class=\"nav\" onclick=\"window.location.href='login.php'\">Se connecter</button>";
                    echo "<button class=\"nav\" onclick=\"window.location.href='signin.php'\">Créer compte</button>";
                }
                ?>
            </div>
            <h2>Navigation</h2>
            <button id="<?php if ($_GET['menu'] != "La science" && $_GET['menu'] != "Contact") {
                            echo "this";
                        } ?>" class="nav" onclick="changeUrl(event, 'accueil.php')">Accueil</button>
            <button id="<?php if ($_GET['menu'] == "La science") {
                            echo "this";
                        } ?>" class="nav" onclick="changeUrl(event, 'science.php<?php
                                                                                if ($_GET['cat']) {
                                                                                    echo "?cat=$_GET[cat]";
                                                                                } ?>')">La science</button>
            <button id="<?php if ($_GET['menu'] == "Contact") {
                            echo "this";
                        } ?>" class="nav" onclick="changeUrl(event, 'contact.php')">Contact</button>
        </div>
    </div>
    <main>
        <iframe onload="resizeIFrameToFitContent(this)" id="main-frame" title="Contenu"></iframe>
    </main>
    <footer>
        <p>Copyright Aperture Science</p>
        <br />
        <p>CY tech</p>
    </footer>
</body>

</html>