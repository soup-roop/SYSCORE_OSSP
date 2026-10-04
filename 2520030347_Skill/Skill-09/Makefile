CC=gcc
CFLAGS=-Wall -Wextra -g

all: cd_demo builtin_table

cd_demo: cd_demo.c
	$(CC) $(CFLAGS) cd_demo.c -o cd_demo

builtin_table: builtin_table.c
	$(CC) $(CFLAGS) builtin_table.c -o builtin_table

clean:
	rm -f cd_demo builtin_table
