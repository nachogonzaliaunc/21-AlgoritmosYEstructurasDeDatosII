/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array with the type of tclimate */
    WeatherTable array;

    /* parse the file to fill the array and obtain the actual length */
    array_from_file(array, filepath);

    /* show the ordered array in the screen */
    array_dump(array);

    /* calculate the lowest historical temperature */
    int min = min_hist_temp(array);
    printf("\nthe lowest historical temperature is: %.1f°C\n\n", (float)min/10);

    /* calculates the highest maximum temperature of each year */
    int output[YEARS];
    max_hist_temp(array, output);
    /* dump the results */
    for (unsigned int year = 0; year < YEARS; year++) {
        printf("maximum temperature of %u: %.1f°C\n", year+1980, (float)output[year]/10);
    }
    printf("\n");

    /* calculates the month with the highest amount of precipitation each year */
    month_t month_with_most_rainfall[YEARS];
    max_prec_per_month(array, month_with_most_rainfall);
    /* dump the results */
    for (unsigned int year = 0; year < YEARS; year++) {
        printf("month with most amount of rainfall of %d: %d\n", year+1980, month_with_most_rainfall[year]+1);
    }

    return (EXIT_SUCCESS);
}
