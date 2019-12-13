#!/bin/bash
#• Ej7: Realizar un programa que lea una letra minúscula
#(a-z) e imprima la letra leída en mayúscula. El
#programa debe tener los siguientes módulos:
#leerLetra(), convertirAMayuscula() y escribirLetra().

echo "Programa que convierte una letra de minúsculas a mayúsculas"

entrada(){

	validacionBool=false

	until [[ $validacionBool == "true" ]]
	do
		read -p "Introduzca la letra a convertir: " letra
		longitud=$(echo "$letra" | wc -c)
		((longitud--))



		if [ $longitud -eq 1 ]
			then
				validacionBool=true
			else
				validacionBool=false
		fi
		if [ $validacionBool = true ]
			then
				if [[ $letra == [a-zA-Z] ]]
					then
						validacionBool=true
					else
						validacionBool=false
				fi
		fi		
	done



	echo "La longitud de la letra introducida \"$letra\" es de $longitud caracter"

	#Conversor a ASCII:
	#https://superuser.com/questions/597620/how-to-convert-ascii-character-to-integer-in-bash
	letraAscii=$(printf '%d\n' "'$letra")


	printf "El valor en ascii de %c es %d\n" $letra $letraAscii


	echo letaasicii $letraAscii
	if ([ $letraAscii -ge 97 ] && [ $letraAscii -le 122 ])
	then
		((letraAscii = $letraAscii-32))
		printf 'La letra introducida en mayúsculas es '
		printf \\$(printf '%03o\n' $letraAscii)
	else
		((letraAscii = $letraAscii+32))
		printf 'La letra introducida en minúsculas es '
		printf \\$(printf '%03o' $letraAscii)
	fi
	printf "\n"
}
entrada
