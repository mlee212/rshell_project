#!/bin/sh

input=("exit" "ls -a; exit" "exit; ls -a" "exit && ls -a" "exit || ls -a")

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	../rshell ${i}
done
