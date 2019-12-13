#!/bin/bash

#programa que muestra el tiempo transcurrido entre dos fechas
argumentoEjecucion1=$1
argumentoEjecucion2=$2
main(){


	if [[ $argumentoEjecucion1 == "-help" ]]
	then
		help
	fi
	portada

	if [[ $argumentoEjecucion1 == -DefaultDate ]]
	then
		dia1=8
		dia2=15
		mes1=2
		mes2=9
		anio1=2004
		anio2=2015
		diasTranscurridos
	else 
		selectorOpcion
	fi

	#diasTranscurridos
	#imprimir	
}

selectorOpcion(){
	#El código original no estaba pensado para estas mierdas

	#está sin terminar porque quiero pasar a otros proyectos

	echo -e "Escoja un tipo de programa"
	echo -e "1) Tiempo transcurrido entre dos fechas"
	#echo -e "2) Tiempo transcurrido a lo largo de un año"
	#echo -e "3) Tiempo restante en un año"

	selectorOpcion_BoolEntrada=false

	until [ $selectorOpcion_BoolEntrada == true ] ; do
		read -p "-->" selectorOpcion_Entrada
		selectorOpcion_BoolEntrada=true
		case $selectorOpcion_Entrada in
			1) entradaTotal #todos
			;;
			2) entradaTotal #restantes
			;;	
			3) entradaTotal #transcurridos
			;;
			*)
			selectorOpcion_BoolEntrada=false
		esac
		done	
			


}

help(){

	echo -e "Bienvenido al menú de ayuda\n----------------------------------"
	echo "Ejecute el programa con -DefaultDate para saltarse el modo de introducción de datos y saltar directamente al programa"
	echo "Este modo está pensado para testeo/debug, no es recomendable editar los parámetros directamente en el Script, ya que no son validados"




	exit 0
}

#Variables GLOBALES

portada(){

	echo "Use -help como parametro de ejecución para más información"
	numeroColumnasTerminal=$(tput cols)
	mitadColumnasTerminal=$(($(tput cols)/2))
	


	
	programa="Calculadora de tiempo transcurrido entre dos fechas"
	fecha="06/08/2019"
	limitesCuadrados="-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
	printf '%-*s\n' $numeroColumnasTerminal $limitesCuadrados
	printf "|%*s%-*s|\n" $mitadColumnasTerminal $autor  " "



}

entrada(){

	echo -e "Escoja el formato de entrada\n1) Separado mediante \"/\"\n2) Entrada individual"

	verBool=false

	until [ $verBool == true ]
	do
		read -p "--> " nEntrada


		#Switch-case que se encarga de verificar la entrada y seleccionar un tipo de entrada de variables
		case $nEntrada in
			1)
			echo "Usted ha escogido la entrda manual."
			verBool=true
			entradaManual #Ejecuta la FUNCIÓN entradaManual
			;;
			2)
			echo -e "Usted ha escogido la entrada individual."
			verBool=true
			entradaIndividual
			;;
			*)
			echo "Compruebe que ha introducido correctamente el entero en el selector"
			;;

		esac
	done

}

entradaManual(){

	boolEntradaM=false #BoolEntradaManual

	echo "Introduzca una fecha con el siguiente formato: DD/MM/AAAA"
	echo -e "Introduzca valores POSITIVOS\n"
	until [ $boolEntradaM == "true" ]
	do
		read -p "--> " fechaManual

		dia=$(echo $fechaManual | cut -d / -f 1) 
		mes=$(echo $fechaManual | cut -d / -f 2)
		anio=$(echo $fechaManual | cut -d / -f 3)
		
		verificacionFecha 
		boolEntradaM=flagDeFuncion

	done
	echo "Fecha introducida correcta"
}

entradaIndividual(){
	boolEntradaI=false
	until [ $boolEntradaI == true ]
	do
		echo "A continuación deberá introducir cada parámetro individualmente"

		echo -e "\nIntroduzca valores POSITIVOS"
		read -p "Dia: " dia
		read -p "Mes: " mes
		read -p "Año: " anio

		verificacionFecha 
		boolEntradaI=flagDeFuncion
	done

}

