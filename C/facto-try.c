#include <stdio.h>

long facto(int a) {

	int i;
	long result = 1;
	if (a<=1) { 
	return 1;} else {
	
	result = a * facto(a-1);
	
	}
	return result;

}



int main(void) {

int k;
scanf("%d",&k);
printf("output : %ld\n", facto(k));
return 0;	

}
