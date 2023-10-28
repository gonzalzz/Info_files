// Nom : GONZALEZ Léo
# include <stddef.h>
# include "dm2.h"
// e m a i l : gonzalezleo@orange.fr
// gcc leo_gonzalez.c −Wall −Werror=v

// finir _display_mat / resoudre merge et faire strassen

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int nballoc = 0;
int nbfree = 0;

/*--------Toutes les allocations/libérations se font avec :-------*/
// avec incrémentation de nballoc
void *mymalloc(size_t size){
  nballoc++;
  return malloc(size);
}
//avec incrémentation de nbfree
void myfree(void *ptr){
  nbfree++;
  free(ptr);
}

/*------------ Créations/libérations-------------------------------*/
int* make_vect(int n, int x){
  int* tab;
  tab = mymalloc(n);
  for (int i = 0; i < n ; i++){
    tab[i] = x;
  }
  return tab;
}

int** make_mat(int n, int m, int x){
  int** p;
  p = mymalloc(n*(sizeof(int*)));
  for (int i=0;i<n;i++){
    p[i] = mymalloc(m*sizeof(int));
    for (int j = 0;j<m; j++){
        p[i][j] = x;
    }
  }
  return p;
}

void freemat(int n, int **M){
  for (int i=0;i<n;i++){
    myfree(M[i]);
  }
  myfree(M);
  
}

/*-----------------------Afichage--------------------------------*/
void display_vect(int n, int* v){// avec passage à la ligne
  printf("{ ");
  for (int i=0; i<n-1;i++){
    printf("%d, ",v[i]);
  }
  printf("%d }\n",v[n-1]);
}

void display_mat(int n, int m, int** mat){// avec passage à la ligne
  for (int i=0; i<n;i++){
    printf("| ");
    for (int j = 0;j<m;j++){
    printf("%d, ",mat[i][j]);
    }
    printf("|\n");
  }
}

int** cl(int n, int m, int alpha, int** M1, int** M2){
  int** p;
  p = mymalloc(n*sizeof(int*));
  for (int i=0;i<n;i++){
    p[i] = mymalloc(n*sizeof(int));
    for (int j=0;j<m;j++){
      p[i][j] = M1[i][j] + alpha * M2[i][j];
    }
  }
  return p;
}

int ** naif_mult(int n, int m, int p, int **M1, int **M2){
  int** mat;
  mat = mymalloc(n*sizeof(int*));
  for (int i=0;i<n;i++){
    mat[i] = mymalloc(p*sizeof(int));
    for (int j = 0; j<p;j++){
      mat[i][j] = 0;
      for (int y = 0; y<m;y++){
        mat[i][j] += M1[i][y]* M2[y][j];
      }
    }
  }
  return mat;
}

int log_2(int n){
  int value=1;
  int i=1;
  for (;value<n;i++){
    value = value << 1;
  }
  return i-1; // on retire l'incrémentation de trop   
}

int *** fourblocks(int n, int **mat){
  int*** p;
  p = mymalloc(4*sizeof(int*)); // création d'un tableau contenant 4 éléments
  for (int i = 0; i<4; i++){ // création d'une matrice dans chacun des élements du tableau
    p[i] = mymalloc((n/2)*sizeof(int)); // taille n/2
    for (int j=0; j<n/2;j++){
      p[i][j] = mymalloc(n/2*sizeof(int));
      for(int k = 0; k<n/2;k++){
        p[i][j][k] = mat[(i/2)*(n/2) + j][(i%2)*(n/2)+k]; // j'ai utilisé cette méthode de calcul qui parrait fonctionner
      } // Mais je ne sais pas si c'est la meilleure solution
    }
  }
  return p;
}

void merge(int n, int ** t[4],int **m){
  for (int k=0; k<4; k++){
    for (int i = 0; i<n ; i++){
      for (int j = 0; j<n; j++){
        m[(k/2)*n+i][(k%2)*n+j] = t[k][i][j]; // même chose que précedemment
      }
    }
  }
}

void _display_tab_blocs(int n, int nb,  int *** t){
  for (int k = 0; k<nb;k++){
    printf("Tableau t[%d]\n",k);
    for (int i=0 ;i<n ; i++){
      printf("| ");
      for (int j = 0; j<n; j++){
        printf("%d, ",t[k][i][j]); 
      }
      printf(" |\n");
    }
  }
}

int** strassen(int n,int** M1,int** M2){ // j'ai un problème avec strassen il me manque des multiplications de matrices voici tout de même ma fonction
  int** res;
    res = make_mat(n,n,0);
    int p1,p2,p3,p4,p5,p6,p7; 
    p1 = (M1[0][0] + M1[1][1]) * (M2[0][0] + M2[1][1]);
    p2 = (M1[1][0] + M1[1][1]) * M2[0][0];
    p3 = M1[0][0] * (M2[0][1] - M2[1][1]);
    p4 = M1[1][1] * (M2[1][0] - M2[0][0]);
    p5 = (M1[0][0] + M1[0][1]) * M2[1][1];
    p6 = (M1[1][0] - M1[0][0]) * (M2[0][0] + M2[0][1]);
    p7 = (M1[0][1] - M1[1][1]) * (M2[1][0] + M2[1][1]);
    res[0][0] = p1+p4-p5+p7; 
    res[0][1] = p3+p5;
    res[1][0] = p2+p4;
    res[1][1] = p1-p2+p3+p6;
    return res;
}

