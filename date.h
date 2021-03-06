#ifndef DATE_H 
#define DATE_H 
#define DATE_LENGTH 11
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *parse_date_string(char *user_date);
int date_plausibility(const int day, const int month, const int year);

#endif