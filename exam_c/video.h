#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <stdbool.h>
#include "image.h"


typedef struct Noeud {
   Image* image;
   struct Noeud* suivant;
} Noeud;

typedef struct Video {
   Noeud* debut; // première image de la vidéo
   Noeud* fin;   // dernière image de la vidéo
   int nbImg;    // nombre d'images
   int msec;     // pause entre deux images (en millisecondes)
} Video;


/**
 * Crée une nouvelle vidéo
 * PRE: temps: nombre de millisecondes
 * RES: renvoie une vidéo vide (càd. sans image) avec une pause
 *      entre deux images définie à temps millisecondes
 */
Video creerVideo (int temps);


/** 
 * Ajoute une image à la fin de la vidéo
 * PRE: vid: une vidéo
 *      im: une image
 * POST: l'image pointée par im a été ajoutée à la fin de la vidéo vid
 * RES: renvoie vrai si l'ajout de im a été correctement effectué;
 *      faux sinon
 */
bool ajouterImage (Video* vid, Image* im);


/**
 * Libère la mémoire associée à une vidéo
 * PRE: vid: une vidéo
 * POST: vid est une vidéo vide, i.e. elle ne contient plus aucune 
 *       image (toutes ses images ont été libérées)
 */
void libererVideo(Video* vid); // TODO compléter la signature


/**
 * Ajoute une image à la fin de la vidéo
 * PRE: source: une vidéo
 *      clipboard: une vidéo ne contenant pas d'images
 *      tDebut: position de début de la copie
 *      tFin: position de fin de la copie
 * POST: Les images de la vidéo source situées entre tDebut et tFin ont été
 *       copiées dans la vidéo clipboard.
 * RES: renvoie vrai si la copie a été correctement effectuée;
 *      faux sinon
 */
bool copier (Video *source, Video *clipboard, int tDebut, int tfin);


/**
 * Ajoute les images de la vidéo clipboard dans la vidéo destination à
 * la position spécifiée.
 * PRE: clipboard: une vidéo 
 *      destination: vidéo dans laquelle on copiera les images
 *      tInsert: position d'insertion 
 * POST: Toutes les images de la vidéo clipboard ont été
 *       transférées dans la vidéo destination. Les images sont insérées
 *       après la après la dernière image dont la position dans le temps est <= tInsert.
 *       Si tInsert est >= à la fin de la vidéo, on insèrera à la fin.
 * RES: renvoie vrai si le collage a été correctement effectuée;
 *      faux si les msec de délais de clipboard et destination sont différentes. 
 */
bool coller(Video *destination, Video* clipboard, int tInsert); // TODO compléter la signature 


/**********************/
/*  FONCTION FOURNIE  */
/**********************/


/**
 * Joue une vidéo
 * PRE: vid: une vidéo
 * POST: affiche le nombre d'images de vid ainsi que la séquence 
 *       d'images
 */
void jouerVideo (Video vid);

#endif  // _VIDEO_H_
