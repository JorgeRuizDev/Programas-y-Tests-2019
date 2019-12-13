/*
Nombre: Multiplicación de dos números
Descripción: Se aplica el algoritmo de multiplicación rusa
Compilado mediante gcc y ejecutado mediante ./a.out

Autor: Jorge Ruiz Gómez
Fecha: 22/04/2019

Versión 1.0
*/
#include <stdio.h>

void entrada(int*, int *);
int multiplicacion(int , int);

int main(){
	int a,b;
	entrada(&a,&b);
	int resultado=multiplicacion(a,b);
	printf("%d*%d=%d mediante la multiplicación rusa.\n",a,b,resultado);

}

void entrada(int *a, int *b){//Entrada mediante asignación de punteros
	printf("Introduzca los el multiplicando y multiplicador con el siguiente formato: a*b\n");
	scanf("%d*%d",a,b);
	
}
int multiplicacion(int a, int b){
	int suma=0;
	//***Comprobación Inicial
	if(a==b)
		return a;
	else if(a==0 |b==0)
		return 0;
	else if(a==1)
		return b;
	else if(b==1)
		return a;
	//****
	
	if(b%2!=0)//Se realiza una primera comprobación antes del bucle con los operandos introducidos
		suma+=a;
	
	while (b!=1){
	
		a<<=1;//mutiplicando
		b>>=1;//multiplicador
		if(b%2!=0)
			suma+=a;
	}
		return suma;
}