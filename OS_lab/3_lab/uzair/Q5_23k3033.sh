#!/bin/bash

src="../Q4/data/"
dest="../Q5/backup/"

for file in "$src"*;do
	if [[ -f "$file" ]] && [[ $(find "$file" -mtime +7 -type f) ]]; then
		cp "$file" "$dest"
		echo "$file moved to backup"
	fi
done
