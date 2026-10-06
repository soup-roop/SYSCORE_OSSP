#include <stdio.h>

#define MAX_HISTORY 5

int main() {
    char history[MAX_HISTORY][100];

    printf("Enter 5 commands:\n");

    for (int i = 0; i < MAX_HISTORY; i++) {
        printf("> ");
        fgets(history[i], sizeof(history[i]), stdin);
    }

    printf("\nCommand History:\n");

    for (int i = 0; i < MAX_HISTORY; i++)
        printf("%d: %s", i + 1, history[i]);

    return 0;
}
