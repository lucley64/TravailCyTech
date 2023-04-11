<?php
session_start();
if (isset($_SESSION["login"])) {
    $json = json_decode(file_get_contents("php://input"), true);
    $qte = intval($json["produit"]["qte"]);
    $produit = $json["produit"]["nom"];
    if (!isset($_SESSION["panier"])) {
        $_SESSION["panier"][$produit] = $qte;
    } else {
        $_SESSION["panier"][$produit] += $qte;
    }
} else {
    http_response_code(401);
}
