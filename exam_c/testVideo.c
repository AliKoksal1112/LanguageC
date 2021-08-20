#include <stdlib.h>
#include <stdio.h>
#include "video.h"

#define POS_IMG 1
#define POS_TMP 2

int main (int argc, char* argv[]) {
   int imageCnt, temps; 
   bool ok;

   if (argc != 3) {
      printf("Erreur, USAGE: nbImg msec\n");
      exit(1);
   }
   imageCnt = atoi(argv[POS_IMG]);
   temps = atoi(argv[POS_TMP]);
   // Test 1: création de la vidéo

   // Création d'une vidéo
   printf("Test creerVideo\n");
   Video v = creerVideo(temps);

   // Ajout d'images à la vidéo
   printf("Test ajouterImage: ajout de %d images à la vidéo\n",imageCnt);
   Image* im;
   char nom[MAX_TITRE+1];
   for (int i=1; i<=imageCnt; i++) {
      sprintf(nom, "image_%d", i);
      im = creerImage(nom, 8, 8);
      if (im == NULL) {
         printf("Erreur lors de la création d'une image");
         exit(1);
      }
      if (!ajouterImage(&v, im)){
         printf("Erreur lors de l'ajout d'une image à la vidéo");
         exit(1);
      }
   }

   // Lecture de la vidéo
   jouerVideo(v);


   // Test 2:
   
   Video clipboard = creerVideo(temps);
   
   // Test copie
   printf("\nTest copier: copie des images 3 et 4 de la vidéo\n");
   ok = copier(&v, &clipboard, temps+1, 3*temps+1);
   if (!ok){
      printf("Erreur lors de copier\n");
      exit(1);
   }
   jouerVideo(clipboard);


  // Test collage
   printf("\nTest coller: insertion des images 3 et 4 après l'image 6 de la vidéo\n");
   printf("Résultat attendu: Image_1, 2, 3, 4, 5, 6, 3, 4, 7, ...\n");
   coller(&v, &clipboard, 5*v.msec+1);
   jouerVideo(v);

   // Test libération
   printf("\nTest libererVideo: libération des images\n");
   libererVideo(&v);
   jouerVideo(v);
}
