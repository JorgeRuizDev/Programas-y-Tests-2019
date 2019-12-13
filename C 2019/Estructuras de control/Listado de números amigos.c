/*
Nombre: Listado de numéros amigos mayores que 1000
Descripción: Muestra todos los números amigos comprendidos entre 1000 y un
número de 16 bits (2Bytes) introducido por teclado

Compilado: Mediante gcc y ejecución mediante ./a.out en la termianl


Autor:Jorge Ruiz Gómez
Fecha 23/04/2019

Versión 1.0:
*/
//***Directivas de Preprocesador*****************************************
#include <stdio.h>
#include <stdbool.h>

//***Declaración de Prototipos*******************************************

int suma_div(unsigned);
unsigned entrada ();
void f_clearStdin();
void numerosAmigos (int);



//**Función central*******************************************************

int main () {
	
	unsigned numeroMax = entrada ();
	numerosAmigos (numeroMax);
	
	
	return 0;
}

int suma_div(unsigned n){
	
		int suma=0,a;

		for (a=1; a<=n-1; a++){
			
			if(n%a==0)
				suma +=(a);	
			}	

	return suma;
}

unsigned entrada (){
	int  entradaCorrecta, numero;
	bool entradaCorrectaBool;
	char enter;
	
	printf("Introduzca un número positivo mayor que 1000\n");
	do{
	printf("---> ");
	entradaCorrecta = scanf("%d%c",&numero,&enter);
	
	if (entradaCorrecta !=2 | numero <=1000 |enter != '\n'){
		entradaCorrectaBool = false;
		f_clearStdin();
		}
	
	else
		entradaCorrectaBool = true;


	}while (entradaCorrectaBool == false);	
	return numero;
}


void f_clearStdin(){
	printf("Introduzca un dato válido");
	while (getchar () != '\n');
}

void numerosAmigos (int max){
	int i; //Contador del programa
	printf("------------------\n");
	for (i=1000; i<=max; i++){
		
		for (int b=i; b<=max; b++){//Si b<i, se pueden repetir los resultados
			
			if ((suma_div (i)==b ) && (suma_div(b)==i ))  
				printf("%d y %d son números primos\n------------------\n",b,i);
		}
	
	}
}
