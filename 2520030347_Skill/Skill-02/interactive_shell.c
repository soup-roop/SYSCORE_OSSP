#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

int main()
{
    char input[MAX_INPUT];

    printf("=====================================\n");
    printf("        Simple Interactive Shell\n");
    printf("=====================================\n");

    while (1)
    {
        printf("SimpleShell> ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT, stdin) == NULL)
        {
            printf("\nInput error.\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }

        if (strlen(input) == 0)
        {
            continue;
        }

        printf("You entered: %s\n", input);
    }

    return 0;
}
