#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char command[100];
    char *path = getenv("PATH");

    printf("Enter executable name: ");
    scanf("%99s", command);

    char *copy = strdup(path);
    char *directory = strtok(copy, ":");

    while (directory != NULL) {
        char fullpath[512];

        snprintf(fullpath, sizeof(fullpath),
                 "%s/%s", directory, command);

        if (access(fullpath, X_OK) == 0) {
            printf("Executable found: %s\n", fullpath);
            free(copy);
            return 0;
        }

        directory = strtok(NULL, ":");
    }

    printf("Command not found.\n");

    free(copy);

    return 1;
}
