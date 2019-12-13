/*
Nombre: Calculadora que nos muestra cuanto ha pasado desde el 1/3/2000
Descripción: (C99) nos muestra segundos, minutos, horas, dias y semanas.


Compilado mediante gcc y ejecución desde terminal con ./a.out
Es necesario tener la bisiesto.h en la misma carpeta donde se realizará
el compilado o dará error. Otra opción es copiar y pegar dichas funciones


Autor: Jorge Ruiz Gómez
Fecha: 22/04/2019

Versión 1.0

*/

//***Directivas de Preprocesador***********************************************
#include <stdio.h>
#include <stdbool.h>
#include "bisiesto.h"


//**Definición de prototipos***************************************************
//Entrada
void entrada(int *, int *, int *);
void cleanStdin ();

//Programa Central
int f_diasTranscurridos(int, int, int);
void imprimir(int);

//Otros
int selectorSiNo();

//***Definición de meses mediante enum***************************************

enum mes {ENERO=1,FEBRERO,MARZO,ABRIL,MAYO,JUNIO,JULIO,AGOSTO,SEPTIEMBRE, OCTUBRE,NOVIEMBRE, DICIEMBRE};

//***Función central***********************************************************
int main (){
	printf("-------¿Cuántos días han pasado desde el 1/3/2000?-------\n\n");//Cabecera
	
	int dia, mes, anio;
	entrada(&dia, &mes, &anio);
	
	int diasTrans = f_diasTranscurridos(dia,mes,anio);
	imprimir (diasTrans);
}

//**Otras funciones************************************************************

void entrada(int *d, int *m, int*a){
	bool entradaValidaBool;
	int entradaValida;
	char enter;
	
	printf("Introduzca una fecha (Superior al 1/3/2000) con el formato dd/mm/aaaa\n");
	do{ //Bucle que no permite n
		printf("->");
		entradaValida = scanf("%d/%d/%d%c",d,m,a,&enter);
		
//**************Validación de Entrada*******	

	
		//Primero, validamos que los meses con 30 días no tengan más de los necesarios
			
				switch (*m){
				case ABRIL:
				case JUNIO:
				case MAYO:
				case SEPTIEMBRE:
				case NOVIEMBRE:
				if (*d>30){
					printf("El mes que has introducido tiene solo 30 días.\n");
					entradaValidaBool = false;
					cleanStdin();}
				break;
				

				}

		//Después comprobamos que las fechas introducidas son válidas y si febrero es
		//bisiesto o no para comprobar si tiene días de sobra
		
		if(*m<1 ||*m==2|| *m>12 || *d<1 || *a<=2000 || *d>31 || entradaValida != 4 || enter !='\n'){

			entradaValidaBool = false; //En este punto no se si esta asignación es necesaria

			/****/
			if(*m==2){//Comprobamos si el mes es bisiesto o no, y si concuerda
				
				if (*a<2001){
				printf("Las fechas inferiores al 1/3/2000 son inválidas\n");
				entradaValidaBool =false; 
				cleanStdin();					
				}
				
				else if (bisiesto(*m,*a)==true && *d>29){
					entradaValidaBool = false;
					printf("El mes que has introducido tiene solo 29 días\n");
					cleanStdin();}
				else if(bisiesto(*m,*a)==false && *d>28){
					entradaValidaBool = false;
					printf("El mes que has introducido tiene solo 28 días\n");
					cleanStdin();}
				else
					entradaValidaBool = true;
					
			}
			/****/
			
			if (*a==2000 && *m<3){
				printf("Las fechas inferiores al 1/3/2000 son inválidas\n");
				entradaValidaBool =false; 
				cleanStdin();
			}
		
			else if(*m<1 || *m>12 || *d<1 || *a<2000 || *d>31 ||entradaValida != 4 || enter !='\n'){
				entradaValidaBool =false;
				cleanStdin();
			}
			else
				entradaValidaBool =true;
				
		}else{

			entradaValidaBool = true;
			}
	
	}while(entradaValidaBool != true);
	printf("Fecha correcta\n");
}

