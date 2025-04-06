#!/bin/bash
src="data"

for file in "$src"/*; do
        if [[ -f "$file" ]]; then
                case "${file##*.}" in
                jpeg)
                        mv "$file" "${src}/../Imgs/"
			echo "($file) moved to Imgs"
                        ;;
                txt)
                        mv "$file" "${src}/../Docs/"
			echo "($file) moved to Docs"
                        ;;
                esac
        fi
done

echo "Process Completed!!"
