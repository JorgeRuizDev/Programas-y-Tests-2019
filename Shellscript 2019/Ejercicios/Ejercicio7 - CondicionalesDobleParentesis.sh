#!/bin/bash

main(){
	read -p "a: " a
	if (( $a < 5 )); then
		echo a es menor que 5
		else
		echo a es mayor o igual que 5
	fi

	b=$(echo "005,006" | cut -d "," -f 1)

	echo $b

	if (($b != 7)); then
		echo hola
	else
		echo adios
	fi
	

}

main