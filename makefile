CC = gcc
# adding -g for debugging and -Wall for all warnings
CFLAGS = -g -Wall

# all: dbtest.c
	# $(CC) $(CFLAGS) -o dbtest dbtest.c -lsqlite3
diary: main.o date.o queries.o
	$(CC) $(CFLAGS) -o diary main.o date.o queries.o

main.o: main.c queries.h date.h
	$(CC) $(CFLAGS) -c main.c

date.o: date.c date.h
	$(CC) $(CFLAGS) -c date.c

queries.o: queries.c queries.h
	$(CC) $(CFLAGS) -c queries.c
clean:
	$(RM) diary
