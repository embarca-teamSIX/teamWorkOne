/*
 * @file temperature.h
 * @brief Declarações de funções para conversões de temperatura.
 *
 * Este arquivo contém as definições e protótipos das funções responsáveis por realizar
 * conversões entre as escalas de temperatura Celsius, Fahrenheit e Kelvin.
 *
 * @author Jorge Palma
 * @date 18/12/2024
 * @project Embarcatech - Primeira atividade em grupo
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

/**
 * @enum return_code_temp_t
 * @brief Códigos de retorno para as funções de conversão de temperatura.
 *
 * Valores possíveis:
 * - `CONVERSION_OK`: Conversão realizada com sucesso.
 * - `CONVERSION_FAILED`: Falha genérica na conversão.
 * - `CONVERSION_INVALID_VALUE`: Valor inválido fornecido para conversão.
 */
typedef enum 
{
    CONVERSION_OK = 0x00,          /**< Conversão bem-sucedida. */
    CONVERSION_FAILED = 0x01,     /**< Falha na conversão. */
    CONVERSION_INVALID_VALUE = 0x02 /**< Valor de entrada inválido. */
} return_code_temp_t;

/**
 * @brief Converte Celsius para Fahrenheit.
 *
 * @param celsius Valor em Celsius a ser convertido.
 * @param fahrenheit Ponteiro para armazenar o resultado em Fahrenheit.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_temp_t celsius_to_fahrenheit(double celsius, double *fahrenheit);

/**
 * @brief Converte Celsius para Kelvin.
 *
 * @param celsius Valor em Celsius a ser convertido.
 * @param kelvin Ponteiro para armazenar o resultado em Kelvin.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_temp_t celsius_to_kelvin(double celsius, double *kelvin);

/**
 * @brief Converte Fahrenheit para Celsius.
 *
 * @param fahrenheit Valor em Fahrenheit a ser convertido.
 * @param celsius Ponteiro para armazenar o resultado em Celsius.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_temp_t fahrenheit_to_celsius(double fahrenheit, double *celsius);

/**
 * @brief Converte Fahrenheit para Kelvin.
 *
 * @param fahrenheit Valor em Fahrenheit a ser convertido.
 * @param kelvin Ponteiro para armazenar o resultado em Kelvin.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_temp_t fahrenheit_to_kelvin(double fahrenheit, double *kelvin);

/**
 * @brief Converte Kelvin para Celsius.
 *
 * @param kelvin Valor em Kelvin a ser convertido.
 * @param celsius Ponteiro para armazenar o resultado em Celsius.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_temp_t kelvin_to_celsius(double kelvin, double *celsius);

/**
 * @brief Converte Kelvin para Fahrenheit.
 *
 * @param kelvin Valor em Kelvin a ser convertido.
 * @param fahrenheit Ponteiro para armazenar o resultado em Fahrenheit.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_temp_t kelvin_to_fahrenheit(double kelvin, double *fahrenheit);

#endif // TEMPERATURE_H
