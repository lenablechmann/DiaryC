An offline command line diary app written in C which will take user input and save it into a local SQLite table.
![diary_in_action](diary.gif)

# Features
- no need to navigate menus, everything can be done in one command using simple words
- You can write your entry, read it and delete it if necessary
- It's possible to write multiple entries throughout the day then read them in one go
- everything is saved into your local database file, that is completely offline
- there is a built in sql-injection protection as well as checking user command input for plausibility
  
# Installation and dependencies
- sqlite3 is required for this diary (should come preinstalled if you are using linux)
- to install it on linux, download the git repository, run makefile, put the diary file into the `/home/"yourusername"/.local/bin/` folder, then you should be able to run it from your command line anywhere, the db will be saved to home


# How to use
Once installed, you can input the following in your command line/terminal:

`diary write today`

or

`diary w today`

from here on out you will be able to input your diary entry. 

To end your entry press `CTRL+D`

The entry will be saved to SQLite database and the program will close automatically. You can write for the same day multiple times a day no problem.

To read the entry of the day, input:

`diary read today` 
or 
`diary r today`

To delete the entry for the day (if you so choose):
`diary delete today` or `diary d today`

You can also write, edit and delete entries of other days. Possible date inputs are
`today`

`yesterday`

`DD.MM.YYYY`  like `2.11.2020` (a common European date format)

# Future feature ideas
- making inputs for future dates not acceptable (except for "tomorrow") 
- adding the MM/DD/YYYY date format
- adding text statistics
  - streak
  - how many words per entry
  - "grade level" kinda like Hemingway App
- back up of the database
- add keywords (possibly another table)
