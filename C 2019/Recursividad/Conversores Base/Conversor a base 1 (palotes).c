#include <stdio.h>




void entrada(int *);
int palotes (int);

int main () {
	int numero;
	printf("--------Imprime un número en palotes--------\n\n");
	entrada(&numero);
	palotes(numero);
	
	
}

void entrada(int *n){
	printf("Introduzca un número natural a mostrar: ");
	scanf("%d",n);
}

int palotes (int n){
	
	if (n==1)
		printf("I\n");
	
	else{
		if (n%5==0)
			printf(" ");
		
		printf("I");
		return (palotes(n-1));
	}
	
	
}