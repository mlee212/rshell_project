#~/bin/sh

input=("cat < inFile1" "cat < inFile2" "cat < inFile2 | tr A-Z a-z" "cat < inFile1 inFile2") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell
done

