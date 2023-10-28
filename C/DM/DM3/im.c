/*
Nom : Léo Gonzalez
Mail : gonzalezleo@orange.fr
compilation :
*/

#include "bibli.h"
#include "im.h"

int nballoc = 0;
int nbfree = 0;


/*------------ Fonctions données ---------------------------*/

void* mymalloc(size_t size){
  nballoc++;
  return malloc(size);
}
//avec incrémentation de nbfree
void myfree(void *img){
  nbfree++;
  free(img);
}

im* make_im(int n, int m, bool x){
  bool ** p = mymalloc(n*sizeof(bool*));
  for (int i=0;i<n;i++)
    p[i] = mymalloc(m*sizeof(bool));
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      p[i][j] = x;
  im * img = mymalloc(sizeof(im));
  img->nbl=n;
  img->nbc=m;
  img->mat=p;
  return img;
}

void _display_ligne(int n, bool* v){// avec passage à la ligne
  for (int i=0;i<n;i++)
    printf("%2d",v[i]);
  printf("\n");
}

void clear(im *img){
  //met une image en blanc
  int n = img->nbl, m = img->nbc;
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      img->mat[i][j] = true;
}

void display_im(im* img){
  // avec passage à la ligne
  for (int i=0;i<img->nbl;i++){
    _display_ligne(img->nbc,img->mat[i]); // ici
  }
}

void _freemat(int n, bool **p){
  for (int i=0;i<n;i++)
    myfree(p[i]);
  myfree(p);
}

void free_image(im* img){
  _freemat(img->nbl,img->mat);
  myfree(img);
}

//afficher un point
/*
void display_pt(pt p){
  printf("{%f,%f,%f}",p.x,p.y,p.color);
}
*/

// Fonctions

void save(char* nom, im* img){
  // enregistre une image dans un fichier donné en paramètre
  FILE* fichier = fopen(nom,"w");
  assert(fichier!=NULL);
  fprintf(fichier,"P1\n");
  fprintf(fichier,"%d ",img->nbc);
  fprintf(fichier,"%d\n\n",img->nbl);
  for (int i=0; i<img->nbl;i++){
    for (int j=0; j<img->nbc;j++){
      fprintf(fichier,"%d", img->mat[i][j]);
    }
    fprintf(fichier,"\n");
  }
  fclose(fichier);
}

bool chaine_egale(char* ch1,char* ch2, int n){
  for (int i = 0;i<n;i++){
    if (ch1[i] != ch2[i]){
      return false;
    }
  }
  return true;
}

void space_manager(FILE* fichier){
  // fonction qui fait avancer le pointeur jusqu'à un charactère non '\n' ou '\t' ou ' '
  char c;
  fscanf(fichier,"%c",&c);
}

char space_manager2(FILE* fichier){
  // fonction qui fait avancer le pointeur jusqu'à un charactère non '\n' ou '\t' ou ' '
  char c;
  fscanf(fichier,"%c",&c);
  while (c=='\n' || c=='\t' || c==' '){
    fscanf(fichier,"%c",&c);
  }
  return c;
}

im* load(char * nom){
  FILE* fichier = fopen(nom,"r");
  assert(fichier!=NULL);
  char entete[2];
  if (fscanf(fichier,"%2c",entete)!=1){ // vérification de l'entete de type "P1" à rajouter || chaine_egale(entete,"P1",2)
    fclose(fichier);
    return NULL;
  }
  char c;
  int nbl,nbc;
  space_manager(fichier);
  fscanf(fichier,"%d",&nbc);
  space_manager(fichier);
  fscanf(fichier,"%d",&nbl);
  im* img = make_im(nbl,nbc,true);
  img->nbl = nbl;
  img->nbc = nbc;
  int cpt_l=0,cpt_c=0;
  img->mat[cpt_l][cpt_c] = space_manager2(fichier)- '0';
  cpt_c++;
  while (fscanf(fichier,"%c",&c)!=EOF){ //
    if (c!='\n'&&c!='\t'&&c!=' '){
      bool coeff;
      coeff = c - '0'; // apres recherche cela permet de convertir un char en int dans ce cas un bool
      img->mat[cpt_l][cpt_c]= coeff;
      cpt_c++;
    }
    else if (c == '\n'){
      cpt_c = 0;
      cpt_l++;
    }
  }
  fclose(fichier);
  return img;
}
