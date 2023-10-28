#include <stdio.h>

void affiche_tab(int tab[],int n){
    printf("{");
    for(int i=0;i<n-1;i++){
        printf("%d,",tab[i]);
    }
    printf("%d}\n",tab[n-1]);
}


void selection2(int t[], int n){
    for (int i=1;i<n;i++){
        int j = i;
        int x = t[i];
        for (;j>0&&t[j-1]>x;j--){
                t[j]= t[j-1];
        }
        t[j] = x;
    }
}

void insertion(int t[],int n){
    for(int i =1;i<n;i++){ // on fait varier i désignant l'élement du tableau à placer
        int j=i; 
        int x=t[i]; // valeur de l'élement à comparer en variable
        for(;j>0 && t[j-1]>x;j--){ // tant que strictement supérieur à 0 et l'élement précedent j-1 grand que l'élement qu'on veut placer
            t[j] = t[j-1]; // décalage des éléments
        }
        t[j] = x ^ t[j]; // swap des valeurs de j à i
        x = x ^ t[j];
        t[j] = x ^ t[j];
    }
}

void try(){
    int a[11] = {4,2,4,6,-1,-120,238,282,-182,0,6};
    affiche_tab(a,11);
    selection2(a,11);
    affiche_tab(a,11);
}

int main(void){
    try();
    return 0;
}