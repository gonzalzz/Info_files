#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void affiche_tab(int n, int tab[n]){
    for(int i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

// exo 1

void creer(){
    int n;
    printf("Quelle taille de tableau ? ");
    scanf("%d",&n);
    int* p = malloc(n*sizeof(int));
    for (int i = 0;i<n;i++){
        p[i]=0;
    }
    affiche_tab(n,p);
    free(p);
}


// exo 2
int carre(int x){
    static int nbcall =0;
    nbcall+=1;
    printf("nb appel : %d ",nbcall);
    return x*x;
}

void bench_carre(){
    int x;
    scanf("%d",&x);
    for (int i=1;i<=x;i++){
        printf("nb carré : %d\n", carre(i));
    }
}
//exo 3
void fill(int** tab,int n, int m){
    *tab = malloc(sizeof(int)*n);
    for (int i=0;i<n;i++){
        (*tab)[i] = m; 
    }
}

void bench_fill(){
    int n=5;
    int* tab = NULL;
    fill(&tab,n,9);
    affiche_tab(n,tab);
    free(tab);
}

int* add_vect(int n, int V1[n], int V2[n]){
    int* p;
    p = malloc(n*sizeof(int));
    for (int i = 0;i<n; i++){
        p[i] = V1[i] + V2[i];
    }
    return p;
}



int main(){
    //bench_fill();
    return 0;
}
