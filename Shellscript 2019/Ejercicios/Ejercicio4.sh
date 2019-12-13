#!/bin/bash

#Ej5: pide el nº de lados y el valor del radio de un polígono
#regular y nos muestre el perímetro y el área
#{l2=2* r2
#* (1- cos(360º/n)), a2=l2 +(½*l)2
#, P= l*n, A=½*P*a}
#Con los siguientes prototipos establecer el orden lógico de
#llamadas entre módulos
#int pide_lados(); /*Utilizar entrada robusta, enteros y máximo 8
#lados*/ void pide_radio(float*);
#void peri(int, float); void longitud_lado(float);
#void area(float, float); float apotema(float);

#-----------------------
#constantes
readonly PI=3.14159265359


echo "Calculadora de perímetro y área a partir del número de lados del polígono y su radio"
echo "Sin termianar por no poder calcular trigonométricas útiles"
entrada(){
verificacionBool=false

until [ $verificacionBool = true ]
do
read -p "Introduzca el número de lados: " lados
if [ $lados -ge 3 ]
	then
	verificacionBool=true
else 
	echo "Los datos introducidos no son válidos, comprube que el polígono existe y sus lados son positivos"
	verificacionBool=false
fi
done



read -p "Introduzca el radio en centímetros: " radio
}

entrada
echo "El polígono introducido tiene un radio de $radio centímetros y $lados lados"

perimetro(){

	ladoCuadrado=2*$radio*(1-c)

}