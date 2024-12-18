/*
* Made by: Jorge Palma
* Date:    18/12/2024
* Project Embarcatech - First activite in group
*
* File: Temperature.c
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
return_code_temp_t celsius_to_kelvin(double celsius)
{
    return 0.0;
}

// Converts Fahrenheit to Celsius
return_code_temp_t fahrenheit_to_celsius(double fahrenheit)
{
    return 0.0;
}

// Converts Fahrenheit to Kelvin
return_code_temp_t fahrenheit_to_kelvin(double fahrenheit)
{
    return 0.0;
}

// Converts Kelvin to Celsius
return_code_temp_t kelvin_to_celsius(double kelvin)
{
    return 0.0;
}

// Converts Kelvin to Fahrenheit
return_code_temp_t kelvin_to_fahrenheit(double kelvin)
{
    return 0.0;
}
