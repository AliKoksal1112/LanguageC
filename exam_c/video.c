#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "video.h"

Video creerVideo (int temps) {
	Video video = {NULL, NULL, 0, temps};
	return video;
}

bool ajouterImage (Video* vid, Image* im) {
	Noeud* n;
	if ((n = (Noeud*)malloc(sizeof(Noeud))) == NULL) {
		perror("Allocation dynamique de n impossible");
		return false;
	}
	n->image = im;
	n->suivant = NULL;
	if (vid->debut == NULL) {
		vid->debut = n;
		vid->fin = n;
	} else {
		vid->fin->suivant = n;
		vid->fin = n;
	}
	vid->nbImg++;
	return true;
}

void libererVideo(Video* vid) {
	Noeud* n = vid->debut;
	while(n != NULL) {
		free(n->image);
		Noeud* temp = n;
		n = n->suivant;
		free(temp);
	}
	vid->debut = NULL;
	vid->fin = NULL;
	vid->nbImg = 0;
}

bool copier (Video *source, Video *clipboard, int tDebut, int tfin) {
	int msec = source->msec;
	int temps = 0;
	int nbImgCopiees = 0;
	Noeud* n = source->debut;
	while (n != NULL) {
		if (temps >= tDebut && temps <= tfin) {	
			Image* img = creerImage(n->image->titre, n->image->hauteur, n->image->largeur);	
			if (!ajouterImage(clipboard, img))
				return false;
			nbImgCopiees++;
		}
		temps+=msec;
		n = n->suivant;
	}
	clipboard->nbImg = nbImgCopiees;
	clipboard->msec = msec;
	return true;
}

bool coller(Video *destination, Video* clipboard, int tInsert) {
	int msec = destination->msec;
	int temps = 0;
	int nbrImgCollees = 0;
	if (msec != clipboard->msec)
		return false;
	if (clipboard->debut == NULL)
		return true;
	if (tInsert >= msec*destination->nbImg) {
		//INSERER A LA FIN DE DESTINATION
		Noeud* nClipboard = clipboard->debut;
		if (destination->debut == NULL) {
			destination->debut = nClipboard;
			destination->fin = nClipboard;
			nClipboard = nClipboard->suivant;
			nbrImgCollees++;
		}
		while (nClipboard != NULL) {
			destination->fin->suivant = nClipboard;
			destination->fin = nClipboard;
			nbrImgCollees++;
			nClipboard = nClipboard->suivant;
		}
	} else {
		Noeud* n = destination->debut;
		while (temps <= tInsert) {
			temps+=msec;
			if (temps <= tInsert)
				n = n->suivant;
		}
		//INSERER APRES N
		Noeud* nClipboard = clipboard->debut;
		while (nClipboard != NULL) {
			Noeud* temp = n->suivant;
			n->suivant = nClipboard;
			nClipboard = n->suivant->suivant;
			n->suivant->suivant = temp;
			n = n->suivant;
			nbrImgCollees++;
		}
	}
	clipboard->debut = NULL;
	clipboard->fin = NULL;
	destination->nbImg+=nbrImgCollees;
	clipboard->nbImg-=nbrImgCollees;
	return true;
}	


/**********************/
/*  FONCTION FOURNIE  */
/**********************/


void jouerVideo (Video vid) {
   printf("Lecture de vidéo (%d images - %d msec)\n",vid.nbImg,vid.msec);
   Noeud* frame = vid.debut;
   while (frame != NULL) {
      afficherImage(*(frame->image));      
      frame = frame->suivant;
   }
}
