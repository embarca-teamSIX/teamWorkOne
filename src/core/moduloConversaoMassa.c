#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "mass_conversion.h" // Cabeçalho com as funções de conversão de massa.
#include "MODULO_OPERACAO_MASSA.h"
#include "utils.h"

#define MASS_OPERACOES 3      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.



void exibeTelaSelecao_MASS(int escolha, char *menuExibicao[]) {
    limpaTela();
    printf("--------- MENU ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < MASS_OPERACOES) {
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

void exibeTelaEntrada_MASS(char *nomeOperacao, char *entrada, char *resultado) {
    limpaTela();
    printf("--------- %s ---------\n", nomeOperacao);
    printf("Entrada: %s\n", entrada);
    printf("Resultado: %s\n", resultado);
    printf("\nDigite um número e pressione 'D' para calcular, 'A' para voltar.\n");
}

void protoOperacoesMassa_MASS(int escolha) {
    char entrada[50] = "";  // Buffer para o valor digitado.
    char resultado[50] = "Aguardando...";
    char tecla;
    int posicao = 0;

    char *menuExibicao[MASS_OPERACOES] = {
        "Quilogramas para Gramas",
        "Quilogramas para Toneladas",
        "Gramas para Quilogramas"
    };

    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada_MASS(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
            double valorEntrada = atof(entrada);
            double valorResultado = 0.0;
            mass_conversion_status status;

            switch (escolha) {
                case 0:
                    status = kg_to_g(valorEntrada, &valorResultado);
                    break;
                case 1:
                    status = kg_to_ton(valorEntrada, &valorResultado);
                    break;
                case 2:
                    status = g_to_kg(valorEntrada, &valorResultado);
                    break;
                default:
                    status = MASS_CONVERSION_INVALID_VALUE;
            }

            if (status == MASS_CONVERSION_OK) {
                snprintf(resultado, sizeof(resultado), "%.2f", valorResultado);
            } else {
                snprintf(resultado, sizeof(resultado), "Valor inválido!");
            }

            exibeTelaEntrada_MASS(nomeOperacao, entrada, resultado); // Exibe o resultado final
            getchar(); // Espera para que o usuário veja o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            return; // Voltar ao menu principal
        }
    }
}

void menuProtoMassa_MASS() {//entry point aqui
    char *composicaoMenu[MASS_OPERACOES + 1] = {
        "Quilogramas para Gramas",
        "Quilogramas para Toneladas",
        "Gramas para Quilogramas",
        "Sair"
    };

    int escolhaTemp = 0;
    char leitura;

    while (1) {
        exibeTelaSelecao_MASS(escolhaTemp, composicaoMenu);

        leitura = leOpcao();

        switch (leitura) {
            case 'w':
            case 'W':
                escolhaTemp = (escolhaTemp - 1 + MASS_OPERACOES) % (MASS_OPERACOES + 1);
                break;
            case 's':
            case 'S':
                escolhaTemp = (escolhaTemp + 1) % (MASS_OPERACOES + 1);
                break;
            case 'd':
            case 'D':
                if (escolhaTemp == MASS_OPERACOES) {
                    return; // Sai do programa
                } else {
                    protoOperacoesMassa_MASS(escolhaTemp);
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
