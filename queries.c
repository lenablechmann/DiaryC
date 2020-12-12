// Responsible for searching and modifying the database.
// potentially will have to rewrite the table to include string length

#include "queries.h"


bool search_db(char *date_string, size_t date_len)
{
    // will take the date string and search the database for entries
    // returns true if entry exists, false if no entry exists. 

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

    int err = sqlite3_prepare_v2(db, "SELECT entry FROM diary WHERE date = ? ORDER BY id ASC", -1, &stmt, NULL);
    if (err != SQLITE_OK)
    {
        printf("Sql failed to run the select statement. %s \n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // binding values (date and entry):
    sqlite3_bind_text(stmt, 1, date_string, -1, NULL);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
    sqlite3_finalize(stmt);
    sqlite3_close(db);
        return true;
    }
    else
    {
    sqlite3_finalize(stmt);
    sqlite3_close(db);
        return false;
    }

    // clearing memory alloced for the stmt

}

bool write_entry(char *date_string, size_t date_len)
{
    // initializing a string for the user input
    char *entry;
    printf("Write away (CTRL + D to save the entry and exit):\n");
    entry = dynamic_input();

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
    free(entry);

    if (sqlite3_close(db) == SQLITE_BUSY)
    {
        printf("Failed to finalize statements in the database.\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool edit_entry(char *date_string, size_t date_len)
{
    // will also check if db exists or not
    // will take the date string and search the database for entries, just to see if entry exists.
    return true;
}

bool display_entry(char *date_string, size_t date_len)
{
    if(search_db(date_string, date_len) == false)
    {
        printf("There is no entry for the date %s\n", date_string);
        return false;
    }

    sqlite3 *db;
    int result = sqlite3_open("diary.db", &db);

    // Checking db opened successfully (is not 0)
    if (result)
    {
        printf("Can't open database.\n");
        sqlite3_close(db);
        return 0;
    }

    // using prepared statements v2 (v3 is for special occasions according to doco)
    sqlite3_stmt *stmt;

    int err = sqlite3_prepare_v2(db, "SELECT entry FROM diary WHERE date = ? ORDER BY id ASC", -1, &stmt, NULL);
    if (err != SQLITE_OK)
    {
        printf("Sql failed to run the select statement. %s \n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // binding values (date and entry):
    sqlite3_bind_text(stmt, 1, date_string, -1, NULL);
    
    // Printing out all entries for the date
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        printf("%s\n", sqlite3_column_text(stmt, 0));
    }
    // clearing memory alloced for the stmt
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return true;
}

bool delete_entry(char *date_string, size_t date_len)
{
    // delete(), which will take the date string, use search_db, and delete entry if finds it.
    // returns false if nothing can be found
    return true;
}

// getting endless user input and allocating memory dynamically
char *dynamic_input()
{
    // allocating base memory for the entry string
    char *entry = (char *)(malloc((ENTRY_LEN + 1) * sizeof(char)));
    if (entry == NULL)
    {
        printf("Error allocating initial memory for the entry.\n");
        exit(EXIT_FAILURE);
    }

    int char_counter = 0; // will count every single char of the entry
    // programm will keep count of reallocs and stop at a designated maximum, so that user can't overflow
    // the system with endless text
    int block_counter = 0; // each block is a realloc
    int char_in_block = 0; // counts chars in the realloc block
    int input_tmp = 0;     // saves user input in an int, since EOF is negative

    for (char_counter = 0; block_counter < BLOCKS_MAX; char_counter++)
    {
        // saving user input from stdin in the string
        input_tmp = getchar();
        entry[char_counter] = input_tmp;
        char_in_block++;

        if (input_tmp == EOF)
        {
            // creating null terminated string if EOF
            entry[char_counter] = '\0';
            break;
        }
        else if (char_in_block == ENTRY_LEN)
        {
            // realloc to a buffer just in case the realloc fails
            char *buffer = NULL;
            buffer = realloc(entry, (strlen(entry) + ENTRY_LEN));

            if (buffer == NULL)
            {
                printf("Error reallocating memory for the entry.\n");
                break;
            }

            else
            {
                //since realloc hasn't failed, we can reassign the real deal to the memory
                entry = buffer;
                buffer = NULL;
                // and reset the char counter for the next realloc
                char_in_block = 0;
                block_counter++;
            }
        }
        if (block_counter == BLOCKS_MAX - 1 && char_in_block == ENTRY_LEN - 1)
        {
            entry[char_counter] = '\0';
            printf("You've reached the entry input limit.");
            break;
        }
    }
    return entry;
}