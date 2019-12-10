#!/bin/sh

inputs=("[ -e ../rshell ]" "[ -f ../rshell ]" "[ -d ../rshell ]" "[ -e ../header ]" "[ -f ../header ]" "[ -d ../header ]" "[ ../rshell ]" "[ ../header ]" "[ -e 5 ]" "[ -f 5 ]" "[ -d 5 ]" "[ 5 ]" "[ -e ../rshell ] && echo hello "
 "[ -e ../rshell ]; echo hello]" "[ -e ../rshell ] || echo hello" "[ -f ../rshell ] && echo hello" "[ -f ../rshell ]; echo hello]" "[ -f ../rshell ] || echo hello" "[ -d ../rshell ] && echo hello" "[ -d ../rshell ]; echo hello" 
"[ -d ../rshell ] || echo hello" " [ -e ../header ] && echo hello" "[ -e ../header ]; echo hello" "[ -e ../header ] || echo hello" "[ -f ../header ] && echo hello" "[ -f ../header ]; echo hello" "[ -f ../header ] || echo hello"
 "[ -d ../header ] && echo hello" "[ -d ../header ]; echo hello" "[ -d ../header] || echo hello" "[ ../rshell ] && echo hello" "[ ../rshell ]; echo hello" "[ ../rshell ] || echo hello" "[ ../header ] && echo hello" "[ ../header ]; echo hello" 
"[ ../header ] || echo hello" "[ -e 5 ] && echo hello" "[ -e 5 ]; echo hello" "[ -e 5 ] || echo hello" "[ -d 5 ] && echo hello" "[ -d 5 ]; echo hello" "[ -d 5 ] || echo hello" "[ 5 ] && echo hello" "[ 5 ] && echo hello" "[ 5 ]; echo hello" "[ 5 ] || echo hello")

for i in "${inputs[@]}"
do
		echo "Executing ../rshell ${i}"
		echo -e "${i}" | ./rshell
done
