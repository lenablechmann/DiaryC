#ifndef QUERIES_H
#define QUERIES_H 

#include <ctype.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 4000
#define DATE 12

bool search_db(char *date_string);
bool write_entry(char *date_string);
bool display_entry(char *date_string);
bool delete_entry(char *date_string);

#endif