verificacionFecha(){
	diasMes=0

	#A esta función se le pasa como parámetro la variable de uno de los bucles de verificación de entrada
	#Por ejemplo: BoolentradaM

	#Definimos el parámetro como correcto, y si algo no es válido, convertimos la fecha a incorrecta
	flagDeFuncion=true #este flag se encargará de cambiar a false si algún parámetro no es correcto, permitiendo que se vuelva a pedir los datos al actualizar la entrada

	#¿Qué es el flag de función? A lo largo del programa vamos a validar varios datos, y si uno de estos es incorrecto, el flag de funcion cambiará de TRUE a false
	#Dejamos el flag de función en true ya que así sólo tenemos que negarlo



	if [ $anio -le 0 ]
	then
		$flagDeFuncion=false
		echo "El año introducido no es válido"
		break
	fi




	case $mes in
		1|01|3|03|5|05|7|07|8|08|10|12)
		#1,3,5,7,8,10,12)
		diasMes=31
		;;
		4|04|6|06|9|09|11)
		diasMes=30
		;;
		2|02)
		boolBisiesto=false
		bisiesto true
		

		if [ $boolBisiesto == true ]
		then
			if [[ $dias -le 0 ]] && [[ $dias -gt 29 ]]
			then
				flagDeFuncion=false
			else
				diasMes=29
			fi
		else
			if [[ $dias -le 0 ]] && [[ $dias -gt 28 ]]
			then 
				flagDeFuncion=false
			else
				diasMes=28
			fi
		fi			
		;;
		*)
		echo "El mes introducido \"$mes\" no es válido"
		echo "Por favor, introduzca la fecha como indica el formato"
		flagDeFuncion=false
		;;
	esac

	#El siguiente stement comprueba que el día introducido se encuentre en el intervalo de días que tiene el mes.
	if [ $dia -le "0" ] || [ $dia -gt $diasMes ]
	then 
		echo "El día introducido ($dia) no se encuentra en el intervalo de días que tiene el mes (1-$diasMes)"
		flagDeFuncion=false
	fi

	if [ $flagDeFuncion == false ]
		then
			echo -e "El formato de fecha no coincide, vuelva a intentarlo\n\n"
			
		else
			echo -e "Los datos introducidos son correctos\n\n"
			
	fi
}


bisiesto(){

	
	if (( $anio % 4 == 0 )) && (($anio % 100 != 0 )) || (($anio % 400 == 0 ))
	then
		if [[ $1 == true ]]
			then
		echo -e "El año $anio es Bisiesto"
		fi
		boolBisiesto=true
	else
		boolBisiesto=false
	fi


}

entradaTotal(){

	until [[ $boolFechaFinal == true ]]
	do
		echo -e "\nIntroduzca la primera fecha:\n"
		entrada #Introducimos los datos de nuevo

		dia1=$dia
		mes1=$mes
		anio1=$anio

		unset dia
		unset mes
		unset anio

		echo -e "\nIntroduzca la segunda fecha:\n"
		until [[ $boolSegundaFecha == true ]]
		do
			entrada

			dia2=$dia
			mes2=$mes
			anio2=$anio
			if [[ $anio2 -eq $anio1 ]]
				then
					if [[ $mes2 -lt $mes1 ]] || ([[ $mes2 -eq $mes1 ]] && [[ $dia2 -le $dia1 ]] )
					then 
						echo -e "No puede introducir dos fechas iguales o inferiores\n"
						boolSegundaFecha=false
					else
						boolSegundaFecha=true
					fi
			elif [[ $anio2 -gt $anio1 ]]
				then 
					boolSegundaFecha=true
			else
				boolSegundaFecha=false
				echo -e "No puede introducir el segundo año ($anio2) menor que el primero ($anio1)\n"
			fi

		done
		echo -e "\nLas fechas introducidas son:"
		echo "Desde $dia1/$mes1/$anio1 hasta $dia2/$mes2/$anio2"

		echo -e "¿Desea introducir una fecha distinta?\n"

		read -p "Introduzca (S/s/Y/y) para repetir el prceso, cualquier dato para saltarlo --> " lecturadaRepetirDato

		case $lecturadaRepetirDato in
			S|s|Y|y)
			boolFechaFinal=false
			;;
			*)
			boolFechaFinal=true
			;;
		esac
	done

		diasTranscurridos
		imprimir



#	if [ $1 == todos ]
#	then
#		diasTranscurridos
#		imprimir
#	elif [[ $1 == restantes ]]; then
#		f_diasRestantesAnio restantes
#	elif [[ $1 == transcurridos ]]; then
#		#statements
#		f_diasRestantesAnio transcurridos
#	fi


}

