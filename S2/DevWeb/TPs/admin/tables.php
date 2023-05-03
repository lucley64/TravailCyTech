<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="../js/admin.js"></script>
    <title>Tables</title>
</head>

<body>
    <h1>
        <?php

        error_reporting(E_ALL);
        ini_set('display_errors', 'On');
        if (isset($_GET['table'])) {
            echo "Contenu de la table $_GET[table]";

            include "../php/bdd.php";
            $cred = getCred("../config.json");
            $host = $cred['bdd']['host'];
            $db = $cred['bdd']['name'];
            $user = $cred['bdd']['login'];
            $passworddb = $cred['bdd']['password'];

            $bd = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
            $query = "SELECT * FROM $_GET[table]";
            $data = $bd->query($query);
            $rows = $data->fetchAll();
            $data = $bd->query("SHOW COLUMNS FROM $_GET[table]");
            $cols = $data->fetchAll();
        } else {
            echo "Selectionner une table";
        }
        ?>
    </h1>
    <table>
        <thead>
            <tr>
                <?php
                if (isset($_GET['table'])) {
                    echo "<th> select </th>";
                    foreach ($cols as $key => $value) {
                        echo "<th> $value[Field] </th>";
                    }
                }
                ?>
            </tr>
        </thead>
        <tbody>
            <?php
            if (isset($_GET['table'])) {
                foreach ($rows as $key => $value) {
                    echo "<tr>";
                    echo "<td><input type='checkbox'></td>";
                    foreach ($cols as $n => $row) {
                        $field = $row["Field"];
                        echo "<td> $value[$field] </td>";
                    }
                    echo "</tr>";
                }
            }
            ?>
        </tbody>
    </table>
</body>

</html>