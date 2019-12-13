#Modularizar el programa para operar con
#fracciones realizado la segunda semana. El
#programa leerá las fracciones con formato
#"numerador/denominador".



f_entrada(){

	echo "Introduzca una fracción"
	entradaCorrecta=false
	until [ $entradaCorrecta = "true" ]
		do
			read -p "Numerador: " numerador
			if [[ $numerador -gt 0 ]] || [[$numerador -lt 0]]
			then
				echo "Numerador leido correctamente"
				entradaCorrecta=true
			else
				echo "Por favor, introduzca un entero distinto de 0"
				entradaCorrecta=false
			fi
		done


	entradaCorrecta=false
	until [ $entradaCorrecta = "true" ]
		do
			read -p "Denominador: " denominador
			if [[ $denominador -gt 0 ]] || [[$denominador -lt 0]]
			then
				echo "Denominador leido correctamente"
				entradaCorrecta=true
			else
				echo "Por favor, introduzca un entero distinto de 0"
				entradaCorrecta=false
			fi
		done


	echo -e "\n---Numerador $1 $numerador, denominador $2 $denominador"


	#$1=$numerador
	#$2=$denominador
	eval $1=$numerador
	eval $2=$denominador
	#export $2=$denomiandor
	#export $1=$numerador


}

f_imprimir(){

	echo "La fracción introducida sin redondear es $numerador1/$denom1 y $numerador2/$denom2"

}

f_suma(){
	suma=$(($numerador1*$denom2+$numerador2*$denom1))
	denomF=$(($denom1*$denom2))
	echo "La suma de $numerador1/$denom1+$numerador2/$denom2=$suma/$denomF"
}


#Fin de funciones--------------

f_entrada numerador1 denom1
f_entrada numerador2 denom2
f_imprimir
f_suma

