// Nom : Gonzalez--Torreadrado Léo
# include "dm1_prof.h"
// email : gonzalezleo@orange.fr
// gcc −Wall −Werror=v l a −o leo.gonzalez.c

# include <stdio.h>
# include <stdbool.h>

void display_line(int n, float t[n]){
    int cpt = 0; // compteur pour variable n
    while (cpt <n){
        printf("%8.2f",t[cpt]); // affichage de 8 charactères pour espacé et alligné
        cpt++;
    }
}

void display_mat(int n, int m,float t[n][m]){
  int cpt1 =0;  // Compteur faisant varier n
  while(cpt1<n){ // Boucle faisant varier cpt1 de 0 à n
  int cpt2 =0;  // Compteur faisant varier m réinitialiser à chaque boucle finie de cpt2
    while(cpt2<m){  // Boucle faisant varier cpt2 de 0 à m
      printf("%8.2f",t[cpt1][cpt2]);
      cpt2++;
    }
    cpt1++;
    printf("\n");
  }
}

float sarrus(float m[3][3]){
  int det = 0;
  det = det + (m[0][0]*m[1][1]*m[2][2]);    // calcul un a un de la formule sarrus
  det = det - (m[0][0]*m[1][2]*m[2][1]);   
  det = det + (m[0][1]*m[1][2]*m[2][0]);   
  det = det - (m[0][1]*m[1][0]*m[2][2]);    
  det = det + (m[0][2]*m[1][0]*m[2][1]);
  det = det - (m[0][2]*m[1][1]*m[2][0]);
  return det;
  }

void remplacer(float m[3][3],float v [3],int k){
  int cpt = 0;
  while (cpt < 3){
    m[cpt][k] = v[cpt];
    cpt= cpt +1;
  }
}

void afficheN(int n, char c){
  int cpt1 = 0; // compteur faisant virier le numero de la ligne
  while(cpt1<n){ // boucle pour ecrire n lignes
    printf("%c",c); // ecriture premier caractère en debut de ligne
    int cpt2 = 0; // compteur faisant virier le numero de la collone
    while(cpt2<cpt1){ // premiers espaces
      printf(" ");
      cpt2 = cpt2 + 1;
    }
    printf("%c",c); // caractère
    cpt2 = cpt2 + 1;
    while(cpt2<n){ // reste des espaces
      printf(" ");
      cpt2 = cpt2 + 1;
    }
    printf("%c\n",c); // dernier caractère de la ligne
    cpt1 = cpt1 + 1;
  }
}

void afficheA(int n, char c) {
  int cpt1 =0; // compteur de ligne
  while(cpt1<n){ // boucle faisant varier les lignes
    int cpt2 = 0; // compteur de collones
    if(cpt1 == 2*n/5) // cas ligne est la barre du A
    { 
      while(cpt2<n-cpt1){
        printf(" ");
        cpt2++;
      }
      while(cpt2<= cpt1 + n){
        printf("%c",c);
        cpt2++;
      }
    }
    else  // tous les autres cas
    { 
      while(cpt2<n-cpt1){ 
        printf(" ");
        cpt2++;
      }
      printf("%c",c);
      cpt2++;
      while(cpt2<n+cpt1){
        printf(" ");
        cpt2++;
      }
      if (n+cpt1 != n-cpt1){
        printf("%c",c);
      }
    }
    printf("\n");
    cpt1 = cpt1 + 1; // incrementation du numero de ligne
  }
}

void test_display_line(){
  float t[3] = {12.,13.256,100.659};
  display_line(3,t);
  printf("\n");
}

void test_display_mat(){
  float t[3][3] = {{6.25,3.2,4.891},{12.,13.256},{1.123,256.3,568.}};
  display_mat(3,3,t);
  printf("\n");
}
/*
void test_solve2(void){
  float m[2][2] = {{1.,2.},{-1.,1.}};
  float v[2] = {0.,1.};  
  float r[2] = {0.,0.};
  int nb = solve2(m,v,r);
  if (nb){
    printf("solution unique\n");
    printf("%f,%f\n",r[0],r[1]);
  }
  else
    printf("déterminant nul\n");
}
*/
void test_sarrus(){
  float m[3][3] = {{1,2,-1},{-1,0,1},{2,-1,2}};
  printf("sarrus(m)=%f\n",sarrus(m));
}

void test_remplacer(){
  float m[3][3] = {{1,2,-1},{-1,0,1},{2,-1,2}};
  float v[3] = {5.,5.,6.};
  remplacer(m,v,2);
  display_mat(3,3,m);
  printf("\n");
}
/*
void test_cramer(){
  float m[3][3] = {{1,2,-1},{-1,0,1},{2,-1,2}};
  float v[3] = {16.,8.,32.};
  float res[3];
  cramer(m,v,res);
  display_line(3,res);
  printf("\n");
}
*/
void test_afficheN(){
  afficheN(6,'x');
  printf("\n");
}

void test_afficheA(){
  afficheA(8,'x');
  printf("\n");
}

int main_el(void){
  test_display_line();
  test_display_mat();
  //test_solve2();
  test_sarrus();
  test_remplacer();
  //test_cramer();
  test_afficheN();
  test_afficheA();
  return 0;
}
