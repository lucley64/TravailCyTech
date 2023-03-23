<?php

namespace DevWeb;

session_start();


$json = file_get_contents("../json/produits.json");
$_SESSION['produits'] = $json;
