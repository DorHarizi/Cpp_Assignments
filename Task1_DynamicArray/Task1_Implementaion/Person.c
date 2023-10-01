#ifndef PERSON_H
#define PERSON_H
#include "AdptArray.h"

// Define a structure for representing a person
typedef struct PERSON_ {
    char *first_name;
    char *last_name;
    int id;
} person, *pperson;

// Function to copy a person
PElement copy_person(PElement original);

// Function to delete a person
void delete_person(PElement to_del);

// Function to print a person
void print_person(PElement b_);

// Function to create a new person
pperson create_person(char* first_name, char* last_name, int id);

#endif
