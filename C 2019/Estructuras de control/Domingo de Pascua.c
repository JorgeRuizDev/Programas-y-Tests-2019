#include <stdio.h>
/*
Nombre: Calculadora de domingo de Pascua en C (C99)
Descripción:  Bases (2-16) y números de 16bits comprobados.
Compilado mediante gcc y ejecución desde terminal con ./a.out


Autor: Jorge Ruiz Gómez
Fecha: 21/04/2019



Versión 0.9
		Falta:Limpiar el código, cambiar el puntero *N a variable, y 
			cambiar N de tipo float a integer al dar resultados redondos

*/

//**************************************************************************

int entrada();
void calculo(int, int, int, int, int, int, float *); //El puntero no es necesario,
											//Inicialmente, el programa iba a tener una 
											//Función para imprimir el resultado (N) y se esperaba
											//que este no fuese entero

//**************************************************************************

int main (){
	printf("--------Calculadora de domingo de Pascua para los sigos XX y XXI--------\n\n");
	int A,B,C,D,E;
	float N;
	int anio=entrada();
	calculo(anio,A,B,C,D,E,&N);
	
	
	
	return 0;
}

//**************************************************************************

int entrada(){ //Entrada por retorno
	int a;

	printf("Introduzca un año ente 1901 y 2100.\n-->");
	scanf("%d",&a);

	return a;
}

//**************************************************************************

void calculo(int n, int a, int b, int c, int d, int e, float *N){
		//Se calculan las distintas variables que luegos se usarán para la fórmula *N
	a = n%19;
	b = n%4 ;
	c = n%7 ;
	d = (19*a+24)%30;
	e = (2*b+4*c+6*d+5)%7;
	*N = (22 + d + e);
	
	int aa = *N;	//Evitamos comparar enteros con punteros tipo FLOAT
	if (aa<=31){
		
		printf("El día %d de marzo de %d es domingo de Pascua.\n",aa,n);	
	}
	else										/*Se restan 31 dias al ser abril*/
		printf("El día %d de abril de %d es domingo de Pascua.\n",aa-31,n);
}