/* Responsible for parsing user input, calling functions and exiting the program after */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queries.h"
#include "date.h"

#define LENGTH 10

int main(int argc, char *argv[])
{
    // User input will have 3 argc: argv[1] is the command, argv[2] is the date string
    if (argc != 3)
    {
        printf("Usage: ./diary command date.\nFor example: ./diary write today \n");
        exit(EXIT_FAILURE);
    }

    // Preparing a string where the date in ISO format will be stored (for future SQL queries)
    char *date_string = (char*)(malloc((LENGTH + 1) * sizeof(char)));
    if (date_string == NULL)
    {
        printf("Error allocating memory for the date string.\n");
        exit(EXIT_FAILURE);
    }

    // Initializing the string to NUL
    for (int i = 0; i < LENGTH + 1; i++)
    {
        date_string[i] = '\0';
    }

    // Sends the argv (user date input) to date.c, will return a null string if user input seems off
    // If the date is plausible, the function will return the formatted date string YYYY-MM-DD
    date_string = parse_date_string(argv[2]);
    if (!date_string)
    {
        printf("Acceptable date input formats: today, yesterday or DD.MM.YYYY\n");
        exit(EXIT_FAILURE);
    }
    // printf("Your date is %s, and string length is %d\n", date_string, LENGTH);
    // invoking write for testing
    search_db(date_string, LENGTH);

    // Checks general command input. make use of tolower(), also w, r, d, rm, and -r -w -d -rm are ok

    // w, write, -w, should print "How was your day?",
    // call the write function from queries.c,
    // which will save the user input to the database (or cat it if the entry already exists)
    // until the user inputs the ending

    // r, -r, read should call the display function from queries.c, which will print the required entry
    // if that entry exists (make a separate search db function in queries.c)

    // if user input is delete, check if there is an entry with the date,
    // if so, delete the entry

    // once finished and got "true" from the function it called, exit the program
    return 0;
}
