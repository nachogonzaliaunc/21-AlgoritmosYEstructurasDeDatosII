/*
  @file array_helpers.h
  @brief defines array helpers methods. These methods operates over multidimensional array of prices
*/
#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdbool.h>
#include "stock.h"

#define NR_STOCKS 10
#define NR_COMPANY 4
#define MAX_FILELINES (NR_STOCKS * NR_COMPANY)

typedef enum {META, TSLA, MSFT, MELI} company_t;

typedef Stock StockTable[NR_COMPANY][NR_STOCKS];

/**
 * @brief Given a company symbol as string, returns the enumertion company value.
 * @param[in] c string company symbol  
 * */
company_t get_company_enum(char *c);

/**
 * @brief Given a enumerationj company value, returns the caompany sysmbol as string.
 * @param[in] c enumeration company value  
 * */
char* get_company_string(company_t c);


/**
 * @brief Write the content of the array 't' into stdout.
 * @param[in] t array to dump in stdout
 */
void array_dump(StockTable t);


/**
 * @brief calculates close price average of the company_t c in the StockTable t.
 * @param[in] t array with data
 */
price avg_close_price(company_t c, StockTable t);


/**
 * @brief calculates the maximun volume of the company_t c in the StockTable t.
 * @param[in] t array with data
 */
volume max_volume(company_t c, StockTable t);



/**
 * @brief reads an array of prices information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 * <unsigned int>-<unsigned int>-<unsigned int>,<float>,<float>,<float>,<float>,<float>,<unsigned int>
 *
 *   Those elements are copied into the array 't'.
 *   The dimensions of the array are given by the macros noted above.
 *
 * @param t array which will contain read file
 * @param filepath file with prices data
 */
void array_from_file(StockTable t, const char *filepath);


#endif
