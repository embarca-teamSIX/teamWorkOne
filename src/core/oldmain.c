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


#define OPCOES 4

void loopMenu()//uma func para cada op
{

}
void exibirMenu(int destaque, char *opcoes[]) {
    system("clear || cls"); // Limpa o terminal (cls no Windows, clear no Linux/Mac)
    printf("==== MENU ====\n\n");
    for (int i = 0; i < OPCOES; i++) {
        if (i == destaque) {
            printf("> %s <\n", opcoes[i]); // Destaque para a opção selecionada
        } else {
            printf("  %s\n", opcoes[i]);
        }
    }
}

void menuLoop()//menu da operação
{

    char *opcoes[OPCOES] = {"Iniciar Jogo", "Configurações", "Ajuda", "Sair"};
    int escolha = 0;
    char tecla;

    while (1) {
        exibirMenu(escolha, opcoes);

        // Captura entrada do teclado
        tecla = getchar(); // No Linux, substitua por getchar()

        if (tecla == 'w' || tecla == 'W') { // Simula tecla "cima"
            escolha = (escolha - 1 + OPCOES) % OPCOES; // Navega ciclicamente para cima
        } else if (tecla == 's' || tecla == 'S') { // Simula tecla "baixo"
            escolha = (escolha + 1) % OPCOES; // Navega ciclicamente para baixo
        } else if (tecla == '\n' || tecla == '\r') { // Enter
            if (escolha == 3) { // "Sair" foi selecionado
                printf("\nEncerrando...\n");
                break;
            } else {
                printf("\nVocê selecionou: %s\n", opcoes[escolha]);
                printf("Pressione qualquer tecla para continuar...");
                getchar(); // Aguarda uma tecla
            }
        }
    }


}


int main(){
    
menuLoop();

return 0;    
}