#!/bin/bash



main(){

	#arrayTest1
	#arrayTest2
	arrayTest3
	arrayTest4




}

arrayTest1(){
	read -p "Introduzca el tamaño del array (entero): " MAX

	declare -ga array1

	

	for ((a=0;a<MAX;a++)); do

		random=$(echo $(($RANDOM %100 )))
		array1[a]=$random 

	done


	for ((a=0;a<MAX;a++));do

		echo $a: ${array1[a]}

	done

	echo "Tamaño del array: ${#array1[*]}"


}
arrayTest2(){
	#Son los arrays variables globales o locales?


	echo -e "Todos los valores del array:\n${array1[*]}"

	#Son locales ¿Cómo hacerlos globales?

	#Usando declare -g
}

arrayTest3(){

	#arrays multidimensionales
	read -p "Intrdozca el número de filas: " nFilas
	read -p "Introduzca el número de columnas: " nColumnas

	#Importante: Declarar matrices con -A
	declare -A matriz

	for ((a=0;a<nFilas;a++)); do
		for ((b=0;b<nColumnas;b++)); do
			echo -n "$a,$b: "
			#read -p "Valor: " entrada
			#matriz[a,b]=$entrada
			matriz[$a,$b]=$RANDOM


		done #fin bucle b
		echo
	done #fin bucle a


	for ((a=0; a<nFilas;a++));do

		for ((b=0;b<nColumnas;b++)); do

			echo -n "$a,$b: "
			echo -n "${matriz[$a,$b]} "
		done
		printf "\n"
	done





}

arrayTest4(){

#https://stackoverflow.com/questions/16487258/how-to-declare-2d-array-in-bash

		declare -A matrix
	num_rows=4
	num_columns=5

	for ((i=1;i<=num_rows;i++)) do
	    for ((j=1;j<=num_columns;j++)) do
	        matrix[$i,$j]=$RANDOM
	    done
	done

	f1="%$((${#num_rows}+1))s"
	f2=" %9s"

	printf "$f1" ''
	for ((i=1;i<=num_rows;i++)) do
	    printf "$f2" $i
	done
	echo

	for ((j=1;j<=num_columns;j++)) do
	    printf "$f1" $j
	    for ((i=1;i<=num_rows;i++)) do
	        printf "$f2" ${matrix[$i,$j]}
	    done
	    echo
	done

	for ((a=1; a<=nFilas;a++));do

		for ((b=1;b<=nColumnas;b++)); do

			#echo -n "$a,$b: "
			echo -n "${matrix[$a,$b]} "
		done
		printf "\n"
	done

}
main