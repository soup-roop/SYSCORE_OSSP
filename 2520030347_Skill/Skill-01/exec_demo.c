#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Before exec():\n");
    printf("PID: %d\n", getpid());

    printf("\nExecuting the 'ls' command using execl().\n\n");

    execl("/bin/ls", "ls", "-l", NULL);

    perror("execl failed");

    return 1;
}
