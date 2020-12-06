// gets a date string from argv and returns it as YYYY-MM-DD string
// dates are only acceptable if they have the form "today", "yesterday" or DD.MM.YYYY

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// todo add a function, that checks if date is plausible (leap year, months and days), returns 0 if nah, 1 if plausible

char *parse_date_string(char *user_date)
{
    // the final result will be stored in this string
    char date_final[DATE_LENGTH] = {0};
    char *final_string = date_final;

    // ints for error checking user input dates
    int day = 0, month = 0, year = 0;

    // turning array into string and checking base length
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
        for (int i = 0; *input_string_ptr != '\0'; input_string_ptr++, i++)
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

        // Assuming user input is a numeric date then. Parse it into ints.
        sscanf(user_date, " %d.%d.%d ", &day, &month, &year);

        int plausibility = date_plausibility(day, month, year);

        if (plausibility == 1)
        {
            // Use sprintf concatenate ints into strings incl leading zeroes.
            sprintf(date_final, "%04d-%02d-%02d", year, month, day);
            return final_string;
        }
        else
        {
            return NULL;
        }
    }
}

int date_plausibility(const int day, const int month, const int year)
{
    // checks date plausibility (days in a month, leap year), returns 0 if date unplausible. 1 if plausible.

    // first preliminary check; covering generally impossible things like negative days
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year <= 0 || year > 9999)
    {
        return 0;
    }
    else
    {
        // Arrays for days per month in leap years and non leap years, 0 indexed so January is 0, December is 11:
        int days_per_month_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days_per_month_non[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // check if year is a leap year
        if (year % 4 == 0 && year % 100 != 0)
        {
            // definitely a leap year, checking if days are plausible via array. month - 1 cause arrays are 0 indexed
            if (day > days_per_month_leap[month - 1])
            {
                return 0;
            }
        }

        else if(year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
        {
            // a leap year, checking if days are plausible via array. month - 1 cause arrays are 0 indexed
            if (day > days_per_month_leap[month - 1])
            {
                return 0;
            }
        }

        else
        {
            // not a leap year, checking if days are plausible via array. month -1 cause arrays are 0 indexed
            if (day > days_per_month_non[month - 1])
            {
                return 0;
            }
        }

        return 1;
    }
}