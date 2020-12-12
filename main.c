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
        printf("Usage: ./diary command date.\nAcceptable commands are: w, -w, write for writing a diary entry\n");
        printf("Example: ./diary write today.\nOr: r, -r, read for reading a diary entry\n");
        printf("Example: ./diary read yesterday.\nOr: d, -d, delete for deleting a diary entry\n");
        printf("Example: ./diary delete 10.12.2020.\nAcceptable dates are today, yesterday and DD.MM.YYYY\n");
        exit(EXIT_FAILURE);
    }

    // Preparing a string where the date in ISO format will be stored (for future SQL queries)
    // needn't allocate memory, since the string will be created in date.c, and we can just point at it here.
    char *date_string;

    // Sends the argv (user date input) to date.c, will return a null string if user input seems off
    // If the date is plausible, the function will return the formatted date string YYYY-MM-DD
    date_string = parse_date_string(argv[2]);
    if (!date_string)
    {
        printf("Acceptable date input formats: today, yesterday or DD.MM.YYYY\n");
        exit(EXIT_FAILURE);
    }

    // Checks general command input and calls appropriate functions.
    if (strcmp(argv[1], "w") == 0 || strcmp(argv[1], "write") == 0 || strcmp(argv[1], "-w") == 0)
    {
        write_entry(date_string, LENGTH);
    }

    else if (strcmp(argv[1], "r") == 0 || strcmp(argv[1], "read") == 0 || strcmp(argv[1], "-r") == 0)
    {
        display_entry(date_string, LENGTH);
    }

    else if (strcmp(argv[1], "d") == 0 || strcmp(argv[1], "delete") == 0 || strcmp(argv[1], "-d") == 0)
    {
        delete_entry(date_string, LENGTH);
    }
    free(date_string);
    return 0;
}
