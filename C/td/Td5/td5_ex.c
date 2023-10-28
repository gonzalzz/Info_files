#include <stdlib.h>
#include <stdio.h>


typedef struct array_with_size aws;

struct array_with_size{
    int* t;
    int size;
};

typedef struct matrix_with_size mws;

struct matrix_with_size{
    int** mat;
    int nbl;
    int nbc;
};

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

void free_mws(mws* a){
    for (int i = 0;i<a->nbl;i++){
        free(a->mat[i]);
    }
    free(a);
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

void test(){
    aws* p = new_aws(15);
    display_aws(p);
    free_aws(p);
    mws* q = new_mws(15,3);
    display_mws(q);
    free_mws(q);
}

void test_hadamard(){
    mws* m1 = new_mws(3,3);
    mws* m2 = new_mws(3,3);
    m1->mat[1][2] = 6;
    m2->mat[1][2] = 3;
    mws* res = hadamard(m1,m2);
    display_mws(res);
    free_mws(m1);
    free_mws(m2);
    free_mws(res);
}


int main(){
    //test();
    test_hadamard();
    return 0;
}
