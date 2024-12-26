#ifndef ARMAZENAMENTO_H
#define ARMAZENAMENTO_H

/**
 * @file armazenamento.h
 * @brief Declarações de funções para conversão de unidades de armazenamento digital.
 *
 * Este arquivo contém as definições de funções utilizadas para converter valores
 * entre diferentes unidades de medida de armazenamento digital, como bits, bytes, 
 * kilobytes, megabytes, gigabytes e terabytes. 
 *
 * Cada função retorna um código indicando o status da conversão, utilizando o enum `return_code_data`.
 *
 * @author [Seu Nome]
 * @date [Data de Criação]
 */

/**
 * @enum return_code_data
 * @brief Códigos de retorno para operações de conversão.
 *
 * Valores possíveis:
 * - `CONVERSION_OK`: Conversão realizada com sucesso.
 * - `CONVERSION_INVALID_VALUE`: Valor de entrada inválido.
 */
typedef enum {
    ARMAZENAMENTO_CONVERSION_OK = 0x00,           /**< Conversão realizada com sucesso. */
    ARMAZENAMENTO_CONVERSION_INVALID_VALUE = 0x01 /**< Valor de entrada inválido. */
} armazenamento_return_code_data;

/**
 * @brief Converte bits para bytes.
 *
 * @param numero String representando o valor em bits.
 * @param resultado Ponteiro para armazenar o resultado em bytes.
 * @return Código de retorno indicando sucesso ou falha na conversão.
 */
armazenamento_return_code_data bit_to_byte(char numero[], char *resultado);

/**
 * @brief Converte bits para kilobytes.
 *
 * @param numero String representando o valor em bits.
 * @param resultado Ponteiro para armazenar o resultado em kilobytes.
 * @return Código de retorno indicando sucesso ou falha na conversão.
 */
armazenamento_return_code_data bit_to_kb(char numero[], char *resultado);

/**
 * @brief Converte bits para megabytes.
 *
 * @param numero String representando o valor em bits.
 * @param resultado Ponteiro para armazenar o resultado em megabytes.
 * @return Código de retorno indicando sucesso ou falha na conversão.
 */
armazenamento_return_code_data bit_to_mb(char numero[], char *resultado);

/**
 * @brief Converte bits para gigabytes.
 *
 * @param numero String representando o valor em bits.
 * @param resultado Ponteiro para armazenar o resultado em gigabytes.
 * @return Código de retorno indicando sucesso ou falha na conversão.
 */
armazenamento_return_code_data bit_to_gb(char numero[], char *resultado);

/**
 * @brief Converte bits para terabytes.
 *
 * @param numero String representando o valor em bits.
 * @param resultado Ponteiro para armazenar o resultado em terabytes.
 * @return Código de retorno indicando sucesso ou falha na conversão.
 */
armazenamento_return_code_data bit_to_tb(char numero[], char *resultado);
armazenamento_return_code_data byte_to_bit(char numero[], char *resultado);
armazenamento_return_code_data byte_to_kb(char numero[], char *resultado);
armazenamento_return_code_data byte_to_mb(char numero[], char *resultado);
armazenamento_return_code_data byte_to_gb(char numero[], char *resultado);
armazenamento_return_code_data byte_to_tb(char numero[], char *resultado);

armazenamento_return_code_data kb_to_bit(char numero[], char *resultado);
armazenamento_return_code_data kb_to_byte(char numero[], char *resultado);
armazenamento_return_code_data kb_to_mb(char numero[], char *resultado);
armazenamento_return_code_data kb_to_gb(char numero[], char *resultado);
armazenamento_return_code_data kb_to_tb(char numero[], char *resultado);

armazenamento_return_code_data mb_to_bit(char numero[], char *resultado);
armazenamento_return_code_data mb_to_byte(char numero[], char *resultado);
armazenamento_return_code_data mb_to_kb(char numero[], char *resultado);
armazenamento_return_code_data mb_to_gb(char numero[], char *resultado);
armazenamento_return_code_data mb_to_tb(char numero[], char *resultado);

armazenamento_return_code_data gb_to_bit(char numero[], char *resultado);
armazenamento_return_code_data gb_to_byte(char numero[], char *resultado);
armazenamento_return_code_data gb_to_kb(char numero[], char *resultado);
armazenamento_return_code_data gb_to_mb(char numero[], char *resultado);
armazenamento_return_code_data gb_to_tb(char numero[], char *resultado);

armazenamento_return_code_data tb_to_bit(char numero[], char *resultado);
armazenamento_return_code_data tb_to_byte(char numero[], char *resultado);
armazenamento_return_code_data tb_to_kb(char numero[], char *resultado);
armazenamento_return_code_data tb_to_mb(char numero[], char *resultado);
armazenamento_return_code_data tb_to_gb(char numero[], char *resultado);

#endif // ARMAZENAMENTO_H
