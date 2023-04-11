<?php
session_start();
if (isset($_SESSION["login"]) && isset($_SESSION["panier"])) {
    unset($_SESSION["panier"]);
} else {
    http_response_code(401);
}
