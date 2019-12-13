#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
	Programa básico de prueba para ordenar un array mediante el algoritmo de la burbuja, para practicar con ordenación
	
	Autor: Jorge Ruiz Gómez
	Fecha: 27/05/2019
*/

int main(){
	
	printf("----Ordenar Array de n elementos----\n\n");
	
//Variables
	int nElementos = 5;
	char enter; 
	bool ValBool;
	
	printf("Introduzca el tamaño que desea tener el array\n");
	
	do{
	printf("-->");
	scanf("%d%c",&nElementos,&enter);
	if(nElementos <=0 ||enter !='\n')
		ValBool = false;
	else
		ValBool=true;
	}while (ValBool==false);
	
	
	int array[nElementos];
	
	for (int a=0; a<nElementos; a++){
		
		printf("\n---\nIntroduzca el elemento número %d del array\n",a+1);
		scanf("%d",&array[a]);
	}
	
	printf("Array con %d elementos: {",nElementos);
	
	for (int a=0; a<nElementos; a++){
			printf("%d,",array[a]);
	}
	printf("}\n");
	
	//int array[5]={55,156,15687,16549,1654};
	
	printf("\nOrdenar!!!\n");
	int y;
	for (int y=0; y<nElementos; y++){
		
		for (int x=1; x<nElementos; x++){
		
			if (array[x-1]>array[x]){
				
				int z=array[x];
				array[x]=array[x-1];
				array[x-1]=z;	
			}//Fin If
		}//Fin for Y	
	}//Fin for x
	
	for (int i=0; i<nElementos; i++)
	printf("%3d: %5d\n",i+1,array[i]);
	
	/*
	printf("Inversión!\n");
	
	int c=nElementos-1, invertido[nElementos];
	
	for (int b=0; b<nElementos; b++){
		
		invertido[c]=array[b];
		c--;

	}
	printf("\n-------------\n");
	for (int i=0; i<nElementos; i++)
	printf("%d: %5d\n",i+1,invertido[i]);
*/
}