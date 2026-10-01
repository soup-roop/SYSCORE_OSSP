#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 100;

int main() {
    int local_var = 200;

    int *heap_var = malloc(sizeof(int));

    if (heap_var == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *heap_var = 300;

    printf("Process ID: %d\n", getpid());

    printf("Address of global variable : %p\n", (void *)&global_var);
    printf("Address of local variable  : %p\n", (void *)&local_var);
    printf("Address of heap variable   : %p\n", (void *)heap_var);

    printf("Value of global variable   : %d\n", global_var);
    printf("Value of local variable    : %d\n", local_var);
    printf("Value of heap variable     : %d\n", *heap_var);

    free(heap_var);

    return 0;
}
