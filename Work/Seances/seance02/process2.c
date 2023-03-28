#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int i = 3;
  do {
    pid = fork();
    if (pid < 0) {
      if (errno == ENOMEM) {
        printf("Impossible de créer le processus enfant\n");
        return EXIT_FAILURE;
      } else {
        printf("Echec temporaire de la création du processus enfant, nouvelle "
               "tentative en cours...\n");
      }
    }
  } while (errno == EAGAIN);

  if (pid == 0) {
    printf("Je suis le processus enfant, mon PID est %d\n", (int)getpid());
    i += 9;
  } else { // Code pour le processus parent
    printf("Je suis le processus parent, mon PID est %d\n", (int)getpid());
    i += 4;
  }
  printf("pour %d, i = %d\n", getpid(), i);
  return EXIT_SUCCESS;
}
