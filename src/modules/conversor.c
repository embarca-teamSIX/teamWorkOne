#include "conversor.h"

// Implementação das funções
void metroParaCentimetro(double *metro) {
    *metro = (*metro) * 100.0;
}

void metroParaMilimetro(double *metro) {
    *metro = (*metro) * 1000.0;
}

void centimetroParaMetro(double *centimetro) {
    *centimetro = (*centimetro) / 100.0;
}

void milimetroParaMetro(double *milimetro) {
    *milimetro = (*milimetro) / 1000.0;
}
