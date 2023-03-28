#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t monMutex = PTHREAD_MUTEX_INITIALIZER;

void *routineThread(void *arg) {
  int numeroThread = (int)arg;
  int nombreIterations = rand() % 8;
  int i, j, k, n;

  for (i = 0; i < nombreIterations; i++) {
    n = rand() % 10000;

    pthread_mutex_lock(&monMutex);

    printf("Le thread numero %d commence son travail \n", numeroThread);
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
      }
    }
    printf("Le thread %d a fini son travail \n", numeroThread);
    pthread_mutex_unlock(&monMutex);
  }
  pthread_exit(NULL);
}

int main(void) {
  int i, codeRetour;
  srand(time(NULL));
  pthread_t mesThreads[10];

  for (i = 0; i < 10; i++) {
    codeRetour = pthread_create(&mesThreads[i], NULL, routineThread, (void *)i);

    if (codeRetour != 0) {
      fprintf(stderr, "Erreur: errno=%d %s\n", errno);
      exit(EXIT_FAILURE);
    }
  }

  for (i = 0; i < 10; i++) {
    pthread_join(mesThreads[i], NULL);
  }

  return EXIT_SUCCESS;
}