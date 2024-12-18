#include <stdio.h>
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
            printf("Resultado: %.2f cm\n", metroParaCentimetro(valor));
            break;
        case 2:
            printf("Resultado: %.2f mm\n", metroParaMilimetro(valor));
            break;
        case 3:
            printf("Resultado: %.2f m\n", centimetroParaMetro(valor));
            break;
        case 4:
            printf("Resultado: %.2f m\n", milimetroParaMetro(valor));
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
