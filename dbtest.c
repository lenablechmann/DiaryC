#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
    // Schema for the table:
    // CREATE TABLE entry (time INTEGER PRIMARY KEY ASC, day INTEGER NOT NULL, month INTEGER NOT NULL, year INTEGER NOT NULL, entry TEXT NOT NULL, keywords TEXT DEFAULT NULL);

    // Opening the diary database (sqlite3 should be installed)
    sqlite3 *db;
    int result = sqlite3_open("diary.db", &db);

    // Checking it opened successfully (is not 0)
    if (result)
    {
        printf("Can't open database \n");
        sqlite3_close(db);
        return 0;
    }

    // using prepared statements v2 (v3 is for special occasions according to doco)
    // prepare_v2 helps you avoid sql injections https://www.sqlite.org/c3ref/prepare.html

    sqlite3_stmt *stmt;
    int err = sqlite3_prepare_v2(db, "INSERT INTO entry VALUES(?, ?, ?, ?, ?, ?)", -1, &stmt, NULL);
    if (err != SQLITE_OK)
        {
            printf("Sql statement failed. %s \n", sqlite3_errmsg(db));
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 0;
        }
    // binding values (time, day, month, year, entry):
    sqlite3_bind_int(stmt, 1, 1345);
    sqlite3_bind_int(stmt, 2, 21);
    sqlite3_bind_int(stmt, 3, 11);
    sqlite3_bind_int(stmt, 4, 2020);
    sqlite3_bind_text(stmt, 5, "just testing away.", -1, NULL);
    sqlite3_bind_null(stmt, 6);

    // Inserts values into table via step
    sqlite3_step(stmt);
    // clearing memory alloced for the stmt
    sqlite3_finalize(stmt);

    // same story with update sql.
    // now off to delete rows  DELETE FROM table WHERE day
    sqlite3_close(db);
}