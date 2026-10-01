#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int source, destination;
    char buffer[1024];
    ssize_t bytes_read;

    source = open("source.txt", O_RDONLY);

    if (source < 0) {
        perror("Error opening source file");
        return 1;
    }

    destination = open("destination.txt",
                      O_WRONLY | O_CREAT | O_TRUNC,
                      0644);

    if (destination < 0) {
        perror("Error opening destination file");
        close(source);
        return 1;
    }

    while ((bytes_read = read(source, buffer, sizeof(buffer))) > 0) {
        write(destination, buffer, bytes_read);
    }

    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}
