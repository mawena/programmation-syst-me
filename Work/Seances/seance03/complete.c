#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void fatherCode(void) { printf("Je suis le père : %d\n", getpid()); }

void childCode(void) { printf("Je suis le fils : %d\n", getpid()); }

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