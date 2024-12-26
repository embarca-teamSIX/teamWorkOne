#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "armazenamento.h" // Cabeçalho com as funções de conversão de armazenamento.
#include "MODULO_OPERACAO_ARMAZENAMENTO.h"
#include "utils.h"


#define OPERACOES 20 // Número total de operações de conversão.
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.

void exibeTelaSelecao_ARMAZENAMENTO(int escolha, char *menuExibicao[]) {
    limpaTela();
    printf("--------- MENU DE CONVERSÃO ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < OPERACOES) {
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

void exibeTelaEntrada_ARMAZENAMENTO(char *nomeOperacao, char *entrada, char *resultado) {
    limpaTela();
    int linhaMeio = LINHAS_TELA / 2;
    int linhaNome = linhaMeio - 1;
    int linhaEntrada = linhaMeio;
    int linhaResultado = linhaMeio + 1;

    printf("--------- %s ---------\n", nomeOperacao);
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i == linhaNome) {
            printf("%s\n", nomeOperacao);  // Exibe o nome da operação.
        } else if (i == linhaEntrada) {
            printf("Entrada: %s\n", entrada);  // Exibe o valor de entrada.
        } else if (i == linhaResultado) {
            printf("Resultado: %s\n", resultado);  // Exibe o resultado.
        } else {
            printf("\n");
        }
    }
    printf("\nDigite um valor e pressione 'D' para calcular, 'A' para voltar.\n");
}



void protoOperacoesArmazenamento_ARMAZENAMENTO(int escolha) {
    char entrada[50] = ""; // Buffer para o valor digitado.
    char resultado[50] = "Aguardando..."; // Resultado inicial.
    char tecla;
    int posicao = 0;

    // Definir operações de conversão
    char *menuExibicao[OPERACOES] = {
        "Bits para Bytes",
        "Bits para Kilobytes",
        "Bits para Megabytes",
        "Bits para Gigabytes",
        "Bits para Terabytes",
        "Bytes para Bits",
        "Bytes para Kilobytes",
        "Bytes para Megabytes",
        "Bytes para Gigabytes",
        "Bytes para Terabytes",
        "Kilobytes para Bits",
        "Kilobytes para Bytes",
        "Kilobytes para Megabytes",
        "Kilobytes para Gigabytes",
        "Kilobytes para Terabytes",
        "Megabytes para Bits",
        "Megabytes para Bytes",
        "Megabytes para Kilobytes",
        "Megabytes para Gigabytes",
        "Megabytes para Terabytes"
    };

    // O nome da operação selecionada
    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada_ARMAZENAMENTO(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
            // Realizar a operação com o valor na entrada.
            armazenamento_return_code_data status;

            switch (escolha) {
                     case 0: 
                    status = bit_to_byte(entrada, resultado); break;
                case 1: 
                    status = bit_to_kb(entrada, resultado); break;
                case 2: 
                    status = bit_to_mb(entrada, resultado); break;
                case 3: 
                    status = bit_to_gb(entrada, resultado); break;
                case 4: 
                    status = bit_to_tb(entrada, resultado); break;
                case 5: 
                    status = byte_to_bit(entrada, resultado); break;
                case 6: 
                    status = byte_to_kb(entrada, resultado); break;
                case 7: 
                    status = byte_to_mb(entrada, resultado); break;
                case 8: 
                    status = byte_to_gb(entrada, resultado); break;
                case 9: 
                    status = byte_to_tb(entrada, resultado); break;
                case 10: 
                    status = kb_to_bit(entrada, resultado); break;
                case 11: 
                    status = kb_to_byte(entrada, resultado); break;
                case 12: 
                    status = kb_to_mb(entrada, resultado); break;
                case 13: 
                    status = kb_to_gb(entrada, resultado); break;
                case 14: 
                    status = kb_to_tb(entrada, resultado); break;
                case 15: 
                    status = mb_to_bit(entrada, resultado); break;
                case 16: 
                    status = mb_to_byte(entrada, resultado); break;
                case 17: 
                    status = mb_to_kb(entrada, resultado); break;
                case 18: 
                    status = mb_to_gb(entrada, resultado); break;
                case 19: 
                    status = mb_to_tb(entrada, resultado); break;
                case 20: 
                    status = gb_to_bit(entrada, resultado); break;
                case 21: 
                    status = gb_to_byte(entrada, resultado); break;
                case 22: 
                    status = gb_to_kb(entrada, resultado); break;
                case 23: 
                    status = gb_to_mb(entrada, resultado); break;
                case 24: 
                    status = gb_to_tb(entrada, resultado); break;
                case 25: 
                    status = tb_to_bit(entrada, resultado); break;
                case 26: 
                    status = tb_to_byte(entrada, resultado); break;
                case 27: 
                    status = tb_to_kb(entrada, resultado); break;
                case 28: 
                    status = tb_to_mb(entrada, resultado); break;
                case 29: 
                    status = tb_to_gb(entrada, resultado); break;
                default:
                    status = ARMAZENAMENTO_CONVERSION_INVALID_VALUE;
            }

            if (status == ARMAZENAMENTO_CONVERSION_OK) {
                snprintf(resultado, sizeof(resultado), "%.2f", atof(resultado));
            } else {
                snprintf(resultado, sizeof(resultado), "Valor inválido!");
            }

            exibeTelaEntrada_ARMAZENAMENTO(nomeOperacao, entrada, resultado); // Exibe o resultado final
            getchar(); // Espera para que o usuário veja o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            // Voltar ao menu de seleção de operações
            return; // Volta ao menu
        }
    }
}

void menuProtoArmazenamento_ARMAZENAMENTO() {
    char *composicaoMenu[OPERACOES] = { // Removendo a opção "Sair"
        "Bits para Bytes",
        "Bits para Kilobytes",
        "Bits para Megabytes",
        "Bits para Gigabytes",
        "Bits para Terabytes",
        "Bytes para Bits",
        "Bytes para Kilobytes",
        "Bytes para Megabytes",
        "Bytes para Gigabytes",
        "Bytes para Terabytes",
        "Kilobytes para Bits",
        "Kilobytes para Bytes",
        "Kilobytes para Megabytes",
        "Kilobytes para Gigabytes",
        "Kilobytes para Terabytes",
        "Megabytes para Bits",
        "Megabytes para Bytes",
        "Megabytes para Kilobytes",
        "Megabytes para Gigabytes",
        "Megabytes para Terabytes"
    };

    int escolhaTemp = 0;
    char leitura;

    while (1) {
        exibeTelaSelecao_ARMAZENAMENTO(escolhaTemp, composicaoMenu);

        leitura = leOpcao();

        switch (leitura) {
            case 'w':
            case 'W':
                escolhaTemp = (escolhaTemp - 1 + OPERACOES) % OPERACOES;
                break;
            case 's':
            case 'S':
                escolhaTemp = (escolhaTemp + 1) % OPERACOES;
                break;
            case 'd':
            case 'D':
                protoOperacoesArmazenamento_ARMAZENAMENTO(escolhaTemp); // Seleciona a operação
                break;
            case 'a':
            case 'A':
                return; // Encerra o programa quando 'A' for pressionado
            default:
                continue;
        }
    }
}

