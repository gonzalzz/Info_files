#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


void affiche_tab(int* tab,int n){ // affiche en cmd un tableau
    printf("{");
    int i = 0;
    for(;i<n-1;i++){
        printf("%d,",tab[i]);
    }
    printf("%d}\n",tab[i]);
}

void affiche_mat(int** mat, int n,int m){ // affiche en cmd une matrice
    for (int i=0;i<m;i++){
        printf("| ");
        int j=0;
        for (;j<n-1;j++){
            printf("%15d ,",mat[i][j]);
        }
        printf("%5d |\n",mat[i][j]);
    }
}

void array(int** p,int n){ // créer un talbleau avec malloc
    *p = malloc(n*sizeof(int));
}

void matrice(int*** mat,int n,int m){ // créer une matrice avec malloc
    *mat = malloc(m*sizeof(int));
    for (int i = 0;i<n;i++){
        (*mat)[i] = calloc(n,sizeof(int));
    }
}

int taill_tab(){ // Demander à l'utilisateur cb de ligne il souhaite
    int n;
    printf("Quelle taille veux-tu ? ");
    scanf("%d",&n);
    return n;
}

void carre(int *p,int n){   // revoie dans un tableau les elements au carré
    for (int i=0 ;i<n ;i++){
        p[i] = i*i;
    }
}

int facto(int x){ // fonction factorielle
    long acc=1;
    if (x<=1){
        return 1;
    } else {
        acc = x * facto(x-1);
    }
    return acc;
}

void facto_arr(int* p,int n){ // revoie dans un tableau la factorielle des elements 
    for (int i=0 ;i<n ;i++){
        p[i] = facto(i);
    }
}

void fusion(int*** m,int* p1,int* p2,int n){ // fusionne deux tableaux en une matrice
    for (int j=0;j<n;j++){
        (*m)[0][j] = p1[j];
    }
    for (int i=0;i<n;i++){
        (*m)[1][i] = p2[i];
    }
}

int main(){
    int* p1;
    int* p2;
    int** m;
    int n;
    n= taill_tab(); // nb de ligne
    array(&p1,n);
    array(&p2,n);
    matrice(&m,n,2);
    carre(p1,n);
    facto_arr(p2,n);
    fusion(&m,p1,p2,n);
    affiche_tab(p1,n);
    affiche_tab(p2,n);
    affiche_mat(m,n,2);
    free(p2);
    free(p1);
    free(m);
    return 0;
}


