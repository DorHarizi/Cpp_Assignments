#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Person.h"

// Function to copy a person
PElement copy_person(PElement original) {
    // Cast the original element to a person pointer
    pperson org = (pperson)original;

    // Allocate memory for the copied person
    pperson cp = (pperson)malloc(sizeof(person));
    if (!cp) return NULL;

    // Allocate memory for the first name string and copy it
    cp->first_name = (char*)malloc(strlen(org->first_name) + 1);
    if (!cp->first_name) {
        free(cp);
        return NULL;
    }
    strcpy(cp->first_name, org->first_name);

    // Allocate memory for the last name string and copy it
    cp->last_name = (char*)malloc(strlen(org->last_name) + 1);
    if (!cp->last_name) {
        free(cp->first_name);
        free(cp);
        return NULL;
    }
    strcpy(cp->last_name, org->last_name);

    // Copy the ID
    cp->id = org->id;

    return cp;
}

// Function to delete a person
void delete_person(PElement to_del) {
    // Cast the element to a person pointer
    pperson p = (pperson)to_del;

    // Free memory for first name, last name, and the person structure
    free(p->first_name);
    free(p->last_name);
    free(p);
}

// Function to print a person
void print_person(PElement p_) {
    // Cast the element to a person pointer
    pperson p = (pperson)p_;

    // Print the person's details
    printf("first name: %s last name: %s id: %d\n", p->first_name, p->last_name, p->id);
}

// Function to create a new person
pperson create_person(char* first_name, char* last_name, int id) {
    // Allocate memory for the person structure
    pperson cp = (pperson)malloc(sizeof(person));
    if (!cp) return NULL;

    // Allocate memory for the first name string and copy it
    cp->first_name = (char*)malloc(strlen(first_name) + 1);
    if (!cp->first_name) {
        free(cp);
        return NULL;
    }
    strcpy(cp->first_name, first_name);

    // Allocate memory for the last name string and copy it
    cp->last_name = (char*)malloc(strlen(last_name) + 1);
    if (!cp->last_name) {
        free(cp->first_name);
        free(cp);
        return NULL;
    }
    strcpy(cp->last_name, last_name);

    // Set the ID
    cp->id = id;

    return cp;
}
