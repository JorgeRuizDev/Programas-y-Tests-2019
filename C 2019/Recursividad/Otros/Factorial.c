#include <stdio.h>

#define numero 5




int factorial(int);

int main (){
	printf("--------Factorial--------\n\n");
	int resultado = factorial(numero);
	printf("El factorial es %d\n",resultado);
	return 0;
}


int factorial(int n){
	
	if (n==1)
		return 1;
	else
		return (n*factorial(n-1));
	
}