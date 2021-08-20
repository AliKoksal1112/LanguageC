#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "track.h"

// Déclaration de fonctions

/* Initialise une playlist
 * PRE: ariste, titre chaines de caractere non null
 * POST: renvoie un pointeur vers une Track contenu la duree et la copie 
 *       des chaines de caractères passées en paramètre ou NULL si la 
 *       création n'a pas pû être faites.
 *       
 */
Track *initTrack(char *artiste, char *titre, int duree){
	// TODO
    Track *t = (Track *)malloc(sizeof(Track));
    if (t==NULL) return t;

    strncpy(t->artiste, artiste, ARTISTE_LENGTH);
    t->artiste[ARTISTE_LENGTH] = '\0';   // ou utiliser calloc au lieu de malloc
    strncpy(t->titre, titre, TITLE_LENGTH);
    t->titre[TITLE_LENGTH] = '\0';   // ou utiliser calloc au lieu de malloc
    t->duree = duree;
    return t;
}


/* Compare deux tracks
 * PRE: t1, t2 pointeurs non null vers deux tracks
 * POST: compare les artistes puis s'ils sont égaux les titres puis
 *       s'ils sont égaux les durées et renvoie
 *          - un nombre négatif si t1 et plus petit que 2
 *          - zéro si t1 et t2 sont structurellement égaux
 *          - un nombre positif si t1 est plus grand que t2
 */
int compareTrack(Track *t1, Track *t2)
{
    int cmp = strcmp(t1->artiste, t2->artiste);

    if (cmp != 0)
        return cmp;

    cmp = strcmp(t1->titre, t2->titre);
    if (cmp != 0)
        return cmp;

    return t1->duree - t2->duree;
}


/* Affiche un track
 * PRE: t pointeur non null vers un track
 * POST: affiche le track
 */
void afficherTrack(Track *t)
{
    printf("%s - %s - %d", t->artiste, t->titre, t->duree);
}

