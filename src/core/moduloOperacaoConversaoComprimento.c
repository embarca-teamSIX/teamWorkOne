#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "conversor.h" // Cabeçalho com as funções de conversão de comprimento.
#include "MODULO_OPERACAO_COMPRIMENTO.h"
#include "utils.h"

#define COMPRIMENTO_OPERACOES 4      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.

void exibeTelaSelecao_COMPRIMENTO(int escolha, char *menuExibicao[]) {
    limpaTela();
    printf("--------- MENU ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < COMPRIMENTO_OPERACOES) {
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

void exibeTelaEntrada_COMPRIMENTO(char *nomeOperacao, char *entrada, char *resultado) {
    limpaTela();
    printf("--------- %s ---------\n", nomeOperacao);
    printf("Entrada: %s\n", entrada);
    printf("Resultado: %s\n", resultado);
    printf("\nDigite um número e pressione 'D' para calcular, 'A' para voltar.\n");
}

void protoOperacoesComprimento_COMPRIMENTO(int escolha) {
    char entrada[50] = "";  // Buffer para o valor digitado.
    char resultado[50] = "Aguardando...";
    char tecla;
    int posicao = 0;

    char *menuExibicao[COMPRIMENTO_OPERACOES] = {
        "Metros para Centímetros",
        "Metros para Milímetros",
        "Centímetros para Metros",
        "Milímetros para Metros"
    };

    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada_COMPRIMENTO(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
            double valorEntrada = atof(entrada);
            double valorConvertido = valorEntrada;

            switch (escolha) {
                case 0:
                    metroParaCentimetro(&valorConvertido);
                    break;
                case 1:
                    metroParaMilimetro(&valorConvertido);
                    break;
                case 2:
                    centimetroParaMetro(&valorConvertido);
                    break;
                case 3:
                    milimetroParaMetro(&valorConvertido);
                    break;
                default:
                    snprintf(resultado, sizeof(resultado), "Erro na operação.");
                    continue;
            }

            snprintf(resultado, sizeof(resultado), "%.2f", valorConvertido);
            exibeTelaEntrada_COMPRIMENTO(nomeOperacao, entrada, resultado); // Exibe o resultado final
            getchar(); // Espera para que o usuário veja o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            return; // Voltar ao menu principal
        }
    }
}

void menuProtoComprimento_COMPRIMENTO() {
    char *composicaoMenu[COMPRIMENTO_OPERACOES + 1] = {
        "Metros para Centímetros",
        "Metros para Milímetros",
        "Centímetros para Metros",
        "Milímetros para Metros",
        "Sair"
    };

    int escolhaTemp = 0;
    char leitura;

    while (1) {
        exibeTelaSelecao_COMPRIMENTO(escolhaTemp, composicaoMenu);

        leitura = leOpcao();

        switch (leitura) {
            case 'w':
            case 'W':
                escolhaTemp = (escolhaTemp - 1 + COMPRIMENTO_OPERACOES) % (COMPRIMENTO_OPERACOES + 1);
                break;
            case 's':
            case 'S':
                escolhaTemp = (escolhaTemp + 1) % (COMPRIMENTO_OPERACOES + 1);
                break;
            case 'd':
            case 'D':
                if (escolhaTemp == COMPRIMENTO_OPERACOES) {
                    return; // Sai do programa
                } else {
                    protoOperacoesComprimento_COMPRIMENTO(escolhaTemp);
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
