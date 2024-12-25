#ifndef CONVERSOR_UNID_POTENCIA
#define CONVERSOR_UNID_POTENCIA

/**
 * @file conversor_unid_potencia.h
 * @brief Declarações de funções para conversão de unidades de potência.
 *
 * Este arquivo contém definições de funções para realizar conversões entre 
 * unidades de potência como watts, kilowatts e cavalos-vapor (cv).
 * As funções retornam um código de status indicando sucesso ou falha na operação.
 *
 * @author [Seu Nome]
 * @date [Data de Criação]
 */

/**
 * @enum return_code_potencia
 * @brief Códigos de retorno para operações de conversão de potência.
 *
 * Valores possíveis:
 * - `SUCESSFUL_OPERATION`: Operação realizada com sucesso.
 * - `ERROR`: Erro genérico na operação.
 * - `INVALID_INPUT`: Entrada inválida para a conversão.
 */
typedef enum {
    SUCESSFUL_OPERATION = 0x00, /**< Operação realizada com sucesso. */
    ERROR = 0x01,               /**< Erro genérico na operação. */
    INVALID_INPUT = 0x10        /**< Entrada inválida. */
} return_code_potencia;

/**
 * @brief Converte watts para kilowatts.
 *
 * @param watts Valor em watts a ser convertido.
 * @param kilowatts Ponteiro para armazenar o resultado em kilowatts.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_potencia watts_para_kilowatts(double watts, double *kilowatts);

/**
 * @brief Converte watts para cavalos-vapor (cv).
 *
 * @param watts Valor em watts a ser convertido.
 * @param cv Ponteiro para armazenar o resultado em cavalos-vapor.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_potencia watts_para_cv(double watts, double *cv);

/**
 * @brief Converte kilowatts para watts.
 *
 * @param kilowatts Valor em kilowatts a ser convertido.
 * @param watts Ponteiro para armazenar o resultado em watts.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_potencia kilowatts_para_watts(double kilowatts, double *watts);

/**
 * @brief Converte kilowatts para cavalos-vapor (cv).
 *
 * @param kilowatts Valor em kilowatts a ser convertido.
 * @param cv Ponteiro para armazenar o resultado em cavalos-vapor.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_potencia kilowatts_to_cv(double kilowatts, double *cv);

/**
 * @brief Converte cavalos-vapor (cv) para watts.
 *
 * @param cv Valor em cavalos-vapor a ser convertido.
 * @param watts Ponteiro para armazenar o resultado em watts.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_potencia cv_para_watts(double cv, double *watts);

/**
 * @brief Converte cavalos-vapor (cv) para kilowatts.
 *
 * @param cv Valor em cavalos-vapor a ser convertido.
 * @param kilowatts Ponteiro para armazenar o resultado em kilowatts.
 * @return Código de retorno indicando sucesso ou falha.
 */
return_code_potencia cv_para_kilowatts(double cv, double *kilowatts);

#endif // CONVERSOR_UNID_POTENCIA_H
