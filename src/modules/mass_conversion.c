/**
 * @file mass_conversion.c
 * @brief Implementação de funções para conversão de unidades de massa.
 *
 * Este módulo fornece funções para conversões entre as unidades:
 * - Quilogramas (kg)
 * - Gramas (g)
 * - Toneladas (ton)
 */

#include "mass_conversion.h"
#include <stdlib.h>

/**
 * @brief Converte quilogramas (kg) para gramas (g).
 *
 * Fórmula: g = kg * 1000
 *
 * @param kg Valor em quilogramas a ser convertido.
 * @param g Ponteiro para armazenar o resultado em gramas.
 * @return Código de status indicando sucesso ou falha na conversão.
 */
conversion_status_t kg_to_g(double kg, double *g) {
    if (g == NULL) {
        return CONVERSION_ERROR;
    }
    if (kg < 0) {
        return CONVERSION_INVALID_VALUE;
    }
    *g = kg * 1000.0;
    return CONVERSION_OK;
}

/**
 * @brief Converte quilogramas (kg) para toneladas (ton).
 *
 * Fórmula: ton = kg / 1000
 *
 * @param kg Valor em quilogramas a ser convertido.
 * @param ton Ponteiro para armazenar o resultado em toneladas.
 * @return Código de status indicando sucesso ou falha na conversão.
 */
conversion_status_t kg_to_ton(double kg, double *ton) {
    if (ton == NULL) {
        return CONVERSION_ERROR;
    }
    if (kg < 0) {
        return CONVERSION_INVALID_VALUE;
    }
    *ton = kg / 1000.0;
    return CONVERSION_OK;
}

/**
 * @brief Converte gramas (g) para quilogramas (kg).
 *
 * Fórmula: kg = g / 1000
 *
 * @param g Valor em gramas a ser convertido.
 * @param kg Ponteiro para armazenar o resultado em quilogramas.
 * @return Código de status indicando sucesso ou falha na conversão.
 */
conversion_status_t g_to_kg(double g, double *kg) {
    if (kg == NULL) {
        return CONVERSION_ERROR;
    }
    if (g < 0) {
        return CONVERSION_INVALID_VALUE;
    }
    *kg = g / 1000.0;
    return CONVERSION_OK;
}
