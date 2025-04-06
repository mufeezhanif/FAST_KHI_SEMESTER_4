#!/bin/bash

backupfunc(){
    read -p "Enter directory name to backup: " dir
    if [[ ! -d "$dir" ]]; then
        echo "Non-existent directory!!"
        exit 1
    fi

    local timestamp=$(date +"%Y%m%d_%H%M%S")
    local backup_file="${dir}_backup_${timestamp}.tar.gz"

    tar -czf "$backup_file" -C "$dir" .
    echo "Backup created: $backup_file"
}

restorefunc(){
    read -p "Enter the backup file to restore: " backup_file
    if [[ ! -f "$backup_file" ]]; then
        echo "Backup file does not exist!"
        exit 1
    fi

    local restore_dir="restored_$(basename "$backup_file" .tar.gz)"
    mkdir -p "$restore_dir"
    tar -xzf "$backup_file" -C "$restore_dir"
    echo "Backup restored to: $restore_dir"
}

echo "Choose an option:"
echo "1. Create Backup"
echo "2. Restore from backup"

read -p "Your Choice: " ch

case "$ch" in
    1)
        backupfunc
        ;;
    2)
        restorefunc
        ;;
    *)
        echo "Exiting..."
        exit 1
        ;;
esac

