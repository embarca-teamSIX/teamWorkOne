
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef _WIN32
#include<conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include "utils.h"

void limpaTela() 
{
    #ifdef SYSTEM_TYPE
    if(strcmp(SYSTEM_TYPE, "WINDOWS")==0)
    {
        (void)system( "cls");
    }else
    {
        (void)system("clear");
    }
    #endif
}
char leOpcao() {
    char ch;
    
 #ifdef _WIN32
    ch = _getch(); // Leitura de tecla sem eco no Windows
#else
    struct termios oldt, newt;

    // Configurar terminal para leitura sem eco no Linux
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    // Tratamento para sequências de escape (setas direcionais)
    if (ch == '\033') {
        char seq[2];
        read(STDIN_FILENO, seq, 2);
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': ch = 'w'; break; // Seta para cima
                case 'B': ch = 's'; break; // Seta para baixo
                case 'C': ch = 'd'; break; // Seta para a direita
                case 'D': ch = 'a'; break; // Seta para a esquerda
            }
        }
    }

    // Restaurar configuração do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

    return ch;
}