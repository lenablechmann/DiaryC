/* Responsible for parsing user input, calling functions and exiting the program after */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queries.h"
#include "date.h"

int main(int argc, char *argv[])
{
    // User input needs to have 3 parts (program name, what do, and date).
    if (argc != 3)
    {
        printf("Usage: ./diary command date.\nLike: ./diary write today \n");
        exit(EXIT_FAILURE);
    }
    // Sends the date string to date.c, which decides if it's an alright date.

    // Checks general command input. make use of tolower(), also w, r, d, rm, and -r -w -d -rm are ok

    // w, write, -w, should print "How was your day?",
    // call the write function from queries.c,
    // which will save the user input to the database (or cat it if the entry already exists)
    // until the user inputs the ending

    // r, -r, read should call the read function from queries.c, which will print the required entry
    // if that entry exists (make a separate search db function in queries.c)

    // if user input is delete, check if there is an entry with the date,
    // if so, delete the entry

    // once finished and got "true" from the function it called, exit the program
    printf("We did it.\n");
    return 0;
}
