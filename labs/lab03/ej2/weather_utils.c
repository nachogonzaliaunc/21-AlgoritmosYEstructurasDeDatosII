#include <stdio.h>
#include <stdlib.h>
#include "weather_utils.h"

int min_hist_temp (WeatherTable a) {
    int min = a[0][0][0]._min_temp;

    for (unsigned int year = 0; year < YEARS; year++) {
        for (unsigned int month = 0; month < MONTHS; month++) {
            for (unsigned int day = 0; day < DAYS; day++) {
                if(a[year][month][day]._min_temp < min) min = a[year][month][day]._min_temp;
            }
        }
    }

    return min;
}


void max_hist_temp (WeatherTable a, int output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++) {
        int max_year = a[year][0][0]._max_temp;
        for (unsigned int month = 0; month < MONTHS; month++) {
            for (unsigned int day = 0; day < DAYS; day++) {
                output[year] = max_year < a[year][month][day]._max_temp
                                    ? a[year][month][day]._max_temp
                                    : max_year;
            }
        }
    }
}


void max_prec_per_month (WeatherTable a, month_t month_with_most_rainfall[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++) {
        int tmp_res = 0;
        for (month_t month = 0; month < MONTHS; month++) {
            int rainfall_count = 0;
            // count the amount of rainfall in this month
            for (unsigned int day = 0; day < DAYS; day++) {
                rainfall_count += a[year][month][day]._rainfall;
            }
            if(tmp_res < rainfall_count) {
                month_with_most_rainfall[year] = month;
                tmp_res = rainfall_count;
            }
        }
    }
}