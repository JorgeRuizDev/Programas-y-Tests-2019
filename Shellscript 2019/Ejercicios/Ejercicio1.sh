#!/bin/bash
#Ej1: Pide el valor del radio de una circunferencia y
#nos muestre su perímetro y el área del círculo que
#encierra (datos enteros, redondeo de resultado)
#• {L= 2 * PI *r, A=PI *r2}. Utiliza DEFINE para la
#constante PI

#FUNCIONES---------------------------------------
f_perimetro(){
#L= 2 * PI *r, A=PI *r2

#per=$((3,14*$1*2)) 
per=$(echo "3.14*2*$1" | bc)
export per
}

f_area(){

	area=$(echo "3.14*$1" | bc)
	export area
}






#------------------------------------------------


read -p "Introduce el radio en cm: " radio
echo "El radio introduciedo es: $radio cm"
f_perimetro $radio
echo "El perímetro de la circunferencia de radio $radio cm es $per cm"
f_area $radio
echo "El área de la circunferencia de radio $radio cm es $area cm"


