/*
main/
    |->menu para selecionar
    |->funções de loop para interação visual
    |                   |->apos função ser selecionada 
    |                   |-> iniciar subfunções para interface de iteração
    |                   |   da opção desejada EX: interface de ler re retornar valor 
    |                   |   convertido de cms para kms ou Cº para Fº
    |                   |-> em caso de erro retornar status do erro e não encerrar
    |->implementar foward e backward entre os sub menus
    
    {
    loopMenu[operacao]()
    }
    menuLoop()
    main()
*/

#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <unistd.h>

#define OPCOES 6

/**
 * Nome: protoOperacoes
 * 
 * Descrição: função que recebe o valor do indice da opção do menu e 
 *            chama a tela subsequente
 * 
 * Parametros: 
 *          -int escolhaMenu: inteiro que contem o indice 
 * 
 * Retorno:
 *          -sem retorno
 * 
 */
void protoOperacoes(int escolhaMenu)//0 to 9
{
        system("clear || cls");

    switch (escolhaMenu)
    {
    case 9:
        printf("sair");
        break;
    
    default:
    printf("escolha: %d", escolhaMenu);
        break;
    }
    return;
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
 * exibeMenu() -imprime em tela as strings de forma ordenada
 * 
 * Descrição: essa função exibe em tela de forma ordenada as strings do menu
 * 
 * Parametros: 
 *          -int indiceParaDestaque: que retorna o indice atual do apontador "><"
 *          -char* menuExibicao: string com o textual do menu
 * 
 * Retorno:
 *          -sem retorno
 * 
 */
void exibeMenu(int indiceParaDestaque, char*menuExibicao[])
{
    system("clear || cls");
    (void)printf("---------MENU---------\n\n");
    for(int i =0;i<OPCOES; i++)
    {
        if(i==indiceParaDestaque){printf("> %s <\n", menuExibicao[i]);continue;}
        (void)printf(" %s\n",menuExibicao[i]);
    }
    printf("\n\nUse as teclas >>W<< e >>S<< para navegar o menu");
    return ;
}
/**
 * menuLoop() -menu em loop 
 * 
 * Descrição: essa função fica rodando em loop para exibir em tela e processar as entradas
 * 
 * Parametros: 
 *          -nenhum
 * 
 * Retorno:
 *          -sem retorno
 * 
 */
void menuLoop()
{
    char*listaMenu[OPCOES]={"Unidades de comprimento","Unidades de massa","Unidades de volume","Unidades de temperatura","Unidades de velocidade","Unidades de Energia","Unidades de área","Unidades de tempo","Unidades de Armazenamento", "SAIR"};
    int escolhaMomento=0;
    char leitura; 

    while(1)
    {
        (void)exibeMenu(escolhaMomento, listaMenu);
        leitura=leOpcao();
        switch (leitura)
        {
        case 'w':
            escolhaMomento=(escolhaMomento-1+OPCOES)%OPCOES;
            break;
        case 'W':
            escolhaMomento=(escolhaMomento-1+OPCOES)%OPCOES;
            break;
        case 's':
            escolhaMomento=(escolhaMomento+1)%OPCOES;
            break;
        case 'S':
            escolhaMomento=(escolhaMomento+1)%OPCOES;
            break;
        case 'd':
        case 'D':
            (void)protoOperacoes(escolhaMomento);//funcao void que recebe o valor da operacao e 
                                          //inicia a chamada das funções das operações
            break;
        
        
        default:
            continue;
            break;
        }
    }

}
int main(int argc, char*argv[])
{
    menuLoop();
return 0;
}