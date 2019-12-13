#include <stdio.h>
#include <string.h>
//NOTA: No hay control de entrada.

//Structs

struct nombreCompleto{
	char nombre[50];
	char apellido1[50];
	char apellido2[50];
};

struct usuario{
	
	char nick[50];
	struct nombreCompleto nombreC;
	int NIF;
	float nota;

};
typedef struct usuario USUARIO;




int main(){
	//system ("clear");
	printf("----Prueba de structs----\n\n");
	int TamVector;
	printf("Introduzca el número de usuarios que quiere introducir\n");
	scanf("%d",&TamVector);
	
	USUARIO vector[TamVector];
	
	for (int a=0; a<TamVector; a++){
		printf("\n-------------\nUsuario número %d\n",a+1);
		printf("Nombre: ");
		scanf("%s",vector[a].nombreC.nombre);
		
		printf("Apellidos: ");
		scanf("%s %s",vector[a].nombreC.apellido1,vector[a].nombreC.apellido2);	
		
		printf("Nick: ");
		scanf("%s",vector[a].nick);		
		
		printf("NIF: ");
		scanf("%d",&vector[a].NIF);

		printf("Nota: ");
		scanf("%f",&vector[a].nota);

	}
	printf("--------------\n");
	for (int a=0; a<TamVector; a++){
		
		printf("%s %s, %s\nNick: %s\nNIF: %d\nNota: %2.f\n\n",vector[a].nombreC.apellido1,vector[a].nombreC.apellido2,vector[a].nombreC.nombre,vector[a].nick,vector[a].NIF,vector[a].nota);
		
	}
}