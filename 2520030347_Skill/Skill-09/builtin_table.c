#include <stdio.h>
#include <string.h>

void help() {
    printf("Built-ins: cd pwd help exit\n");
}

void pwd() {
    printf("pwd built-in executed.\n");
}

void exit_shell() {
    printf("exit built-in executed.\n");
}

int main() {
    char command[50];

    printf("Enter command: ");
    scanf("%49s", command);

    if (strcmp(command, "help") == 0)
        help();
    else if (strcmp(command, "pwd") == 0)
        pwd();
    else if (strcmp(command, "exit") == 0)
        exit_shell();
    else
        printf("Unknown command.\n");

    return 0;
}
