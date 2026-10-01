#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"

int main() {
    char buffer[100];

    mkfifo(FIFO_NAME, 0666);

    printf("Server waiting for message...\n");

    int fd = open(FIFO_NAME, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Server received: %s\n", buffer);

    close(fd);

    unlink(FIFO_NAME);

    return 0;
}
