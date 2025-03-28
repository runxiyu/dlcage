.POSIX:

CC = gcc
CFLAGS += -Wall -Wextra -pedantic -D_GNU_SOURCE -fPIC -std=gnu99

all: ghost.so test

ghost.so: ghost.c ghost.h
	$(CC) $(CFLAGS) -shared -o ghost.so ghost.c

test: test.c
	$(CC) $(CFLAGS) -ldl -lpthread -o test test.c

.PHONY: all
