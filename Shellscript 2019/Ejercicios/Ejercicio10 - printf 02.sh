#!/bin/bash

main(){


	for ((;;)); do
	columnas
	text="Hola buenas tardes, mi nombre es joseluis"
	
	printf "%*s\n" $(((${#text}+$cols)/ 2)) "$text"
	sleep 0.5
done

}
columnas(){
	#Esta función actualiza la variable nColumnas con el valor actual dependiendo del terminal
	#No se puede dejar en un bucle con Sleep porque las variables del shell hijo no se transmiten al padre. 
	cols=$(tput cols)
	
}

main