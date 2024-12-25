#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "conversor_unid_potencia.h" // Incluindo o cabeçalho de conversão de potência.
#include "MODULO_OPERACAO_POTENCIA.h"

#define OPERACOES 6      // Número de operações disponíveis no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para a interface.
#define COLUNAS_TELA 80  // Largura fixa para o terminal.

void limpaTela() {
    system("clear || cls");
}

// Protótipos de funções
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void operacoesPotencia(int escolha);
void menuConversorPotencia();



char leOpcao() {
    struct termios oldt, newt;
    char ch;

    // Configura o terminal para leitura sem buffer.
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == '\033') {
        char seq[2];
        read(STDIN_FILENO, seq, 2);
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': ch = 'w'; break; // Seta para cima
                case 'B': ch = 's'; break; // Seta para baixo
                case 'C': ch = 'd'; break; // Seta para direita
                case 'D': ch = 'a'; break; // Seta para esquerda
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void exibeTelaSelecao(int escolha, char *menuExibicao[]) {
    limpaTela();
    printf("--------- MENU DE CONVERSÃO DE POTÊNCIA ---------\n");
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

void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado) {
    limpaTela();
    printf("--------- %s ---------\n", nomeOperacao);
    printf("Entrada: %s\n", entrada);
    printf("Resultado: %s\n", resultado);
    printf("\nDigite um valor e pressione 'D' para calcular, ou 'A' para voltar.\n");
}

void operacoesPotencia(int escolha) {
    char entrada[50] = "";  // Buffer para o valor digitado.
    char resultado[50] = "Aguardando...";
    char tecla;
    int posicao = 0;

    char *menuExibicao[OPERACOES] = {
        "Watts para Kilowatts",
        "Watts para Cavalos-Vapor",
        "Kilowatts para Watts",
        "Kilowatts para Cavalos-Vapor",
        "Cavalos-Vapor para Watts",
        "Cavalos-Vapor para Kilowatts"
    };

    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
            double valorEntrada = atof(entrada);
            double valorResultado = 0.0;
            return_code_potencia status;

            switch (escolha) {
                case 0:
                    status = watts_para_kilowatts(valorEntrada, &valorResultado);
                    break;
                case 1:
                    status = watts_para_cv(valorEntrada, &valorResultado);
                    break;
                case 2:
                    status = kilowatts_para_watts(valorEntrada, &valorResultado);
                    break;
                case 3:
                    status = kilowatts_to_cv(valorEntrada, &valorResultado);
                    break;
                case 4:
                    status = cv_para_watts(valorEntrada, &valorResultado);
                    break;
                case 5:
                    status = cv_para_kilowatts(valorEntrada, &valorResultado);
                    break;
                default:
                    status = ERROR;
            }

            if (status == SUCESSFUL_OPERATION) {
                snprintf(resultado, sizeof(resultado), "%.2f", valorResultado);
            } else {
                snprintf(resultado, sizeof(resultado), "Erro na conversão!");
            }
        } else if (tecla == 'a' || tecla == 'A') {
            return;
        }
    }
}

void menuConversorPotencia() {
    char *composicaoMenu[OPERACOES + 1] = {
        "Watts para Kilowatts",
        "Watts para Cavalos-Vapor",
        "Kilowatts para Watts",
        "Kilowatts para Cavalos-Vapor",
        "Cavalos-Vapor para Watts",
        "Cavalos-Vapor para Kilowatts",
        "Sair"
    };

    int escolhaTemp = 0;
    char leitura;

    while (1) {
        exibeTelaSelecao(escolhaTemp, composicaoMenu);

        leitura = leOpcao();

        switch (leitura) {
            case 'w':
            case 'W':
                escolhaTemp = (escolhaTemp - 1 + OPERACOES) % (OPERACOES + 1);
                break;
            case 's':
            case 'S':
                escolhaTemp = (escolhaTemp + 1) % (OPERACOES + 1);
                break;
            case 'd':
            case 'D':
                if (escolhaTemp == OPERACOES) {
                    return;
                } else {
                    operacoesPotencia(escolhaTemp);
                }
                break;
            case 'a':
            case 'A':
                return;
            default:
                continue;
        }
    }
}
