#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

/*
    Metodo_01 - Mostrar certa quantidade de valores
*/
void metodo_01a(int x)
{
    // def dados
    int y = 1; // controle
    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor =", y);
        // passar para o prox
        y = y + 1;
    } // end while
} // end metodo_01a

/*
    Metodo_01 - Mostrar certa quantidade de valores
*/

void metodo_01()
{
    // identificar
    IO_id("Metodo_01 v0.0");
    // exec metodo auxiliar
    metodo_01a(5);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_01()
/*
    Metodo_02a - Mostrar certa quantidade de valores pares
*/
void metodo_02a(int x)
{
    // def dado local
    int y = 1; // controle
    int z = 2;

    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, z);
        // passar para o prox par
        z = z + 2;
        // passar para o prox valor controlado
        y = y + 1;
    } // end while
} // end metodo_02a()
/*
    Metodo_02
*/
void metodo_02()
{
    // identificar
    IO_id("Metodo_02 v0.0");
    // executar metodo auxiliar
    metodo_02a(5);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_02()
/**
    Metodo_03a - Mostrar certa quantidade de valores pares
 */
void metodo_03a(int x)
{
    // def dado
    int y = 1; // controle
    int z = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // vincular o valor a ser mostrado ao controle
        z = 2 * y;

        // mostrar valor
        IO_printf("%d: %d\n", y, z);
        // passar para o prox valor controlado
        y = y + 1;
    } // end while
} // end metodo_03a()
/**
    Metodo_03
 */
void metodo_03()
{
    // identificar
    IO_id("Metodo_03 v0.0");
    // executar metodo auxiliar
    metodo_03a(5);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
/*
    Metodo_04a - Mostrar certa quantidade de valores pares
*/
void metodo_04a(int x)
{
    // def dados
    int y = x; // controle
    int z = 0; // valor a ser mostrado

    // repetir enquanto controle menor que a quantidade desejada
    while (y > 0)
    {
        // vincular o valor a ser mostrado ao controle
        z = 2 * y;

        // mostrar valor
        IO_printf("%d: %d\n", y, z);
        // passar para o prox valor controlado
        y = y - 1;
    } // end while
} // end metodo_04a()
/*
    Metodo_04
*/
void metodo_04()
{
    // identificar
    IO_id("Metodo_04 v0.0");
    // executar metodo auxiliar
    metodo_04a(5);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/*
    Metodo_05a()
*/
void metodo_05a(int x)
{
    // def dados local
    int y = 0;

    // repetir enquanto controle menor que a quantidade desejada
    for (y = x; y > 0; y = y - 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y));
    } // end for
} // end metodo_05a()
/*
    Metodo_05
*/
void metodo_05()
{
    // identificar
    IO_id("Metodo_05 - v0.0");

    // executar o metodo auxiliar
    metodo_05a(5);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_05()

/*
    somarValores
*/
int somarvalores(int x)
{
    // def dados locais
    int soma = 1;
    int y = 0;

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y));
        // somar valor
        soma = soma + (2 * y);
    } // end for
    // retornar resultado
    return (soma);
} // end somaValores
/*
    Metodo_06()
*/
void metodo_06()
{
    // def dado
    int soma = 0;

    // identificar
    IO_id("Metodo_06");

    // chamar e receber resultado da funcao
    soma = somarvalores(5);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
    /*
    OBS: Reparar que a repetição se encerrará para o valor igual a zero.
    A repetição será feita, portanto, (x-1) vezes.
    */
} // end metodo_06()

