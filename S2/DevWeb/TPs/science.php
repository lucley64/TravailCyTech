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
    <div id="contenu">
        <div id="tab-buttons">
            <button onclick="openTab(this.innerHTML)">Experimental</button>
            <button onclick="openTab(this.innerHTML)">Utilitaires</button>
            <button onclick="openTab(this.innerHTML)">I.A.</button>
        </div>
        <div id="Experimental" class="tab">
            <table>
                <caption>
                    <h1>Experimental</h1>
                </caption>
                <thead>
                    <tr>
                        <th>
                            Image
                        </th>
                        <th>
                            Nom
                        </th>
                        <th>
                            Prix
                        </th>
                        <th>
                            Commande
                        </th>
                        <th class="qte" hidden>
                            Stock
                        </th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>
                            <img src="./img/Aperture_Science_Handheld_Portal_Device_Portal.webp" alt="portal gun" height="100" width="100" />
                        </td>
                        <td>
                            Aperture Science Quantum Tunneling Device
                        </td>
                        <td>
                            125 000 €
                        </td>
                        <td>
                            <input type="number" min=0 max="99"/>
                        </td>
                        <td class="qte" hidden>
                            25
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/P2_afp.webp" alt="afp" height="100" width="100" />
                        </td>
                        <td>
                            Plaque de foie aérienne d'Aperture Science
                        </td>
                        <td>
                            60 000 €
                        </td>
                        <td class="qte" hidden>
                            25
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/400px-Excursion_Funnel.jpeg" alt="ef" height="100" width="100" />
                        </td>
                        <td>
                            Tunnel D'éxcurtion d'Aperture Science
                        </td>
                        <td>
                            250 000 €
                        </td>
                        <td class="qte" hidden>
                            10
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/Early_Grill.jpg" alt="gem" height="100" width="100">
                        </td>
                        <td>
                            Grille d'émencipation matérielle d'Aperture Science
                        </td>
                        <td>
                            60 000 €
                        </td>
                        <td class="qte" hidden>
                            50
                        </td>
                    </tr>
                </tbody>
            </table>
        </div>
        <div id="Utilitaires" class="tab" hidden>
            <table>
                <caption>
                    <h1>Utilitaires</h1>
                </caption>
                <thead>
                    <tr>
                        <th>
                            Image
                        </th>
                        <th>
                            Nom
                        </th>
                        <th>
                            Prix
                        </th>
                        <th class="qte" hidden>
                            Stock
                        </th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>
                            <img src="./img/tumblr_m9nbkkBi1Z1rnrq03o1_1280.webp" alt="lfb" height="100" width="100">
                        </td>
                        <td>
                            Aperture Science Long Fall Boots
                        </td>
                        <td>
                            25 000 €
                        </td>
                        <td class="qte" hidden>
                            155
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/85.2_FM.webp" alt="asr" height="100" width="100">
                        </td>
                        <td>
                            Aperture Science Radio
                        </td>
                        <td>
                            100 €
                        </td>
                        <td class="qte" hidden>
                            5 000
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/Weighted_Storage_Cube_p2.webp" alt="wsc" height="100" width="100">
                        </td>
                        <td>
                            Cube de stockage lesté d'Aperture Science
                        </td>
                        <td>
                            500 €
                        </td>
                        <td class="qte" hidden>
                            66
                        </td>
                    </tr>
                </tbody>
            </table>
        </div>
        <div id="I.A." class="tab" hidden>
            <table>
                <caption>
                    <h1>Inteligences artificielles</h1>
                </caption>
                <thead>
                    <tr>
                        <th>
                            Image
                        </th>
                        <th>
                            Nom
                        </th>
                        <th>
                            Prix
                        </th>
                        <th class="qte" hidden>
                            Stock
                        </th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>
                            <img src="./img/Portal2_Turret_Standard.webp" alt="asst" height="100" width="100">
                        </td>
                        <td>
                            Tourelle automatique d'Aperture Science
                        </td>
                        <td>
                            150 000 €
                        </td>
                        <td class="qte" hidden>
                            50
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/Crap_turret.webp" alt="ascst" height="100" width="100">
                        </td>
                        <td>
                            Tourelle automatique au rabais d'Aperture Science
                        </td>
                        <td>
                            20 000 €
                        </td>
                        <td class="qte" hidden>
                            150
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/Wheatley_model.webp" alt="pc" height="100" width="100">
                        </td>
                        <td>
                            Cœur de personalité d'Aperture Science
                        </td>
                        <td>
                            200 000 €
                        </td>
                        <td class="qte" hidden>
                            2
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <img src="./img/Companion_Cube_p2.webp" alt="cc" height="100" width="100">
                        </td>
                        <td>
                            Cube de stockage lesté d'Aperture Science
                        </td>
                        <td>
                            1 000 000 €
                        </td>
                        <td class="qte" hidden>
                            395
                        </td>
                    </tr>
                </tbody>
            </table>
        </div>
        <button id="sockButton" onclick="afficherStock()">Afficher stocks</button>
    </div>
</body>

</html>