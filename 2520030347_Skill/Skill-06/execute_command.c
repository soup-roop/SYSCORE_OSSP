#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);

        perror("exec");
        return 1;
    }

    waitpid(pid, NULL, 0);

    printf("Parent: child completed.\n");

    return 0;
}
