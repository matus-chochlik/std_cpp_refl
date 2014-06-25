#!/bin/bash
self=${0}
prefix=${1}
input=${2}
sed -n 's|^\s*\\input{\([^}]\+\)}|\1|p' ${input} |
while read file
do
	echo "${prefix}/${file} \\"
	${self} ${prefix} ${file}
done 2> /dev/null
