/*
Autor: Jorge Ruiz Gómez
Fecha:23/04/2019

Descripción: Introduce un número y muestra todos los números perfectos
	comprendidos entre 1 y el número
	
	Código para práctica personal
*/

//Directivas de preprocesador
#include <stdio.h>


//Definición de prototipos
void entrada(int *);
void perfectos(int);
//main
int main(){
	printf("----Calculadora de números perfectos en un intervalo (1-n)----\n\n");
	//variables
	int n;
	
	
	//cuerpo
	entrada(&n);
	perfectos(n);
	
}

void entrada(int *n){
	
	printf("Introduzca el número máximo del intervalo abierto (1-n) :");
	scanf("%d",n);
	
}
void perfectos(int n){
	
	for (int a=2; a<n; a++){
		int suma = 0;
		
		for (int b=1; b<a;b++){
			if(a%b==0)
				suma+=b;			
		}
		
		if(suma==a)
			printf("\n\n%d es un número perfecto\n",a);
		
	}
	
	
}