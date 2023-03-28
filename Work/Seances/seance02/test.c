#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int i = 1;
  int j = 1;
  int x = ++i;
  int y = j++;
  printf("x = %d, y = %d", x, y);
  return EXIT_SUCCESS;
}