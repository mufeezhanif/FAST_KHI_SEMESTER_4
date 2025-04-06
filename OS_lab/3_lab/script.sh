#function with parameters 
important_details(){
local name="$0"
mkdir "$name"
local data="$2"
touch "$name/$data"
ls "$name"

}


important_details "mydir" "intro1.txt" 
