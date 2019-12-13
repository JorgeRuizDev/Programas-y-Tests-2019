/*
Nombre: Calculadora de Máximo Común Divisor mediante Euclides
Descripción: Utiliza el algoritmo de Euclides para calcular el MCD
Compilado mediante gcc y ejecutado mediante ./a.out

Autor: Jorge Ruiz Gómez
Fecha: 22/04/2019

Versión 1.0
*/


#include <stdio.h>

void entrada(int *, int *);
int euclides(int a, int b);

int main (){
	
	int a,b;
	entrada(&a,&b);
	int resultado = euclides (a,b);
	printf("El mínimo común divisor de %d y %d es %d\n",a,b,resultado);
	return 0;
}

void entrada(int *a, int *b){
	
	printf("Introduzca dos números separados con un enter\n");
	scanf("%d\n%d",a,b);
}

int euclides(int a, int b){
	
	if(b>a){
		int c=a;
		a=b;
		b=c;
	}
		
	while (b!=0){
		
		int c=a;
		a=b;
		b=c%b;
		
	}
	return a;
}