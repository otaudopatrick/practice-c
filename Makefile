CC = gcc
CFLAGS = -Wall -Iinclude

all: dinamic_array linked_list stack queue tree hashtable

dinamic_array: src/dinamic_array.c
	$(CC) $(CFLAGS) -o bin/dinamic_array src/dinamic_array.c

clean:
	rm -f bin/*
