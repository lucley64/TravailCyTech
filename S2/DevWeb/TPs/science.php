<!DOCTYPE html>
<html lang="fr" xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta name="description" content="rien" />
    <meta name="keywords" content="rien" />
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Accueil</title>
    <script src="./js/science.js"></script>
    <link rel="stylesheet" href="./css/science.css">
</head>

<body>
    <?php
    session_start();
    ?>
    <div id="contenu">
        <div id="panier-menu" <?php if (!isset($_SESSION["panier"])) {
                                    echo "hidden";
                                } ?>>
            <button class="menu" id="toggle" onclick="togglePanier(this)">Voir panier</button>
            <div id="panier" hidden>
                <ul>
                    <?php
                    $panier = $_SESSION["panier"];
                    foreach ($panier as $key => $value) {
                        echo "<li>$key : $value</li>";
                    }
                    ?>

                </ul>
                <button class="menu" onclick="viderPanier(this)">Vider le panier</button>
                <button class="menu" onclick="commander(this)">Vider le panier</button>
            </div>
        </div>
        <?php
        include "./php/bdd.php";
        $db = getBdd();
        $host = getHost();
        $user = getLogin();
        $passworddb = getPassword();

        $dbConnect = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
        $request1 = $dbConnect->query("SELECT * FROM `Categorie`");

        $headbtn = "<div id=\"tab-buttons\">";
        $content = "";
        while ($cats = $request1->fetch()) {
            $id = "";
            if ($_GET['cat'] == $cats['Nom']) {
                $id = "this-btn";
            }

            $headbtn = $headbtn . "<button id=\"" . $id . "\" class=\"menu\" onclick=\"openTab(this)\">$cats[Nom]</button>";
            $request2 = $dbConnect->query("SELECT p.* FROM `Produit` p JOIN `Categorie` c ON c.Id = p.Categorie WHERE c.Id = $cats[Id]");
            $content = $content . "<div id=\"$cats[Nom]\" class=\"tab\" hidden>
            <table>
                <caption>
                    <h1>$cats[Nom]</h1>
                </caption>
                <thead>
                    <tr>
                    <th>Image</th>
                    <th>Nom</th>
                    <th>Prix</th>
                    <th>Commande</th>
                    <th class=\"qte\" hidden>Stock</th>
                    </tr>
            </thead>
            <tbody>";
            while ($value = $request2->fetch()) {
                $content = $content . "<tr>
                <td>
                    <img class=\"image\" src=\"$value[Image]\" alt=\"$value[Nom]\" height=\"100\" width=\"100\" />
                </td>
                <td class='name' id=$value[Id]>
                    $value[Nom]
                </td>
                <td>
                    $value[Prix] €
                </td>
                <td class=\"cmd\">
                    <div class=\"counter\">
                        <button class=\"counter\" onclick=\"remCmd(this)\" disabled>-</button>
                        <input class=\"counter\" type=\"number\" value=\"0\" disabled />
                        <button class=\"counter\" onclick=\"addCmd(this)\">+</button>
                    </div>
                    <button name=\"$value[Nom]\" id=\"panier\" class=\"panier\" onclick=\"ajouterAuPanier(this)\">Ajouter au panier</button>
                </td>
                <td class=\"qte\" hidden>
                    $value[Stock]
                </td>
                </tr>";
            }
            $content = $content."</tbody>
            </table>
            </div>";
        }
        echo $headbtn . "</div>";
        echo $content;


        ?>
        <div id="downMenu">
            <button id="sockButton" class="menu" onclick="afficherStock()">Afficher stocks</button>
        </div>
    </div>
    <div id="zoomImage" hidden></div>
    <div id="zoomLens" hidden></div>
</body>

</html>
