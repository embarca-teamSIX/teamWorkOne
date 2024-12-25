#ifndef MODULO_OPERACAO_POTENCIA
#define MODULO_OPERACAO_POTENCIA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "conversor_unid_potencia.h" // Incluindo o cabeçalho de conversão de potência.

#define OPERACOES 6      // Número de operações disponíveis no menu.
#define LINHAS_TELA 30   // Número mínimo de linhas para a interface.
#define COLUNAS_TELA 80  // Largura fixa para o terminal.

void limpaTela();
char leOpcao();
void exibeTelaSelecao(int escolha, char *menuExibicao[]);
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
void operacoesPotencia(int escolha);
void menuConversorPotencia();

#endif