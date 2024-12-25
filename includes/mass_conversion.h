#ifndef MASS_CONVERSION_H
#define MASS_CONVERSION_H

/**
 * @file mass_conversion.h
 * @brief Declarações de funções para conversão de unidades de massa.
 *
 * Este arquivo contém as assinaturas das funções utilizadas para realizar conversões
 * entre as unidades de massa: quilogramas (kg), gramas (g) e toneladas (ton).
 * As funções retornam um código de status para indicar se a conversão foi bem-sucedida ou se ocorreu algum erro.
 *
 * @author [Seu Nome]
 * @date [Data de Criação]
 */

/**
 * @enum conversion_status_t
 * @brief Códigos de status para operações de conversão de massa.
 *
 * - `CONVERSION_OK`: Conversão bem-sucedida.
 * - `CONVERSION_ERROR`: Erro genérico durante a conversão.
 * - `CONVERSION_INVALID_VALUE`: Valor de entrada inválido para a conversão.
 */
typedef enum {
    CONVERSION_OK = 0x00,              /**< Conversão bem-sucedida. */
    CONVERSION_ERROR = 0x01,           /**< Erro genérico durante a conversão. */
    CONVERSION_INVALID_VALUE = 0x02   /**< Valor de entrada inválido. */
} conversion_status_t;

/**
 * @brief Converte quilogramas para gramas.
 *
 * Esta função converte o valor em quilogramas para gramas.
 *
 * @param kg Valor em quilogramas a ser convertido.
 * @param g Ponteiro para armazenar o resultado em gramas.
 * @return Código de status indicando se a conversão foi bem-sucedida ou não.
 */
conversion_status_t kg_to_g(double kg, double *g);

/**
 * @brief Converte quilogramas para toneladas.
 *
 * Esta função converte o valor em quilogramas para toneladas.
 *
 * @param kg Valor em quilogramas a ser convertido.
 * @param ton Ponteiro para armazenar o resultado em toneladas.
 * @return Código de status indicando se a conversão foi bem-sucedida ou não.
 */
conversion_status_t kg_to_ton(double kg, double *ton);

/**
 * @brief Converte gramas para quilogramas.
 *
 * Esta função converte o valor em gramas para quilogramas.
 *
 * @param g Valor em gramas a ser convertido.
 * @param kg Ponteiro para armazenar o resultado em quilogramas.
 * @return Código de status indicando se a conversão foi bem-sucedida ou não.
 */
conversion_status_t g_to_kg(double g, double *kg);

#endif // MASS_CONVERSION_H
