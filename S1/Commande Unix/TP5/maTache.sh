#!/bin/bash
# shellcheck disable=SC2086

if [ $# -eq 1 ]; then
    if [ -d "$1" ]; then
        files=$(find "$1" -maxdepth 1 -executable -type f)
        sizes=$(ls -sh $files)
        count=$(echo $files | wc -w)
        printf "There is %s executables files in %s: \n%s\n" "$count" "$1" "$sizes"
        read -r -p "Move them to exec ? [Y/N] " awnser
        [ $awnser = "Y" ] && mkdir $1"exec" && mv $files $1"exec"
    else
        echo "$1 is not e diretory"
    fi
else
    echo "Command takes one parameter"
fi
