#include <stdio.h>

void swap(int* px,int* py){
    *py = *px^*py;
    *px = *px^*py;
    *py = *px^*py;
}

void scalprod(int vx,int vy,int a,int *vax,int *vay){
    *vax = vx *a ;
    *vay = vy * a;
}

void test_scal(){
    int x=2,y=3;
    int vay,vax;
    scalprod(x,y,3,&vax,&vay);
    printf("vax = %d vay = %d \n",vax, vay);
}

int main(){
    int x = 1,y=2;
    swap(&x,&y);
    test_scal();
    printf("x = %d  y = %d\n",x,y);
}