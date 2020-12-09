// Responsible for searching and modifying the database.
// assuming user won't input more than 4000 chars in a day

#include "queries.h"

bool search_db(char *date_string, size_t date_len)
{
    // will take the date string and search the database for entries, just to see if entry exists.
    // accessing the db (creating one if doesn't exist)
    sqlite3 *db;
    int result = sqlite3_open("diary.db", &db);

    // Checking db opened successfully (is not 0)
    if (result)
    {
        printf("Can't open database.\n");
        sqlite3_close(db);
        return 0;
    }

    // making sure the table either exists or is created here.
    if (sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS diary (id INTEGER PRIMARY KEY AUTOINCREMENT DEFAULT 0, date INTEGER NOT NULL,entry TEXT NOT NULL);", NULL, NULL, NULL))
    {
        printf("Error opening the sqlite table.\n");
    }

    // using prepared statements v2 (v3 is for special occasions according to doco)
    sqlite3_stmt *stmt;

    int err = sqlite3_prepare_v2(db, "SELECT entry FROM diary WHERE date = ?", -1, &stmt, NULL);
    if (err != SQLITE_OK)
    {
        printf("Sql failed to run the select statement. %s \n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // binding values (date and entry):
    sqlite3_bind_text(stmt, 1, date_string, -1, NULL);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("your entry is:\n%s \n", sqlite3_column_text(stmt, 0));
    }

    // clearing memory alloced for the stmt
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return true;
}

bool write_entry(char *date_string, size_t date_len)
{
    printf("The size of this string is %ld and the string is %s\n", date_len, date_string);

    //TODO realloc date_string if not enough has been allocated
    // initializing a string for the user input
    char *entry = (char *)(malloc((ENTRY_LEN + 1) * sizeof(char)));
    if (entry == NULL)
    {
        printf("Error allocating memory for the entry.\n");
        return false;
    }

    // Initializing the string to NUL
    for (int i = 0; i < ENTRY_LEN + 1; i++)
    {
        entry[i] = '\0';
    }

    printf("Write away (CTRL + D to save the entry and exit):\n");

    // getc needs to be stored in an int, cause EOF is a negative int
    int input_tmp = 0;
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

    // which will take the date string, use search_db, then if entry exists cat onto the existing
    // if entry doesn't exist, make a new entry for the date, returns bool for success

    // accessing the db (creating one if doesn't exist)
    sqlite3 *db;
    int result = sqlite3_open("diary.db", &db);

    // Checking db opened successfully (is not 0)
    if (result)
    {
        printf("Can't open database.\n");
        sqlite3_close(db);
        return 0;
    }

    // making sure the table either exists or is created here.
    if (sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS diary (id INTEGER PRIMARY KEY AUTOINCREMENT DEFAULT 0, date INTEGER NOT NULL,entry TEXT NOT NULL);", NULL, NULL, NULL))
    {
        printf("Error executing sql statement\n");
    }

    // using prepared statements v2 (v3 is for special occasions according to doco)
    sqlite3_stmt *stmt;
    int err = sqlite3_prepare_v2(db, "INSERT INTO diary(date, entry) VALUES(?, ?)", -1, &stmt, NULL);
    if (err != SQLITE_OK)
    {
        printf("Sql statement failed. %s \n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // binding values (date and entry):
    sqlite3_bind_text(stmt, 1, date_string, -1, NULL);
    sqlite3_bind_text(stmt, 2, entry, -1, NULL);

    // Inserts values into table via step
    sqlite3_step(stmt);
    // clearing memory alloced for the stmt
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    printf("successfully used the db\n");

    free(entry);

    return true;
}

bool edit_entry(char *date_string, size_t date_len)
{
    // will also check if db exists or not
    // will take the date string and search the database for entries, just to see if entry exists.
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