int** mult(int n,int** M1,int** M2){
  if (n==2){
    int** res;
    res = strassen(n,M1,M2);
    return res;
  } else {
    int*** tab_m1;
    int*** tab_m2;
    int** tab_res[4];
    int** res_final; 
    res_final = make_mat(n,n,0);
    tab_m1 = fourblocks(n,M1);
    tab_m2 = fourblocks(n,M2);
    res_final = strassen(n,M1,M2);
    for (int i =0;i<4;i++){
      tab_res[i] = make_mat(n,n,0);
      tab_res[i] = mult(n/2,tab_m1[i],tab_m2[i]);
    }
    merge(n/2,tab_res,res_final);
    return res_final;
  }

}


// Tests 

void test_display_make_vect(){
  int *p = make_vect(5,1);
  display_vect(5,p);
  myfree(p);
}

void test_display_make_mat(){
  int **p = make_mat(5,3,2);
  display_mat(5,3,p);
  freemat(5,p);
}

void test_cl(){
  int n=3;
  int **mat1 = make_mat(n,n,0), **mat2 = make_mat(n,n,0);
  for (int i=0;i<n;i++){
    mat1[i][i]=i+1;
    mat2[i][n-1-i]=3-i;
  }
  printf("mat1 = \n");
  display_mat(n,n,mat1);
  printf("mat2 = \n");
  display_mat(n,n,mat2);
  printf("cl(n,n,-1,mat1,mat2) = \n");
  int** p= cl(n,n,-1,mat1,mat2);
  display_mat(n,n,p);
  freemat(n,mat1);freemat(n,mat2);freemat(n,p);
}

void test_naif_mult(){
  int n=2,m=3,p=4;
  int** mat1 = make_mat(n,m,0);
  int** mat2 = make_mat(m,p,0);
  
  mat1[0][0]=1;mat1[0][2]=-1;
  mat1[1][0]=2;mat1[1][1]=1;
  
  mat2[0][0]=1;mat2[0][2]=-1;
  mat2[1][0]=2;mat2[1][3]=1;
  mat2[2][1]=-1;mat2[2][2]=1;mat2[2][3]=1;
  
  printf("mat1 = \n");
  display_mat(n,m,mat1);
  printf("mat2 = \n");
  display_mat(m,p,mat2);
  printf("mat1 * mat2 = \n");
  int ** res = naif_mult(n,m,p,mat1,mat2);
  display_mat(n,p,res);
  freemat(n,mat1);freemat(m,mat2);freemat(n,res);
}

void test_log_2(){
  int tab[3] = {15,16,17};
  for (int i =0; i<3;i++)
    printf("log_2(%d)=%d\n",tab[i],log_2(tab[i]));
}

void test_fourblocks(){
  int n = 4;
  int** mat = make_mat(n,n,0);
  for(int i = 0; i<n;i++)
      for(int j = 0; j<n;j++)
	mat[i][j]=i*n +j;
  printf("mat = \n");
  display_mat(n,n,mat);
  int *** t = fourblocks(n,mat);
  for(int i = 0; i<4;i++){
    printf("t[%d] = \n",i);
    display_mat(n/2,n/2,t[i]);
  }
  for(int i = 0; i<4;i++)
    freemat(n/2,t[i]);
  freemat(n,mat);
  myfree(t);
}

void test_merge(){
  int n = 4;
  int ** mat = make_mat(n,n,0);
  int ***t = mymalloc(4 * sizeof(int**));
  int p = n/2;
  for(int i = 0;i<4;i++){
    t[i]=make_mat(p,p,i);
  }// for i
  // affichage des matrices dans t
  _display_tab_blocs(p,4,t);
  // fusion + affichage
  merge(n/2,t,mat);
  printf("mat= \n");
  display_mat(n,n,mat);
  //libérations
  for(int i = 0; i<4;i++)
    freemat(p,t[i]);
  freemat(n,mat);
  myfree(t);

  mat = make_mat(2,2,0);
  t = mymalloc(4 * sizeof(int**));
  t[0]=make_mat(1,1,1);
  t[1]=make_mat(1,1,2);
  t[2]=make_mat(1,1,6);
  t[3]=make_mat(1,1,1);
  _display_tab_blocs(1,4,t);
  merge(1,t,mat);
  printf("mat= \n");
  display_mat(2,2,mat);
  
  //libérations
  for(int i = 0; i<4;i++)
    freemat(1,t[i]);
  freemat(2,mat);
  myfree(t);
}

void test_strassen(){
  int n = 4;
  int** mat1 = make_mat(n,n,0);
  for(int i = 0; i<n;i++)
      for(int j = 0; j<n;j++)
	mat1[i][j]=i*n +j*j;
  printf("mat1 = \n");
  display_mat(n,n,mat1);
  
  int** mat2 = make_mat(n,n,0);
  for(int i = 0; i<n;i++)
      for(int j = 0; j<n;j++)
	mat2[i][j]=2*i*i-j;
  printf("mat2 = \n");
  display_mat(n,n,mat2);

  int ** s = strassen(n,mat1,mat2);
  printf("mat1 * mat2 = \n");
  display_mat(n,n,s);

  freemat(n,mat1);  freemat(n,mat2);
  freemat(n,s);
}

int main_el(){
  //test_display_make_vect();
  //test_display_make_mat();
  //test_cl();
  //test_naif_mult();$
  //test_log_2();
  //test_fourblocks();
  //test_merge();
  test_strassen();
  printf("nballoc =%d, nbfree=%d\n",nballoc , nbfree);
  assert(nballoc == nbfree);
  return 0;
}

