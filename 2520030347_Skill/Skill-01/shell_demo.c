#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Shell Architecture Demonstration\n");
    printf("---------------------------------\n");

    printf("Process PID  : %d\n", getpid());
    printf("Parent PID   : %d\n", getppid());

    printf("\nThe shell creates a process to execute this program.\n");
    printf("The program executes in user space.\n");
    printf("System calls provide access to kernel services.\n");

    return 0;
}
