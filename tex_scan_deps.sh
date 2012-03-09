#!/bin/bash
self=${0}
sed -n 's|\\input{\([^}]\+\)}|\1|p' ${1} |
while read file
do
	echo "${file} \\"
	${self} ${file}
done
