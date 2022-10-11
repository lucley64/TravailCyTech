#!/bin/bash

for item in "$@"; do
   case "${item}" in
    "(")
        echo "parenthèse ouvrante"
        calc=$calc${item}
    ;;
    ")")
       echo 'parenthèse fermante'
       calc=$calc${item}
    ;;
    "+")
        echo "addition"
        calc=$calc${item}
    ;;
    "-")
        echo "soustraction"
        calc=$calc${item}
    ;;
    "*")
        echo "multiplication"
        calc=$calc${item}
    ;;
    "/")
        echo "division"
        calc=$calc${item}
    ;;
    *)
        echo "entier"
        calc=$calc${item}
    ;;
   esac
   
done

echo $(("$calc"))