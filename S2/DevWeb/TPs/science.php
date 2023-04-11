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
            <button class="menu" id="toggle" onclick="togglePanier(this)" >Voir panier</button>
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
            </div>
        </div>
        <?php
        $json = file_get_contents("json/produits.json");
        $obj = json_decode($json, true);

        $cats = $obj['categories'];

        echo "<div id=\"tab-buttons\">";
        foreach ($cats as $cat) {
            $id = "";
            if ($_GET['cat'] == $cat['nom']) {
                $id = "this-btn";
            }

            echo "<button id=\"" . $id . "\" class=\"menu\" onclick=\"openTab(this)\">$cat[nom]</button>";
        }
        echo "</div>";


        foreach ($cats as $cat) {
            echo "<div id=\"$cat[nom]\" class=\"tab\" hidden>
            <table>
                <caption>
                    <h1>$cat[nom]</h1>
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
            <tbody>
            ";
            foreach ($cat["produits"] as $value) {
                echo "<tr>
                
                <td>
                <img class=\"image\" src=\"$value[image]\" alt=\"$value[nom]\" height=\"100\" width=\"100\" />
            </td>
            <td>
                $value[nom]
            </td>
            <td>
                $value[prix] €
            </td>
            <td class=\"cmd\">
                <div class=\"counter\">
                    <button class=\"counter\" onclick=\"remCmd(this)\" disabled>-</button>
                    <input class=\"counter\" type=\"number\" value=\"0\" disabled />
                    <button class=\"counter\" onclick=\"addCmd(this)\">+</button>
                </div>
                <button name=\"$value[nom]\" id=\"panier\" class=\"panier\" onclick=\"ajouterAuPanier(this)\">Ajouter au panier</button>
            </td>
            <td class=\"qte\" hidden>
                $value[stock]
            </td>
                </tr>";
            }
            echo "</tbody>
            </table>
            </div>";
        }


        ?>
        <div id="downMenu">
            <button id="sockButton" class="menu" onclick="afficherStock()">Afficher stocks</button>
        </div>
    </div>
    <div id="zoomImage" hidden></div>
    <div id="zoomLens" hidden></div>
</body>

</html>