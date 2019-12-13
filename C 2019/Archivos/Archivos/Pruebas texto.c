/*
	Programa con el que practicar la entrada, modificación y salida de archivos de texto.
		Comprobaciones con wc -lwc
		
	Autor: Jorge Ruiz Gómez
	Fecha: 25/05/2019


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Define
#define MAX 900
#define MAX2 999999
//Prototipos
int selectorNumerico(int min, int max);
void cleanStdin ();
void selector(FILE *);
int contarElementos (FILE *,char []);
int cifrado(char archivo[]);
void filaMasLarga(FILE *pArchivo);
	
	
	
	
	
	
int main (){
	//system("clear");
	

	FILE *pEntrada;
	pEntrada = fopen ("texto.txt","r+");

	printf("Bienvenido al analizador de datos 9000\nIntroduzca en el fichero \"texto.txt\" los datos con los que desea trabajar\n");
	
	if (pEntrada == NULL){
		printf("\nERROR\nCompruebe que existe el archivo y tiene los permisos adecuados para poder manipularlo\n");
		printf("Deteniendo ejecución...\n");
		exit(0);
	}

	selector(pEntrada);

	return 0;
}


void cleanStdin (){
	/*Clean stdin (standar Input) nos permite limpiar la entrada 
	en caso de que introduzcamos dos valores en un mismo scnaf(integer+char)*/
	
	printf("Entrada de datos no válida\n");
	while (getchar () != '\n');	
}

int selectorNumerico(int min, int max){

	//El selector devuelve un valor validado para ser usado en un SWITCH (u otros)
	//Se introduce el intervalo de valores aceptados, y permite devolver un valor
	int num;
	char enter;
	bool validacionBool;
	do{
		printf("---> ");
		int numDatosIntro = scanf("%d%c",&num,&enter);
		
		if(numDatosIntro != 2 || enter != '\n' || num>max || num<min){
			validacionBool=false;
			cleanStdin();
		}
		else
			validacionBool = true;
			
	}while (validacionBool==false);
		
	return num;	 
}

void selector(FILE *pEntrada){
		
	char archivo[MAX2];
	int nLineas;

	printf("Información sobre el archivo:\n");

	nLineas=contarElementos (pEntrada,archivo);
	
	printf("Pulse [enter] para continuar\n");
	getchar();

	filaMasLarga(pEntrada);

	printf("Pulse [enter] para continuar\n");
	getchar();
	
	printf("Nuevo archivo \"Hola.txt\" con el archivo 'cifrado'\n");
	cifrado(archivo);	
	
	/*
	 //Debug que imprime todo el archivo
	for (int i=0; i<99999 && i>=0;i++){
		printf("%c",archivo[i]);

		if(archivo[i]==EOF)
			i=-1;
		}
	*/
		
}	

int contarElementos (FILE *pEntrada, char archivo[] ){
	char c;
	//char hola[MAX2];
	int nLineas=0, nPalabras=0, nCaracteres=0;
	
	c=fgetc(pEntrada);
	while (c != EOF){
	strcpy(&archivo[nCaracteres],&c);
//	printf("%c",c);
	nCaracteres++;
	
	if(c=='\n')
		nLineas++;
	if(c==' ' || c== '\n')
		nPalabras++;
	
	c=fgetc(pEntrada);
	
	}

	printf("El número de líneas es: %d\nEl número de palabras es: %d\nEl número de caracteres es: %d\n",nLineas,nPalabras,nCaracteres);

	printf("\nSegún el comando \n$wc -wlc texto.txt:\n");

	char command[50];
   	strcpy(command, "wc -wlc texto.txt" );
   	system(command);
	return nLineas;
}

int cifrado(char archivo[]){
	int tam=strlen(archivo);
	//printf("Tamaño array %d\n",tam);
	char nuevo[tam];
	char c;

	FILE *pEscribir;
	pEscribir = fopen ("Hola.txt","w+");





	for (int bucle=0; bucle<=tam; bucle++){
//	strcpy(&c,&archivo[bucle]);
//	if(archivo[bucle]!='\n')
	c=archivo[bucle];
	c++;

	//strcpy(&nuevo[bucle],&c);
	

		if (archivo[bucle]=='\n')
			fprintf(pEscribir,"\n");
		else
			fprintf(pEscribir,"%c",c);
	}
	fclose(pEscribir);
}

void filaMasLarga(FILE *pArchivo){
	char lineas[9999];
	char buffer[100];
	int a=0;

	fflush(pArchivo);
	
	/*while(fscanf(pArchivo,"%[^\n]\n",lineas[a])!=EOF){
		printf("%s",lineas[a]);
		a++;
	}*/
	

	while(fgets(lineas[a],strlen(lineas[a]),pArchivo)!= NULL){
		printf("..");
		//puts(&lineas[a]);
		//amano[a]=strlen(&lineas[a]);
		a++;
	}
	
	printf("%d\n",a);
	
	
	
}

