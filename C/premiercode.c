#include <stdio.h>

/*
C'est le premier code de l'année
*/

int

int main(void){

int i;
int j[3] = {6,2,15};
printf("j[%d]=%d,j[%d]=%d, j[%d]=%d\n",0,j[0],1,j[1],2,j[2]);
scanf("%d",&i);
printf("%d,%d\n",i,j[i]);

char hello[10];
scanf("%s",hello);
printf("%s\n",hello);


return 0; // on renvoie 0 pour le recup 

}
