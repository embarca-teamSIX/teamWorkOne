#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <unistd.h>

//macros
#define OPCOES 7
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.

//modulos das operacoes
#include "MODULO_OPERACAO_TEMP.h"
#include "MODULO_OPERACAO_ARMAZENAMENTO.h"
#include "MODULO_OPERACAO_POTENCIA.h"
#include "MODULO_OPERACAO_MEDIDAS.h"
#include "MODULO_OPERACAO_MASSA.h"
#include "MODULO_OPERACAO_COMPRIMENTO.h"

void limpaTela();
void telaSaida();
void telaInicial();
void exibeMenu(int indiceParaDestaque, char* menuExibicao[]);
void protoOperacoes(int escolhaMenu);
char leOpcao();
void menuLoop();
int main(int argc, char* argv[]);

/**
 * @brief Limpa a tela do terminal.
 *
 * Esta função utiliza o comando do sistema para limpar a tela, 
 * para sistemas Unix-like usa `clear` e no Windows usa `cls`.
 */
void limpaTela() {
    system("clear || cls");
}

/**
 * @brief Exibe a tela de saída do programa.
 *
 * Esta função exibe uma animação de triângulo invertido e, ao final, 
 * exibe a mensagem "See you Space cowboy..." antes de encerrar o programa.
 */
void telaSaida() {
    int altura = (int)(LINHAS_TELA * 0.6); // 60% da altura da tela para o triângulo invertido

    limpaTela();
    printf("\n\n");
    printf("%*sSUB GRUPO 4\n\n", (COLUNAS_TELA / 2) - 8, "");

    for (int linha = altura; linha > 0; linha--) {
        int espacos = (COLUNAS_TELA - (linha * 2)) / 2;
        printf("%*s", espacos, "");

        if (linha == altura) {
            for (int j = 0; j < linha * 2; j++) {
                printf("-");
            }
        } else {
            printf("\\");
            for (int j = 0; j < (linha * 2) - 2; j++) {
                printf(" ");
            }
            printf("/");
        }
        printf("\n");
    }

    for (int linha = altura + 1; linha < LINHAS_TELA - 3; linha++) {
        printf("\n");
    }

    printf("%*sSee you Space cowboy...\n", (COLUNAS_TELA / 2) - 4, "");
    sleep(2);

    exit(0);
}

/**
 * @brief Exibe a tela inicial do programa.
 *
 * Esta função exibe uma animação semelhante à da tela de saída, com um triângulo
 * que desaparece de cima para baixo e a exibição das informações "ILHEUS", "BA" e "2024".
 */
void telaInicial() {
    int altura = (int)(LINHAS_TELA * 0.6);

    limpaTela();
    printf("\n\n");
    printf("%*sSUB GRUPO 4\n", (COLUNAS_TELA / 2) - 8, "");

    for (int i = altura; i > 0; i--) {
        limpaTela();
        printf("\n\n");
        printf("%*sSUB GRUPO 4\n\n\n", (COLUNAS_TELA / 2) - 8, "");

        for (int linha = altura; linha > 0; linha--) {
            int espacos = (COLUNAS_TELA - (linha * 2)) / 2;
            printf("%*s", espacos, "");

            if (linha == altura) {
                for (int j = 0; j < linha * 2; j++) {
                    printf("-");
                }
            } else {
                printf("\\");
                for (int j = 0; j < (linha * 2) - 2; j++) {
                    printf(" ");
                }
                printf("/");
            }
            printf("\n");
        }

        for (int linha = altura + 1; linha < LINHAS_TELA - 3; linha++) {
            printf("\n");
        }
        printf("%*sILHEUS\n", (COLUNAS_TELA / 10), "");
        printf("%*sBA\n", (COLUNAS_TELA / 10), "");
        printf("%*s2024\n", (COLUNAS_TELA / 10), "");

        usleep(1000);
    }

    sleep(2);
}

/**
 * @brief Exibe o menu principal de opções e destaca a opção selecionada.
 *
 * Esta função exibe as opções do menu e destaca a opção selecionada 
 * com os caracteres `> <`, permitindo navegação com as teclas W, S e D.
 *
 * @param indiceParaDestaque Índice da opção atual selecionada.
 * @param menuExibicao Vetor de strings contendo as opções do menu.
 */
void exibeMenu(int indiceParaDestaque, char* menuExibicao[]) {
    limpaTela();
    printf("--------- MENU ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < OPCOES) {
            if (i == indiceParaDestaque) {
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
 * @brief Função principal para processar as operações do menu.
 *
 * Esta função recebe o índice da opção selecionada e chama a função correspondente 
 * para cada tipo de operação. 
 *
 * @param escolhaMenu Índice da opção selecionada no menu.
 */
void protoOperacoes(int escolhaMenu) {
    limpaTela();

    switch (escolhaMenu) {
        case 1:
            menuProtoArmazenamento();
            break;
        case 2:
            menuConversorPotencia();
            break;
        case 3:
            menuProtoVolume();
            break;
        case 4:
            menuProtoMassa();
            break;
        case 5:
            menuProtoTemp();
            break;
        case 6:
            menuProtoComprimento();
            break;
        case 7:
            telaSaida();
            break;
        default:
            break;
    }
}

/**
 * @brief Lê a opção digitada pelo usuário.
 *
 * Esta função captura a tecla pressionada pelo usuário sem precisar pressionar "Enter".
 * A função trata as teclas direcionais para navegação no menu e a tecla 'D' 
 * para selecionar uma opção.
 *
 * @return A tecla pressionada pelo usuário.
 */
char leOpcao() {
    struct termios oldt, newt;
    char ch;

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
                case 'A': ch = 'w'; break;
                case 'B': ch = 's'; break;
                case 'C': ch = 'd'; break;
                case 'D': ch = 'a'; break;
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

/**
 * @brief Função que exibe o menu principal em loop.
 *
 * Esta função fica em um loop exibindo o menu e processando as teclas pressionadas 
 * pelo usuário para navegação e seleção das opções.
 */
void menuLoop() {
    char* listaMenu[OPCOES] = {
        "Unidades de Armazenamento",
        "Unidades de Energia",
        "Unidades de volume",
        "Unidades de massa",
        "Unidades de temperatura",
        "Unidades de comprimento",
        "SAIR"
    };
    int escolhaMomento = 0;
    char leitura;

    while (1) {
        (void)exibeMenu(escolhaMomento, listaMenu);
        leitura = leOpcao();
        switch (leitura) {
            case 'w':
            case 'W':
                escolhaMomento = (escolhaMomento - 1 + OPCOES) % OPCOES;
                break;
            case 's':
            case 'S':
                escolhaMomento = (escolhaMomento + 1) % OPCOES;
                break;
            case 'd':
            case 'D':
                (void)protoOperacoes(escolhaMomento);
                break;
            default:
                continue;
                break;
        }
    }
}

/**
 * @brief Função principal do programa.
 *
 * A função `main` inicia o loop do menu, chamando a função `menuLoop` que controla 
 * a interação com o usuário.
 *
 * @param argc Número de argumentos de linha de comando.
 * @param argv Vetor contendo os argumentos de linha de comando.
 * @return Retorna 0 após a execução.
 */
int main(int argc, char* argv[]) {
    menuLoop();
    return 0;
}
