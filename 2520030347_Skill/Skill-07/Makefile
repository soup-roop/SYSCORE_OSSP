CC=gcc
CFLAGS=-Wall -Wextra -g

all: waitpid_demo path_search

waitpid_demo: waitpid_demo.c
	$(CC) $(CFLAGS) waitpid_demo.c -o waitpid_demo

path_search: path_search.c
	$(CC) $(CFLAGS) path_search.c -o path_search

clean:
	rm -f waitpid_demo path_search
