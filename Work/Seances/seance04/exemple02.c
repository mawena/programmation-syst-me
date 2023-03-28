#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX 10
#define MIN 5

void *routineThread(void *arg) {
  int valeur;
  printf("\033[0;31m");
  printf("Je suis un thread.\nVeuillez entrer un entier: ");
  scanf("%d", &valeur);
  puts("Je suis un thread et je me termine");
  pthread_exit((void *)valeur);
}

int main(void) {
  int codeRetour;
  pthread_t monThread;

  codeRetour = pthread_create(&monThread, NULL, routineThread, (void *)NULL);

  if (codeRetour != 0) {
    fprintf(stderr, "Erreur : errno=%d %s\n", errno);
    exit(EXIT_FAILURE);
  }

  pthread_join(monThread, (void *)&codeRetour);
  printf("\033[0;33m");
  printf("De retour dans le main.\nLa valeur retournee est : %d \n",
         codeRetour);

  return EXIT_SUCCESS;
}