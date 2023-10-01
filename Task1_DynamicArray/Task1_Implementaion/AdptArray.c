#include "AdptArray.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Define the structure of the AdptArray
struct AdptArray_ {
    // The array of elements
    PElement *arr;
    // The size of the elements in the array
    int size_arr;
    // Pointer to the source copy function
    COPY_FUNC copyFunc;
    // Pointer to the source delete function
    DEL_FUNC delFunc;
    // Pointer to the source print function
    PRINT_FUNC printFunc;
};

// Create a new AdptArray instance
PAdptArray CreateAdptArray(COPY_FUNC copyFunc, DEL_FUNC delFunc, PRINT_FUNC printFunc) {
    // Check if all the required functions were provided
    if (copyFunc == NULL || delFunc == NULL || printFunc == NULL) {
        // Error handling: Functions pointers must be provided
        return NULL;
    }

    // Allocate memory for the AdptArray object
    PAdptArray adptArray = (PAdptArray)malloc(sizeof(struct AdptArray_));
    if (!adptArray) {
        // Error handling: Memory allocation failed
        return NULL;
    }

    // Allocate memory for the dynamic array of elements
    adptArray->arr = (PElement *)calloc(0, sizeof(PElement));
    if (!adptArray->arr) {
        // Error handling: Memory allocation failed
        free(adptArray);
        return NULL;
    }

    // Initialize AdptArray properties
    adptArray->copyFunc = copyFunc;
    adptArray->delFunc = delFunc;
    adptArray->printFunc = printFunc;
    adptArray->size_arr = 0;

    return adptArray;
}

// Delete an AdptArray and its elements
void DeleteAdptArray(PAdptArray adptArray) {
    for (int i = 0; i < adptArray->size_arr; i++) {
        if (adptArray->arr[i] != NULL) {
            adptArray->delFunc(adptArray->arr[i]);
        }
    }
    free(adptArray->arr);
    free(adptArray);
}

// Set an element at a specific index in the AdptArray
Result SetAdptArrayAt(PAdptArray adptArray, int index, PElement element) {
    // Check if the array at the specified index exists
    if (adptArray->size_arr >= index) {
        // Check if the index space is occupied
        if (adptArray->arr[index] != NULL) {
            // Delete the old element to make room for the new element
            adptArray->delFunc(adptArray->arr[index]);
            adptArray->size_arr -= 1;
        }
        // Copy the new element and insert it into the array
        adptArray->arr[index] = adptArray->copyFunc(element);
        adptArray->size_arr += 1;
        return SUCCESS;
    } else {
        // Reallocate memory to increase the array's size
        adptArray->arr = (PElement *)realloc(adptArray->arr, sizeof(PElement) * (index + 1));
        if (!adptArray->arr) {
            // Error handling: Memory allocation failed
            return FAIL;
        }
        // Copy the new element and insert it into the array
        adptArray->arr[index] = adptArray->copyFunc(element);
        adptArray->size_arr = index + 1;
        return SUCCESS;
    }
}

// Get an element at a specific index in the AdptArray
PElement GetAdptArrayAt(PAdptArray adptArray, int index) {
    if ((index < adptArray->size_arr) && (adptArray->arr[index] != NULL)) {
        return adptArray->copyFunc(adptArray->arr[index]);
    }
    return NULL;
}

// Get the size of the AdptArray
int GetAdptArraySize(PAdptArray adptArray) {
    if (adptArray->arr == NULL) {
        return -1;
    }
    return adptArray->size_arr;
}

// Print the elements of the AdptArray
void PrintDB(PAdptArray adptArray) {
    for (int i = 0; i < adptArray->size_arr; i++) {
        if (adptArray->arr[i] != NULL) {
            adptArray->printFunc(adptArray->arr[i]);
        }
    }
}
