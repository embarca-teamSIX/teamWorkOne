#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "temperature.h" // Cabeçalho com as funções de conversão de temperatura.
#include "MODULO_OPERACAO_TEMP.h"

#define OPERACOES 6 // Número total de operações no menu.
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.

void limpaTela() {
    system("clear || cls");
}

// Protótipos de funções
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void protoOperacoes(int escolha);
void menuProto();

int main() {
    menuProto();
    return 0;
}

char leOpcao() {
    struct termios oldt, newt;// Declara duas estruturas 'termios', que armazenam configurações do terminal.
    char ch;

    // Configuração do terminal para leitura de caracteres sem buffer.
    tcgetattr(STDIN_FILENO, &oldt);// Pega as configurações atuais do terminal (stdin) e armazena em 'oldt'.
    newt = oldt; // Copia as configurações atuais para 'newt', que será modificado.
    newt.c_lflag &= ~(ICANON | ECHO);// Modifica a configuração de 'newt' para desabilitar o modo canônico (entrada linha por linha) e o eco (não mostrar o caractere digitado).
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);// Aplica as novas configurações ao terminal de forma imediata (TCSANOW).

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
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);// Restaura as configurações do terminal para o estado original, que foram armazenadas em 'oldt'.

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
    printf("\nDigite um número e pressione 'D' para calcular, 'A' para voltar.\n");
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

    // O nome da operação selecionada
    char *nomeOperacao = menuExibicao[escolha];

    while (1) {
        exibeTelaEntrada(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
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

            exibeTelaEntrada(nomeOperacao, entrada, resultado); // Exibe o resultado final
            getchar(); // Espera para que o usuário veja o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            // Voltar ao menu de seleção de operações
            return; // Volta ao menu
        }
    }
}

void menuProtoTemp() {
    char *composicaoMenu[OPERACOES + 1] = { // Adicionando a opção de sair
        "Celsius para Fahrenheit",
        "Celsius para Kelvin",
        "Fahrenheit para Celsius",
        "Fahrenheit para Kelvin",
        "Kelvin para Celsius",
        "Kelvin para Fahrenheit",
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
                    // Se a opção "Sair" for selecionada
                    return; // Encerra o programa
                } else {
                    protoOperacoes(escolhaTemp); // Seleciona a operação
                }
                break;
            case 'a':
            case 'A':
                return; // Encerra o programa quando 'A' for pressionado no menu principal
            default:
                continue;
        }
    }
}
