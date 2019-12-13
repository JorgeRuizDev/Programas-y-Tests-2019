#include <stdio.h>



int main (){
	
	int n;
	scanf("%d",&n);
	
	
	int a=n;
	int factorial =a;
	for (a; a>0; a--){
		
		if (a==1)
			factorial +=0;
		else
			factorial = factorial*(a-1);
		
	}
printf("Factorial de %d es %d",n,factorial);
return 0;
	
}