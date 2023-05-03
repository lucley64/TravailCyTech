<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <link rel="stylesheet" href="../css/style.css" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="../js/admin.js"></script>

    <title>The lair</title>
</head>

<body>

    <header>
        <h1>Page d'adminitration</h1>
    </header>
    <button class="nav" onclick="window.location.href='..'">Retour</button>
    <div id=menu>
        <div id="navCont">
            <p> Liste des tables: </p>
            <?php

            include "../php/bdd.php";

            $cred = getCred("../config.json");
            $host = $cred['bdd']['host'];
            $db = $cred['bdd']['name'];
            $user = $cred['bdd']['login'];
            $passworddb = $cred['bdd']['password'];

            $bd = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);

            $query = $bd->query("SHOW tables;");

            while ($row = $query->fetch()) {
                echo "<button class=\"nav\" onclick=\"iframeTo(this)\">$row[0]</button>";
            }

            ?>
        </div>
    </div>

    <main><iframe id="main" height="500px" title="contenu" src="tables.php"></iframe></main>
</body>

</html>