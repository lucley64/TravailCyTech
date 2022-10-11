#!/bin/bash

for item in "$@"; do
   case "${item}" in
    "(")
        echo "parenthèse ouvrante"
        ouvr=$(("$ouvr"+1))
        calc=$calc${item}
    ;;
    ")")
       echo 'parenthèse fermante'
       ouvr=$(("$ouvr"-1))
        calc=$calc${item}
    ;;
    "+")
        echo "addition"
        oper=$(("$oper"+1))
        ent=0
        if [ $oper -gt 1 ]; then
            echo "** erreur alternance **"
            exit 1
            break
        fi
        calc=$calc${item}
    ;;
    "-")
        echo "soustraction"
        oper=$(("$oper"+1))
        ent=0
        if [ $oper -gt 1 ]; then
            echo "** erreur alternance **"
            exit 1
            break
        fi
        calc=$calc${item}
    ;;
    "*")
        echo "multiplication"
        oper=$(("$oper"+1))
        ent=0
        if [ $oper -gt 1 ]; then
            echo "** erreur alternance **"
            exit 1
            break
        fi
        calc=$calc${item}
    ;;
    "/")
        echo "division"
        oper=$(("$oper"+1))
        ent=0
        if [ $oper -gt 1 ]; then
            echo "** erreur alternance **"
            exit 1
            break
        fi
        calc=$calc${item}
    ;;
    *)
        echo "entier"
        oper=0
        ent=$(("$ent"+1))
        if [ $ent -gt 1 ];then
            echo "** erreur alternance **"
            exit 1
            break
        fi
        calc=$calc${item}
    ;;
   esac
done

[ $ouvr = 0 ] || echo "** erreur parenthèse ! **"
[ $ouvr = 0 ] || exit 1



echo $(("$calc"))