//*****************************************************************************

void cleanStdin(){
	printf("Fecha inválida\n");
	while (getchar() !='\n');
}

//*****************************************************************************

int f_diasTranscurridos(int d,int m, int a){
	int total =0;
	
	int diaActual; // Si diaActual =0 cuenta el día de hoy, suma 24h, etc, (1/3/2000 y 1/3/2000 ha pasado 1 día)
	
	printf("\n¿Desea incluir el 1/3/2000 en los días pasados?		S/n\n");
	diaActual = selectorSiNo();

	if (a==2000){	/*Para el año 2000 solo tenemos que sumar los días del mes anterior acumulados
						(Marzo =0, abril = 31 de marzo, mayo = 31 marzo+30 abril,etc)
						al final se sumarán los días introducidos*/
		
		switch (m){
		case ABRIL : 
		total+=31;
		break;
		case MAYO: 
		total+=61;
		break;
		case JUNIO : 
		total+=92;
		break;
		case JULIO: 
		total+=122;
		break	;	
		case AGOSTO:
		total+=153;
		break;		
		case SEPTIEMBRE: 
		total+=184;
		break ;		
		case OCTUBRE: 
		total+=214;
		break;		
		case NOVIEMBRE:
		total+=245;
		break;		
		case DICIEMBRE:
		total+=275;
		break;			
		}
		
	}
	

	
	else if (a!=2000){
		
		switch(m){
		
		case ABRIL : 
		total+=31;
		break;
		case MAYO: 
		total+=61;
		break;
		case JUNIO : 
		total+=92;
		break;
		case JULIO: 
		total+=122;
		break	;	
		case AGOSTO:
		total+=153;
		break;		
		case SEPTIEMBRE: 
		total+=184;
		break ;		
		case OCTUBRE: 
		total+=214;
		break;		
		case NOVIEMBRE:
		total+=245;
		break;		
		case DICIEMBRE:
		total+=275;
		break;		
		case ENERO:{
		total+=-28-31;
		break;		
		}
		case FEBRERO:{
		total+=-28;
		}
		break;		
		case MARZO: //Enero (1)-1 = 0
		total+=0;
		break;
			if (bisiesto(2,a)==true)
				total -=1;
		
		
		
		
		total +=366-31-28;//Se suma todos los días del año 2000 366 días menos los 60 contando el bisiesto
		}	
	}
		int c=a;
	for (int b=0; b<(a-2000); b++){
		
		if (bisiesto(2,c)==true)
			total++;
		total+=365;
		c++;
	}
	
	
	
	return total+d-diaActual;/*Restar a d 1 si queremos que no se inlcuya el mismo día*/
}

//*****************************************************************************

int selectorSiNo (){
	//Creado por Jorge Ruiz Gómez
	char enter, SiNo;
	bool entradaCorrecta;

	
	do{
	printf("\n-->");
	int nDatosIntroducido = scanf("%c%c",&SiNo,&enter);
	
	switch (SiNo){
	case 'y':
	case 'Y':
	case 's':
	case 'S':
	case 'n':
	case 'N':
	entradaCorrecta = true;
	break;
	
	default:
	entradaCorrecta = false; //Si no se ha introducido uno de los valores aceptados, se repite
	break;
	}
	
	if ((nDatosIntroducido !=2) | (entradaCorrecta == false))
		cleanStdin();

	}while (entradaCorrecta == false);
	
	switch (SiNo){
	case 'y':
	case 'Y':
	case 's':
	case 'S':
	return 0;
	break;
	
	case 'n':
	case 'N':
	return 1;
	break;
	}

}

//*****************************************************************************

void imprimir(int n){
	
	printf("\nHan pasado %d día(s)\n",n);
	printf("Han pasado %d hora(s)\n",n*24);
	printf("Han pasado %d minuto(s)\n",n*24*60);
	printf("Han pasado %d segundo(s)\n",n*24*3600);	
	printf("Han pasado %d semana(s) y %d día(s)\n",n/7,n-(n/7)*7);
	
}

//*****************************************************************************