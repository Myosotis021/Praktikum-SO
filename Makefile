CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SOURCES=$(wildcard *.c)
TARGETS=$(SOURCES:.c=)

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
