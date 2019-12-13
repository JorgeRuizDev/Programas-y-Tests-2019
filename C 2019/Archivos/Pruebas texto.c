/*
	Programa con el que practicar la entrada, modificación y salida de archivos de texto.
		Comprobaciones con wc -lwc
		
	Autor: Jorge Ruiz Gómez
	Fecha: 25/05/2019


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Define
#define MAX 900

//Prototipos
int selectorNumerico(int min, int max);
void cleanStdin ();

void contarElementos (FILE *);

int main (){
	
	printf("Bienvenido al analizador de datos 9000\nIntroduzca en el fichero \"texto.txt\" los datos con los que desea trabajar\n");
	
	FILE *pEntrada;
	pEntrada = fopen (".\texto.txt","r+");
	
	if (pEntrada == NULL){
		printf("ERROR\n\nCompruebe que existe el archivo y tiene los permisos adecuados para poder manipularlo\n");
		printf("Deteniendo ejecución...\n");
		exit(0);
	}
	
	printf("¿Qué desea hacer?\n");
	printf("1) Contar el número de caracteres, líneas y palabras\n");
		

	int entrada = selectorNumerico(1,4);
	
	switch (entrada){
		case 1:
		printf("a");
			
		
		
	}
		
		
		
		

	
	
	
	return 0;
}


void cleanStdin (){
	/*Clean stdin (standar Input) nos permite limpiar la entrada 
	en caso de que introduzcamos dos valores en un mismo scnaf(integer+char)*/
	
	printf("Entrada de datos no válida\n");
	while (getchar () != '\n');	
}

int selectorNumerico(int min, int max){

	//El selector devuelve un valor validado para ser usado en un SWITCH (u otros)
	//Se introduce el intervalo de valores aceptados, y permite devolver un valor
	int num;
	char enter;
	bool validacionBool;
	do{
		printf("---> ");
		int numDatosIntro = scanf("%d%c",&num,&enter);
		
		if(numDatosIntro != 2 || enter != '\n' || num>max || num<min){
			validacionBool=false;
			cleanStdin();
		}
		else
			validacionBool = true;
			
	}while (validacionBool==false);
		
	return num;	 
}

void contarElementos (FILE *pEntrada){
	
	
	
}