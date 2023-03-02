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
</head>

<body>
    <div id="logo">
        <img src="./img/1200px-Aperture_Science_Logo.svg.png"
         alt="Aperture science logo" height="100px" width="100px" />
    </div>
    <header>
        <h1>Magasin de la science Aperture</h1>
    </header>
    <div id="menu">
        <h2>Navigation</h2>
        <ul>
            <li><a id="lien-accueil" href="./accueil">Accueil</a></li>
            <li><a id="lien-science" href="./science">La science</a></li>
            <li><a id="lien-contact" href="./contact">Contact</a></li>
        </ul>
    </div>
    <main>
        <iframe onload="resizeIFrameToFitContent(this)" id="main-frame" <?php
                                $url = $_GET["url"];
                                if ($url == null) {
                                    $url = "accueil";
                                }
                                echo "src=\"$url.php\"";
                                phpinfo();
                                ?> title="Contenu"></iframe>
    </main>
    <footer>
        <p>Copyright Aperture Science</p>
        <br />
        <p>CY tech</p>
    </footer>
</body>
<script src="./js/main.js"></script>
</html>
