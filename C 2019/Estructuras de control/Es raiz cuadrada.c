#include <stdio.h>
#include <math.h>
//El programa nos devuelve si un programa es una raiz cuadrada perfecta
//Compilar mediante GCC enlazando la librería math.h con -ln al final
//gcc Es\ raiz\ cuadrada.c -lm && ./a.out

int main (){
	
	printf("-------Has this number a Square Root?-------\n\n-->");
	int n;
	scanf("%d",&n);
	putchar('\n');
	if (sqrt(n)==round(sqrt(n)))
		printf("Square Root!!!!\n");

	else
		printf("It's not a square root:(\n");




}
