#include <stdio.h>
#include <string.h>

int main(){
	
	char hola[50];
	char adios[50];
	

	
	printf("Introduzca la palabra hola\n");
	scanf("%s",hola);
	printf("Ha introducido %s\n",hola);
	
	char *d=strchr(hola,'a');
	printf("%d",d);
	
	const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
}