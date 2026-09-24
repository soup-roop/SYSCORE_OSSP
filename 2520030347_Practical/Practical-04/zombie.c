#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        printf("Child is exiting now...\n");
        exit(0);
    }

    // Parent does not immediately call wait()
    printf("Parent process: PID = %d\n", getpid());
    printf("Child PID = %d\n", pid);
    printf("Parent sleeping for 15 seconds...\n");
    printf("During this time, the child becomes a ZOMBIE.\n");

    sleep(15);

    // Remove zombie
    wait(NULL);

    printf("Parent collected the child. Zombie removed.\n");

    return 0;
}
