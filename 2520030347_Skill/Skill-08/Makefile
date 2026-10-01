CC=gcc
CFLAGS=-Wall -Wextra -g

all: variable_expand builtin_dispatch

variable_expand: variable_expand.c
	$(CC) $(CFLAGS) variable_expand.c -o variable_expand

builtin_dispatch: builtin_dispatch.c
	$(CC) $(CFLAGS) builtin_dispatch.c -o builtin_dispatch

clean:
	rm -f variable_expand builtin_dispatch
