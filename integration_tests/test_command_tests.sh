#!/bin/sh

inputs=("test -e ../rshell" "test -f ../rshell" "test -d ../rshell" "test -e ../header" "test- f ../header" "test -d ../header" "test ../rshell" "test ../header" "test -e 5" "test -f 5" "test -d 5" "test 5" "test -e ../rshell && echo hello "
 "test -e ../rshell; echo hello]" "test -e ../rshell || echo hello" "test -f ../rshell && echo hello" "test -f ../rshell; echo hello]" "test -f ../rshell || echo hello" "test -d ../rshell && echo hello" "test -d ../rshell; echo hello" 
"test -d ../rshell || echo hello" "test -e ../header && echo hello" "test -e ../header; echo hello" "test -e ../header || echo hello" "test -f ../header && echo hello" "test -f ../header; echo hello" "test -f ../header || echo hello" 
"test -d ../header && echo hello" "test -d ../header; echo hello" "test -d ../header || echo hello" "test ../rshell && echo hello" "test ../rshell; echo hello" "test ../rshell || echo hello" "test ../header && echo hello" "test ../header; echo hello" 
"test ../header || echo hello" "test -e 5 && echo hello" "test -e 5; echo hello" "test -e 5 || echo hello" "test -d 5 && echo hello" "test -d 5; echo hello" "test -d 5 || echo hello" "test 5 && echo hello" "test 5 && echo hello" "test 5; echo hello" "test 5 || echo hello")


for i in "${inputs[@]}"
do
		echo "Executing ../rshell ${i}"
		echo -e "${i}\nexit" | ../rshell 
done
