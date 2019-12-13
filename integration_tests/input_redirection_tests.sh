#~/bin/sh

input=("cat < single_command_tests.sh" "cat < nonExistent") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell
done

