#include <stdio.h>
#include <stdlib.h>
/*
	Programa básico de prueba para invertir un array, para practicar con ordenación
	
	Autor: Jorge Ruiz Gómez
	Fecha: 27/05/2019
*/

int main(){
	
	printf("----Invertir Array de n elementos----\n\n");
	
//Variables
	int nElementos;
	char enter; 
	bool ValBool;
	
	printf("Introduzca el tamaño que desea tener el array\n");
	
	do{
	printf("-->");
	scanf("%d%c",&nElementos,&enter);
	if(nElementos <0 ||enter !='\n')
		ValBool = false;
	else
		ValBool=true;
	}while (ValBool==false);
	
	
	int array[nElementos];
	
	for (int a=0; a<nElementos; a++){
		
		printf("\n---\nIntroduzca el elemento número %d del array\n",a+1);
		scanf("%d",&array[a]);
	}

	printf("Inversión!\n");
	
	int c=nElementos-1, invertido[nElementos];
	
	for (int b=0; b<nElementos; b++){
		
		invertido[c]=array[b];
		c--;

	}
	printf("\n-------------\n");
	for (int i=0; i<nElementos; i++)
	printf("%d: %5d\n",i+1,invertido[i]);
}
