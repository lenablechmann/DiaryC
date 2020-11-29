CC = gcc
# adding -g for debugging and -Wall for all warnings
CFLAGS = -g -Wall
all: dbtest.c
	$(CC) $(CFLAGS) -o dbtest dbtest.c -lsqlite3

clean:
	$(RM) dbtest
