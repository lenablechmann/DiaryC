/* Responsible for parsing user input, calling functions and exiting the program after */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queries.h"
#include "date.h"

int main(int argc, char *argv[])
{
    // User input will have 3 argc: argv[1] is the command, argv[2] is the date string
    if (argc != 3)
    {
        printf("Usage: ./diary command date.\nFor example: ./diary write today \n");
        exit(EXIT_FAILURE);
    }

    // Sends the date string to date.c, will return a null string if date is wrong.
    char user_date[DATE_LENGTH] = {0};
    char *usr_date_string = user_date;
    usr_date_string = parse_date_string(argv[2]);

    if (usr_date_string == NULL)
    {
        printf("Acceptable date input formats: today, yesterday or DD.MM.YYYY\n");
        exit(EXIT_FAILURE);
    }
    printf("Your date is %s\n", usr_date_string);


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
    return 0;
}
