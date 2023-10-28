#include <stdio.h>

// exercices 1,3,4,5,6

// exo 1
void affiche_mat(int n, int m, double mat[n][m]){
    int cl = 0;
    while(cl<n){
        int cc = 0;
        printf("|");
        while(cc<m){
            printf("%5.2f ",mat[cl][cc]);
            cc++;
        }
        printf("|\n");
        cl++;
    }
}
// compléxité quadratique car boucle à l'interieur de boucle dépendant de n et m => O(n*m)

// exo 3
void add(int n, int m, double M1[n][m], double M2[n][m], double res[n][m]){
    for (int i=0; i<n;i++){
        for (int j=0; j<m;j++){
            res[i][j]= M1[i][j] + M2[i][j];
        }
    }
}
/*
complexité quadratique double boucle à l'intérieur des deux boucles ni appel de fonction 20 opé élementaires
au total 0(n*m)
*/

// exo 4

void prod(int n, double M1[n][n], double M2[n][n],double res[n][n]) {
    int j = 0;
    while(j<n){
        int i = 0;
        while(i<n){
            res[i][j] = 0;
            int k = 0;
            while(k<n){
                res[i][j] += M1[k][j]*M2[i][k];
                k++;
            }
            i++;
        }
        j++;
    }
}

// ex5 transposée

void transpose(int n, int m, double M[n][m], double res[m][n]){
    for (int i = 0;i<n;i++){
        for (int j=0;j<m;j++){
            res[j][i]= M[i][j];
        }
    }
}
// Complexité 0(n*m) /soit quadratique car passage double boucle interne et corps boucle interne est en 0(1)



int main() {
    double y[2][2]= 
    {{1.,2.},
    {4.,5.}};
    double d[2][2]=
    {{-3.,3.},
    {1.,5.}};
    double c[2][2];
    affiche_mat(2,2,y);
    affiche_mat(2,2,d);
    prod(2,y,d,c);
    affiche_mat(2,2,c);
}