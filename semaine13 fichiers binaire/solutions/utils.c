#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

#include "utils.h"

#define BUF_LEN 256

//******************************************************//
// LECTURE CLAVIER
//******************************************************//

// Anciennement: litEtValideChaine (cf. TP 11)

int readLimitedLine (char* s, int sz) {
   while (fgets(s, sz, stdin) != NULL) {
      // Traitement d'une ligne vide
      if (strlen(s) == 1) {
         printf("Chaine vide. Recommencez.\n");
         continue;
      }

      // Traitement d'une ligne trop longue
      if (s[strlen(s)-1] != '\n') {
         printf("Ligne trop longue (max %d caracteres). Recommencez.\n", sz-2);
         // vidage du buffer de lecture bloc par bloc
         while (fgets(s, sz, stdin) && s[strlen(s)-1] != '\n') ;
         // OU vidage du buffer de lecture caractere par caractere
         //while (getchar() != '\n');
         continue;
      }

      // Chaine valide: suppression de '\n' et renvoi du nombre de caractères de la chaine
      s[strlen(s)-1] = '\0';
      return strlen(s);
   }

   // Cas d'erreur ou de fin de fichier
   return 0;
}

// Anciennement: lireLigne (cf. TP 13)
// Pour une vidéo sur cette fonction: http://youtu.be/Zuyhvnwmlao?hd=1

char* readLine () {
   char buf[BUF_LEN];
   char* s = NULL;
   bool fin = false;

   while (fgets(buf, BUF_LEN, stdin)) {
      // Traitement d'un bloc de caractères lus sur stdin
      int taille = strlen(buf);
      if (buf[taille-1] == '\n') {
         taille--;
         buf[taille] = '\0';
         fin = true;
      }

      if (s == NULL) {
         // Première allocation de la chaîne s
         s = (char*) malloc((taille+1) * sizeof(char));
         if (s == NULL) return NULL;
         // Copie des caractères du buffer dans s
         strcpy(s,buf);
      } else {
         // Réallocation de la chaîne s
         s = (char*) realloc(s, (strlen(s)+taille+1) * sizeof(char));
         if (s == NULL) return NULL;
         // Concaténation des caractères du buffer à la fin de s
         strcat(s,buf);
      }

      if (fin)
         // Fin de la ligne lue sur stdin
         return s;
   }

   // Cas d'erreur ou de fin de fichier
   return NULL;
}


//******************************************************
// ENTIER ALEATOIRE
//******************************************************

/*
  static long getMicroTime () {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);    // gettimeofday défini dans <sys/time.h>
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
  }
*/

static unsigned generateRandomSeed () {
   unsigned seed;
   FILE* fd = fopen("/dev/urandom", "r");  // fichier d'entropie dans les OS de type Unix
   fread(&seed, sizeof(unsigned), 1, fd);
   fclose(fd);
   return seed;
}

	
int unEntierAuHasardEntre (int valMin, int valMax) {
   // Initialisation de la 'random seed'
   //srand((unsigned) time(NULL));  // KO si unEntierAuHasardEntre est exécuté
   // plusieurs fois en 1 seconde  (time défini dans <time.h>)
   //srand(getMicroTime());         // KO si unEntierAuHasardEntre est exécuté
   // plusieurs fois en 1 microseconde
   srand(generateRandomSeed());
   
   // Génération d'une valeur aléatoire
   int nombre = valMin + (int)(rand()/(RAND_MAX+1.0)*(valMax-valMin+1));  // rand, srand et RAND_MAX définis dans  <stdlib.h>
   return nombre;
}	
	
	
