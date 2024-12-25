#ifndef MODULO_OPERACAO_ARMAZENAMENTO
#define MODULO_OPERACAO_ARMAZENAMENTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include "armazenamento.h" // Cabeçalho com as funções de conversão de armazenamento.


void limpaTela();


// Funções de conversão - Exemplos
return_code_data bit_to_byte(char numero[], char *resultado);
return_code_data bit_to_kb(char numero[], char *resultado);
return_code_data bit_to_mb(char numero[], char *resultado);
return_code_data bit_to_gb(char numero[], char *resultado) ;
return_code_data byte_to_bit(char numero[], char *resultado) ;
return_code_data byte_to_kb(char numero[], char *resultado);
return_code_data byte_to_mb(char numero[], char *resultado);
return_code_data byte_to_gb(char numero[], char *resultado);
return_code_data byte_to_tb(char numero[], char *resultado) ;
return_code_data kb_to_bit(char numero[], char *resultado);
return_code_data kb_to_byte(char numero[], char *resultado);
return_code_data kb_to_mb(char numero[], char *resultado);
return_code_data kb_to_gb(char numero[], char *resultado);
return_code_data kb_to_tb(char numero[], char *resultado);
return_code_data mb_to_bit(char numero[], char *resultado);
return_code_data mb_to_byte(char numero[], char *resultado);
return_code_data mb_to_kb(char numero[], char *resultado);
return_code_data mb_to_gb(char numero[], char *resultado);
return_code_data mb_to_tb(char numero[], char *resultado);
return_code_data gb_to_bit(char numero[], char *resultado);
return_code_data gb_to_byte(char numero[], char *resultado);
return_code_data gb_to_kb(char numero[], char *resultado);
return_code_data gb_to_mb(char numero[], char *resultado);
return_code_data gb_to_tb(char numero[], char *resultado);
return_code_data tb_to_bit(char numero[], char *resultado);
return_code_data tb_to_byte(char numero[], char *resultado);
return_code_data tb_to_kb(char numero[], char *resultado);
return_code_data tb_to_mb(char numero[], char *resultado);
return_code_data tb_to_gb(char numero[], char *resultado);

void exibeTelaSelecao(int escolha, char *menuExibicao[]); 
void exibeTelaEntrada(char *nomeOperacao, char *entrada, char *resultado);
char leOpcao();
void protoOperacoes(int escolha);
void menuProtoArmazenamento();

#endif