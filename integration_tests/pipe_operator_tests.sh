#~/bin/sh

input=("echo hi | tr a-z A-Z" "cat < existingInputFile | tr A-Z a-z" "cat < existingInputFile | tee newOutputFile1 | tr a-z A-Z" "echo hello | tr a-z A-Z | tr A-Z a-z | tr a-z A-Z | tr A-Z a-z" "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell
done
