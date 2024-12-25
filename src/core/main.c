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

#define OPCOES 7
#define LINHAS_TELA 30 // Número mínimo de linhas para todas as telas.
#define COLUNAS_TELA 80 // Tamanho fixo para largura visual.

void limpaTela() {
    system("clear || cls");
}
void telaInicial()
{   int altura = (int)(LINHAS_TELA * 0.6); // 60% da altura da tela para o triângulo

    // Limpa a tela e imprime a parte superior
    limpaTela();
    printf("\n\n");
    printf("%*sSUB GRUPO 6\n", (COLUNAS_TELA / 2) - 8, ""); // Centraliza "SUB GRUPO 6"

    // Desenha o triângulo invertido
    for (int i = altura; i > 0; i--) {
        limpaTela(); // Limpa a tela para atualização
        printf("\n\n");
        printf("%*sSUB GRUPO 6\n\n\n", (COLUNAS_TELA / 2) - 8, ""); // Centraliza "SUB GRUPO 6"
        
        // Desenha a parte superior do triângulo
        for (int linha = altura; linha > 0; linha--) {
            int espacos = (COLUNAS_TELA - (linha * 2)) / 2;
            printf("%*s", espacos, ""); // Alinha o triângulo no centro
            
            // Desenha as bordas do triângulo
            if (linha == altura) {
                for (int j = 0; j < linha * 2; j++) {
                    printf("-"); // Usando traços para a base
                }
            } else {
                printf("\\"); // Correção: Contra barra agora à esquerda
                for (int j = 0; j < (linha * 2) - 2; j++) {
                    printf(" "); // Espaço vazio dentro do triângulo
                }
                printf("/"); // Correção: Barra agora à direita
            }
            printf("\n");
        }

        // Exibe o texto "ILHEUS", "BA" e "2024" na parte inferior
        for (int linha = altura + 1; linha < LINHAS_TELA - 3; linha++) {
            printf("\n");
        }
        printf("%*sILHEUS\n", (COLUNAS_TELA / 10), "");
        printf("%*sBA\n", (COLUNAS_TELA / 10), "");
        printf("%*s2024\n", (COLUNAS_TELA / 10), "");

        // Aguarda 1 segundo
        usleep(1000);
    }

    sleep(2);// Aguarda 5 segundos antes de continuar
   

}
void exibeMenu(int indiceParaDestaque, char*menuExibicao[])
{
   limpaTela();
    printf("--------- MENU ---------\n");
    for (int i = 0; i < LINHAS_TELA - 3; i++) {
        if (i < OPCOES) {
            if (i == indiceParaDestaque) {
                printf("> %s <\n", menuExibicao[i]);
            } else {
                printf("  %s\n", menuExibicao[i]);
            }
        } else {
            printf("\n");
        }
    }
    printf("\nUse as teclas >>W<< para subir, >>S<< para descer, >>D<< para selecionar.\n");
    printf("Pressione 'A' para sair.\n");
}
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
    limpaTela();

    switch (escolhaMenu)
    {
        case 1:
        //armazenamento
        break;
    case 2:
        //energia
        break;
    case 3:
        //volume
        break;
    case 4:
        //massa
        break;
    case 5:
        //temperatura
        break;
    case 6:
        //comprimento
        break;
    case 7:
        //sair
        break;
    
    default:
    //printf("escolha: %d", escolhaMenu);
        break;
    }
    return;
}

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
    char*listaMenu[OPCOES]={"Unidades de Armazenamento",
                            "Unidades de Energia",
                            "Unidades de volume",
                            "Unidades de massa",
                            "Unidades de temperatura",
                            "Unidades de comprimento",
                            "SAIR"};
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