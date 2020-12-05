#ifndef DATE_H 
#define DATE_H 
#define DATE_LENGTH 11

char *parse_date_string(char *user_date);
int date_plausibility(const int day, const int month, const int year);

#endif