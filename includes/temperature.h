/*
* Made by: Jorge Palma
* Date:    18/12/2024
* Project Embarcatech - First activite in group
*
* File: temperature.h
*/

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

typedef enum 
{
    CONVERSION_OK = 0x00,
    CONVERSION_FAILED = 0x01,
    CONVERSION_INVALID_VALUE = 0x02,
} return_code_temp_t;

// Converts Celsius to Fahrenheit
return_code_temp_t celsius_to_fahrenheit(double celsius, double *fahrenheit);

// Converts Celsius to Kelvin
return_code_temp_t celsius_to_kelvin(double celsius, double *kelvin);

// Converts Fahrenheit to Celsius
return_code_temp_t fahrenheit_to_celsius(double fahrenheit, double *celsius);

// Converts Fahrenheit to Kelvin
return_code_temp_t fahrenheit_to_kelvin(double fahrenheit, double *kelvin);

// Converts Kelvin to Celsius
return_code_temp_t kelvin_to_celsius(double kelvin, double *celsius);

// Converts Kelvin to Fahrenheit
return_code_temp_t kelvin_to_fahrenheit(double kelvin, double *fahrenheit);

#endif // TEMPERATURE_H