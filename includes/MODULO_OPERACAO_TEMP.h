#ifndef MODULO_OPERACAO_TEMP
#define MODULO_OPERACAO_TEMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "temperature.h" // Cabeçalho com as funções de conversão de temperatura.

#define OPERACOES 6 // Número total de operações no menu.
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.
// Protótipos de funções
void limpaTela();
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void protoOperacoes(int escolha);
void menuProto();
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado) ;
void protoOperacoes(int escolha);
void menuProtoTemp();
   

#endif