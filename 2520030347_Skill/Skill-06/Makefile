CC=gcc
CFLAGS=-Wall -Wextra -g

all: escape_parser execute_command

escape_parser: escape_parser.c
	$(CC) $(CFLAGS) escape_parser.c -o escape_parser

execute_command: execute_command.c
	$(CC) $(CFLAGS) execute_command.c -o execute_command

clean:
	rm -f escape_parser execute_command
