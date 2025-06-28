#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "io.h"

/*
    Metodo_01
*/

void metodo_01(void)
{
    // def dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;

    // identificar
    IO_id("\nEXEMPLO0401 - Programa - v0.0");

    // ler  do teclado
    quantidade = IO_readint("\nEntre com a quantidade: ");

    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler do teclado
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        // mostrar valor lido
        printf("%s%d\n", "Valor lido = ", valor);
        // passar ao proximo valor
        controle = controle + 1;
    } // end while

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");

} // end metodo_01

bool positive(int x)
{
    // def dado local
    bool result = false;
    // testar a condicao
    if (x > 0)
    {
        result = true;
    } // end if

    return (result);
} // end positive

/*
    Metodo_02
*/
void metodo_02(void)
{
    // def dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;

    // identificar
    IO_id("\nEXEMPLO0402 - Programa - v0.0");

    // ler do teclado
    quantidade = IO_readint("\nEntre com a quantidade: ");

    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler do teclado
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        // mostrar valor lido
        printf("%s%d\n", "Valor lido = ", valor);
        // testar a condicao
        if (positive(valor))
        {
            contador = contador + 1;
        } // end if
        // passar ao proximo valor
        controle = controle + 1;
    } // end while
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "positivos = ", contador);

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");

} // end metodo_02()

bool belongsTo(int x, int inferior, int superior)
{
    // def dado local
    bool result = false;
    // testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    } // end if

    return (result);
} // end belongsTo

/*
    Metodo_03
*/
void metodo_03(void)
{
    // def dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;

    // identificar
    IO_id("\nEXEMPLO0403 - Programa - v0.0");

    // ler do teclado
    quantidade = IO_readint("\nEntre com a quantidade: ");

    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler do teclado
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        // testar e contar se valor for positivo
        if (belongsTo(valor, 0, 100))
        {
            contador = contador + 1;
        } // end if
        // passar ao proximo valor
        controle = controle + 1;
    } // end while
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "positivos menores que 100= ", contador);

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");

} // end metodo_03()

bool even(int x)
{
    // def dado local
    bool result = false;
    // testar a condicao
    if (x % 2 == 0)
    {
        result = true;
    } // end if

    return (result);
}

/*
    Metodo_04
*/

void metodo_04(void)
{
    // def dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;

    // identificar

    IO_id("\nEXEMPLO0404 - Programa - v0.0");

    // ler do teclado
    quantidade = IO_readint("\nEntre com a quantidade: ");

    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler do teclado
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        // testar e contar se valor for positivo
        if (belongsTo(valor, 0, 100) && even(valor))
        {
            contador = contador + 1;
        } // end if
        // passar ao proximo valor
        controle = controle + 1;
    } // end while
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "positivos pares menores que 100= ", contador);

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");

} // end metodo_04()

/*
    Metodo_05
*/

void metodo_05(void)
{
    // def dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    bool ok = false;

    // identificar
    IO_id("\nEXEMPLO0405 - Programa - v0.0");

    // ler do teclado
    quantidade = IO_readint("\nEntre com a quantidade: ");

    // repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        // ler do teclado
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        // testar e contar se valor for positivo
        ok = belongsTo(valor, 0, 100);
        ok = ok && even(valor);
        if (ok)
        {
            contador = contador + 1;
        } // end if
        // passar ao proximo valor
        controle = controle + 1;
    } // end while
    // mostrar a quantidade de valores positivos
    IO_printf("%s%d\n", "positivos pares menores que 100= ", contador);

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");
} // end metodo_05()

bool isLowerCase(char x)
{
    // def dado local
    bool result = false;
    // testar a condicao
    if ('a' <= x && x <= 'z')
    {
        result = true;
    } // end if

    return (result);
} // end isLowerCase

/*
    Metodo_06
*/

void metodo_06(void)
{
    // def dado
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    // identificar
    IO_id("\nEXEMPLO0406 - Programa - v0.0");

    // ler do teclado
    palavra = IO_readstring("\nEntre com uma palavra: ");

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbol por vez
        simbolo = palavra[posicao];
        // testar e contar se simbolo for letra minuscula
        if (isLowerCase(simbolo))
        {
            contador = contador + 1;
        } // end if
    } // end for
    // mostrar a quantidade de letras minusculas
    IO_printf("%s%d\n", "letras minusculas = ", contador);
    // encerrar
    IO_pause("\nApertar ENTER para continuar.");

} // end metodo_06