diasTranscurridos(){

	

	#calcular los días que hay entre los años completos

	anio1Sig=$((anio1+1)) #El año siguiente al introducido, si hemos introducido 2001, el anio1Sig es 2002
	anio2Previo=$((anio2-1)) #El año previo al introducido, si hemos introducido 2001, el anio2Precio es 2000
	#Esto lo hacemos para sumar 365 entre los años completos, si hemos introducido una fecha entre 2000 y 2010, 2001 a 2009 son años completos, que podemos sumar del tirón


	aniosCompletos=0
	aniosBisietosCompletos=0

	for (( anio1Sig ; anio1Sig <= anio2Previo ; anio1Sig++ ))
	do

		boolBisiesto=false
		anio=$anio1Sig # igualamos anio a anio1Sig porque anio es la variable global que se usa en la llamda de bisisto

		bisiesto true

		if [[ $boolBisiesto == true ]]
			then
				((aniosBisietosCompletos++))
			else
				((aniosCompletos++))
		fi	

	done
	echo "Número de años nomales: $aniosCompletos; Número de años bisiestos $aniosBisietosCompletos"


	#En este punto ya hemos obtenido los años completos, para obtener los días que han transcurrido entre estos años, completos:
	#Multiplicamos los años completos por 365 y los años bisiestos completos por 366, y sumamos el total a una variable

		#----------------------------------------------------------------

	#Ahora calculamos los días que han transcurrido en el primer año. 
	# Lo primero de todo, es saber si el año es bisiesto

	#Llamasmos a la función con la que calcularemos los días restantes del mes
	f_diasRestantesAnio_dia=$dia1
	f_diasRestantesAnio_mes=$mes1
	f_diasRestantesAnio_anio=$anio1
	f_diasRestantesAnio restantes
	diasRestantesAnio1=$f_diasRestantesAnio_return

	#Esta misma función nos puede devolver los días transcurridos, depende del parámetro que pasemos.
	f_diasRestantesAnio_dia=$dia2
	f_diasRestantesAnio_mes=$mes2
	f_diasRestantesAnio_anio=$anio2
	f_diasRestantesAnio transcurridos
	diasTranscurridosAnio2=$f_diasRestantesAnio_return


	if [[ $anio1 -eq $anio2 ]]; then

		
		boolBisiesto=false
		anio=$anio1 # igualamos anio a anio1Sig porque anio es la variable global que se usa en la llamda de bisisto

		bisiesto

		if [[ $boolBisiesto == true ]]
			then
				diasTotalesAnio1=366
			else
				diasTotalesAnio1=365
		fi				

			diasTotalesEntreAmbasFechas=$((diasRestantesAnio1+diasTranscurridosAnio2-diasTotalesAnio1))

		
	else
		diasTotalesEntreAmbasFechas=$((diasRestantesAnio1+diasTranscurridosAnio2+(aniosCompletos*365)+(aniosBisietosCompletos*366)))
	#echo "$diasRestantesAnio1 + $diasTranscurridosAnio2 + $aniosCompletos*365 + $aniosBisietosCompletos*366"
	fi
	
}

