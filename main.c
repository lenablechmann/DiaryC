/* Responsible for parsing user input, calling functions and exiting the program after */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// write a main function that takes user input. "diary write today" or similar

// checks user input for errors and edge cases
// needs to have 3 parts.
// dates are only acceptable if they have the form "today", "yesterday", YYYY-MM-DD or DD.MM.YYYY or MM/DD/YYYY
// checks general date format, prints error if wrong, if date format is ok, sends it to date.c

// checks general command input. make use of tolower(), also w, r, d, rm, and -r -w -d -rm are ok

// w, write, -w, should print "How was your day?", 
// call the write function from controller.c, 
// which will save the user input to the database (or cat it if the entry already exists)
// until the user inputs the ending

// r, -r, read should call the read function from controller.c, which will print the required entry
// if that entry exists (make a separate search db function in controller)

// if user input is delete, check if there is an entry with the date,
// if so, delete the entry

// once finished exit the program
