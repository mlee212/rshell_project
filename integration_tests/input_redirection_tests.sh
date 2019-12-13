#~/bin/sh

input=("echo hey bro > inFile1" "echo \"wsup bro\" > inFile2" "cat < inFile2 | tr a-z A-Z > inFile3" "echo helLo | tee inFile4" "cat < inFile3 | tr A-Z a-z > inFile4 && echo hElLo | tr A-Z a-z | tee inFile5" "echo \"will be concat\" >> inFile1") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell
done

