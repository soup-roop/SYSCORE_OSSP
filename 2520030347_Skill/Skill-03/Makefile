CC = gcc
CFLAGS = -Wall -Wextra -g

all: command_history dynamic_buffer

command_history: command_history.c
	$(CC) $(CFLAGS) command_history.c -o command_history

dynamic_buffer: dynamic_buffer.c
	$(CC) $(CFLAGS) dynamic_buffer.c -o dynamic_buffer

clean:
	rm -f command_history dynamic_buffer
