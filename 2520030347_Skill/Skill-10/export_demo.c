#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    if (getcwd(path, sizeof(path)) != NULL)
        printf("Current directory: %s\n", path);

    printf("Exit request received.\n");
    printf("Resources cleaned up.\n");

    return 0;
}
