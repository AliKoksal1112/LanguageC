#ifndef _UTILS_H_   // ou:  #if ! defined _UTILS_H_
#define _UTILS_H_

//******************************************************
// LECTURE CLAVIER
//******************************************************

/**
 * Lit une ligne à l'entrée standard et la copie dans le buffer s
 * PRE: s : tableau de char de taille sz
 *      sz : un entier > 2
 * POST: une chaine de caractères non vide et d'au plus sz-2 caractères 
 *       a été lue sur stdin et placée dans s (sans '\n')
 * RES: renvoie le nombre de caractères de la chaine s ;
 *      0 en cas d'erreur ou EOF
 */
int readLimitedLine (char* s, int sz);

/**
 * Renvoie une ligne lue à l'entrée standard
 * RES: renvoie une ligne de caractères de taille quelconque lue sur stdin (sans '\n') ;
 *      NULL en cas d'erreur ou EOF ; la chaîne ayant été allouée dynamiquement, 
 *      elle doit être libérée
 */
char* readLine ();


//******************************************************
// ENTIER ALEATOIRE
//******************************************************

/**
 * PRE: valMin, vamMax: valeurs entières t.q. valMin < valMax
 * RES: renvoie une valeur entière aléatoire comprise entre valMin et valMax
 */
int unEntierAuHasardEntre (int valMin, int valMax);

#endif   // _UTILS_H_
