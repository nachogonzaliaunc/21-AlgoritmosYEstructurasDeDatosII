/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_helpers.h"

company_t get_company_enum(char *c){
    company_t res;
    if (strcmp(c,"META") == 0) res = META;
    if (strcmp(c,"TSLA") == 0) res = TSLA;
    if (strcmp(c,"MSFT") == 0) res = MSFT;
    if (strcmp(c,"MELI") == 0) res = MELI;
    return res;
}

char* get_company_string(company_t c){
    char *res;
    if (c == META) res = "META";
    if (c == TSLA) res = "TSLA";
    if (c == MSFT) res = "MSFT";
    if (c == MELI) res = "MELI";
    return res;
}


void array_dump(StockTable t){
    for (company_t c = META; c <= MELI; ++c) {
        for (unsigned int j = 0u; j < NR_STOCKS; ++j) {
        Stock s = t[c][j];
        fprintf(stdout, "symbol:%s date:%u-%u-%u open:%.2f high:%.2f low:%.2f close:%.2f adj:%.2f vol:%u\n",
                get_company_string(c),s.year,s.month,s.day, s.open, s.high, s.low, s.close, s.adj, s.vol);
        }
    }
    fprintf(stdout,"\n"); 
}

price avg_close_price(company_t c, StockTable t){
    price res = 0;
    for(unsigned int i = 0; i < NR_STOCKS; i++) { res += t[c][i].close; }
    return (res / NR_STOCKS);
}

volume max_volume(company_t c, StockTable t){
    volume res = t[c][0].vol;

    for(unsigned int i = 1; i < NR_STOCKS; i++) {
        if(res < t[c][i].vol) res = t[c][i].vol;
    }

    return res;
}

void array_from_file(StockTable table, const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    
    unsigned int readlines = 0u;
    while (!feof(file)) {
        char symbol[4];
        unsigned round;
        company_t c;

        int res = fscanf(file, " %s %u ", symbol, &round);
        if (res != 2) {
        fprintf(stderr, "1-Invalid stock data.\n");
        exit(EXIT_FAILURE);
        }

        c = get_company_enum(symbol);
        Stock stock_res = stock_from_file(file);
        // storage in array
        table[c][round-1] = stock_res;

        readlines++;
    }
    // only 10 rounds per company
    if(readlines != NR_STOCKS*NR_COMPANY) {
        fprintf(stderr, "Invalid data: must be 10 rounds, 4 companies.\n");
        exit(EXIT_FAILURE);
    }        

    fclose(file);
}
