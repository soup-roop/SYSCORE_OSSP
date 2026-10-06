#include <stdio.h>

int main() {
    int commands;

    printf("Number of commands in pipeline: ");
    scanf("%d", &commands);

    printf("\nPipeline execution order:\n");

    for (int i = 0; i < commands; i++) {
        if (i < commands - 1)
            printf("Command %d -> ", i + 1);
        else
            printf("Command %d\n", i + 1);
    }

    return 0;
}
