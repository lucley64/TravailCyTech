#!/bin/bash

for item in "$@"; do
   case "${item}" in
    "(")
        echo "parenthèse ouvrante"
    ;;
    ")")
       echo 'parenthèse fermante'
    ;;
    "+")
        echo "addition"
    ;;
    "-")
        echo "soustraction"
    ;;
    "*")
        echo "multiplication"
    ;;
    "/")
        echo "division"
    ;;
    *)
        echo "entier"
    ;;
   esac
   
done
