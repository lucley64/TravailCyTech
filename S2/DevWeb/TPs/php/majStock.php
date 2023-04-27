<?php
include "./bdd.php";
$db = getBdd();
$host = getHost();
$user = getLogin();
$passworddb = getPassword();
// $dbConnect = new PDO("mysql:host=" . $host . ";dbname=" . $db, $user, $passworddb);
session_start();
var_dump(getBdd());


