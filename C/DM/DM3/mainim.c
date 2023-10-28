/*
Nom : Léo Gonzalez
Mail : gonzalezleo@orange.fr
compilation :
*/

#include "im.h"
#include "bibli.h"

// Test

void test_save ( ) {
    char* croix = "croix.pbm";
    int n =10;
    int m = 7;
    im* img = make_im(n,m, true);
    for (int i = 0; i<img->nbl;i++){
        img->mat[i][img->nbc/2] = false;
    }
    for (int i = 0; i<img->nbc;i++){
        img->mat[img->nbl/2][i] = false;
    }
    save(croix, img);
    free_image(img);
}

void test_load(){
    char* nom = "croix.pbm";
    im* img;
    img = load(nom);
    assert(img!=NULL);
    display_im(img);
}

// Main
int main(){
    test_save();
    test_load();
    return 0;
}