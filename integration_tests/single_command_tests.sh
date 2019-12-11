#!/bin/sh

inputs=("ls" "ls -a" "echo world" "echo hi" "mdir five" "mkdir five" "rm -r five")

for i in "${inputs[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}\nexit" | ../rshell 
done

