/**
 * @file unidade_de_medida.c
 * @brief Implementação de funções para conversão entre litros, mililitros e metros cúbicos.
 *
 * Este módulo realiza conversões entre:
 * - Litros (L)
 * - Mililitros (mL)
 * - Metros cúbicos (m³)
 */

#include <stdio.h>
#include "unidade_de_medida.h"

/**
 * @brief Converte litros para mililitros.
 * 
 * Fórmula: mililitros = litros * 1000
 * 
 * @param litros Quantidade em litros a ser convertida.
 */
void converterLitrosParaMililitros(float litros) {
    printf("%.2f Litros = %.2f Mililitros\n", litros, litros * 1000);
}

/**
 * @brief Converte mililitros para litros.
 * 
 * Fórmula: litros = mililitros / 1000
 * 
 * @param mililitros Quantidade em mililitros a ser convertida.
 */
void converterMililitrosParaLitros(float mililitros) {
    printf("%.2f Mililitros = %.2f Litros\n", mililitros, mililitros / 1000);
}

/**
 * @brief Converte litros para metros cúbicos.
 * 
 * Fórmula: metros cúbicos = litros / 1000
 * 
 * @param litros Quantidade em litros a ser convertida.
 */
void converterLitrosParaMetrosCubicos(float litros) {
    printf("%.2f Litros = %.6f Metros Cúbicos\n", litros, litros / 1000);
}

/**
 * @brief Converte metros cúbicos para litros.
 * 
 * Fórmula: litros = metros cúbicos * 1000
 * 
 * @param metrosCubicos Quantidade em metros cúbicos a ser convertida.
 */
void converterMetrosCubicosParaLitros(float metrosCubicos) {
    printf("%.6f Metros Cúbicos = %.2f Litros\n", metrosCubicos, metrosCubicos * 1000);
}

/**
 * @brief Converte mililitros para metros cúbicos.
 * 
 * Fórmula: metros cúbicos = mililitros / 1.000.000
 * 
 * @param mililitros Quantidade em mililitros a ser convertida.
 */
void converterMililitrosParaMetrosCubicos(float mililitros) {
    printf("%.2f Mililitros = %.6f Metros Cúbicos\n", mililitros, mililitros / 1000000);
}

/**
 * @brief Converte metros cúbicos para mililitros.
 * 
 * Fórmula: mililitros = metros cúbicos * 1.000.000
 * 
 * @param metrosCubicos Quantidade em metros cúbicos a ser convertida.
 */
void converterMetrosCubicosParaMililitros(float metrosCubicos) {
    printf("%.6f Metros Cúbicos = %.2f Mililitros\n", metrosCubicos, metrosCubicos * 1000000);
}
