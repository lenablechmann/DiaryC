// a realloc prototype to polish up the write function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ENTRY_LEN 2
#define BLOCKS_MAX 6

char * dynamic_input();

int main(void)
{
    char * user_entry;

    user_entry = dynamic_input();
    puts(user_entry);
    return 0;

}

char * dynamic_input()
{
    // allocating base memory for the entry string
    char *entry = (char *)(malloc((ENTRY_LEN + 1) * sizeof(char)));
    if (entry == NULL)
    {
        printf("Error allocating initial memory for the entry.\n");
        return false;
    }
    printf("Write away (CTRL + D to save the entry and exit):\n");

   int char_counter = 0; // will count every single char of the entry
   // programm will keep count of reallocs and stop at a designated maximum, so that user can't overflow
   // the system with endless text
   int block_counter = 0; // each block is a realloc
   int char_in_block = 0; // counts chars in the realloc block
   int input_tmp = 0; // saves user input in an int, since EOF is negative

    for(char_counter = 0; block_counter < BLOCKS_MAX; char_counter++)
    {
        // saving user input from stdin in the string
        input_tmp = getchar();
        entry[char_counter] = input_tmp;
        char_in_block++;

        if(input_tmp == EOF)
        {
            // creating null terminated string if EOF
            entry[char_counter] = '\0';
            break;
        }
        else if(char_in_block == ENTRY_LEN)
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
        if(block_counter == BLOCKS_MAX - 1 && char_in_block == ENTRY_LEN - 1)
        {
            entry[char_counter] = '\0';
            printf("You've reached the entry input limit.");
            break;
        }
    }
    return entry;
}