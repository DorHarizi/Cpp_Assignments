#ifndef BOOK_H
#define BOOK_H

#include "AdptArray.h"

// Define a structure named 'book' with two members: 'name' and 'serial_number'
typedef struct BOOK_ {
    char *name;
    int serial_number;
} book, *pbook;

// Function declarations
PElement copy_book(PElement original); // Function to copy a book
void delete_book(PElement to_del);     // Function to delete a book
void print_book(PElement b_);          // Function to print the details of a book
pbook create_book(char *name, int serial_number); // Function to create a new book

#endif
