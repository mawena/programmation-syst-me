#include <stdio.h>
#include <stdlib.h>
int SaisisEntier(void) {
  int n;

  printf("Veuillez entrer un entier : ");
  scanf("%d", &n);
  return n;
}

void AfficherDecimal(void *arg) {
  int n = (int)arg;
  printf("Votre entier n vaut %d \n", n);
}
void AfficherHexa(void *arg) {
  int n = (int)arg;
  printf("Votre entier n vaut %x \n", n);
}
void ExecAffichage(void (*foncAff)(void *arg), void *arg) { foncAff(arg); }
int main(void) {
  int (*foncSais)(void);

  int entier;

  foncSais = SaisisEntier;

  entier = foncSais();
  ExecAffichage(AfficherDecimal, (void *)entier);
  ExecAffichage(AfficherHexa, (void *)entier);

  return EXIT_SUCCESS;
}