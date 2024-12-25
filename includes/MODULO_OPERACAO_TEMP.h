#ifndef MODULO_OPERACAO_TEMP
#define MODULO_OPERACAO_TEMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "temperature.h" // Cabeçalho com as funções de conversão de temperatura.

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