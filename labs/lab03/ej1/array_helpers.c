#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdio.h>
#include <stdlib.h>

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    unsigned int length = 0;

    // open the file
    FILE *file = fopen(path, "r");
    // check if the file exists
    if(file == NULL) {
        printf("File doesn't exists\n");
        exit(EXIT_FAILURE);
    } 

    // read the file
    for (unsigned int i = 0; i < max_size && !feof(file); i++) {
        if(fscanf(file, "%u -> *%c*", &indexes[i], &letters[i]) == 2) length++;
    }
    // check if the indexes values are correct
    for (unsigned int i = 0; i < length; i++) {
        if (indexes[i] > max_size) {
            printf("ERROR: index value %u are larger than the maximum alowed\n", indexes[i]);
            exit(EXIT_FAILURE);
        }
    }

    // close the file
    fclose(file);

    return length;
}


void sort_letters(unsigned int indexes[], char letters[], char sorted[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        for (unsigned int j = 0; j < length; j++) {
            if(i == indexes[j]) { sorted[i] = letters[j]; }
        }
    }
}


void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

#endif
