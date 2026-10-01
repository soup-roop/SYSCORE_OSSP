#include <stdio.h>
#include <string.h>

int main() {
    char input[256];

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == '\n') {
        printf("Error: Empty command\n");
        return 1;
    }

    printf("\nParser analysis:\n");

    if (strchr(input, '|'))
        printf("Pipeline detected\n");

    if (strchr(input, '<') || strchr(input, '>'))
        printf("Redirection detected\n");

    printf("Syntax accepted: %s", input);

    return 0;
}