/*
    somarFracao1 - funcao para somar certa quantidade de fracoes
*/
double somarFracao1(int x)
{
    // def dados locais
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0; // controle

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // calcula numerador
        numerador = 1.0;
        // calcula denominador
        denominador = (2.0 * y);
        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y, numerador,
                  denominador, (numerador / denominador));
        // somar valor
        soma = soma + (1.0) / (2.0 * y);
    } // end for
    // retornar resultado
    return (soma);
} // end somarFracao1()
/*
    Metodo_07()
*/
void metodo_07()
{
    // def dado
    double soma = 0.0;

    // identificar
    IO_id("Metodo_07");

    // chamar e receber resultado da funcao
    soma = somarFracao1(5);

    // mostrar resultado
    IO_printf("Soma de fracoes= %lf\n", soma);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
    /*
    OBS.: Reparar que a repetição se iniciará para o valor igual a 2, e terminará em (x).
    A repetição será feita, portanto, (x-1) vezes.
    */
} // end metodo_07()
/*
    somarFracao2 - funcao para somar certa quantidade de fracoes
*/
double somarFracao2(int x)
{
    // def dados locais
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0; // controle

    // mostrar primeiro valor
    IO_printf("%d: %7.4lf/%7.4lf = %lf\n", 1, 1.0, soma);

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // calcular numerador
        numerador = 2.0 * y - 1;
        // calcular denominador
        denominador = 2.0 * y;
        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y, numerador, denominador, (numerador / denominador));
        // somar valor
        soma = soma + (1.0) / (2.0 * y);
    } // end for
    // retornar resultado
    return (soma);
} // end somarFracao2()
/*
    Metodo_08()
*/
void metodo_08()
{
    // def dados
    double soma = 0.0;

    // identificar
    IO_id("Metodo_08");
    // chamar e receber resultado da funcao
    soma = somarFracao2(5);
    // mostrar resultado
    IO_printf("Soma de fracoes = %lf\n", soma);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_08()
/*
    somarFracao3 - funcao para somar certa quantidade de fracoes
*/
double somarFracao3(int x)
{
    // def dados locais
    double soma = 1.0;
    int y = 0; // controle
    // mostrar primeiro valor
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y < x; y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %7.4lf\n",
                  y + 1, (2.0 * y), (2.0 * y + 1), ((2.0 * y) / (2.0 * y + 1)));
        // somar valor
        soma = soma + (2.0 * y) / (2.0 * y + 1);
    } // end for
    // retornar resultado
    return (soma);
} // end somarFracao3()
/*
    Metodo_09()
*/
void metodo_09()
{
    // def dados
    double soma = 0.0;
    // identificar
    IO_id("Metodo_09");
    // chamar e receber resultado da funcao
    soma = somarFracao3(5);
    // mostrar resultado
    IO_printf("Soma de fracoes = %lf\n", soma);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_09()
/*
    multiplicarValores - funcao para multiplicar certa quantidade de valores impares
*/
int multiplicarValores(int x)
{
    // def dados locais
    int produto = 1;
    int y = 0; // controle

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= x; y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y - 1));
        // calcular produto
        produto = produto * (2 * y - 1);
    } // end for
    // retornar resultado
    return (produto);
} // end multiplicarValores()
/**
    Metodo_10
 */
void metodo_10()
{
    // identificar
    IO_id("Metodo_10");
    // mostrar produtos de valores
    IO_printf("%s%d\n", "produto =", multiplicarValores(5));
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_10()

/*
    Funcao principal.
*/

int main(void)
{
    // def da do
    int opcao = 0;
    // identificar
    IO_id("EXEMPLO05 - Programa - v0.0");

    do
    {
        // apresentar metodos
        IO_printf("Opcao 0: Sair\n");
        IO_printf("Opcao 1: Metodo_01\n");
        IO_printf("Opcao 2: Metodo_02\n");
        IO_printf("Opcao 3: Metodo_03\n");
        IO_printf("Opcao 4: Metodo_04\n");
        IO_printf("Opcao 5: Metodo_05\n");
        IO_printf("Opcao 6: Metodo_05\n");
        IO_printf("Opcao 7: Metodo_07\n");
        IO_printf("Opcao 8: Metodo_08\n");
        IO_printf("Opcao 9: Metodo_09\n");
        IO_printf("Opcao 10: Metodo_10\n");
        // ler opcao
        opcao = IO_readint("Escolha uma opcao: ");
        // mostrar opcao
        IO_printf("Opcao escolhida: %d\n", opcao);
        // selecionar opcao

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            metodo_01();
            break;
        case 2:
            metodo_02();
            break;
        case 3:
            metodo_03();
            break;
        case 4:
            metodo_04();
            break;
        case 5:
            metodo_05();
            break;
        case 6:
            metodo_06();
            break;
        case 7:
            metodo_07();
            break;
        case 8:
            metodo_08();
            break;
        case 9:
            metodo_09();
            break;
        case 10:
            metodo_10();
            break;
        default:
            IO_printf("ERRO: Valor invalido.\n");
            break;
        }
    } while (opcao != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // end main

/*
 ---------------------------------------------- historico

Versao Data      Modificacao
  0.1 26/03

 ---------------------------------------------- testes

Versao          Teste
  0.1             01. ( OK )
  Sem problemas na primeira versao do programa, funcionando corretamente.
Valor inserido = 5
Retorno = 1,2,3,4,5

 ----------------------------------------------
Versao          Teste
  0.2             01. ( OK )
*/