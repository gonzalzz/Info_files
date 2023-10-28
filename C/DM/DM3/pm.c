/*Tous les prototypes et déclaration de structures*/
#include "bibli.h"


int compte_c(FILE* f){
    // Fonction comptant le nombre de charactère d'un fichier
    assert(f!=NULL); // Cas ou le fichier s'est mal ouvert
    char c;
    int compteur = 0;
    while (fscanf(f,"%c",&c) != EOF){
        compteur++;
    }
    return compteur;
}

int compte_l(FILE* f){
    // Fonction comptant le nombre de lignes d'un fichier
    assert(f!=NULL); // Cas ou le fichier s'est mal ouvert
    char c;
    int compteur = 1; // On commence à 1 ligne puisque c'est le minimum possible
    while (fscanf(f,"%c",&c) != EOF){
        if (c== '\n'){
        compteur++;
        }
    }
    return compteur;
}

int compte_m(FILE* f){
    // Fonction comptant le nombre de mots d'un fichier
    assert(f!=NULL); // Cas ou le fichier s'est mal ouvert
    char c;
    int compteur = 0;
    bool b_mot =false; // On definit un bool pour indiquer si le charactère précédent était un mot ou non
    while (fscanf(f,"%c",&c) != EOF){
        if (c!= '\n' && c != '\t' && c!= ' '){ // Si le charactère n'est pas ' ' '\n' '\t' alors c'est un mot
            b_mot = true;
        }
        if ((c== '\n' || c == '\t' || c== ' ')&& b_mot){ // Si le charactère est ' ' '\n' '\t' et mot true alos incrémentation
        compteur++;
        b_mot = false;
        }
    }
    return compteur;
}

bool facteur(FILE* f,char* mot){
    // Fonction qui vérifie si un mot est facteur d'un fichier
    assert(f!=NULL); // Cas ou le fichier s'est mal ouvert
    char c;
    int taille = strlen(mot); // taille du potentiel facteur
    bool etat = false;
    int compteur = 0; 
    while (fscanf(f,"%c",&c) != EOF){
        if (etat == true){ // cas ou les lettres se suivent comme le facteur
            if (mot[compteur] == c){ // cas d'égalité du caréctère
                compteur++;
                if (compteur == taille){ // cas d'arrêt
                    return true;
                }
            } 
            else { // cas d'inégalité
                etat = false;
                compteur = 0;
            }
        }
        else { // cas ou aucune lettre est précedemment en commun
            if (mot[0] == c){
                etat = true;
                compteur++;
            }
        }
    }
    return false;
}
