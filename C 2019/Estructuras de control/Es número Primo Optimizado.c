/*
Nombre: Calculadora de números primos
Descripción: Si el número es par, o tiene raiz cuadrada, detiene la ejecución.
Compilado mediante gcc enlazando la librería matemática -lm

gcc Es\ número\ Primo\ Optimizado.c -lm && ./a.out

Autor: Jorge Ruiz Gómez
Fecha: 22/04/2019



Versión 1.0


*/
#include <stdio.h>
#include <math.h>
void primos(int);

int main(){
	
	int n;
	
	printf("Introduzca un nÃºmero: ");
	scanf("%d",&n);
	
	primos (n);
	
	return 0;
	
}


void primos(int n){
	int contador=0;
	
	if ((n%2==0) && n!=2)
		contador=2;
	else if(sqrt(n)==round(sqrt(n)))//Si tiene raiz cuadrada sabemos que no es primo
		contador=2;
	else{
		
		for (int a=1; a<n; a+=2){
			if(n%a==0)
				contador++;
			
		}	
	}
	
	if((contador ==1)&&(n!=1))
		printf("%d es primo\n",n);
	else
		printf("%d no es primo\n",n);
	
	
	
}