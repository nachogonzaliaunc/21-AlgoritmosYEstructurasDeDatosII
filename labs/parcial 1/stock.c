/*
  @file stock.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "stock.h"

static const int NUMBER_OF_STOCK_VARS = 9;


Stock stock_from_file(FILE* file) {
  Stock stock;  
  int res = fscanf(file, EXPECTED_ROW_FORMAT, &stock.year,
                                              &stock.month,
                                              &stock.day,
                                              &stock.open,
                                              &stock.high,
                                              &stock.low,
                                              &stock.close,
                                              &stock.adj,
                                              &stock.vol);

  if(res != NUMBER_OF_STOCK_VARS) {
    fprintf(stderr, "Invalid data.\n");
    exit(EXIT_SUCCESS);
  }

  return stock;
}
