//main
#include <stdio.h>

// Include libs in this space
#include "temperature.h"

void tests_temperature_lib();

int main()
{
    tests_temperature_lib();

    return 0;
}

void tests_temperature_lib()
{
    /* Init tests with the temperature conversion */
    // Creating variables
    double temperature_value;
    double temperature_response;
    return_code_temp_t response;
    
    // Celsius to fahrenheit
    temperature_value = 30.0;
    response = celsius_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -300.0;
    response = celsius_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Celsius to kelvin
    temperature_value = 30.0;
    response = celsius_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -300.0;
    response = celsius_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Fahrenheit to Celsius
    temperature_value = 30.0;
    response = fahrenheit_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -460.00;
    response = fahrenheit_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Fahrenheit to Kelvin
    temperature_value = 30.0;
    response = fahrenheit_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -460.00;
    response = fahrenheit_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }


    // Kelvin to Celsius
    temperature_value = 30.0;
    response = kelvin_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -10;
    response = kelvin_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Kelvin to Fahrenheit
    temperature_value = 30.0;
    response = kelvin_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -10;
    response = kelvin_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }
}