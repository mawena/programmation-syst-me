#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX 10
#define MIN 5

void *routineThread(void *arg) {
  int nbsec = (int)arg;
  printf("\033[0;31m");
  printf("Je suis un thread et j'attends %d secondes \n", nbsec);
  sleep(nbsec);
  puts("Je suis un thread et je me termine");
  pthread_exit(NULL);
}

int main(void) {
  int codeRetour;
  pthread_t monThread;
  srand(time(NULL));
  int nbsec = (rand() % (MAX - MIN + 1)) + MIN;
  time_t tempsDebut = time(NULL);

  codeRetour = pthread_create(&monThread, NULL, routineThread, (void *)nbsec);

  if (codeRetour != 0) {
    fprintf(stderr, "Erreur : errno=%d %s\n", errno);
    exit(EXIT_FAILURE);
  }

  pthread_join(monThread, NULL);
  printf("\033[0;33m");
  printf("De retour dans le main, nbsec = %d \n", nbsec);
  printf("Duree de l'operation : %ld secondes", time(NULL) - tempsDebut);

  return EXIT_SUCCESS;
}