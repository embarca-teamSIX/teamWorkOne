#ifndef MODULO_OPERACAO_ARMAZENAMENTO
#define MODULO_OPERACAO_ARMAZENAMENTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "armazenamento.h" // Cabeçalho com as funções de conversão de armazenamento.


void limpaTela();



void exibeTelaSelecao(int escolha, char *menuExibicao[]); 
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
char leOpcao();
void protoOperacoes(int escolha);
void menuProtoArmazenamento();

#endif