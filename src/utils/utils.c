
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

#include "utils.h"

void limpaTela() {
    system("clear || cls");
}

char leOpcao() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == '\033') {
        char seq[2];
        read(STDIN_FILENO, &seq, 2);
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': ch = 'w'; break;
                case 'B': ch = 's'; break;
                case 'C': ch = 'd'; break;
                case 'D': ch = 'a'; break;
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}