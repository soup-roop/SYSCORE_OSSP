#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int *value = malloc(sizeof(int));

    if (value == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *value = 100;

    printf("Before fork: value = %d\n", *value);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        free(value);
        return 1;
    }

    if (pid == 0) {
        printf("Child before modification: %d\n", *value);

        *value = 200;

        printf("Child after modification: %d\n", *value);
    } else {
        wait(NULL);

        printf("Parent value: %d\n", *value);
    }

    free(value);

    return 0;
}
