<?php
session_start();
if (isset($_SESSION["panier"])) {
    include "./php/bdd.php";
    $db = getBdd();
    $host = getHost();
    $user = getLogin();
    $passworddb = getPassword();
    $dbConnect = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
    $panier = json_encode($_SESSION["panier"], JSON_UNESCAPED_UNICODE);
    $panier = str_replace("'", "\'", $panier);
    $res = $dbConnect->prepare("UPDATE `user` SET `Panier` = '" . $panier . "' WHERE `id` = " . $_SESSION["id"]);
    var_dump($res->execute());
}
session_unset();
session_destroy();
header('location: index.php');
