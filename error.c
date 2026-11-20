#include <stdio.h>
#include "error.h"

void afficherErreur(error_t * err){
  printf("retour = %d\n%s\n", err->retour, err->string);
  return;
}
