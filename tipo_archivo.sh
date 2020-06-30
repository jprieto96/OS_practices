#!/bin/bash 

for num;
do
	if [ -e $num ]; then
		echo “Tipo de fichero: ”
		if [ -f $num ]; then
			echo " fichero regular"
		elif [ -d $num ]; then
			echo " directorio"
		elif [ -e $num ]; then
			echo " FIFO/pipe"
		elif [ -b $num ]; then
			echo " dispositivo de bloques"
		elif [ -c $num ]; then
			echo " dispositivo de caracteres"
		elif [ -S $num ]; then
			echo " socket"
		elif [ -h $num -o -L $num ]; then
			echo " enlace simbólico"
		fi

		echo "Permisos:"
		if [ -r $num ]; then
			echo " lectura"
		fi
		if [ -w $num ]; then
			echo " escritura"
		fi
		if [ -x $num -a -d $num ]; then
			echo " paso"
		elif [ -x $num ]; then
			echo " ejecución"
		fi

		echo "Fecha actualización:" $(date -r $num +%F)
	else
		echo “El archivo $num no existe”
	fi

	echo -e "\n"
done
