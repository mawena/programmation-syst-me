#include <stdio.h>     //printf, scanf
#include <stdlib.h>    //EXIT_FAILURE, EXIT_SUCCESS
#include <sys/types.h> //pid_t
#include <unistd.h>    //fork, system, execv

int main() {
  fork();
  fork();
  fork();
  printf("hello\n");
  exit(EXIT_SUCCESS);
}