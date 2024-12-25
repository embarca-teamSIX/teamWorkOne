#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "temperature.h" // Cabeçalho com as funções de conversão de temperatura.

#define OPERACOES 6 // Número total de operações no menu.
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.

void limpaTela() {
    system("clear || cls");
}

// Protótipos de funções
char leOpcao();
void exibeTelaOperacoes(int escolha, char *menuExibicao[], char *entrada, char *resultado);
void protoOperacoes(int escolha);
void menuProto();

int main() {
    menuProto();
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

    // Restaura a configuração original do terminal.
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void exibeTelaOperacoes(int escolha, char *menuExibicao[], char *entrada, char *resultado) {
    limpaTela();
    int linhaMeio = LINHAS_TELA / 2;

    // Cabeçalho
    printf("--------- MENU ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < OPERACOES) {
            if (i == escolha) {
                printf("> %s <\n", menuExibicao[i]);
            } else {
                printf("  %s\n", menuExibicao[i]);
            }
        } else if (i == linhaMeio - 1) {
            printf("Entrada: %s\n", entrada);
        } else if (i == linhaMeio + 1) {
            printf("Resultado: %s\n", resultado);
        } else {
            printf("\n");
        }
    }
    printf("\nUse as teclas >>W<< e >>S<< para navegar, insira números, pressione 'F' para calcular.\n");
}

void protoOperacoes(int escolha) {
    char entrada[50] = ""; // Buffer para o valor digitado.
    char resultado[50] = "Aguardando..."; // Resultado inicial.
    char tecla;
    int posicao = 0;

    char *menuExibicao[OPERACOES] = {
        "Celsius para Fahrenheit",
        "Celsius para Kelvin",
        "Fahrenheit para Celsius",
        "Fahrenheit para Kelvin",
        "Kelvin para Celsius",
        "Kelvin para Fahrenheit"
    };

    while (1) {
        exibeTelaOperacoes(escolha, menuExibicao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'f' || tecla == 'F') {
            // Realizar a operação com o valor na entrada.
            double valorEntrada = atof(entrada);
            double valorResultado = 0.0;
            return_code_temp_t status;

            switch (escolha) {
                case 0:
                    status = celsius_to_fahrenheit(valorEntrada, &valorResultado);
                    break;
                case 1:
                    status = celsius_to_kelvin(valorEntrada, &valorResultado);
                    break;
                case 2:
                    status = fahrenheit_to_celsius(valorEntrada, &valorResultado);
                    break;
                case 3:
                    status = fahrenheit_to_kelvin(valorEntrada, &valorResultado);
                    break;
                case 4:
                    status = kelvin_to_celsius(valorEntrada, &valorResultado);
                    break;
                case 5:
                    status = kelvin_to_fahrenheit(valorEntrada, &valorResultado);
                    break;
                default:
                    status = CONVERSION_INVALID_VALUE;
            }

            if (status == CONVERSION_OK) {
                snprintf(resultado, sizeof(resultado), "%.2f", valorResultado);
            } else {
                snprintf(resultado, sizeof(resultado), "Valor inválido!");
            }
        } else if (tecla == 'd' || tecla == 'D') {
            return; // Voltar ao menu.
        }
    }
}

void menuProto() {
    char *composicaoMenu[OPERACOES] = {
        "Celsius para Fahrenheit",
        "Celsius para Kelvin",
        "Fahrenheit para Celsius",
        "Fahrenheit para Kelvin",
        "Kelvin para Celsius",
        "Kelvin para Fahrenheit"
    };

    int escolhaTemp = 0;
    char leitura;

    while (1) {
        exibeTelaOperacoes(escolhaTemp, composicaoMenu, "", "Aguardando...");

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
                protoOperacoes(escolhaTemp);
                break;
            default:
                continue;
        }
    }
}
