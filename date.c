// gets a date string from argv and returns it as YYYY-MM-DD
// dates are only acceptable if they have the form "today", "yesterday" or DD.MM.YYYY
#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DATE_LENGTH 11

char *parse_date_string(char *user_date)
{
    int day = 0, month = 0, year = 0;
    int length = strlen(user_date);
    char *pointer = user_date;

    //Error checking user input:
    if (length >= DATE_LENGTH)
    {
        return NULL;
    }

    else
    {
        // in this array the date shall be stored:
        char date[DATE_LENGTH] = {0};

        // Checking if user input is "today" or "yesterday".
        for(int i = 0; *pointer != '\0'; pointer++, i++)
        {
            if (isalpha(*pointer))
            {
                date[i] = tolower(*pointer);
            }
        }

        // making the array into a string.
        pointer = date;

        if (strcmp(pointer, "today") == 0)
        {
            // TODO: get the real date via time library (also add the lib), save into a string and return it
            return "today";
        }
        if (strcmp(pointer, "yesterday") == 0)
        {
            // TODO: get the real date via time library (also add the lib), save into a string and return it
            return "yersterday";
        }

        // Apparently user input is numeric date then.        
        // Resetting pointer address to parse the user input:
        pointer = user_date;

        for(int i = 0; *pointer != '\0'; pointer++, i++)
        {
            // Check if input is a special char, if it aint ".", return NULL, cause it aint a format we like
            // Can add USA MM/DD/YYYY format later at some point.
            if (isalpha(*pointer) == 0 && *pointer == '.')
            {
                date[i] = '-';
            }
        }
    }
    return "all g";
}