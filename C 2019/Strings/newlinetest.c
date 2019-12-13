#include <stdio.h>
#include <string.h>
//Programa muy simple que elimina el \n ó \r\n de un string.
//obtenido de stackoverflow, "programado" por Jorge Ruiz Gómez
int main (){
	
	
	char buffer[50];
	char entrada[50];
	strcpy(entrada,"holacaracola\n");
	printf("entrada: %s",entrada);
	printf("-----\n");
	entrada[strcspn(entrada, "\r\n")] = 0;
	printf("entrada: %s",entrada);
	printf("-----\n");
}