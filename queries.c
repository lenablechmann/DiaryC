// Responsible for searching and modifying the database.

#include "queries.h"

bool search_db(char *date_string)
{
    // will take the date string and search the database for entries, just to see if entry exists.
    return true;
}

bool write_entry(char *date_string)
{
    // prints: how was the day? and accepts user input
    // which will take the date string, use search_db, then if entry exists cat onto the existing
    // if entry doesn't exist, make a new entry for the date, returns bool for success
    return true;
}

bool display_entry(char *date_string)
{
    // prints here is your entry from date: and then the entry itself
    // which will take the date string, use search_db, and either print out entry to screen, or return error to main
    // which will have to apologize (read returns bool)
    return true;
}

bool delete_entry(char *date_string)
{
    // delete(), which will take the date string, use search_db, and delete entry if finds it.
    // returns false if nothing can be found
    return true;
}