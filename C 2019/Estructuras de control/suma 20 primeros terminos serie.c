/*
Nombre: Sumatorio
Descripción: Ni me acuerdo de que era
Compilado mediante gcc y enlazado de librería matemática con -lm
Ejecutado mediante ./a.out

Autor: Jorge Ruiz Gómez
Fecha: 22/04/2019

Versión 1.0
*/


#include <stdio.h>
#include <math.h>

int main (){
	
	int num =0, den=0;
	int sumDen=0,sumNum=0;
	for(int a=1; a<=20;a++){
	
		
		num++;
		sumNum+=num;
		den=pow(2,a);
		sumDen+=den;
		printf("%d/%d+",num,den);
			if (a==20)
			printf("\n\n");
	}
	printf("%d\n--\n%d\n",sumNum, sumDen);
	
}