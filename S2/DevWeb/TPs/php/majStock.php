<?php
include "./bdd.php";

$cred = getCred("../config.json");
$host = $cred['bdd']['host'];
$db = $cred['bdd']['name'];
$user = $cred['bdd']['login'];
$passworddb = $cred['bdd']['password'];
session_start();

if (isset($_SESSION["panier"])) {
    $dbConnect = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
    $panier = $_SESSION["panier"];
    foreach ($panier as $key => $value) {
        $prod = explode(".", $key);
        $query = $dbConnect->prepare("UPDATE `Produit` SET `Stock` = `Stock` - $value WHERE `Id` = $prod[1]");
        $query->execute();
    }
    include "./viderPanier.php";
}
