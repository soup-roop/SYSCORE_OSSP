#include <stdio.h>

int main() {
    char input[256];
    char output[256];
    int j = 0;

    printf("Enter escaped input: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\\' && input[i + 1] != '\0')
            i++;

        output[j++] = input[i];
    }

    output[j] = '\0';

    printf("Processed input: %s", output);

    return 0;
}
