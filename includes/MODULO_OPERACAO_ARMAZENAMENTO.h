#ifndef MODULO_OPERACAO_ARMAZENAMENTO
#define MODULO_OPERACAO_ARMAZENAMENTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "armazenamento.h" // Cabeçalho com as funções de conversão de armazenamento.

#include "utils.h"


void exibeTelaSelecao_ARMAZENAMENTO(int escolha, char *menuExibicao[]);
void exibeTelaEntrada_ARMAZENAMENTO(char *nomeOperacao, char *entrada, char *resultado);
void protoOperacoesArmazenamento_ARMAZENAMENTO(int escolha);
void menuProtoArmazenamento_ARMAZENAMENTO();

#endif