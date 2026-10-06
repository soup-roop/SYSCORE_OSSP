#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);

        char buffer[100] = {0};

        read(fd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    } else {
        close(fd[0]);

        char message[] = "Hello through pipe";

        write(fd[1], message, sizeof(message));

        close(fd[1]);

        waitpid(pid, NULL, 0);
    }

    return 0;
}
