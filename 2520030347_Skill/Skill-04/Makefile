CC=gcc
CFLAGS=-Wall -Wextra -g

all: tokenizer parser

tokenizer: tokenizer.c
	$(CC) $(CFLAGS) tokenizer.c -o tokenizer

parser: parser.c
	$(CC) $(CFLAGS) parser.c -o parser

clean:
	rm -f tokenizer parser
