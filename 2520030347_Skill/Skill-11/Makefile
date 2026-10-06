CC=gcc
CFLAGS=-Wall -Wextra -g

all: history_buffer pipeline_structure

history_buffer: history_buffer.c
	$(CC) $(CFLAGS) history_buffer.c -o history_buffer

pipeline_structure: pipeline_structure.c
	$(CC) $(CFLAGS) pipeline_structure.c -o pipeline_structure

clean:
	rm -f history_buffer pipeline_structure
