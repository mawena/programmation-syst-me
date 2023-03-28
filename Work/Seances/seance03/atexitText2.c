#include <stdio.h>
#include <stdlib.h>

void routine1(void) {
  printf(" Execution de la routine1 de terminaison \n");
  printf(" Bye ! \n");
}

void routine2(void) {
  printf(" Execution de la routine2 de terminaison \n");
  printf(" Bye ! \n");
}

void routine3(void) {
  printf(" Execution de la routine3 de terminaison \n");
  printf(" Bye ! \n");
}

int main() {
  if (atexit(routine3) == -1) {
    perror("atexit :");
    return EXIT_FAILURE;
  }
  if (atexit(routine2) == -1) {
    perror("atexit :");
    return EXIT_FAILURE;
  }
  if (atexit(routine1) == -1) {
    perror("atexit :");
    return EXIT_FAILURE;
  }
  // Les routines seront executé dans l'ordre inversion des blocs if

  printf(" Fin du programme !\n");
  return EXIT_SUCCESS;
}
