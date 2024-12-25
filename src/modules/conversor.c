/**
 * @file conversor.c
 * @brief Implementação de funções para conversão de unidades de comprimento.
 *
 * Este arquivo contém as funções para realizar conversões entre metros, centímetros e milímetros.
 */

#include "conversor.h"
#include <stdlib.h>

/**
 * @brief Converte metros para centímetros.
 *
 * Fórmula: centímetros = metros * 100
 *
 * @param metro Ponteiro para o valor em metros a ser convertido.
 * O resultado será armazenado no mesmo ponteiro.
 */
void metroParaCentimetro(double *metro) {
    if (metro == NULL) {
        return;
    }
    *metro = (*metro) * 100.0;
}

/**
 * @brief Converte metros para milímetros.
 *
 * Fórmula: milímetros = metros * 1000
 *
 * @param metro Ponteiro para o valor em metros a ser convertido.
 * O resultado será armazenado no mesmo ponteiro.
 */
void metroParaMilimetro(double *metro) {
    if (metro == NULL) {
        return;
    }
    *metro = (*metro) * 1000.0;
}

/**
 * @brief Converte centímetros para metros.
 *
 * Fórmula: metros = centímetros / 100
 *
 * @param centimetro Ponteiro para o valor em centímetros a ser convertido.
 * O resultado será armazenado no mesmo ponteiro.
 */
void centimetroParaMetro(double *centimetro) {
    if (centimetro == NULL) {
        return;
    }
    *centimetro = (*centimetro) / 100.0;
}

/**
 * @brief Converte milímetros para metros.
 *
 * Fórmula: metros = milímetros / 1000
 *
 * @param milimetro Ponteiro para o valor em milímetros a ser convertido.
 * O resultado será armazenado no mesmo ponteiro.
 */
void milimetroParaMetro(double *milimetro) {
    if (milimetro == NULL) {
        return;
    }
    *milimetro = (*milimetro) / 1000.0;
}
