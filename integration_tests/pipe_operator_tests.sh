#~/bin/sh

input=("echo hi | tr a-z A-Z" "cat < single_command_tests.sh | tr a-z A-Z") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell
done