/*
    Metodo_07
*/
void metodo_07(void)
{
    // def dado
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    // identificar
    IO_id("\nEXEMPLO0407 - Programa - v0.0");

    // ler do teclado
    palavra = IO_readstring("\nEntre com uma palavra: ");

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);
    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];
        // testar e contar se simbolo for letra minuscula
        if (isLowerCase(simbolo))
        {
            // mostrar
            IO_printf("%c\n", simbolo);
            // contar
            contador = contador + 1;
        } // end if
    } // end for

    // mostrar a quantidade de letras minusculas
    IO_printf("%s%d\n", "letras minusculas = ", contador);

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");
} // end metodo_07()
/*
    Metodo_08
*/
void metodo_08(void)
{
    // def dado
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;
    chars minusculas = IO_new_chars(STR_SIZE);

    strcpy(minusculas, STR_EMPTY); // vazio

    // identificar
    IO_id("Metodo_08");
    // ler do teclado
    palavra = IO_readstring("Entre com uma palavra: ");
    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);
    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];
        // testar e contar se simbolo for letra minuscula
        if (isLowerCase(simbolo))
        {
            // contar
            contador = contador + 1;
            // concatenar
            minusculas = IO_concat(minusculas, IO_toString_c(simbolo));
        } // end if
    } // end for

    // mostrar a quantidade de minusculas
    IO_printf("\n%S%D[%s]\n", "Minusculas=", contador, minusculas);

    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // end metodo_08

bool isDigit(char x)
{
    // def dado local
    bool result = false;
    // testar a condicao
    if ('0' <= x && x <= '9')
    {
        result = true;
    } // end if

    return (result);
} // end isDigit

/*
    Metodo_09
*/
void metodo_09(void)
{
    // def dado
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    // identificar
    IO_id("\nEXEMPLO0409 - Programa - v0.0");

    // ler do teclado
    palavra = IO_readstring("\nEntre com uma palavra: ");

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);
    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];
        // testar e contar se simbolo for letra minuscula
        if (isDigit(simbolo))
        {
            // mostrar
            IO_printf("%c\n", simbolo);
            // contar
            contador = contador + 1;
        } // end if
    } // end for

    // mostrar a quantidade de letras minusculas
    IO_printf("%s%d\n", "digitos = ", contador);

    // encerrar
    IO_pause("\nApertar ENTER para continuar.");
} // end metodo_09()

bool isADigit(char x)
{
    return ('0' <= x && x <= '9');

} // end isADigit()

chars concatADigit(chars string, char digit)
{
    return (IO_concat(string, IO_toString_c(digit)));
} // end concatADigit()

/*
    Metodo_10
*/
void metodo_10(void)
{
    // def dado
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    chars digitos = IO_new_chars(STR_SIZE);

    strcpy(digitos, STR_EMPTY); // vazio

    // identificar
    IO_id("Metodo_10");

    // ler do teclado
    palavra = IO_readstring("Entre com uma palavra: ");

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];
        // testar e contar se simbolo for letra minuscula
        if (isADigit(simbolo))
        {
            // concatenar
            digitos = concatADigit(digitos, simbolo);
        } // end if
    } // end for

    // mostrar a quantidade de minusculas
    IO_printf("\n%s%d[%s]\n", "Algarismos=", strlen(digitos), digitos);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_10()

int main()
{
    // def dado
    int x = 0;

    do
    {
        // identificar
        IO_id("EXEMPLO0400 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - Metodo_01");
        IO_println("2 - Metodo_02");
        IO_println("3 - Metodo_03");
        IO_println("4 - Metodo_04");
        IO_println("5 - Metodo_05");
        IO_println("6 - Metodo_06");
        IO_println("7 - Metodo_07");
        IO_println("8 - Metodo_08");
        IO_println("9 - Metodo_09");
        IO_println("10 - Metodo_10");

        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        switch (x)
        {
        case 0:
            /* code */
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
            IO_pause(IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat(IO_toString_d(x), ")")));
        } // end switch
    } while (x != 0);

    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);

} // end main