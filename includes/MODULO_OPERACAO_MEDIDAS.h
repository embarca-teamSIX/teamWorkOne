#ifndef MODULO_OPERACAO_MEDIDAS
#define MODULO_OPERACAO_MEDIDAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

#include "unidade_de_medida.h" // Cabeçalho com as funções de conversão de volume.

#define OPERACOES 6      // Número total de operações no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80  // Tamanho fixo para largura visual.

void limpaTela();

// Protótipos de funções
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void protoOperacoesVolume(int escolha);
void menuProtoVolume();

char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);

void protoOperacoesVolume(int escolha);
void menuProtoVolume();//entry point

#endif