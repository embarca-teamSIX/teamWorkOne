/*
main/
    |->menu para selecionar
    |->funções de loop para interação visual
    |                   |->apos função ser selecionada 
    |                   |-> iniciar subfunções para interface de iteração
    |                   |   da opção desejada EX: interface de ler re retornar valor 
    |                   |   convertido de cms para kms ou Cº para Fº
    |                   |-> em caso de erro retornar status do erro e não encerrar
    |->implementar foward e backward entre os sub menus
    
*/

#include <stdio.h>
#include <stdlib.h>

// Include libs in this space
#include "includes/temperature.h"

void tests_temperature_lib();

int main()
{

    // tests_temperature_lib();

    return 0;    
}

// void tests_temperature_lib()
// {
//     /* Init tests with the temperature conversion */
//     // Creating variables
//     double temperature_value;
//     double temperature_response;
//     return_code_temp_t response;
    
//     // Celsius to fahrenheit
//     temperature_value = 30.0;
//     response = celsius_to_fahrenheit(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     temperature_value = -300.0;
//     response = celsius_to_fahrenheit(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     // Celsius to kelvin
//     temperature_value = 30.0;
//     response = celsius_to_kelvin(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Kelvin: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     temperature_value = -300.0;
//     response = celsius_to_kelvin(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Kelvin: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     // Fahrenheit to Celsius
//     temperature_value = 30.0;
//     response = fahrenheit_to_celsius(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Celsius: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     temperature_value = -460.00;
//     response = fahrenheit_to_celsius(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Celsius: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     // Fahrenheit to Kelvin
//     temperature_value = 30.0;
//     response = fahrenheit_to_kelvin(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Kelvin: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     temperature_value = -460.00;
//     response = fahrenheit_to_kelvin(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Kelvin: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }


//     // Kelvin to Celsius
//     temperature_value = 30.0;
//     response = kelvin_to_celsius(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Celsius: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     temperature_value = -10;
//     response = kelvin_to_celsius(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Celsius: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     // Kelvin to Fahrenheit
//     temperature_value = 30.0;
//     response = kelvin_to_fahrenheit(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }

//     temperature_value = -10;
//     response = kelvin_to_fahrenheit(temperature_value, &temperature_response);
//     if (response == CONVERSION_OK) {
//         printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
//     } else {
//         printf("Error: Conversion failed.\n");
//     }
// }