#include <stdio.h>
#include <stdbool.h>

// exercice 12

void affiche(int t[], int n){
    int cpt = 0;
    printf("{");
    while (cpt<n-1){
        printf("%d,",t[cpt]);
        cpt++;
    }
    printf("%d}\n",t[cpt]);
}

// exercice 13

void inv(int t[], int nb){
    int cpt = 0;
    while (cpt<nb/2){
        int k = t[cpt];
        t[cpt] = t[nb-cpt-1];
        t[nb-cpt-1] = k;
        cpt++;
    }
}
// Complecité temporelle linéaire car on passe n/2 fois dans la boucle donc 0(n)

// Exercice 14

bool is_sorted(int t[], int n){
    int cpt=0;
    while(cpt<n-1){
        if(t[cpt]>t[cpt+1]){
            return false;
        }
        cpt++;
    }
    return true;
}

/*
complexité :

meilleur cas complexité en O(1) si premier elt est plus grand que le second
pire cas compolexité en 0(n) si le tableau est trié
*/

// exercice 15

void swap(int t[], int i, int j){
    t[i]= t[i]^t[j];
    t[j]= t[i]^t[j];
    t[i]= t[i]^t[j];
} 

// exercice 18

int min(int t[], int n){
    int mini = t[0], i = 1;
    while(i<n){
        if(t[i]<mini){
            mini = t[i];
        }
        i++;
    }
    return mini;
}

/*
boucle de n-1 fois
dans la boucle -ni bouce interne - ni appel de fonction 
=> compléxité temporelle linéaire -> O(n)
*/

int main(){
    int j[9] = {1,2,3,-4,4,5,6,7,7};
    //printf("is sorted : %d\n",is_sorted(j,9));
    //inv(j,9);
    //printf("is sorted : %d\n",is_sorted(j,9));
    //affiche(j,9);
    //swap(j,0,8);
    affiche(j,9);
    printf("%d\n",min(j,9));
}