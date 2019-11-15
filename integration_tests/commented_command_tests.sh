#~/bin/sh

input=("ls -a # && echo five" "ls -a && # echo five" "#" "# ls -a && echo five" "ls -a; && echo five #" "#") 

for i in "${input[@]}"
do
	../rshell ${i}
done

