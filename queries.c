// Responsible for searching and modifying the database.
// assuming user won't input more than 4000 chars in a day

#include "queries.h"

bool search_db(char *date_string, size_t date_len)
{
    // will take the date string and search the database for entries, just to see if entry exists.
    return true;
}

bool write_entry(char *date_string, size_t date_len)
{
    printf("The size of this string is %ld and the string is %s\n", date_len, date_string);
    //TODO remalloc date_string

    // initializing a string for the user input
    char *entry = (char*)(malloc((ENTRY_LEN + 1) * sizeof(char)));
    if (entry == NULL)
    {
        printf("Error allocating memory for the entry.\n");
        return false;
    }
    printf("The date is %s\n", date_string);

    // Initializing the string to NUL
    for (int i = 0; i < ENTRY_LEN + 1; i++)
    {
        entry[i] ='\0';
    }

    printf("Your entry:\n");
    char input_tmp = 0;
    int count = 0;

    for (; count <= ENTRY_LEN; count++)
    {
        input_tmp = getc(stdin);
        if (input_tmp == EOF)
        {
            break;
        }
        entry[count] = input_tmp;
    }
    printf("\nYour entry for the day %s is:\n", date_string);
    
    for (char *trace = entry; *trace != '\0'; trace++)
    {
        printf("%c", *trace);
    }

    // prints: how was the day? and accepts user input 
    // which will take the date string, use search_db, then if entry exists cat onto the existing
    // if entry doesn't exist, make a new entry for the date, returns bool for success
    free(entry);
    return true;
}

bool display_entry(char *date_string, size_t date_len)
{
    // prints here is your entry from date: and then the entry itself
    // which will take the date string, use search_db, and either print out entry to screen, or return error to main
    // which will have to apologize (read returns bool)
    return true;
}

bool delete_entry(char *date_string, size_t date_len)
{
    // delete(), which will take the date string, use search_db, and delete entry if finds it.
    // returns false if nothing can be found
    return true;
}