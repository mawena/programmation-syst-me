#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    printf("Je suis le fils, mon PID est %d\n", (int)getpid());
    sleep(10);
    exit(0);
  } else { // Code pour le processus parent
    printf("Je suis le père, mon PID est %d\n", (int)getpid());
    sleep(10);
    exit(0);
  }
}
