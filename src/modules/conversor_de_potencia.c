/*
 * @file conversor_de_potencia.c
 * @brief Módulo de funções para conversão de unidades de potência.
 *
 * Este módulo contém funções para realizar conversões entre as unidades de potência:
 * - Watts (W)
 * - Quilowatts (kW)
 * - Cavalo-Vapor (CV)
 */

#include <stdlib.h>
#include "conversor_unid_potencia.h"

/**
 * @brief Converte Watts para Quilowatts.
 *
 * @param watts Valor em Watts a ser convertido.
 * @param kilowatts Ponteiro para armazenar o resultado em Quilowatts.
 * @return Código de retorno indicando o status da conversão.
 */
return_code_potencia watts_para_kilowatts(double watts, double *kilowatts) {
    if (kilowatts == NULL) {
        return ERROR;
    }
    if (watts < 0) {
        return INVALID_INPUT;
    }

    *kilowatts = watts / 1000.0;
    return SUCESSFUL_OPERATION;
}

/**
 * @brief Converte Watts para Cavalo-Vapor.
 *
 * @param watts Valor em Watts a ser convertido.
 * @param cv Ponteiro para armazenar o resultado em Cavalo-Vapor.
 * @return Código de retorno indicando o status da conversão.
 */
return_code_potencia watts_para_cv(double watts, double *cv) {
    if (cv == NULL) {
        return ERROR;
    }
    if (watts < 0) {
        return INVALID_INPUT;
    }

    *cv = watts / 735.5;
    return SUCESSFUL_OPERATION;
}

/**
 * @brief Converte Quilowatts para Watts.
 *
 * @param kilowatts Valor em Quilowatts a ser convertido.
 * @param watts Ponteiro para armazenar o resultado em Watts.
 * @return Código de retorno indicando o status da conversão.
 */
return_code_potencia kilowatts_para_watts(double kilowatts, double *watts) {
    if (watts == NULL) {
        return ERROR;
    }
    if (kilowatts < 0) {
        return INVALID_INPUT;
    }

    *watts = kilowatts * 1000.0;
    return SUCESSFUL_OPERATION;
}

/**
 * @brief Converte Quilowatts para Cavalo-Vapor.
 *
 * @param kilowatts Valor em Quilowatts a ser convertido.
 * @param cv Ponteiro para armazenar o resultado em Cavalo-Vapor.
 * @return Código de retorno indicando o status da conversão.
 */
return_code_potencia kilowatts_to_cv(double kilowatts, double *cv) {
    if (cv == NULL) {
        return ERROR;
    }
    if (kilowatts < 0) {
        return INVALID_INPUT;
    }

    *cv = kilowatts / 0.7355;
    return SUCESSFUL_OPERATION;
}

/**
 * @brief Converte Cavalo-Vapor para Watts.
 *
 * @param cv Valor em Cavalo-Vapor a ser convertido.
 * @param watts Ponteiro para armazenar o resultado em Watts.
 * @return Código de retorno indicando o status da conversão.
 */
return_code_potencia cv_para_watts(double cv, double *watts) {
    if (watts == NULL) {
        return ERROR;
    }
    if (cv < 0) {
        return INVALID_INPUT;
    }

    *watts = cv * 735.5;
    return SUCESSFUL_OPERATION;
}

/**
 * @brief Converte Cavalo-Vapor para Quilowatts.
 *
 * @param cv Valor em Cavalo-Vapor a ser convertido.
 * @param kilowatts Ponteiro para armazenar o resultado em Quilowatts.
 * @return Código de retorno indicando o status da conversão.
 */
return_code_potencia cv_para_kilowatts(double cv, double *kilowatts) {
    if (kilowatts == NULL) {
        return ERROR;
    }
    if (cv < 0) {
        return INVALID_INPUT;
    }

    *kilowatts = cv * 0.7355;
    return SUCESSFUL_OPERATION;
}
