#!/bin/bash

if [[ $# != 2 ]]; then
	echo "Not Enough Arguments(MORE THAN OR LESS THAN 2 GIVEN), Exiting..."
        exit 1
fi

if [[ ! -d "$1" ]]; then
	echo "Non-existent Directory"
	exit 1
fi

cnt=1

for file in "$1"/*; do
	if [[ ! -f "$file" ]]; then
		echo "Not a file, Skipping"
		continue
	else
	        extension="${file##*.}"
		if [[ "$file" == *.* ]]; then
            		extension=".$extension"
        	else
            		extension=""
        	fi
        	
        	new="${1}/${2}${cnt}${extension}"
        	mv "$file" "$new"
        	echo "Renamed '$file' to '$new'"
        
        	((cnt++))
    	fi
done
