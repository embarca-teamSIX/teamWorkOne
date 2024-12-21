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

#define OPCOES 10
void protoOperacoes(int escolhaMenu)
{

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
    
    // Restaura as configurações do terminal para o estado original
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void exibeMenu(int iniceParaDestaque, char*menuExibicao[])
{
    system("clear || cls");
    (void)printf("---------MENU---------\n\n");
    for(int i =0;i<OPCOES; i++)
    {
        if(i==iniceParaDestaque){printf("> %s <\n", menuExibicao[i]);continue;}
        (void)printf(" %s\n",menuExibicao[i]);
    }
    printf("\n\nUse as teclas >>W<< e >>S<< para navegar o menu");
    return 0;
}

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
        case '\n':
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

void tests_temperature_lib()
{
    /* Init tests with the temperature conversion */
    // Creating variables
    double temperature_value;
    double temperature_response;
    return_code_temp_t response;
    
    // Celsius to fahrenheit
    temperature_value = 30.0;
    response = celsius_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -300.0;
    response = celsius_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Celsius to kelvin
    temperature_value = 30.0;
    response = celsius_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -300.0;
    response = celsius_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Fahrenheit to Celsius
    temperature_value = 30.0;
    response = fahrenheit_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -460.00;
    response = fahrenheit_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Fahrenheit to Kelvin
    temperature_value = 30.0;
    response = fahrenheit_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -460.00;
    response = fahrenheit_to_kelvin(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Kelvin: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }


    // Kelvin to Celsius
    temperature_value = 30.0;
    response = kelvin_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -10;
    response = kelvin_to_celsius(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Celsius: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    // Kelvin to Fahrenheit
    temperature_value = 30.0;
    response = kelvin_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }

    temperature_value = -10;
    response = kelvin_to_fahrenheit(temperature_value, &temperature_response);
    if (response == CONVERSION_OK) {
        printf("Temperature in Fahrenheit: %.2f\n", temperature_response);
    } else {
        printf("Error: Conversion failed.\n");
    }
}