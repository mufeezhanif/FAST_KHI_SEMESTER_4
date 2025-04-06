#!/bin/bash

read -p "From: " src
read -p "To: " dest

if [[ ! -d "$src" || ! -d "$dest" ]]; then
    echo "Source or destination directory is non-existent!"
    exit 1
fi

for file in "$src"/*.txt; do
    if [[ -f "$file" ]]; then
        cp "$file" "$dest"
        echo "Copied $file to $dest"
    fi
done

echo "All .txt files have been copied."

