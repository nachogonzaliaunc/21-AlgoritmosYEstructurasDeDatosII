/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000


unsigned int array_from_stdin(int array[], unsigned int max_size) {
    // ask the user for the array length
    unsigned int length = printf("Enter the array length: ");

    // check that the length of the array is within the correct values
    if (fscanf(stdin, "%u", &length) != 1 || length <= 0 || length > max_size) {
        printf("Invalid length\n");
        exit(EXIT_FAILURE); 
    }

    // ask the user for the array values and check if the array lenght its okay
    fprintf(stdout, "Enter the array values: ");
    for (unsigned int i = 0; i < length; i++) {
        if ((fscanf(stdin, "%d", &array[i])) != 1) {
            printf("The length of the array and the number of elements don't match\n"); 
            exit(EXIT_FAILURE);
        }
    }
    // salto de linea para el comando crtl+D
    printf("\n");

    return length;
}


void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length-1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[length-1]);
}


int main() {
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);

    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
