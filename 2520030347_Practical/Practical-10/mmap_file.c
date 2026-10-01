#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *filename = "mmap_data.txt";

    int fd = open(filename, O_RDWR | O_CREAT, 0666);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    const char *message = "Hello from mmap!";
    size_t size = strlen(message) + 1;

    if (ftruncate(fd, size) == -1) {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    char *mapped = mmap(NULL,
                        size,
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED,
                        fd,
                        0);

    if (mapped == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    strcpy(mapped, message);

    printf("Data written using mmap: %s\n", mapped);

    if (munmap(mapped, size) == -1) {
        perror("munmap");
    }

    close(fd);

    return 0;
}
