CC = gcc
CFLAGS = -Wall -Wextra

all: interactive_shell keyboard_input

interactive_shell: interactive_shell.c
	$(CC) $(CFLAGS) interactive_shell.c -o interactive_shell

keyboard_input: keyboard_input.c
	$(CC) $(CFLAGS) keyboard_input.c -o keyboard_input

clean:
	rm -f interactive_shell keyboard_input
