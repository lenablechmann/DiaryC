#include "queries.h"
// will have the following functions:
// search_db(), which will take the date string and search the database for entries, will return a bool

// write(), 
// prints: how was the day? and accepts user input
// which will take the date string, use search_db, then if entry exists cat onto the existing
// if entry doesn't exist, make a new entry for the date, returns bool for success

// read(), 
// prints here is your entry from date: and then the entry itself
// which will take the date string, use search_db, and either print out entry to screen, or return error to main
// which will have to apologize (read returns bool)

// delete(), which will take the date string, use search_db, and delete entry if finds it.
// returns false if nothing can be found

// all functions should return boolean (true if successful, false if some error)