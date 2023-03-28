#include <stdio.h>
#include <stdlib.h>
int SaisisEntier(void) {
  int n;

  printf("Veuillez entrer un entier : ");
  scanf("%d", &n);
  return n;
}

void AfficherEntier(int n) { printf("Votre entier n vaut %d \n", n); }

int main(void) {
  void (*foncAff)(int);

  int (*foncSais)(void);

  int entier;

  foncSais = SaisisEntier;
  foncAff = AfficherEntier;

  entier = foncSais();
  foncAff(entier);

  return EXIT_SUCCESS;
}