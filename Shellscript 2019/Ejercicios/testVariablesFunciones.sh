#!/bin/bash

var1=1
var2=2
var3=3
var4=4
var5=5

funcion1(){

	echo "Esta función tiene dos variables"
	echo "variable 1 (sin pasar): $var1"
	echo "variable 2 (pasada): $1"
}

funcion1 $var2

funcion2(){

	echo "Esta función va a modificar 2 variables, y va a compararlas con las exteriores"
	echo "El nuevo valor de la variable 1 y 2 es 288"
	var1=288
	
}

funcion2 $var2
echo -e "\nVariables tras la ejecución de la función:"
echo "var1: $var1"
echo "var2: $var2"

funcion3(){

	echo -e "\nPara actualizar uno de los parámetros que hemos pasado a la función en la zona global, usamos eval"

	echo "actualizamos var3 y var4 con 300"
	echo "Hemos pasado EL NOMBRE de la variable como parámtro, y no el contenido"
	echo 'Es decir, hemos pasado var3 y no $var3'
	echo "Esto nos permite actualizar la variable global con el nombre que hemos usado como parámetro, ya que no podemos actualizar el contenido de la variable global al ser sustituida por \$n"

	eval $1=300
	eval $2=300
}

echo "El valor actual de var3 = $var3 y var4 = $var4"
funcion3 var3 var4
echo "El valor tras actualizar las variables con la función es: var3 = $var3 y var4 = $var4"

funcion4(){

	echo -e "\nEsta función se encargará de crear una variable y no exportarla, es decir, se creará una en la función y se comprobará si es global, o muerte al terminar la ejecución"

	varFuncion="Hola"
	$$1="Adios"
	echo ${$1}
}

funcion4 var5
echo "Variable de la función $varFuncion y var5: $var5, la variable 5 no se actualizam, lo más sencillo es usar EVAL"