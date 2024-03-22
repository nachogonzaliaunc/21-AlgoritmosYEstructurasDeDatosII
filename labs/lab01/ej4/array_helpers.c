#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./array_helpers.h"


unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    // Open the file
    FILE *file = fopen(filepath, "r");

    // If there are problems reading the file, the program execution ends
    if (file == NULL) {
        printf("There was an error opening the file\n");
        exit(EXIT_FAILURE);
    }

    // Read the array length and check if its within the correct values
    unsigned int length;

    if (fscanf(file, "%u", &length) != 1 || length > max_size || length == 0) {
        printf("Invalid length\n"); 
        exit(EXIT_FAILURE); 
    }

    // Read the array values and check if the array lenght its okay
    for (unsigned int i = 0; i < length; i++) {
        if ((fscanf(file, "%d", &array[i])) != 1) {
            printf("The length of the array and the number of elements don't match\n"); 
            exit(EXIT_FAILURE); 
        }
    }

    // Close the file
    fclose(file);

    return length;
}


void array_dump(int a[], unsigned int length) {
    printf("%d\n", length);
    printf("[");
    for (unsigned int i = 0; i < length-1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[length-1]);
}


bool array_is_sorted(int a[], unsigned int length) {
    bool res = true;

    for (unsigned int i = 0; i < length-1 && res; i++) {
        if (a[i] > a[i+1]) res = false;
    }

    res
        ? printf("The array is sorted\n")
        : printf("The array is unsorted\n");

    return res;
}