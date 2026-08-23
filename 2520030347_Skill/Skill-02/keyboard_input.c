#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define MAX_INPUT 100

void enable_raw_mode(struct termios *original)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, original);
    raw = *original;

    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode(struct termios *original)
{
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

int main()
{
    struct termios original;
    char buffer[MAX_INPUT];
    int index = 0;
    char ch;

    enable_raw_mode(&original);

    printf("=====================================\n");
    printf("       Keyboard Input Demonstration\n");
    printf("=====================================\n");
    printf("Type a command and press Enter.\n");
    printf("Backspace is supported.\n");
    printf("Type 'exit' to terminate.\n\n");

    printf("MiniShell> ");
    fflush(stdout);

    while (index < MAX_INPUT - 1)
    {
        read(STDIN_FILENO, &ch, 1);

        if (ch == '\n' || ch == '\r')
        {
            buffer[index] = '\0';

            printf("\nYou entered: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0)
            {
                break;
            }

            index = 0;
            printf("MiniShell> ");
            fflush(stdout);
        }
        else if (ch == 127 || ch == 8)
        {
            if (index > 0)
            {
                index--;
                printf("\b \b");
                fflush(stdout);
            }
        }
        else if (ch >= 32 && ch <= 126)
        {
            buffer[index++] = ch;
            putchar(ch);
            fflush(stdout);
        }
    }

    disable_raw_mode(&original);

    printf("\nShell terminated.\n");

    return 0;
}

