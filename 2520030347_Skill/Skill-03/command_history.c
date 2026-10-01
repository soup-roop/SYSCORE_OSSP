#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 10
#define BUFFER_SIZE 100

char *history[MAX_HISTORY];
int history_count = 0;

void add_history(const char *command) {
    if (history_count < MAX_HISTORY) {
        history[history_count] = malloc(strlen(command) + 1);

        if (history[history_count] == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        strcpy(history[history_count], command);
        history_count++;
    } else {
        free(history[0]);

        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }

        history[MAX_HISTORY - 1] = malloc(strlen(command) + 1);

        if (history[MAX_HISTORY - 1] == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        strcpy(history[MAX_HISTORY - 1], command);
    }
}

void show_history() {
    printf("\nCommand History:\n");

    for (int i = 0; i < history_count; i++) {
        printf("%d: %s", i + 1, history[i]);
    }
}

void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Simple Command History\n");
    printf("Type 'history' to display commands.\n");
    printf("Type 'exit' to quit.\n\n");

    while (1) {
        printf("shell> ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        if (strcmp(buffer, "history\n") == 0) {
            show_history();
            continue;
        }

        add_history(buffer);
    }

    free_history();

    return 0;
}
