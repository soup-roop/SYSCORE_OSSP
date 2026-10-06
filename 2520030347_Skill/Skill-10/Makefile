CC=gcc
CFLAGS=-Wall -Wextra -g

all: pwd_exit export_demo

pwd_exit: pwd_exit.c
	$(CC) $(CFLAGS) pwd_exit.c -o pwd_exit

export_demo: export_demo.c
	$(CC) $(CFLAGS) export_demo.c -o export_demo

clean:
	rm -f pwd_exit export_demo
