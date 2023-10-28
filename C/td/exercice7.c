#include <stdio.h>
#include <stdbool.h>


// exo 7 td n 1 : Code comparant des heures 

int fonct(int l[3]){
/*
input = list
modifie la liste contenant les heures
*/
    printf("Entrer l'heure au format HH:MM:SS :");
    scanf("%d:%d:%d",&l[0],&l[1],&l[2]);
}

void print_list(int list[], int n){
/*
prend une liste et retourne liste en terminal
*/
    printf("[");
    for (int i = 0; i<n; i++)
    {
        printf("%i, ", list[i]);
    }
    printf("]\n");
}

int main(void){
    int j[3],g[3];
    int i;
    fonct(j); // initialisation listes
    fonct(g);
    while(i<3){
        if (j[i]<g[i]){ // comparaison des heures
            printf("heure 2 supérieure\n");
            i=3;
        }
        else if (j[i]>g[i]){
            printf("heure 1 supérieure\n");
            i=3;
        }
        else{ // cas d'égalité
            if (i=2){
                printf("égalité");
            }
        i=i+1; // incrémentation
        }
        
    }
    print_list(j,3); // verification des listes
    print_list(g,3);
    return 0;
}