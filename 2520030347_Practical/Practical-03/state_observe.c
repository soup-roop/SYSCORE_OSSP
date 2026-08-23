#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("PID: %d\n", getpid());
    printf("Process is running. Observe it using ps and /proc.\n");

    printf("Entering waiting state for 20 seconds...\n");
    sleep(20);

    printf("Running again for 10 seconds...\n");
    sleep(10);

    printf("Process terminating now.\n");

    return 0;
}
