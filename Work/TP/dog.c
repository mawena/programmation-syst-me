#include <assert.h>
#include <errno.h>
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

void sigAlarmManagement(int signal) {
  printf("Arrêt après avoir reçu le signal %d", signal);
  exit(EXIT_SUCCESS);
}

void sigTermManagement(int signal) { printf("signal %d", signal); }

void fatherCode(void) { printf("Je suis le père : %d\n", getpid()); }

void childCode(void) {
  signal(SIGALRM, sigAlarmManagement);
  signal(SIGTERM, sigTermManagement);

  printf("Je suis le fils : %d\n", getpid());
  while (1) {
    // Count the number of active processes

    char logTextPath[11] = "log.txt";
    char text[20480] = "\n\tNombre de processus : ";
    strcat(text, execCommand("ps -A --no-headers | wc -l"));
    strcat(text, "\t\tProcessus: ");
    strcat(text, execCommand("ps -eo comm -w --no-headers | tr '\n' ' '"));
    strcat(text, execCommand("ps aux"));

    logToFile(logTextPath, text);

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