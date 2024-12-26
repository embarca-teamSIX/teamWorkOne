#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "temperature.h" // Cabeçalho com as funções de conversão de temperatura.
#include "MODULO_OPERACAO_TEMP.h"
#include "utils.h"

#define OPERACOES 6 // Número total de operações no menu.
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.




/**
 * @brief Exibe a tela de seleção de operações.
 * 
 * Exibe o menu de operações com base na escolha do usuário e permite a navegação 
 * com as teclas W, S para subir e descer, e D para selecionar a opção.
 * 
 * @param escolha A posição atual da escolha do usuário no menu.
 * @param menuExibicao O array contendo as opções de operação para exibição.
 */
void exibeTelaSelecao_TEMP(int escolha, char *menuExibicao[]) {
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

/**
 * @brief Exibe a tela de entrada de dados e resultado da operação.
 * 
 * Exibe a tela para o usuário inserir um valor, realizar a conversão e 
 * visualizar o resultado da operação selecionada.
 * 
 * @param nomeOperacao O nome da operação que está sendo realizada.
 * @param entrada O valor de entrada fornecido pelo usuário.
 * @param resultado O resultado da conversão ou a mensagem de erro.
 */
void exibeTelaEntrada_TEMP(char *nomeOperacao, char *entrada, char *resultado) {
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

/**
 * @brief Realiza a operação de conversão de temperatura com base na escolha do usuário.
 * 
 * Esta função executa a operação de conversão de temperatura selecionada 
 * pelo usuário, realizando o cálculo e exibindo o resultado ou uma mensagem 
 * de erro caso o valor de entrada seja inválido.
 * 
 * @param escolha A escolha da operação que o usuário deseja realizar.
 */
void protoOperacoesTemp_TEMP(int escolha) {
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
        exibeTelaEntrada_TEMP(nomeOperacao, entrada, resultado);

        tecla = leOpcao();

        if (tecla >= '0' && tecla <= '9' && posicao < sizeof(entrada) - 1) {
            entrada[posicao++] = tecla;
            entrada[posicao] = '\0';
        } else if (tecla == 'd' || tecla == 'D') {
            // Realizar a operação com o valor na entrada.
            double valorEntrada = atof(entrada);
            double valorResultado = 0.0;
            temperature_return_code_temp status;

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
                    status = TEMPERATURE_CONVERSION_INVALID_VALUE;
            }

            if (status == TEMPERATURE_CONVERSION_OK) {
                snprintf(resultado, sizeof(resultado), "%.2f", valorResultado);
            } else {
                snprintf(resultado, sizeof(resultado), "Valor inválido!");
            }

            exibeTelaEntrada_TEMP(nomeOperacao, entrada, resultado); // Exibe o resultado final
            getchar(); // Espera para que o usuário veja o resultado
        } else if (tecla == 'a' || tecla == 'A') {
            // Voltar ao menu de seleção de operações
            return; // Volta ao menu
        }
    }
}

/**
 * @brief Exibe o menu principal com as opções de conversão de temperatura.
 * 
 * O menu permite ao usuário navegar entre as opções de conversão de temperatura 
 * e sair do programa. As teclas de navegação são W, S para subir e descer, 
 * e D para selecionar a opção.
 */
void menuProtoTemp_TEMP() {
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
        exibeTelaSelecao_TEMP(escolhaTemp, composicaoMenu);

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
                    protoOperacoesTemp_TEMP(escolhaTemp); // Seleciona a operação
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
