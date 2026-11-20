#define TAILLE_TAB 126

typedef struct error{
  int retour;
  char string[TAILLE_TAB];
}error_t;

void afficherErreur(error_t * err);
