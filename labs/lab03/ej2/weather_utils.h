#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"


int min_hist_temp (WeatherTable a);
/*
 * calculate the lowest historical temperature
 */

void max_hist_temp (WeatherTable a, int output[YEARS]);
/*
 * calculates the highest maximum temperature of
 * each year between 1980 and 2016
 */

void max_prec_per_month (WeatherTable a, month_t month_with_most_rainfall[YEARS]);
/*
 * calculates the month with the highest amount of
 * precipitation each year between 1980 and 2016
 */

#endif // WHEATHER_UTILS_H
