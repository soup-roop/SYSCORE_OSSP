#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    getcwd(path, sizeof(path));
    printf("Current directory: %s\n", path);

    printf("Enter directory: ");
    scanf("%s", path);

    if (chdir(path) == 0) {
        getcwd(path, sizeof(path));
        printf("Changed directory: %s\n", path);
    } else {
        perror("chdir");
    }

    return 0;
}
