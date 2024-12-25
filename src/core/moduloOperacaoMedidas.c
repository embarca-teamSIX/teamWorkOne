#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "unidade_de_medida.h" // Cabeçalho com as funções de conversão de volume.
#include "MODULO_OPERACAO_MEDIDAS.h"

#define OPERACOES 6      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.

void limpaTela() {
    system("clear || cls");
}

// Protótipos de funções
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void protoOperacoesVolume(int escolha);
void menuProtoVolume();

int main() {
    menuProtoVolume();
    return 0;
}

char leOpcao() {
    struct termios oldt, newt;
    char ch;

    // Configuração do terminal para leitura de caracteres sem buffer.
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == '\033') {
        char seq[2];
        read(STDIN_FILENO, &seq, 2);
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': ch = 'w'; break; // Cima
                case 'B': ch = 's'; break; // Baixo
                case 'C': ch = 'd'; break; // Direita
                case 'D': ch = 'a'; break; // Esquerda
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void exibeTelaSelecao(int escolha, char *menuExibicao[]) {
    limpaTela();
    printf("--------- MENU ---------\n");
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
    printf("\nDigite um número e pressione 'D' para calcular, 'A' para voltar.\n");
}

void protoOperacoesVolume(int escolha) {
    char entrada[50] = "";  // Buffer para o valor digitado.
    char resultado[50] = "Aguardando...";
    char tecla;
    int posicao = 0;

    char *menuExibicao[OPERACOES] = {
        "Litros para Mililitros",
        "Mililitros para Litros",
        "Litros para Metros Cúbicos",
        "Metros Cúbicos para Litros",
        "Mililitros para Metros Cúbicos",
        "Metros Cúbicos para Mililitros"
    };

    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada(nomeOperacao, entrada, resultado);

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
            exibeTelaEntrada(nomeOperacao, entrada, resultado);
            getchar(); // Espera para o usuário ver o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            return; // Voltar ao menu principal
        }
    }
}

void menuProtoVolume() {
    char *composicaoMenu[OPERACOES + 1] = {
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
                    return; // Sai do programa
                } else {
                    protoOperacoesVolume(escolhaTemp);
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
