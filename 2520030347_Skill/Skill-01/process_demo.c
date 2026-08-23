#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Process Abstraction and fork() Demonstration\n");
    printf("---------------------------------------------\n");

    printf("Original Process PID : %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("\nChild Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
    }
    else
    {
        printf("\nParent Process\n");
        printf("PID       : %d\n", getpid());
        printf("Child PID : %d\n", pid);

        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}
