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
    // entry array shall be null to prepare it as a string
    /*
    char entry_array[LENGTH + 1] = {0};
    char *entry_string = entry_array;
    char user_char = 0;
    int count;
    */
    /*user_char = getc(stdin);
    for (count = 0; user_char != EOF && count <= LENGTH; count++)
    {
        // Storing user input into the array one char at a time, until EOF (CTRL D)
        entry_array[count] = user_char;
    }
    printf("your entry for the day %s: \n", date_string);
    puts(entry_string);
    */

    // prints: how was the day? and accepts user input 
    // which will take the date string, use search_db, then if entry exists cat onto the existing
    // if entry doesn't exist, make a new entry for the date, returns bool for success
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