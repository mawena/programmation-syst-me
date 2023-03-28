#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void logToFile(char *fileLogPath, char *text) {
  FILE *logFile = fopen(fileLogPath, "a");
  if (logFile == NULL) {
    perror("Error opening log file");
    exit(EXIT_FAILURE);
  }

  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  fprintf(logFile, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", tm->tm_year + 1900,
          tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec,
          text);
  fclose(logFile);
}

char *execCommand(char *command) {
  FILE *process = popen(command, "r");
  if (process == NULL) {
    perror("Error executing command");
    exit(EXIT_FAILURE);
  }
  char output[10240];
  fgets(output, sizeof(output), process);
  pclose(process);

  char *text = output;
  return text;
}

void gestionnaire_signal(int signal) {
  printf("signal %d", signal);
  exit(EXIT_SUCCESS);
}

int main() {
  while (1) {
    // Count the number of active processes
    signal(SIGALRM, gestionnaire_signal);
    char logTextPath[11] = "logTmp.txt";
    char text[20480] = "Nombre de processus : ";
    strcat(text, execCommand("ps -A --no-headers | wc -l"));
    strcat(text, ", processus: ");
    strcat(text, execCommand("ps -eo comm -w --no-headers | tr '\n' ' '"));

    logToFile(logTextPath, text);

    sleep(2);
  }
  exit(EXIT_SUCCESS);
}
