/**
 * @file temperature.c
 * @brief Implementação de funções para conversão de temperaturas entre Celsius, Fahrenheit e Kelvin.
 *
 * Este módulo realiza conversões entre as seguintes escalas de temperatura:
 * - Celsius
 * - Fahrenheit
 * - Kelvin
 * As funções validam os valores de entrada para evitar cálculos abaixo do zero absoluto.
 */

#include <stdio.h>
#include "temperature.h"

/**
 * @brief Converte Celsius para Fahrenheit.
 *
 * Fórmula: Fahrenheit = (Celsius * 9/5) + 32
 *
 * @param celsius Valor em Celsius a ser convertido.
 * @param fahrenheit Ponteiro para armazenar o resultado em Fahrenheit.
 * @return Código de status da conversão.
 */
return_code_temp_t celsius_to_fahrenheit(double celsius, double *fahrenheit) {
    if (fahrenheit == NULL) {
        return CONVERSION_FAILED;
    }
    if (celsius < -273.15) {
        return CONVERSION_INVALID_VALUE;
    }

    *fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return CONVERSION_OK;
}

/**
 * @brief Converte Celsius para Kelvin.
 *
 * Fórmula: Kelvin = Celsius + 273.15
 *
 * @param celsius Valor em Celsius a ser convertido.
 * @param kelvin Ponteiro para armazenar o resultado em Kelvin.
 * @return Código de status da conversão.
 */
return_code_temp_t celsius_to_kelvin(double celsius, double *kelvin) {
    if (kelvin == NULL) {
        return CONVERSION_FAILED;
    }
    if (celsius < -273.15) {
        return CONVERSION_INVALID_VALUE;
    }

    *kelvin = celsius + 273.15;
    return CONVERSION_OK;
}

/**
 * @brief Converte Fahrenheit para Celsius.
 *
 * Fórmula: Celsius = (Fahrenheit - 32) * 5/9
 *
 * @param fahrenheit Valor em Fahrenheit a ser convertido.
 * @param celsius Ponteiro para armazenar o resultado em Celsius.
 * @return Código de status da conversão.
 */
return_code_temp_t fahrenheit_to_celsius(double fahrenheit, double *celsius) {
    if (celsius == NULL) {
        return CONVERSION_FAILED;
    }
    if (fahrenheit < -459.67) {
        return CONVERSION_INVALID_VALUE;
    }

    *celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return CONVERSION_OK;
}

/**
 * @brief Converte Fahrenheit para Kelvin.
 *
 * Fórmula: Kelvin = (Fahrenheit + 459.67) * 5/9
 *
 * @param fahrenheit Valor em Fahrenheit a ser convertido.
 * @param kelvin Ponteiro para armazenar o resultado em Kelvin.
 * @return Código de status da conversão.
 */
return_code_temp_t fahrenheit_to_kelvin(double fahrenheit, double *kelvin) {
    if (kelvin == NULL) {
        return CONVERSION_FAILED;
    }
    if (fahrenheit < -459.67) {
        return CONVERSION_INVALID_VALUE;
    }

    *kelvin = (fahrenheit + 459.67) * 5.0 / 9.0;
    return CONVERSION_OK;
}

/**
 * @brief Converte Kelvin para Celsius.
 *
 * Fórmula: Celsius = Kelvin - 273.15
 *
 * @param kelvin Valor em Kelvin a ser convertido.
 * @param celsius Ponteiro para armazenar o resultado em Celsius.
 * @return Código de status da conversão.
 */
return_code_temp_t kelvin_to_celsius(double kelvin, double *celsius) {
    if (celsius == NULL) {
        return CONVERSION_FAILED;
    }
    if (kelvin < 0.0) {
        return CONVERSION_INVALID_VALUE;
    }

    *celsius = kelvin - 273.15;
    return CONVERSION_OK;
}

/**
 * @brief Converte Kelvin para Fahrenheit.
 *
 * Fórmula: Fahrenheit = (Kelvin * 9/5) - 459.67
 *
 * @param kelvin Valor em Kelvin a ser convertido.
 * @param fahrenheit Ponteiro para armazenar o resultado em Fahrenheit.
 * @return Código de status da conversão.
 */
return_code_temp_t kelvin_to_fahrenheit(double kelvin, double *fahrenheit) {
    if (fahrenheit == NULL) {
        return CONVERSION_FAILED;
    }
    if (kelvin < 0.0) {
        return CONVERSION_INVALID_VALUE;
    }

    *fahrenheit = (kelvin * 9.0 / 5.0) - 459.67;
    return CONVERSION_OK;
}
