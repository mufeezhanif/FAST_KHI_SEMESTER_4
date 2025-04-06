#!/bin/bash

src="data"

for file in "$src"/*; do
    if [[ -f "$file" && ! -s "$file" ]]; then
        rm "$file"
        echo "$file has been deleted"
    fi
done

