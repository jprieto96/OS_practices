#!/bin/bash

echo "Introduce el directorio: "
read directorio
for dir in $directorio
do
	for d in $dir/*
	do
		bash cambia_nombre.sh $d $1
	done
done
