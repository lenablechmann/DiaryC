#ifndef QUERIES_H
#define QUERIES_H 

#include <ctype.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ENTRY_LEN 4000

bool search_db(char *date_string, size_t date_len);
bool write_entry(char *date_string, size_t date_len);
bool edit_entry(char *date_string, size_t date_len);
bool display_entry(char *date_string, size_t date_len);
bool delete_entry(char *date_string, size_t date_len);

#endif