f_diasRestantesAnio(){
	#Parametros de la función:
	#totales   -   Devuelve los días restantes respescto a la fecha introducida para terminar el año
	#transcurridos   -   Devuelve los días que han transcurrido a lo largo del año

	#La función devuelve el resultado en la siguiente variable:

	#f_diasRestantesAnio_return


	#Estas tres son las VARIABLES a las cuales hemos de dar el valor que deseamos calcular antes de llamar a la función:
	#f_diasRestantesAnio_mes
	#f_diasRestantesAnio_dia
	#f_diasRestantesAnio_anio

	f_diasRestantesAnio_mesSig=$((f_diasRestantesAnio_mes+1)) #Al incrementar en una unidad los meses, tendremos los meses completos restantes
	#Sabiendo los días que tiene un mes, los podemos ir sumando a la variable DiasRestantesAnio_total y luego sumar los días restantes del mes introducido al restar los días transcurridos con los días totales del año
	#tendremos en cuenta si es bisiesto 


	DiasRestantesAnio_total=0


	f_diasRestantesAnio_bisiesto=false
	#igualamos anio a anio1 porque la funcion bisiesto utilizar las variables globales ANIO y boolBisiesto

	anio=$f_diasRestantesAnio_anio 
	boolBisiesto=false
	bisiesto 

	if [[ $boolBisiesto == true ]]
		then
			f_diasRestantesAnio_bisiesto=true
			
	fi

	

	case $f_diasRestantesAnio_mesSig in
		2)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total + 28))
	
		;&
		3)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total + 31))
		
		;&
		4)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total + 30))
		
		;&
		5)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +31))
		
		;&
		6)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +30))
		
		;&
		7)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +31))
		
		;&
		8)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +31))
		
		;&
		9)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +30))
		
		;&	
		10)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +31))
		
		;&
		11)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +30))
		
		;&
		12)
		DiasRestantesAnio_total=$((DiasRestantesAnio_total +31))
		;;

	esac



	case $f_diasRestantesAnio_mes in

		#1,3,5,7,8,10,12)
		#1|3|5|7|8|10|12)
		1|01|3|03|5|05|7|07|8|08|10|12)
		f_diasRestantesAnio_DiasMesIntroducido=31
		;;
		4|04|6|06|9|09|11)

		f_diasRestantesAnio_DiasMesIntroducido=30
		;;
		2)
		f_diasRestantesAnio_DiasMesIntroducido=28
		;;
		*)
		echo Error desconocido en el case f_diasRestantesAnio_mes, valor introducido: $f_diasRestantesAnio_mes.
		;;
	esac

	#Realizamos cálculos sobre los dias totales dependiendo de si es bisiesto o no 

	if [ $f_diasRestantesAnio_bisiesto == true ]
	then 
		DiasRestantesAnio_total=$((DiasRestantesAnio_total+1))
		diastotalesAnio=366
		#echo "Al ser bisiesto, sumamos un día: Días totales: $DiasRestantesAnio_total"
	else
		diastotalesAnio=365
	fi

	#Calculamos los días restantes que tiene el mes, es importante para sumar al total que acumulan los meses el resultado final
	diasRestantesMes=$((f_diasRestantesAnio_DiasMesIntroducido - f_diasRestantesAnio_dia))

	#Incluimos el día inicial (Digamos que empezamos un 31, ese mes ya no se contaría (diasMesIntroducido - Dias Restantes anio día = 0) o (31-1 = 30, falta un día del mes, al ser el mes entero))

	DiasRestantesAnio_total=$((1 + diasRestantesMes + DiasRestantesAnio_total )) 



	f_diasRestantesAnio=""

	if [[ $1 == restantes ]]
	then
		f_diasRestantesAnio_return=$DiasRestantesAnio_total

	elif [[ $1 == transcurridos ]]
		then
			
		f_diasRestantesAnio_return=$((diastotalesAnio-DiasRestantesAnio_total))

	else
		echo -e "Por favor, introduzca en la llamad a la función uno de los siguiente parámetros:\nrestantes\ntranscurridos"
	fi
		echo Los días $1 en $f_diasRestantesAnio_anio con la fecha $f_diasRestantesAnio_dia/$f_diasRestantesAnio_mes/$f_diasRestantesAnio_anio son $f_diasRestantesAnio_return

}

imprimir(){

	echo -e "\nEl número de días transucurridos entre $dia1/$mes1/$anio1 y $dia2/$mes2/$anio2 son $diasTotalesEntreAmbasFechas"


	#equivalencias
	echo -e "Equivalen aproximadamente a:\n"
	equiv_meses=$((diasTotalesEntreAmbasFechas/30))
	equiv_meses_dias=$((diasTotalesEntreAmbasFechas - equiv_meses*30))

	equiv_anios=$((diasTotalesEntreAmbasFechas/365))
	equiv_anios_meses=$((equiv_meses-equiv_anios*12))

	echo "$equiv_anios años y $equiv_anios_meses meses"

	echo "$equiv_meses meses y $equiv_meses_dias días"
	

	equiv_horas=$((diasTotalesEntreAmbasFechas*24))
	equiv_minutos=$((diasTotalesEntreAmbasFechas*24*64))
	equiv_segundos=$((diasTotalesEntreAmbasFechas*3600))
	echo
	echo "$equiv_horas horas"
	echo "$equiv_minutos minutos"
	echo "$equiv_segundos segundos" 
}
main


