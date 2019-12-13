/*
Nombre: Conversor de base decimal en C (C99) mediante recursividad
Descripción:  Bases (2-10) y números de 16bits comprobados
Compilado mediante gcc y ejecución desde terminal con ./a.out


*******************************************************
*******************************************************
VERSIÓN MEJORADA:

https://github.com/Jorgestar29/Universidad/blob/master/Conversor%20de%20base%20decimal%20a%20otra%20base%20(2-16).c

*******************************************************
*******************************************************
Autor: Jorge Ruiz Gómez
Fecha: 22/04/2019

Versión 1.0
	-No es el método más efectivo, ya que sería más optimo almacenar las 
		divisiones en un array y luego invertirlo para mostrer el 
		resultado final y poder trabajar con él.

*/


//***Directivas de Preprocesador***********************************************
#include <stdio.h>


//***Definición de Prototipos**************************************************
int conversor(int, int);
void entrada(int *, int *);


int main (){
	printf("-------Conversor de entero decimal a otra base (2 a 10)-------\n\n");
	
	int base, entero;
	entrada (&entero, &base);
	
	conversor(entero, base);
	printf("<------					(Leer de derecha a izquierda)\n");
	
	
}

//*****************************************************************************

void entrada(int *d, int *f){	//Entrada mediante paso por referencia gracias a punteros
	
	printf("Introduzca la base  y un entero a convertir\n");
	
	printf("\nBase (Entre 2 y 10) -> ");
	scanf("%d",f);
	printf("Entero -> ");
	scanf("%d",d);
}

//*****************************************************************************

int conversor(int e, int b ){ //e-->Entero	//	b-->Base
	if (e/b==0)
		printf("%d\n",e%b);
	else{
		printf("%d",e%b);
		conversor(e/b,b);
		
	}
	/*Funcionamiento del conversor:
		Imprime el resto de la división del entero por la base deseada.
		Mediante Recursividad, se realizan los mismos pasos pero con el número
		dividido por la base.
		Así sucesivamente hasta que el resto es MENOR que la base, o la división
		redondeada da 0 exacto, que se detiene la ejecución.
	*/
}
