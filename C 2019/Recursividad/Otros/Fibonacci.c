#include <stdio.h>
//Programar un algoritmo recursivo que calcule un número de la serie fibonacci.
#define numero 8

int f_Fibonacci(int);

int main (){
printf("--------Fibonacci--------\n\n");
	
	printf("El número de la serie de fibonacci de %d es %d\n",numero,f_Fibonacci(numero));
	
}

int f_Fibonacci(int n){
	
	if (n==1 | n==2)
		return 1;
	else
		return (f_Fibonacci(n-1)+f_Fibonacci(n-2));
	
	
}