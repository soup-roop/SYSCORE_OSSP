#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent process started.\n");
    printf("Parent PID  : %d\n", getpid());
    printf("Parent PPID : %d\n", getppid());
    printf("Parent State: Running\n\n");

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process created.\n");
        printf("Child PID   : %d\n", getpid());
        printf("Child PPID  : %d\n", getppid());
        printf("Child State : Running\n");

        printf("Child State : Waiting (sleeping for 10 seconds)\n");
        sleep(10);

        printf("Child State : Running again\n");

        printf("Child State : Terminated\n");
        exit(0);
    }
    else
    {
        printf("\nParent process continues.\n");
        printf("Parent PID  : %d\n", getpid());
        printf("Child PID   : %d\n", pid);
        printf("Parent State: Running\n");

        printf("Parent State: Waiting for child to finish...\n");
        wait(NULL);

        printf("Parent State: Running again\n");
        printf("Parent State: Terminated\n");
    }

    return 0;
}
