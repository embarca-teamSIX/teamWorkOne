#ifndef MODULO_OPERACAO_MASSA
#define MODULO_OPERACAO_MASSA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "unidade_de_medida.h" // Cabeçalho com as funções de conversão de volume.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "mass_conversion.h" // Cabeçalho com as funções de conversão de massa.

#define OPERACOES 3      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.

void limpaTela();
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void protoOperacoesMassa(int escolha);
void menuProtoMassa();

#endif