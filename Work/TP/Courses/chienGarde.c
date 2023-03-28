#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void traitementSignal(int signal) {
  printf("Arrêt après avoir recu le signal %d", signal);
  exit(EXIT_SUCCESS);
}

void fatherCode(void) { printf("Je suis le père : %d\n", getpid()); }

void childCode(void) {
  signal(SIGBUS, traitementSignal);
  printf("Je suis le fils : %d\n", getpid());
  while (1) {
    system("ps aux >> log.txt");
    sleep(5);
  }
}

pid_t createProcess() {
  pid_t pid;
  do {
    pid = fork();
  } while (pid == -1 && errno == EAGAIN);
  return pid;
}

int main(int argc, char *argv[]) {
  pid_t pid = createProcess();
  switch (pid) {
  case -1:
    perror("ENOMEM");
    return EXIT_FAILURE;
    break;
  case 0:
    childCode();
    break;
  default:
    fatherCode();
    break;
  }

  return EXIT_SUCCESS;
}