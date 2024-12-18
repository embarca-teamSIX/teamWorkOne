#include "conversor.h"

double metroParaCentimetro(double metro) {
    return metro * 100.0;
}

double metroParaMilimetro(double metro) {
    return metro * 1000.0;
}

double centimetroParaMetro(double centimetro) {
    return centimetro / 100.0;
}

double milimetroParaMetro(double milimetro) {
    return milimetro / 1000.0;
}
