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
        // Check if date is at least plausible, perhaps use atoi or maybe use calculators as reference
        sscanf(user_date, "%2d.%2d.%4d", &day, &month, &year);

        if(day < 0 || day > 31 || month < 0 || month > 12 || year < 0 || year > 9999)
        {
            return NULL;
        }
        printf("Day is %d month is %d and year is %d \n", day, month, year);

        // Use sprintf concatenate ints into strings
        sprintf(pointer, "%d-%d-%d", year, month, day);
    }

    return pointer;
}