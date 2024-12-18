//main
#include <stdio.h>

// Include libs in this space
#include "temperature.h"

int main()
{
    /* Init tests with the temperature convertion */
    double temperature_value;
    double temperature_response;
    return_code_temp_t response;

    temperature_value = 30.0;  // 30 degrees Celsius
    response = celsius_to_fahrenheit(temperature_value, &temperature_response);

    // Verificação do código de retorno
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    return 0;
}