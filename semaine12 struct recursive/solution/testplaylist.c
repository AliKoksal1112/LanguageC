#include <stdio.h>
#include "playlist.h"

int main(int argc, char **argv)
{
	Track *t1 = initTrack("Eminem", "Venom", 269);
	Track *t2 = initTrack("Happy Mondays", "Loose Fit", 257) ;
	Track *t3 = initTrack("Karl Biscuit", "La Morte", 236);
	//Track *t4 = initTrack("Panda Dub", "Howl", 458);
	Track *t5 = initTrack("Panda Dub", "Shankara", 403);
	Track *t6 = initTrack("Peter Tosh", "Equal Rights", 360);
	Track *t7 = initTrack("Peter Tosh", "Equal Rights", 360);
	Track *t8 = initTrack("Yves Simon", "Amazoniaque", 260);

    Playlist *p1 = initPlaylist();
    if (p1 == NULL)
    {
        printf("Probl création liste p1");
    }

    // Test playlist vide
    printf("\nListe vide :\n");
    afficherPlaylist(p1);

    // Test ajout
    printf("\nListe 1:\n");
    ajouterTrack(p1, t2);
    ajouterTrack(p1, t5);
    ajouterTrack(p1, t6);
    ajouterTrack(p1, t8);

    afficherPlaylist(p1);

    // Test fusion

    Playlist *p2 = initPlaylist();
    if (p2 == NULL)
    {
        printf("Probl création liste p2");
        return 1;
    }

    ajouterTrack(p2, t1);
    ajouterTrack(p2, t3);
    ajouterTrack(p2, t7);
    printf("\nListe 2:\n");
    afficherPlaylist(p2);

    Playlist *mergedList = fusionDestructive(p1, p2);
    printf("\nListe fusionnée\n");
    afficherPlaylist(mergedList);

    printf("\nListes vidées\n");
    afficherPlaylist(p1);
    afficherPlaylist(p2);
}