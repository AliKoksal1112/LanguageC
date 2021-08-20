#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "image.h"

/************************/
/*  FONCTIONS FOURNIES  */
/************************/


Image* creerImage (char* nom, int h, int l) {
   Image* im = (Image*) malloc(sizeof(Image));
   if (im == NULL)
      return NULL;

   strcpy(im->titre, nom);
   im->hauteur = h;
   im->largeur = l;

   return im;
}


void afficherImage (Image im) {
   printf("\tImage '%s' (%dx%d pixels)\n",im.titre,im.hauteur,im.largeur);
}

