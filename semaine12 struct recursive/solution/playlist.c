#include <stdlib.h>
#include <stdio.h>
#include "playlist.h"


// Private
void libererNoeudEtTrack(Noeud *n)
{
    free(n->track);
    free(n);
}

void ajouterNoeud(Playlist *p, Noeud *n){
    if (p->tete == NULL){
        p->tete = p->queue = n;
    }
    else
    {
        p->queue->svt = n;
        p->queue = n;
    }
    
    n->svt = NULL;   
}


// Public

Playlist *initPlaylist() {
	// TODO
    Playlist *p = (Playlist *)malloc(sizeof(Playlist));
    if (p == NULL) return NULL;

    p->tete = p->queue = NULL;
    return p;
}

bool ajouterTrack(Playlist *p, Track *t) {
	// TODO
    Noeud *n = (Noeud *)malloc(sizeof(Noeud));
    if (n == NULL) return false;

    n->track = t;   // copie de pointeur
    n->svt = NULL;
    ajouterNoeud(p, n);
   
    return true;

}

Playlist *fusionDestructive(Playlist *p1, Playlist *p2) {
	// TODO
    Playlist *merged = (Playlist*)malloc(sizeof(Playlist));
    if (merged == NULL) return NULL;

    // la tête des listes est utilisée comme baladeur
    while (p1->tete != NULL && p2->tete != NULL)
    {
        int cmp = compareTrack(p1->tete->track, p2->tete->track);

        if (cmp<0) {
            Noeud *svt = p1->tete->svt;  
            ajouterNoeud(merged, p1->tete);                      
            p1->tete = svt;            
        } else if (cmp>0) {
            Noeud *svt = p2->tete->svt;  
            ajouterNoeud(merged, p2->tete);                      
            p2->tete = svt;            
        } else {  // Doublon
        	Noeud *svt = p1->tete->svt;  
        	ajouterNoeud(merged, p1->tete);                      
        	p1->tete = svt;            
            // libération du noeud non repris dans la liste fusionnée
        	Noeud *tmp = p2->tete;
        	p2->tete = p2->tete->svt;
        	libererNoeudEtTrack(tmp);
        }
    }

    // p2 traitée ; traitement fin de p1
    if (p1->tete != NULL)
    {
        merged->queue->svt = p1->tete;
        merged->queue = p1->queue;
        p1->tete = NULL;
    }
	// p1 traitée ; traitement fin de p2
    else if (p2->tete != NULL)
    {
        merged->queue->svt = p2->tete;
        merged->queue = p2->queue;
        p2->tete = NULL;
    }
    
    p1->queue = p2->queue = NULL;

    return merged;
}


void afficherPlaylist(Playlist *p)
{
    Noeud *bal = p->tete;
    int trackCnt = 1;
    while (bal != NULL)
    {
        printf("%d ", trackCnt++);
        afficherTrack(bal->track);
        printf("\n");
        bal = bal->svt;
    }
}

