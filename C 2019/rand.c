#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include<time.h> 

#define defvitorias1 5
#define defvitorias2 5
//Simple programa para calcular/simular un combate
//Programado por Jorge Ruiz Gómez
int main(){
	//3+5
	
	srand(time(NULL));
	int total=0;
	int victorias1=0, victorias2=1;
	int medianVictorias1=0, medianVictorias2=0;
	for(int b=0; b<200;b++){
		for (int a; a<50; a++){
			int random = rand()%(defvitorias2+defvitorias1);
			//int random = rand()%2;
			printf("%d\n",random);
			total +=random;
		if (random<defvitorias1)
			victorias1+=1;
		else
			victorias2+=1;
		//printf("media: %d\n victorias 1= %d, victorias 2= %d",total/50,victorias1, victorias2);
		}
		medianVictorias1+=victorias1;
		medianVictorias2+=victorias2;
	}
	printf("Media de victorias: %d y %d",medianVictorias1/50, medianVictorias2/50);
	
}