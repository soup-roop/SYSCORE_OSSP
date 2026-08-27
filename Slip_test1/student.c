#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[101];

    fd = open("student.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    int n = read(fd, buffer, 100);

    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    printf("File contents:\n%s\n", buffer);

    close(fd);

    return 0;
}
