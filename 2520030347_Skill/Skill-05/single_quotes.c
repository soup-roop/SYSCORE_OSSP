#include <stdio.h>

int main() {
    char input[256];

    printf("Enter single quoted text: ");
    fgets(input, sizeof(input), stdin);

    printf("Single quoted input is treated literally:\n");
    printf("%s", input);

    return 0;
}
