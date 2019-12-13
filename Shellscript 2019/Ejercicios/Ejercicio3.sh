#!/bin/bash

#Introducir una cantidad entera de segundos y
#muestra el equivalente en horas, minutos y
#segundos

echo "Conversor de segundos"

verificacionEntrada=false
until [ $verificacionEntrada = "true" ]
do
	if [[ $s -ge 0 ]]
		then
			verificacionEntrada=true
		else
			verificacionEntrada=false
	fi
done


read -p "Introuduzca la cantidad de segundos a convertir: " seg

horas=$(($seg/3600))
minutos=$((($seg-$horas*3600)/60))
segundos=$(($seg-($horas*3600+$minutos*60)))

echo "$seg segundos equivale a $horas horas, $minutos minutos, $segundos segundos"