#~/bin/sh

input=("echo a > output.txt" "cat single_command_tests.sh > output2.txt" "cat single_command_tests.sh >> output2.txt") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell
done

