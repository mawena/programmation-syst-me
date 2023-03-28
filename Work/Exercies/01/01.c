#include <errno.h>     //errno.h
#include <stdio.h>     //printf, scanf
#include <stdlib.h>    //EXIT_FAILURE, EXIT_SUCCESS
#include <sys/types.h> //pid_t
#include <unistd.h>    //fork, system, execv

int main() {
  pid_t pid;
  int x = 1;
  pid = fork();
  if (pid == 0) {
    printf("Dans le fils x = %d\n", ++x);
    exit(EXIT_SUCCESS);
  }

  printf("Dans le père x = %d\n", --x);

  return EXIT_SUCCESS;
}