#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

#define MAX_SIZE 1000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* calculate array length and read the values inside the file */
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    /* sort the letters to make the phrase */
    sort_letters(indexes, letters, sorted, length);

    /* dump the phrase */
    dump(sorted, length);
    return EXIT_SUCCESS;
}
