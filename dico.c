#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define TAILLE126 126
#define MAX_MSG 33

typedef struct dico{
  int cle;
  char valeur[MAX_MSG];
  struct dico * suivant;
}dico_t;

int taille = 0;

error_t dicoInit(dico_t ** d){
  for(int i = 0 ; i<taille ; i++){
    d[i]  = NULL;
  }
  return (error_t){0, "OK\n"};
}

error_t dicoTrouveIndex(dico_t * d){
  if(d->cle > 0){
    return (error_t){(d->cle%taille), "OK\n"};
  }
  return (error_t){-1, "[ERR] L'index n'a pas pu être trouvé\n"};
}

error_t dicoIndexVide(dico_t ** d, int index){
  if(d[index] == NULL)
    return (error_t){0, "OK"};
  return (error_t){-1, "[ERR] Il y a une tete de liste à cet indice.\n"};
}

/**
 * Ajout de l'entité source dans le dico destination.
 */
error_t dicoAjouter(dico_t * source, dico_t ** destination){
  error_t err = ( dicoTrouveIndex(source) );
  afficherErreur(&err);
  
  int cle = err.retour;
  destination[cle] = source;
  printf("Je passe par la 3\n");
  //si il n'y a aucune tete de liste à cette indice on ajoute en tête. 
  if( destination[cle]->cle == source->cle &&  strcmp( destination[cle]->valeur, source->valeur ) == 0  )
    return (error_t){0, "OK\n"};//OK
  return (error_t){-1, "[ERR] La source n'a pas été ajouter\n"};//erreur
}

void afficherDico(dico_t ** d){
  for(int i = 0; i < taille ; i++){
    printf("[%s] \n", d[i]->valeur);
  }
  printf("NULL");
  printf("\n");

  return;
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
  taille = TAILLE126;
  dico_t entite = {234, "Lorem", NULL};
  printf("%d\n", entite.cle);

  dico_t **tab = malloc(sizeof(dico_t *)*taille) ;
  error_t err;
  
  
  err = dicoInit(tab);
  afficherErreur(&err);
  
  err = dicoAjouter(&entite, tab);
  afficherErreur(&err);
  if(err.retour == -1)
    exit(-1);

  err = dicoTrouveIndex(&entite);
  afficherErreur(&err);
  if(err.retour == -1)
    exit(-1);

  int cle = err.retour;
  printf("Voici mon entite, cle = %d | valeur = %s\n", tab[cle]->cle, tab[cle]->valeur);
  
  err = dicoIndexVide(tab, cle%taille);
  afficherErreur(&err);

  afficherDico(tab);


  return 0;
}
