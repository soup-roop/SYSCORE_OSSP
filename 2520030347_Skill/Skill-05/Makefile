CC=gcc
CFLAGS=-Wall -Wextra -g

all: single_quotes double_quotes

single_quotes: single_quotes.c
	$(CC) $(CFLAGS) single_quotes.c -o single_quotes

double_quotes: double_quotes.c
	$(CC) $(CFLAGS) double_quotes.c -o double_quotes

clean:
	rm -f single_quotes double_quotes
