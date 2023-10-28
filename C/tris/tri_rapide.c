#include <stdio.h>

void affiche_tab(int tab[],int n){
    printf("{");
    for(int i=0;i<n-1;i++){
        printf("%d,",tab[i]);
    }
    printf("%d}\n",tab[n-1]);
}

int sort(int t[],int m,int n){
    if (n-m!= 1) {
    int pivot=t[n-1];
    int i=m;
    int j=m-1;
    while(i<n-1){
        if(t[i]<= pivot){
            j++;
            if (j<i){
                t[i] = t[j]^t[i];
                t[j] = t[j]^t[i];
                t[i] = t[j]^t[i];
            }
        }
        i++;
    }
    j++;
    t[n-1]= t[n-1]^t[j];
    t[j]= t[n-1]^t[j];
    t[n-1]= t[n-1]^t[j];
    n=j;
    return j;
    }
    return n;
}

void quick(int t[],int n){
    int index_pivot=0;
    index_pivot= sort(t,0,n);
    sort(t,0,index_pivot-1);
    sort(t,index_pivot+1,n);
}


void try(){
    int a[5] = {9,7,4,3,5};
    affiche_tab(a,5);
    quick(a,5);
    affiche_tab(a,5);
}

int main(void){
    try();
    return 0;
}