#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "unidade_de_medida.h" // Cabeçalho com as funções de conversão de volume.
#include "MODULO_OPERACAO_MEDIDAS.h"
#include "utils.h"

#define MEDIDAS_OPERACOES 6      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.



void exibeTelaSelecao_MEDIDAS(int escolha, char *menuExibicao[]) {
    limpaTela();
    printf("--------- MENU ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < MEDIDAS_OPERACOES) {
            if (i == escolha) {
                printf("> %s <\n", menuExibicao[i]);
            } else {
                printf("  %s\n", menuExibicao[i]);
            }
        } else {
            printf("\n");
        }
    }
    printf("\nUse as teclas >>W<< para subir, >>S<< para descer, >>D<< para selecionar.\n");
    printf("Pressione 'A' para sair.\n");
}

void exibeTelaEntrada_MEDIDAS(char *nomeOperacao, char *entrada, char *resultado) {
    limpaTela();
    printf("--------- %s ---------\n", nomeOperacao);
    printf("Entrada: %s\n", entrada);
    printf("Resultado: %s\n", resultado);
    printf("\nDigite um número e pressione 'D' para calcular, 'A' para voltar.\n");
}

void protoOperacoesVolume_MEDIDAS(int escolha) {
    char entrada[50] = "";  // Buffer para o valor digitado.
    char resultado[50] = "Aguardando...";
    char tecla;
    int posicao = 0;

    char *menuExibicao[MEDIDAS_OPERACOES] = {
        "Litros para Mililitros",
        "Mililitros para Litros",
        "Litros para Metros Cúbicos",
        "Metros Cúbicos para Litros",
        "Mililitros para Metros Cúbicos",
        "Metros Cúbicos para Mililitros"
    };

    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada_MEDIDAS(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
            float valorEntrada = atof(entrada);

            switch (escolha) {
                case 0:
                    converterLitrosParaMililitros(valorEntrada);
                    snprintf(resultado, sizeof(resultado), "%.2f ml", valorEntrada);
                    break;
                case 1:
                    converterMililitrosParaLitros(valorEntrada);
                    snprintf(resultado, sizeof(resultado), "%.2f L", valorEntrada);
                    break;
                case 2:
                    converterLitrosParaMetrosCubicos(valorEntrada);
                    snprintf(resultado, sizeof(resultado), "%.6f m³", valorEntrada);
                    break;
                case 3:
                    converterMetrosCubicosParaLitros(valorEntrada);
                    snprintf(resultado, sizeof(resultado), "%.2f L", valorEntrada);
                    break;
                case 4:
                    converterMililitrosParaMetrosCubicos(valorEntrada);
                    snprintf(resultado, sizeof(resultado), "%.6f m³", valorEntrada);
                    break;
                case 5:
                    converterMetrosCubicosParaMililitros(valorEntrada);
                    snprintf(resultado, sizeof(resultado), "%.2f ml", valorEntrada);
                    break;
                default:
                    snprintf(resultado, sizeof(resultado), "Erro na operação.");
                    continue;
            }
            exibeTelaEntrada_MEDIDAS(nomeOperacao, entrada, resultado);
            getchar(); // Espera para o usuário ver o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            return; // Voltar ao menu principal
        }
    }
}

void menuProtoVolume_MEDIDAS() {
    char *composicaoMenu[MEDIDAS_OPERACOES + 1] = {
        "Litros para Mililitros",
        "Mililitros para Litros",
        "Litros para Metros Cúbicos",
        "Metros Cúbicos para Litros",
        "Mililitros para Metros Cúbicos",
        "Metros Cúbicos para Mililitros",
        "Sair"
    };

    int escolhaTemp = 0;
    char leitura;

    while (1) {
        exibeTelaSelecao_MEDIDAS(escolhaTemp, composicaoMenu);

        leitura = leOpcao();

        switch (leitura) {
            case 'w':
            case 'W':
                escolhaTemp = (escolhaTemp - 1 + MEDIDAS_OPERACOES) % (MEDIDAS_OPERACOES + 1);
                break;
            case 's':
            case 'S':
                escolhaTemp = (escolhaTemp + 1) % (MEDIDAS_OPERACOES + 1);
                break;
            case 'd':
            case 'D':
                if (escolhaTemp == MEDIDAS_OPERACOES) {
                    return; // Sai do programa
                } else {
                    protoOperacoesVolume_MEDIDAS(escolhaTemp);
                }
                break;
            case 'a':
            case 'A':
                return; // Sai do programa
            default:
                continue;
        }
    }
}
