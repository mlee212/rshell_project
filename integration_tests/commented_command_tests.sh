#~/bin/sh

input=("ls -a # && echo five" "ls -a && # echo five" "#" "# ls -a && echo five" "ls -a; echo five #" "#") 

for i in "${input[@]}"
do
	echo "Executing ../rshell ${i}"
	echo -e "${i}" | ../rshell
done

