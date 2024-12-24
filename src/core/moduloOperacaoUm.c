/*
Arquivo modelo a ser usado para as demais ops:
        a implementação visual e chamadas paras as demais func
    ------AAATENCAO------
            Mudar o [um]no nome da função para a função a ser operada
*/
#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <unistd.h>
#define OPERACOES 30
//------------

/**
 * Nome: 
 * 
 * Descrição: e
 * 
 * Parametros: 
 *          -
 * 
 * Retorno:
 *          -
 * 
 */

char leOpcao()
{
struct termios oldt, newt;
    char ch;

    // Obtém as configurações atuais do terminal
    tcgetattr(STDIN_FILENO, &oldt);  // STDIN_FILENO refere-se à entrada padrão (teclado)
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Desabilita o modo canônico (sem buffer) e o eco de caracteres
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplica as novas configurações

    ch = getchar(); // Lê o caractere sem esperar por "Enter"
    
        if(ch =='\033'){
            char seq[2];
            read(STDIN_FILENO, &seq, 2); // Lê os dois próximos caracteres
            if(seq[0]=='['){
                switch(seq[1]){
                    case 'A': ch ='w'; break;//cima
                    case 'B': ch ='s'; break;//baixo
                    case 'C': ch ='d'; break;//direita
                    case 'D': ch ='a'; break;//esquerda
                }
            }
        }

    // Restaura as configurações do terminal para o estado original
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

/**
 * Nome: 
 * 
 * Descrição: e
 * 
 * Parametros: 
 *          -
 * 
 * Retorno:
 *          -
 * 
 */
void exibeTela(int indiceDestaque, char*menuExibicao[])//exibir a interação especifica para cada proto
{
    system("clear || cls");
    (void)printf("---------MENU---------\n\n");
    for(int i =0;i<OPERACOES; i++)
    {
        if(i==indiceDestaque){printf("> %s <\n", menuExibicao[i]);continue;}
        (void)printf(" %s\n",menuExibicao[i]);
    }
    //printf("\n\nUse as teclas >>W<< e >>S<< para navegar o menu");
    return ;
}
void protoOperacoes()
{
//receber numero e chamar a função
//criar arrays para cada operação
//a depender do numero que chegar: mudar o texto de saida e chamar a função correspondente

}
/**
 * Nome: 
 * 
 * Descrição: e
 * 
 * Parametros: 
 *          -
 * 
 * Retorno:
 *          -
 * 
 */
void menuProto()//em numero igual as opcoes com [nome da operação] e a ser chamada por protoOperacoes()
{
    //todo
    char*composicaoMenu[OPERACOES]={"bit_to_byte","bit_to_kb","bit_to_mb","bit_to_gb", "bit_to_tb", "byte_to_bit", "byte_to_kb", "byte_to_mb", "byte_to_gb", "byte_to_tb", "kb_to_bit", "kb_to_byte", "kb_to_mb", "kb_to_gb","kb_to_tb","mb_to_bit", "mb_to_byte", "mb_to_kb", "mb_to_gb", "mb_to_tb", "gb_to_bit", "gb_to_byte", "gb_to_kb", "gb_to_kb", "gb_to_tb", "tb_to_bit", "tb_to_byte", "tb_to_kb", "tb_to_mb","tb_to_gb"};
    int escolhaTemp=0;
    char leitura;

    while(1)
    {
        (void)exibeTela(escolhaTemp, composicaoMenu);
        leitura=leOpcao();
        switch (leitura)
        {
        case 'w':
            escolhaTemp=(escolhaTemp-1+OPERACOES)%OPERACOES;
            break;
        case 'W':
            escolhaTemp=(escolhaTemp-1+OPERACOES)%OPERACOES;
            break;
        case 's':
            escolhaTemp=(escolhaTemp+1)%OPERACOES;
            break;
        case 'S':
            escolhaTemp=(escolhaTemp+1)%OPERACOES;
            break;
        case 'd':
        case 'D':
            (void)protoOperacoes(escolhaTemp);//funcao void que recebe o valor da operacao e 
                                          //inicia a chamada das funções das operações
            break;
        
        
        default:
            continue;
            break;
        }
    }
}