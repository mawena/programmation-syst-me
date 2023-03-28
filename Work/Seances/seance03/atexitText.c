#include <stdio.h>
#include <stdlib.h>

void routine(void) {
  printf(" Execution de la routine de terminaison \n");
  printf(" Bye ! \n");
}

int main() {
  if (atexit(routine) == -1) {
    perror("atexit :");
    return EXIT_FAILURE;
  }

  printf(" Fin du programme !\n");
  return EXIT_SUCCESS;
}
