#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe1[2];
    int pipe2[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        return 1;
    }

    printf("Pipe 1: read=%d write=%d\n", pipe1[0], pipe1[1]);
    printf("Pipe 2: read=%d write=%d\n", pipe2[0], pipe2[1]);

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    printf("All pipe descriptors closed.\n");

    return 0;
}
