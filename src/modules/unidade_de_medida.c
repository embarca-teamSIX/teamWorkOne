#include <stdio.h>
#include "unidade_de_medida.h"
void converterLitrosParaMililitros(float litros) {
    printf("%.2f Litros = %.2f Mililitros\n", litros, litros * 1000);
}

void converterMililitrosParaLitros(float mililitros) {
    printf("%.2f Mililitros = %.2f Litros\n", mililitros, mililitros / 1000);
}

void converterLitrosParaMetrosCubicos(float litros) {
    printf("%.2f Litros = %.6f Metros Cubicos\n", litros, litros / 1000);
}

void converterMetrosCubicosParaLitros(float metrosCubicos) {
    printf("%.6f Metros Cubicos = %.2f Litros\n", metrosCubicos, metrosCubicos * 1000);
}

void converterMililitrosParaMetrosCubicos(float mililitros) {
    printf("%.2f Mililitros = %.6f Metros Cubicos\n", mililitros, mililitros / 1000000);
}

void converterMetrosCubicosParaMililitros(float metrosCubicos) {
    printf("%.6f Metros Cubicos = %.2f Mililitros\n", metrosCubicos, metrosCubicos * 1000000);
}

