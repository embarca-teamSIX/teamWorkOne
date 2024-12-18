#ifndef CONVERSOR_H
#define CONVERSOR_H

// Funções de conversão
double metroParaCentimetro(double metro);
double metroParaMilimetro(double metro);
double centimetroParaMetro(double centimetro);
double milimetroParaMetro(double milimetro);

#endif


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
