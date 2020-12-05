// gets a date string from argv and returns it as YYYY-MM-DD string
// dates are only acceptable if they have the form "today", "yesterday" or DD.MM.YYYY

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *parse_date_string(char *user_date)
{
    // adding a final result date string
    char date_final[DATE_LENGTH] = {0};
    char *final_string = date_final;

    // ints for error checking user input dates
    int day = 0, month = 0, year = 0;

    // turning array into string
    int length = strlen(user_date);
    char *input_string_ptr = user_date;

    if (length >= DATE_LENGTH)
    {
        return NULL;
    }

    else
    {
        // Temporary date string for comparing words 
        char date[DATE_LENGTH] = {0};

        // Checking if user input is "today" or "yesterday".
        for(int i = 0; *input_string_ptr != '\0'; input_string_ptr++, i++)
        {
            if (isalpha(*input_string_ptr))
            {
                date[i] = tolower(*input_string_ptr);
            }
        }
        // once we set everything to lower, the pointer can point to the new char array and make it a string
        input_string_ptr = date;

        if (strcmp(input_string_ptr, "today") == 0)
        {
            // TODO: get the real date via time library (also add the lib), save into a string and return it
            return "today";
        }
        if (strcmp(input_string_ptr, "yesterday") == 0)
        {
            // TODO: get the real date via time library (also add the lib), save into a string and return it
            return "yesterday";
        }

        // user input is a numeric date then.        
        sscanf(user_date, " %d.%d.%d ", &day, &month, &year);

        if(day <= 0 || day > 31 || month <= 0 || month > 12 || year <= 0 || year > 9999)
        {
            return NULL;
        }
        // Use sprintf concatenate ints into strings incl leading zeroes.
        sprintf(date_final, "%04d-%02d-%02d", year, month, day);

    }

    return final_string;
}