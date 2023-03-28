#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) { // Erreur de création du processus
        printf("Erreur de création du processus\n");
        return 1;
    }
    else if (pid == 0) { // Code pour le processus enfant
        printf("Je suis le processus enfant, mon PID est %d\n", getpid());
    }
    else { // Code pour le processus parent
        printf("Je suis le processus parent, mon PID est %d\n", getpid());
    }
    return 0;
}
