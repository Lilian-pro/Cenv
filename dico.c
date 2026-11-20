#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define MAX_MSG 33

typedef struct dico{
  int cle;
  char valeur[MAX_MSG];
  struct dico * suivant;
}dico_t;

error_t trouveIndex(dico_t * d){
  if(d->cle > 0)
    return (error_t){(d->cle%TAILLE_TAB), "OK\n"};
  return (error_t){-1, "[ERR] L'index n'a pas pu être trouvé\n"};
}

/**
 * Ajout de l'entité source dans le dico destination.
 */
error_t ajouter(dico_t * source, dico_t ** destination){
  int cle = ( trouveIndex(source) ).retour;
  (*destination)[cle] = *source;
 
  //si il n'y a aucune tete de liste à cette indice on ajoute en tête. 
  if( (*destination)[cle].cle == source->cle &&  strcmp( (*destination)[cle].valeur,source->valeur ) == 0  )
    return (error_t){0, "OK\n"};//OK
  return (error_t){-1, "[ERR] La source n'a pas été ajouter\n"};//erreur
}

/**
 * TODO
 * gérer les listes chainer.
 * retirer(cle, index);
 * voir(cle, index);
 *
 */
int main(){
  printf("Ce programme est une introduction à la structure de donnée du dictionnaire.\n");
  
  dico_t entite = {234, "Lorem", NULL};
  dico_t *tab = malloc(sizeof(dico_t)*TAILLE_TAB) ;
  error_t err;
  
  err = ajouter(&entite, &tab);
  afficherErreur(&err);
  if(err.retour == -1)
    exit(-1);

  err = trouveIndex(&entite);
  afficherErreur(&err);
  if(err.retour == -1)
    exit(-1);

  int cle = err.retour;
  printf("Voici mon entite, cle = %d | valeur = %s\n",tab[cle].cle, tab[cle].valeur);
  return 0;
}
