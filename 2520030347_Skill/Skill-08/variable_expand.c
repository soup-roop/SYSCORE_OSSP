#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[100];

    printf("Enter variable name: ");
    scanf("%99s", name);

    char *value = getenv(name);

    if (value != NULL)
        printf("%s = %s\n", name, value);
    else
        printf("%s is undefined.\n", name);

    return 0;
}
