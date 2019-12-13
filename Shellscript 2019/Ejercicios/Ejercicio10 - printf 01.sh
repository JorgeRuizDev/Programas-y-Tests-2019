#!/bin/bash

main(){
	
	#(varaiblesEntorno) &
	#for ((;;)); do

	#	echo -e "for ((;;));do\nnColumnas=$(tput cols)\ndone &" > /tmp/PracticaDeControlTMP1.sh
	#done &

	//echo -e "for ((;;));do\nnColumnas=$(tput cols)\n export $nColumnas;sleep 1\ndone &" > /tmp/PracticaDeControlTMP1.sh
	. /tmp/PracticaDeControlTMP1.sh 

	



	
	for ((;;)); do
		echo "El número actual de columnas es: $nColumnas"
		sleep 1
	done



}

varaiblesEntorno(){
	nColumnas=$(tput cols)
	for ((;;)); do
	nColumnas=$(tput cols)
	export nColumnas
	echo $nColumnas
	sleep 1
	done
}
main