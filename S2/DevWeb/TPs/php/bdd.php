<?php
function getCred(string $pathToCfg)
{
    return json_decode(file_get_contents($pathToCfg), true);
}

function getLogin()
{
    $cfg = getJson();
    return $cfg['bdd']['login'];
}

function getPassword()
{
    $cfg = getJson();
    return $cfg['bdd']['password'];
}

function getHost()
{
    $cfg = getJson();
    return $cfg['bdd']['host'];
}

function getBdd()
{
    $cfg = getJson();
    return $cfg['bdd']['name'];
}


function getJson()
{
    return json_decode(file_get_contents("./config.json"), true);
}
