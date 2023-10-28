#include <stdio.h>

void affiche(int t[], int n){
    int cpt = 0;
    printf("{");
    while (cpt<n-1){
        printf("%d,",t[cpt]);
        cpt++;
    }
    printf("%d}\n",t[cpt]);
}

/*
Hors affichage

Il y a moins de lg passage dans la boucle 
Chaque passage occasionne au plus 20 opérations élémentaires.
Avant et après la boucle il y a une dizaine d'opération élémentaires.

La compléxité hors affichage est de la forme :
10 + (ls-1) * 10 = 0(lg)
Complexité temporelle linéaire
*/

int main(void){
    int j[3] = {1,2,3};
    affiche(j,3);
    return 0;
}