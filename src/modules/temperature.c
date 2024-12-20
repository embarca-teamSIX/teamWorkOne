/*
* Made by: Jorge Palma
* Date:    18/12/2024
* Project Embarcatech - First activity in group
*
* File: temperature.c
*/

#include <stdio.h>
#include "temperature.h"

// Converts Celsius to Fahrenheit
return_code_temp_t celsius_to_fahrenheit(double celsius, double *fahrenheit)
{
    if (celsius < -273.15) {
        printf("Error: Temperature below absolute zero in Celsius.\n");
        return CONVERSION_INVALID_VALUE;
    }

    *fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return CONVERSION_OK;
}

// Converts Celsius to Kelvin
return_code_temp_t celsius_to_kelvin(double celsius, double *kelvin)
{
    if (celsius < -273.15) {
        printf("Error: Temperature below absolute zero in Celsius.\n");
        return CONVERSION_INVALID_VALUE;
    }

    *kelvin = celsius + 273.15;
    return CONVERSION_OK;
}

// Converts Fahrenheit to Celsius
return_code_temp_t fahrenheit_to_celsius(double fahrenheit, double *celsius)
{
    if (fahrenheit < -459.67) {
        printf("Error: Temperature below absolute zero in Fahrenheit.\n");
        return CONVERSION_INVALID_VALUE;
    }

    *celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return CONVERSION_OK;
}

// Converts Fahrenheit to Kelvin
return_code_temp_t fahrenheit_to_kelvin(double fahrenheit, double *kelvin)
{
    if (fahrenheit < -459.67) {
        printf("Error: Temperature below absolute zero in Fahrenheit.\n");
        return CONVERSION_INVALID_VALUE;
    }

    *kelvin = (fahrenheit + 459.67) * 5.0 / 9.0;
    return CONVERSION_OK;
}

// Converts Kelvin to Celsius
return_code_temp_t kelvin_to_celsius(double kelvin, double *celsius)
{
    if (kelvin < 0.0) {
        printf("Error: Temperature below absolute zero in Kelvin.\n");
        return CONVERSION_INVALID_VALUE;
    }

    *celsius = kelvin - 273.15;
    return CONVERSION_OK;
}

// Converts Kelvin to Fahrenheit
return_code_temp_t kelvin_to_fahrenheit(double kelvin, double *fahrenheit)
{
    if (kelvin < 0.0) {
        printf("Error: Temperature below absolute zero in Kelvin.\n");
        return CONVERSION_INVALID_VALUE;
    }

    *fahrenheit = (kelvin * 9.0 / 5.0) - 459.67;
    return CONVERSION_OK;
}