#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid;
    int status;

    printf("Parent Process Started\n");
    printf("Parent PID: %d\n\n", getpid());

    // Create 3 child processes
    for (i = 1; i <= 3; i++) {
        pid = fork();

        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0) {
            // Child process
            printf("Child %d: PID = %d, PPID = %d\n",
                   i, getpid(), getppid());

            sleep(i);

            printf("Child %d: Finished execution\n", i);
            exit(i);
        }
    }

    // Parent waits for the first child using wait()
    pid = wait(&status);

    if (WIFEXITED(status)) {
        printf("\nParent: wait() collected child PID %d with exit status %d\n",
               pid, WEXITSTATUS(status));
    }

    // Parent waits for remaining children using waitpid()
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("Parent: waitpid() collected child PID %d with exit status %d\n",
                   pid, WEXITSTATUS(status));
        }
    }

    printf("\nAll child processes have been collected.\n");

    return 0;
}
