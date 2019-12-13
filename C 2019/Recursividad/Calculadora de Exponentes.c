/*
Creado por Jorge Ruiz Gómez como ejercicio de prueba para programación en C.
21/04/2019
*/

#include <stdio.h>


void entrada(int *, float *);
float exponente (int, float, int);
int main (){
	printf("----------Decimal elevado a un entero por recursividad----------\n\n");
	int entero;
	float decimal;
	entrada(&entero, &decimal);
	int contador = entero;
	float resultado = exponente (entero, decimal, contador);
	printf("%f elevado a %d es %f\n",decimal, entero, resultado);
	return 0;
}


void entrada(int *d, float *f){
	
	printf("Introduzca un la base en decimal y un entero como exponente\n");
	
	printf("\nBase (Decimal) ->");
	scanf("%f",f);
	printf("Exponente (Entero) ->");
	scanf("%d",d);

	
}
float exponente (int e, float d, int contador){
	
	if (contador ==0)
		return 1;
	else
		return(d * exponente(e,d,contador-1));
	
	
}