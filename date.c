// Gets a date string from argv and returns it as YYYY-MM-DD string
// Dates are currently only acceptable if they have the form "today", "yesterday" or DD.MM.YYYY

#include "date.h"

char *parse_date_string(char *user_date)
{
    // The final result will be stored in this string
    char *str_date = (char*)(malloc((DATE_LENGTH + 1) * sizeof(char)));
    // Null checking malloc is a must.
    if (str_date == NULL)
    {
        printf("Error allocating memory for the date string in date.c.\n");
        return NULL;
    }

    for (int i = 0; i < DATE_LENGTH + 1; i++)
    {
        str_date[i] = '\0';
    }

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
            time_t now = time(NULL);
            // localtime returns a pointer to a tm struct with ints day, month(0 to 11), year(since 1900) and time filled in
            struct tm *lt = localtime(&now);
            sprintf(str_date, "%04d-%02d-%02d", (lt->tm_year)+1900, (lt->tm_mon)+1, lt->tm_mday);

            return str_date;
        }

        if (strcmp(input_string_ptr, "yesterday") == 0)
        {
            time_t now = time(NULL);
            // localtime returns a pointer to a tm struct with ints day, month(0 to 11), year(since 1900) and time filled in
            struct tm *lt = localtime(&now);
            lt->tm_mday--; // getting the previous day
            mktime(lt); // mktime normalizes the time, so that it doesn't show 0 on the 1st etc, says SO

            sprintf(str_date, "%04d-%02d-%02d", (lt->tm_year)+1900, (lt->tm_mon)+1, lt->tm_mday);

            return str_date;
        }

        // Assuming user input is a numeric date then. Parse it into ints.
        sscanf(user_date, " %d.%d.%d ", &day, &month, &year);

        int plausibility = date_plausibility(day, month, year);

        if (plausibility == 1)
        {
            // Use sprintf concatenate ints into strings incl leading zeroes.
            sprintf(str_date, "%04d-%02d-%02d", year, month, day);
            
            return str_date;
        }
        else
        {
            free(str_date);
            return NULL;
        }
    }
}

// Checks date plausibility (days in a month, leap year), returns 0 if date unplausible. 1 if plausible.
int date_plausibility(const int day, const int month, const int year)
{

    // First preliminary check; covering generally impossible things like negative days
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year <= 0 || year > 9999)
    {
        return 0;
    }
    // A thorough leap year check.
    else
    {
        // Arrays for days per month in leap years and non leap years, 0 indexed so January is 0, December is 11:
        int days_per_month_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days_per_month_non[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check if year is a leap year
        if (year % 4 == 0 && year % 100 != 0)
        {
            // Definitely a leap year, checking if days are plausible via array. month - 1 cause arrays are 0 indexed
            if (day > days_per_month_leap[month - 1])
            {
                printf("The date you've entered has too many days in a month.\n");
                return 0;
            }
        }

        else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
        {
            // a leap year
            if (day > days_per_month_leap[month - 1])
            {
                printf("The date you've entered has too many days in a month.\n");
                return 0;
            }
        }

        else
        {
            // not a leap year
            if (day > days_per_month_non[month - 1])
            {
                printf("The date you've entered has too many days/month for a common year.\n");
                return 0;
            }
        }

        return 1;
    }
}