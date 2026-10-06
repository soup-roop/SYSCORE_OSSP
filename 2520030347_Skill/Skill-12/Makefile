CC=gcc
CFLAGS=-Wall -Wextra -g

all: pipe_demo multi_pipe

pipe_demo: pipe_demo.c
	$(CC) $(CFLAGS) pipe_demo.c -o pipe_demo

multi_pipe: multi_pipe.c
	$(CC) $(CFLAGS) multi_pipe.c -o multi_pipe

clean:
	rm -f pipe_demo multi_pipe
