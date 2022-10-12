#!/usr/bin/env bash

echo "$#"

if [ $# != 1 ]; then
    echo "c'est bon"
    exit 1
fi

mkdir Partiel

if [ -f "$1" ]; then
    find -name "$1" -exec mv {} Partiel/ \;
fi
