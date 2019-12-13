#include <stdio.h>
#include <stdbool.h>
//Programa para comprobar si una funcion tipo bool puede devolver true o false.
bool test();

int main (){
	
bool testfinal = test();

		if (testfinal == true)
			printf("True\n");
		else
			printf("False\n");

		printf("Conclusión, funciona el return true/false en funciones tipo bool\n");
}

bool test(){
	int numero;
	printf("1) True\n2)False\n");
	scanf("%d",&numero);
	
	switch (numero){
		case 1:
		return true;
		break;
		case 2:
		return false;
		break;
		
	}

	
}