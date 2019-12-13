/*
Nombre: Conversor de base decimal en C (C99) mediante recursividad
Descripción:  Bases (2-16) y números de 16bits comprobados
Compilado mediante gcc y ejecución desde terminal con ./a.out

Existe versión de cálculo mediante bucles

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
	printf("-------Conversor de entero decimal a otra base (2 a 16)-------\n\n");
	
	int base, entero;
	entrada (&entero, &base);
	
	conversor(entero, base);
	printf("<------					(Leer de derecha a izquierda)\n");
	
	
}

//*****************************************************************************

void entrada(int *d, int *f){	//Entrada mediante paso por referencia gracias a punteros
	
	printf("Introduzca la base  y un entero a convertir\n");
	
	printf("\nBase (Entre 2 y 16) -> ");
	scanf("%d",f);
	printf("Entero -> ");
	scanf("%d",d);
}

//*****************************************************************************

int conversor(int e, int b ){ //e-->Entero	//	b-->Base
	int tmp =e%b;



		
		switch(tmp){
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;			
		case 12:
			printf("C");
			break;		
		case 13:
			printf("D");
			break;		
		case 14:
			printf("E");
			break;		
		case 15:
			printf("F");
			break;	
		default:
			printf("%d",e%b);
		break;}
		
		if (e/b==0)
			putchar ('\n');
		else
			conversor(e/b,b);
		
		
	
	/*Funcionamiento del conversor:
		Imprime el resto de la división del entero por la base deseada.
		Mediante Recursividad, se realizan los mismos pasos pero con el número
		dividido por la base.
		Así sucesivamente hasta que el resto es MENOR que la base, o la división
		redondeada da 0 exacto, que se detiene la ejecución.
		
		Si uno de los valores es superior a 9, se representa con letras (A=10, B=11, C=12...)
	*/
}
