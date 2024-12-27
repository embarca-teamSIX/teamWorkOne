
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

    #ifdef SYSTEM_TYPE
   if(strcmp(SYSTEM_TYPE, "WINDOWS")==0)
   {
        ch=_getch();
   }
   else{
        struct termios oldt, newt;
   
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        ch = getchar();

        if (ch == '\033') 
        {
            char seq[2];
            (void)read(STDIN_FILENO, &seq, 2);
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
         }
#else
        ch=getchar();
#endif
    return ch;
 }