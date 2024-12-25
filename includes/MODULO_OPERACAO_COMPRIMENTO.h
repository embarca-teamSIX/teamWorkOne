#ifndef MODULO_OPERACAO_COMPRIMENTO
#define MODULO_OPERACAO_COMPRIMENTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "conversor.h" // Cabeçalho com as funções de conversão de comprimento.

#define OPERACOES 4      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.

void limpaTela();
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado) ;
void protoOperacoesComprimento(int escolha);
void menuProtoComprimento();


#endif