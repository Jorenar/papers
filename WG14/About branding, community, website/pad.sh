#!/bin/sh

in="$1"
out="$2"

cp "$in" "$out"

pow=1
size=$(wc -c < "$in")

while [ "$pow" -lt "$size" ]; do
    pow=$((pow * 2))
done

pad=$((pow - size - 1))
printf '\n%*s' "$pad" '' >> "$out"
