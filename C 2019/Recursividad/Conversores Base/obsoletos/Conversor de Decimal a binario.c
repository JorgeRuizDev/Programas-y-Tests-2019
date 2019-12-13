/*
Nombre: Conversor de decimal a binario en C (C99) mediante recursividad
Descripción: Obsoleto, visite el siguiente link para una versión compatible
con basesde de 2-10.
https://github.com/Jorgestar29/Programacion-2019/blob/master/Conversor%20de%20base%20decimal%20a%20otra.c

Compilado mediante gcc y ejecución desde terminal con ./a.out


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
void entrada (int *);
int convBinario (int);


int main (){
	printf("----------Imprime un Número en binario----------\n\n");
	int numero;
	entrada (&numero);
	convBinario (numero);
	printf("<-----------\n");
	
	
}

//*****************************************************************************

void entrada(int *n){ //Entrada mediante paso por referencia gracias a punteros
	printf("Introduzca un número natural a convertir: ");
	scanf("%d",n);
}

//*****************************************************************************

int convBinario (int n){
	if (n==0)
		printf("0\n");
	else if (n==0)
		printf("1\n");
	
	else{
		
		if (n%2==0)
			printf("0");
		else
			printf("1");
	
		return (convBinario (n/2));
	}
}
