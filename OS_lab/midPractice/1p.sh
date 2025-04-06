:<<COMMENT
1. A library manager wants a shell script to keep track of book records. The script should allow adding new books with details like title, author, and year, searching for books by title, listing all books, and deleting a book from the records. The script should use a text file for data storage and provide appropriate messages if a book is not found or if an invalid operation is attempted. The script should be menu-driven.

COMMENT

#!/bin/bash


while [ true ] ;
do

read -p "Following are the options
a to enter book
b to find
c to delete
d display books 
e) to exit " choice

case $choice in
    a) 
        echo "opt a"
        read -p "Enter title, author, and year " name | author | year ;;
        $name | $author | $year << records.txt
    b)echo "opt b";;
    c)echo "opt c";;
    d)echo "opt d";;
    e)break;;
    *)break;;
esac
done
echo "loop ended"