#include <stdbool.h>

bool bisiesto (int, int);//(mes,año)

bool bisiesto (int pMes, int pYear){
	
	if (pMes == 2 && ((pYear%4 ==0 && pYear%100 !=0) | (pYear%400==0 && pMes ==2) ))
		return true;
	else
		return false;
}
