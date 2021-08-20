#ifndef _IMAGE_H_
#define _IMAGE_H_

#define MAX_TITRE 20


typedef struct Image {
   char titre[MAX_TITRE+1];  // titre de l'image
   int hauteur;              // nombre de lignes de l'image
   int largeur;              // nombre de colonnes de l'image
} Image;


/************************/
/*  FONCTIONS FOURNIES  */
/************************/

/**
 * Crée une nouvelle image
 * PRE: nom: chaine d'au plus MAX_TITRE caractères
 *      h,l: nombres (non nuls) de pixels en hauteur et largeur
 *      couleur: une couleur (comprise entre 0 et 255)
 * RES: renvoie une image de hxl pixels, dont la valeur est couleur,
 *      avec nom pour titre; renvoie NULL si une erreur s'est produite 
 *      durant la création de l'image
 */
Image* creerImage (char* nom, int h, int l);

/**
 * Affiche une image
 * PRE: im: une image
 * POST: affiche le titre de l'image, sa hauteur, sa largeur,
 *       ainsi que la matrice de pixels
 */
void afficherImage (Image im);



#endif   // _IMAGE_H_
