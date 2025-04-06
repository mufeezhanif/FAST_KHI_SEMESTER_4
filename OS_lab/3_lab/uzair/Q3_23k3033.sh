#!/bin/bash

read -p "Enter file name to backup: " name
if [[ ! -f "$name" ]]; then
    echo "Non-existent file!!"
    exit 1
fi

datestamp=$(date +"%Y%m%d")

backupfile="${name%.*}_${datestamp}.${name##*.}"

cp "$name" "$backupfile"
echo "Backup created: $backupfile"

