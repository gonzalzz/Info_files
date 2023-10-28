#include <stdio.h>
#include <stdbool.h>


int main(){
    int x =0,i=1;
    bool test = false;
    while (!test){
        printf("Cb font 2 x 2 : ");
        scanf("%d",&x);
        test = x==4;
        if (!test){
            printf("encore ! \n");
            i = i + 1;
        }
    }
    printf("ok %d\n",i);
}