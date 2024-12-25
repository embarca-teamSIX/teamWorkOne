/*
Arquivo modelo a ser usado para as demais ops:
        a implementação visual e chamadas paras as demais func
    ------AAATENCAO------
            Mudar o [um]no nome da função para a função a ser operada
*/

#include "moduloOperacaoSeis.h"
#include "conversor_de_potencia.h"
#include <stdio.h>
#include <conio.h>

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
void lerDoTeclado(double *valor)//função nificada para ler e retornar valores em 
{   
    printf("Digite o valor da unidade a ser convertida: \n");
    scanf("%lf", valor);
    system("cls");
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
void exibeTela(char *digito)//exibir a interação especifica para cada proto
{
    system("cls");
    printf("Informe o digito da conversao desejada:\n"); 
    printf("1 - Watts para kilowatts\n");
    printf("2 - Watts para cavalo-vapor\n");
    printf("3 - Kilowatts para watts\n");
    printf("4 - Kilowatts para cavalo-vapor\n");
    printf("5 - Cavalo-vapor para watts\n");
    printf("6 - Cavalo-vapor para kilowatts\n");
    *digito = getch();
    system("cls");
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
void menuProtoSeis(void)//em numero igual as opcoes com [nome da operação] e a ser chamada por protoOperacoes()
{   
    short int validacao;
    double valor_digitado, valor_convertido;
    char escolha;

    exibeTela(&escolha);

    switch(escolha){
        case '1':
            lerDoTeclado(&valor_digitado);
            validacao = watts_para_kilowatts(valor_digitado,&valor_convertido);
            printf("%.2f watts e equivalente a %.2lf kilowatts", valor_digitado, valor_convertido);
            break;

        case '2':
            lerDoTeclado(&valor_digitado);
            validacao = watts_para_cv(valor_digitado,&valor_convertido);
            printf("%.2f watts e equivalente a %.2lf cavalos-vapor", valor_digitado, valor_convertido);
            break;

        case '3':
            lerDoTeclado(&valor_digitado);
            validacao = kilowatts_para_watts(valor_digitado,&valor_convertido);
            printf("%.2f kilowatts e equivalente a %.2lf watts", valor_digitado, valor_convertido);
            break;

        case '4':
            lerDoTeclado(&valor_digitado);
            validacao = kilowatts_to_cv(valor_digitado,&valor_convertido);
            printf("%.2f kilowatts e equivalente a %.2lf cavalos-vapor", valor_digitado, valor_convertido);
            break;

        case '5':
            lerDoTeclado(&valor_digitado);
            validacao = cv_para_watts(valor_digitado,&valor_convertido);
            printf("%.2f cavalos-vapor e equivalente a %.2lf watts", valor_digitado, valor_convertido);
            break;

        case '6':
            lerDoTeclado(&valor_digitado)
            validacao = cv_para_kilowatts(valor_digitado,&valor_convertido);
            printf("%.2f cavalos-vapor e equivalente a %.2lf kilowatts", valor_digitado, valor_convertido);
            break;
        
        default:
            printf("Entrada invalida.");
            break;
    }



}
