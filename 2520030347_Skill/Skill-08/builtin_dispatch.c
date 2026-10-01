#include <stdio.h>
#include <string.h>

void builtin_cd() {
    printf("cd built-in selected.\n");
}

void builtin_pwd() {
    printf("pwd built-in selected.\n");
}

void builtin_exit() {
    printf("exit built-in selected.\n");
}

int main() {
    char command[50];

    printf("Enter built-in command: ");
    scanf("%49s", command);

    if (strcmp(command, "cd") == 0)
        builtin_cd();
    else if (strcmp(command, "pwd") == 0)
        builtin_pwd();
    else if (strcmp(command, "exit") == 0)
        builtin_exit();
    else
        printf("Invalid built-in.\n");

    return 0;
}
