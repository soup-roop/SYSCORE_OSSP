#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        sleep(2);
        printf("Child exiting.\n");
        return 5;
    }

    if (pid > 0) {
        int status;

        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
            printf("Child exit status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
