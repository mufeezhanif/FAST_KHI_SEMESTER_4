#Special Type of variables 
#all arguments treated as string 
echo "'$*' output is $*"
#count of arg 
echo "'$#' output is $#"
#values of 1st and 2nd arguments
echo "'$1' '$2' outputs are  $1 $2"
#pid of arg 
echo "'$$' output is $$"    
#make arg string but treated each arg as separate arg            
echo "'$@' output is $@"
#status of command 0 means exec 1 means issue 
echo "'$?' output is $?"
#pid of prev job 
echo "'$!' output is $!"

#Array 
name[0]="FAST"
name[1]="Bahria"
name[2]="KU"
name[3]="PAF KIET"


# Functions 
Display_Filesin_Documents(){
local folderfile="/home/zainab/Documents"
if [[ -d "$folderfile" ]];then 
	echo "File present in folder"
	ls "$folderfile"
else 
	echo "Not found"
fi		
}
Display_Filesin_Documents

#function with parameters 
important_details(){
local name="$1"
mkdir "$name"
local data="$2"
touch "$name/$data"
ls "$name"

}

important_details "mydir" "intro1.txt" 


