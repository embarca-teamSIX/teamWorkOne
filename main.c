#include <stdio.h>
#include <stdlib.h>
#include "conversor.h"

int main() {

    system("chcp 65001>nul");
    
    double valor = 0.0;
    int opcao;

    printf("Escolha a conversão:\n");
    printf("1 - Metro para Centímetro\n");
    printf("2 - Metro para Milímetro\n");
    printf("3 - Centímetro para Metro\n");
    printf("4 - Milímetro para Metro\n");
    scanf("%d", &opcao);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    switch (opcao) {
        case 1:
            metroParaCentimetro(&valor);
            printf("Resultado: %.2f cm\n", valor);
            break;
        case 2:
            metroParaMilimetro(&valor);
            printf("Resultado: %.2f mm\n", valor);
            break;
        case 3:
            centimetroParaMetro(&valor);
            printf("Resultado: %.2f m\n", valor);
            break;
        case 4:
            milimetroParaMetro(&valor);
            printf("Resultado: %.2f m\n", valor);
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
