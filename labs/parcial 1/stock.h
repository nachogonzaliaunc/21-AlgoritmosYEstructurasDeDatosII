/*
  @file stock.h
  @brief Defines stocks prices 
*/

#ifndef _STOCK_H
#define _STOCK_H
#define EXPECTED_ROW_FORMAT " %u-%u-%u %f %f %f %f %f %u "

typedef float price;
typedef unsigned int volume;
typedef unsigned int natural;


#include <stdio.h>

/** @brief Type used to represent stock data.*/
/*Year-Month-Day,Open,High,Low,Close,Adj Close,Volume*/
typedef struct _stock {
    natural year;
    natural month;
    natural day;
    price open;
    price high;
    price low;
    price close;
    price adj;
    volume vol;
} Stock;

/**
 * @brief reads stock data from file line
 * @details
 * Stock file line must contain:
 * <unsigned int>-<unsigned int>-<unsigned int>,<float>,<float>,<float>,<float>,<float>,<unsigned int>
 *
 * @param[in] file Opened file stream
 * @return Stock structure which contains read information from file
 */
Stock stock_from_file(FILE* file);

#endif //_STOCK_H
