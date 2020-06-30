#!/bin/bash

echo Introduzca los directorios: 
read lista_directorios
for directorio in $lista_directorios
do
	if [ '$HOME' = "$directorio" ]; then
		echo "dir : '$HOME'"
		ls -lR $HOME
	else
		echo "dir : $directorio"
		ls -lR "$directorio"
	fi
done
exit 0
