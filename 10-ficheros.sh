#!/bin/bash

declare -i n
i=0
t=10

while [[ $i -lt 10 ]] 
do
 	t=$(($t**$i)); echo $n
  	./cfa f$i t
  	i=$(( $i+1 ))
done
exit 0
	