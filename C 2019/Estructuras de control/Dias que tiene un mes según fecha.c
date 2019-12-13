/*
Nombre:Calculadora de días del mes

Compilado mediante gcc y ejecución desde terminal con ./a.out


Autor: Jorge Ruiz Gómez
Fecha: 21/04/2019

Versión 1.0
*/

#include <stdio.h>
#include <stdbool.h>
//Constantes Define




//*************************************************************************
//Prototipos
void f_entrada (int *, int *, int*);
void f_cleanStdin ();
int f_bisiesto (int , int );
void diasMes (int , int );






//*******main**************************************************************

int main () {
	
	int mes,anio;
	int bisiesto;
	f_entrada (&mes, &anio, &bisiesto);
	diasMes (mes , bisiesto );

}

void f_entrada (int *m, int *a, int *bisiesto){
	char enter;
	int validacionEntrada;
	bool validacionEntradaBool;
	
	do {
	printf("Introduzca el mes y el año con el siguente formato mm/aaaa\n");
	printf("--->");
	validacionEntrada = scanf("%d/%d%c",m,a,&enter);

	if ( *m<1 | *m>12 | validacionEntrada != 3 | *a<1){
		f_cleanStdin ();
		validacionEntradaBool = false;
		
		}
	else {
		validacionEntradaBool = true;
		*bisiesto = f_bisiesto (*m,*a);
		}
	}while (validacionEntradaBool == false);
	
	
	
	
}

void f_cleanStdin (){
	printf("Entrada Incorrecta, introduzca datos postivios y válidos\n");
	while (getchar () != '\n');
	
} 

void f_diasMes (int m, int a){
	

	
	
	
}

int f_bisiesto (int m, int a){
	
	if (m = 2 && a%4==0){
		return 1;
	}
	
	else
		return 0;
	
	
}

void diasMes (int m, int bisiesto){
	
	if (bisiesto == 1)
		printf("El mes %d tiene 29 días\n",m);
	
	else{
		
		switch (m){
			
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			printf("El mes %d tiene 31 días\n",m);
			break;
			
			case 2:
			printf("El mes %d tiene 28 días",m);
			break;
			
			case 4:
			case 6:
			case 9:
			case 11:
			printf("El mes %d tiene 30 días\n",m);
			break;
		}
			
			
		}
		
		
	}
	
	

