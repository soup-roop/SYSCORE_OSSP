#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_NAME "myfifo"

int main() {
    char message[100];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    int fd = open(FIFO_NAME, O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    printf("Message sent to server.\n");

    return 0;
}
