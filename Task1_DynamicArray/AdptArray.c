#include "AdptArray.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct AdptArray_{
    //The arr of the elements
    PElement  *arr;
    //The size of the elements in the arr
    int size_arr;
    //pointer on the source copy function
    COPY_FUNC  copyFunc;
    //pointer on the source delete function
    DEL_FUNC delFunc;
    //pointer on the source print function
    PRINT_FUNC printFunc;
};

PAdptArray CreateAdptArray(COPY_FUNC copyFunc, DEL_FUNC delFunc,PRINT_FUNC printFunc){
    //First we check if all the functions were accepted
    if(copyFunc == NULL || delFunc == NULL || printFunc == NULL){
//        printf("Error: You need to input the pointers of the functions to create AdptArray");
        return NULL;
    }
    //allocate memory for object PAdptArray
    PAdptArray  adptArray = (PAdptArray) malloc(sizeof(struct AdptArray_));
    //Check if malloc function allocated memory
    if (!adptArray){
//        printf("error malloc function please try again");
        return NULL;
    }
    //allocate memory for dynamic array for the element's
    adptArray->arr = (PElement*) calloc(0, sizeof(PElement));
    //Check if calloc function allocated memory
    if(!adptArray->arr){
//        printf("error calloc function please try again");
        return NULL;
    }

    adptArray->copyFunc = copyFunc;
    adptArray->delFunc = delFunc;
    adptArray->printFunc = printFunc;
    adptArray->size_arr = 0;

    return adptArray;
}
void DeleteAdptArray(PAdptArray adptArray){
    for(int i = 0; i<adptArray->size_arr; i++){
        if(adptArray->arr[i] != NULL){
            adptArray->delFunc(adptArray->arr[i]);
        }
    }
    free(adptArray->arr);
    free(adptArray);
}

Result SetAdptArrayAt(PAdptArray adptArray, int index, PElement element){
    //Check if the array in the index (place that user want to put the element) space in the array is exsit
    if(adptArray->size_arr >= index){
        //Check if index space is catch
        if(adptArray->arr[index] != NULL){
            //Delete the old element for the new element
            adptArray->delFunc(adptArray->arr[index]);
            adptArray->size_arr -= 1;
        }
        //Copy the new element and insert him to the array
        adptArray->arr[index] = adptArray->copyFunc(element);
        adptArray->size_arr += 1;
//        printf("The insert of the element successful:\n");
//        adptArray->printFunc(adptArray->arr[index]);
        return SUCCESS;
    }
    else{
        //realloc function increase the cells in the array and copy the old element's to the new array
        //and release the old array from the memory
        adptArray->arr = (PElement*) realloc(adptArray->arr, sizeof(PElement) * (index + 1));
        //Check if realloc function allocated memory
        if(!adptArray->arr){
//            printf("error realloc function please try again");
            return FAIL;
        }
        //Copy the new element and insert him to the array
        adptArray->arr[index] = adptArray->copyFunc(element);
        adptArray->size_arr = index + 1;
//        printf("The insert of the element successful:\n");
//        adptArray->printFunc(adptArray->arr[index]);
        return SUCCESS;
        }
}

PElement GetAdptArrayAt(PAdptArray adptArray, int index){
    if ((index < adptArray->size_arr) && (adptArray->arr[index] != NULL)){
        return adptArray->copyFunc(adptArray->arr[index]);
    }
    return NULL;
}

int GetAdptArraySize(PAdptArray adptArray){
    if (adptArray->arr == NULL){return -1;}
    return adptArray->size_arr;
}

void PrintDB(PAdptArray adptArray){
//    printf("The adptArray element's:\n");
    for(int i = 0; i<adptArray->size_arr; i++){
        if(adptArray->arr[i] != NULL){
            adptArray->printFunc(adptArray->arr[i]);
        }
    }
}



