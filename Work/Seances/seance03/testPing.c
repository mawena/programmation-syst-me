#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *arguments[] = {"ping", "-c", argv[1], argv[2], NULL};
  char command[1000] = "";

  sprintf(command, "%s %s %s %s", arguments[0], arguments[1], arguments[2],
          arguments[3]);

  if (system(command) == -1) {
    perror("execv");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
