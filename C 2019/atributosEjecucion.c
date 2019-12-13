/*
Autor: Jorge Ruiz Gómez
Fecha: 25/09/2019

Test de entrada de atributos en C

github: jorgestar29
*/

#include <stdio.h>


int main(int argc, char const *argv[])
{
	printf("Hola mundo\n");


	if(argc >1){
		printf("Se han introducido %d atributos\n",argc);
		printf("Atributos Introducidos:\n");

		for (int i=1;i<argc;i++){

			printf("argc[%d] = %s\n",i,argv[i]);
		}
	}else{
		printf("Ejectua el binario ensamblado con texto detrás del nombre del archivo, para poder ejecutar atributos varios\n");
		printf("Ejemplo: \n\t ./a.out hola mundo\n");
	}

	return 0;
}