An offline command line diary app written in C which will take user input and save it into a local SQLite table.
![diary_in_action](diary.gif)

# Features
- no need to navigate menus, everything can be done in one command using simple words
- You can write your entry, read it and delete it if necessary
- It's possible to write multiple entries throughout the day then read them in one go
- everything is saved into your local database file, that is completely offline
- there is a built in sql-injection protection as well as checking user command input for plausibility
  
# Installation and dependencies
- sqlite3 is required for this diary (might come preinstalled on some linux distributions)
- to install this diary on linux, clone or download the git repository
  1. cd into the DiaryC folder you just cloned `cd DiaryC`
  1. run make inside of it `make`, this should create an executable file
  1. if you want to use the diary and save the database in this very folder, enter `./diary write today`, this way you can hide the folder and the database
  1. If you prefer to make the diary accessable from anywhere on linux, copy the executable `diary`file to the bin folder, where your distribution has all programs installed. `/usr/bin/`on ubuntu and give it an executable permission `sudo chmod 777 diary`
  1. This way, you can use your diary like `diary write today`having a more natural flow.


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
