#!/bin/sh

input=("ls -a; echo semicolon" "ls -a && echo ampersand" "ls -a || echo parallel" "l -a && echo ampersand" "l -a || echo parallel" "ls -a && echo \"hello && world\"" "ls -a && echo \"hello || world\"" "ls -a && echo \"hello # world\"" "ls -a # && echo comment" "ls -a; echo hello && mkdir test || echo world; git status")

for i in "${input[@]}"
do
	../rshell ${i}
done
