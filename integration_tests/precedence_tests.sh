#!/bin/sh

inputs=("(echo A && echo B)"  "(echo A || echo B)" "(echo A; echo B)" "(echo A && echo B) || echo C" "(echo A && echo B) || echo C" "(echo A || echo B) && echo C" "(echo A || echo B) && echo C" "(echo A && echo B) || (echo C && echo D)" "((echo A && echo B) || echo C) || echo D")


for i in "${inputs[@]}"
do
	echo "Executing ../rshell ${i}"
	../rshell ${i}

done


