/*Toutes les fonctions de mon prog*/
#ifndef PM_H

#define PM_H
#include "bibli.h"

int compte_c(FILE* f);
int compte_l(FILE* f);
int compte_m(FILE* f);
bool facteur(FILE*f, char* mot);
void rewind(FILE*f);

#endif 