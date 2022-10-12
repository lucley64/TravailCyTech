#!/usr/bin/env bash

echo "1.: ls -lht /home/cytech"

echo "2.: mkdir -p Cours/Unix"

echo "3.: touch Cours/Unix/{TD1,TD2,TD3,TD4}"

echo "4.: chmod -R 744 *"

echo "5.: echo \"Para bailar\" > Cours/Unix/TD1 && echo \"La Bamba\" > Cours/Unix/TD2"

echo "6.: wc -l Cours/Unix/TD1"

echo "7.: ls -alF Cours/Unix"

echo "8.: rm Cours/Unix/TD1"

echo "9.: mv Cours/Unix/TD3 Cours/Unix/Ritchie"

echo "10.: mv Cours/Unix/Ritchie Cours/"

echo "11.: find . TD4"

echo "12.: find -name \"TD4\" -exec mv {} notes \;"