#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void affiche_tab(int tab[],int n){
    printf("{");
    for(int i=0;i<n-1;i++){
        printf("%d,",tab[i]);
    }
    printf("%d}\n",tab[n-1]);
}

// Exercice 1
void exo1(void){
    int a;
    scanf("%d",&a);
    printf("%p",&a);
}

// exo 2

void exo2(void){
    int a,b,c;
    scanf("%d*%d",&a,&b);
    printf("%d\n",a*b);
}

// exo 3

void exo3(void){
    int res = 4,try;
    bool b = true;
    scanf("%d",&try);
    while(b){
        if (try == res){
            printf("Bravo");
            b=false;
        } else {
            scanf("%d",&try);
        }
    }
}

// exo 4

void exo4(void){
    float input;
    bool b = true;
    while (b){
        scanf("%f",&input);
        if (input <=20 && input >=0){
            printf("Okay let's go\n");
        } else {
            printf("Non pas compris entre 0 et 20\n");
            b = false;
        }
    }
}

// exo 5

void exo5(void){
    float a,b;
    printf("entrez une division au format a/b : ");
    scanf("%f/%f",&a,&b);
    printf("%.3f/%.3f = %.3f\n",a,b,a/b);
}

// exo 11 : produit elmts du tableau

int prod_tab(int a[],int n){
    int sum = 1;
    for(int i = 0; i<n;i++){
        sum *= a[i];
    }
    return sum;
}

void test_prod_tab(void){
    int b[4] = {2,3,4,5};
    int a[9] = {1,2,3};
    printf("%d\n",prod_tab(b,4));
    printf("%d\n",prod_tab(a,9));
}

// ex 13

void inv(int tab[],int n){
    for(int i=0;i<n/2;i++){
        tab[i] = tab[n-i-1]^tab[i];
        tab[n-i-1] = tab[i]^tab[n-i-1];
        tab[i] = tab[n-i-1]^tab[i];
    }
}

void test_inv(void){
    int b[4] = {2,3,4,5};
    int a[9] = {1,2,3,4,5,6,7,8,9};
    inv(b,4);
    inv(a,9);
    affiche_tab(b,4);
    affiche_tab(a,9);
}

// exo 14
bool is_sorted(int tab[], int n){
    int i=0;
    while (i<n){
        if(tab[i]>tab[i+1]){
            return false;
        }
        i++;
    }
    return true;
}

void test_is_sorted(void){
    int b[4] = {-1,3,4,5};
    int a[9] = {100,2,5,4,5,6,7,8,9};
    printf("%d\n",is_sorted(b,4));
    printf("%d\n",is_sorted(a,9));
}

// exercice bonus tri d'un tableau

void tri_tab(int tab[], int n){
    for(int i=0;i<n;i++){
        int min =i;
        int j =i+1;
        while(j<n){
            if (tab[j]<tab[min]) {
                min = j;
            }
            j++;
        }
        if (i!=min){
        tab[i] = tab[i]^tab[min];
        tab[min] = tab[i]^tab[min];
        tab[i] = tab[i]^tab[min];
        }
    }
}

// complexité temporelle O(n²) compléxité quadratique

void test_tri_tab(){
    int a[5] = {2,19,-3,-1,-110};
    affiche_tab(a,5);
    tri_tab(a,5);
    affiche_tab(a,5);
}

int main(void){
    //exo1();
    //exo2();
    //exo3();
    //exo4();
    //exo5();
    //test_prod_tab();
    //test_inv();
    //test_is_sorted();
    test_tri_tab();
}