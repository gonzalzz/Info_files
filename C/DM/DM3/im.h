#ifndef IM_H

#define IM_H
#include "bibli.h"

typedef struct image im;
struct image{
    bool** mat;
    int nbl;
    int nbc;
};

typedef struct image pt;
struct point{
    float color;
    float x;
    float y;

};

void * mymalloc(size_t size);
void myfree(void *ptr);
im* make_im(int n, int m, bool x);
void _display_ligne(int n, bool* v);
void clear(im *img);
void display_im(im* img);
void _freemat(int n, bool **p);
void free_image(im* img);
void display_pt(pt p);
void save(char * nom, im * img);
im * load(char * nom);

#endif