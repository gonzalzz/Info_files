/*
Nom : Léo Gonzalez
Mail : gonzalezleo@orange.fr
compilation :
*/

/*toutes les fonctions tests et le main*/
#include "bibli.h"
#include "pm.h"

// Question 1 

void test_compte_c(){
    FILE* f = fopen("toto1.txt","r");
    int taille = compte_c(f);
    printf("Nombre de charactère : %d\n",taille);
    fclose(f);
}

void test_compte_l(){
    FILE* f = fopen("toto1.txt","r");
    int taille = compte_l(f);
    printf("Nombre de lignes : %d\n",taille);
    fclose(f);
}

void test_compte_m(){
    FILE* f = fopen("toto1.txt","r");
    int nb = compte_m(f);
    printf("Nombre de mots : %d\n", nb);
    fclose(f);
}

void test_facteur ( ) {
    char * nom = "toto1.txt";
    FILE*f = fopen(nom,"r");

    char* facteur1 = "salé";
    printf("%s est facteur de %s : %d\n", facteur1, nom, facteur(f,facteur1));
    
    fclose(f);
    f = fopen(nom, "r");

    char* facteur2 = "gogi";
    printf("%s est facteur de %s : %d\n", facteur2, nom, facteur(f,facteur2));

    fclose(f);
}

int main(){
    //test_compte_c();
    //test_compte_l();
    //test_compte_m();
    test_facteur();
    return 0;
}