/*
	Autor: Jorge Ruiz Gómez
	Descripción: Suma dos matrices (introducidas / aleatorias)
	Objetivo: Aprender a utilizar vectores bidimensionales
	Error: Desconocimiento de como pasar un array 2d a otra función
	(Ya que da warnings)
	
	Fecha: 26/05/2019
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//tamaño de la matriz CUADRADA
#define TAM 4


void cargarMatriz (int [TAM][TAM]);
void sumaMatrices(int matriz1[][TAM],int matriz2[][TAM]);

int main(){
	
	int matriz1[TAM][TAM],matriz2[TAM][TAM];
	srand(time(NULL));
	system("clear");
	printf("\n------Suma de matrices cuadradas de tamaño %d------\n",TAM);
	printf("\n\nMatriz 1\n");
	cargarMatriz(matriz1);	
	printf("\n\nMatriz 2\n");
	getchar();
	fflush(stdin);
	cargarMatriz(matriz2);
	
	int matriz3[TAM][TAM],matriz4[TAM][TAM];
	sumaMatrices(matriz1,matriz2);

	
/*	
	int matrizResultado[TAM][TAM];
	int x,y;
			for (x=0;x<TAM;x++){
				
				for (y=0;y<TAM;y++){
				matrizResultado[x][y]=matriz1[x][y]+matriz2[x][y];
				}//fin for y

			}//fin for x

	printf("\n\n\nLa suma de ambas matrices es:\n");
			
			for (x=0;x<TAM;x++){
				printf("|");
				for (y=0;y<TAM;y++){
					printf("%6d",matrizResultado[x][y]);
				}//fin for y
				printf("|\n");	
			}
	
*/	
	return 0;
}

void cargarMatriz (int matriz[TAM][TAM]){
	
	char entrada;
	int manual=0;
	
	
	printf("¿Desea introducir datos manualmente?\nIntroduzca [S] ó [Y] para introducir los datos manualmente\nIntroduzca [ENTER] para datos aleatorios\n-->");
	
	scanf("%c",&entrada);
	
	switch (entrada){
		
		case 's':
		case 'S':
		case 'y':
		case 'Y':
		manual =1;
		break;

	};
	
	int x=0,y=0;//X e Y invertidas (X = Línea, Y = Columna...)
	
		if (manual == 1){
			printf("Los datos se introduciran por filas");
			printf("----\nIntroduce los elementos de la línea %d\n----\n",x+1);
			for (x;x<TAM;x++){
				printf("----\nIntroduce los elementos de la línea %d\n----\n",x+1);
				for (y;y<TAM;y++){
					printf("Introduzca los datos de la posición %d,%d\n",x+1,y+1);
					scanf("%d",&matriz[x][y]);
				}//fin for y
			
			y=0;
			}//fin for x
			
			//Mostrar matriz
			for (x=0;x<TAM;x++){
				printf("|");
				for (y=0;y<TAM;y++){
					printf("%4d",matriz[x][y]);
				}//fin for y
				printf("|\n");
			
			}//fin for x			

		}
		else{
			
			printf("Entrada de datos aleatoria\nEspere...\n");


			for (x;x<TAM;x++){
				
				for (y;y<TAM;y++){
					matriz[x][y]=(rand()%999);
				}//fin for y
			
			y=0;
			}//fin for x
			
			//Mostrar matriz
			for (x=0;x<TAM;x++){
				printf("|");
				for (y=0;y<TAM;y++){
					printf("%4d",matriz[x][y]);
				}//fin for y
				printf("|\n");
			
			}//fin for x						

		}

}

void sumaMatrices(int matriz1 [][TAM],int matriz2[][TAM]){
	int matrizResultado[TAM][TAM];
	int x,y;
			for (int x=0;x<TAM;x++){
				
				for (int y=0;y<TAM;y++){
				matrizResultado[x][y]=matriz1[x][y]+matriz2[x][y];
				}//fin for y

			}//fin for x

	printf("\n\n\nLa suma de ambas matrices es:\n");
			
			for (x=0;x<TAM;x++){
				printf("|");
				for (y=0;y<TAM;y++){
					printf("%7d",matrizResultado[x][y]);
				}//fin for y
				printf("|\n");	
			}
	
	
}