#!/usr/bin/env bash

echo "1.: sort -r -nk 3 notes.txt"

echo "2.: sort -k 2 notes.txt"

echo "3.: sort -nk 4 notes.txt | awk '{print \$2}'"

echo "4.: grep -wi \"Algorithme\" notes.txt | tr [:lower:] [:upper:]"