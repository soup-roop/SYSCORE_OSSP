#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];

    printf("Enter double quoted text: ");
    fgets(input, sizeof(input), stdin);

    printf("Input: %s", input);

    if (strstr(input, "$USER") != NULL) {
        char *user = getenv("USER");

        if (user != NULL)
            printf("Expanded USER = %s\n", user);
    }

    return 0;
}
