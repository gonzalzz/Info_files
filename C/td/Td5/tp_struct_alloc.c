#include "bibli.h"
#include "tp_struct.h"
// Toutes les fonctions

aws* new_aws(int n){
    aws* p = malloc(sizeof(aws));
    int* i;
    i = calloc(n,sizeof(int));
    p->t = i;
    p->size = n;
    return p;
}

mws* new_mws(int n, int m){
    mws* a = malloc(sizeof(mws));
    int** toto = malloc(n * sizeof(int*));
    for (int i = 0; i<n; i++){
        toto[i] = calloc(m,sizeof(int));
    }
    a->mat = toto;
    a->nbl = n;
    a->nbc = m;
}


void free_aws(aws* a){
    free(a->t);
    free(a);
}

void display_aws(aws* tab){
    for (int i =0;i<tab->size;i++){
        printf("%d",tab->t[i]);
    }
    printf("\n");
}

void free_mws(mws* a){
    for (int i = 0;i<a->nbl;i++){
        free(a->mat[i]);
    }
    free(a);
}
void display_mws(mws* m){
    for (int i =0;i<m->nbl; i++){
        printf("|");
        for (int j = 0; j<m->nbc;j++){
            printf("%d, ",m->mat[i][j]);
        }
        printf("|\n");
    }
}

mws* hadamard(mws* m1,mws* m2){
    mws* res = new_mws(m1->nbl,m1->nbc);
    for (int i = 0; i<m1->nbl;i++){
        for (int j = 0; j<m1->nbc;j++){
            res->mat[i][j]= m1->mat[i][j] * m2->mat[i][j];
        }
    }
    return res;
}