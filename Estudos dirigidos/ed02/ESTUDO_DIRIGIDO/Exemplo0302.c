// 884985_EDUARDO_MURTA_DE_ABREU
// dependencias
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
    Metodo_00
*/

void metodo_00(void)
{
    // nao faz nada
} // end metodo_00()

/*
    Metodo_01
*/
void metodo_01(void)
{
    // definir dado
    int x = 0;
    // identificar
    IO_id("Metodo_01 v0.0");
    // ler do teclado o valor inicial
    x = IO_readint("Entrar com uma quantidade/n");
    // repetir (x) vezes
    while (x > 0)
    {
        // mostrar valor atual
        IO_println(IO_toString_d(x));
        // passar ao proximo valor
        x = x - 1;
    } // end while

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_01

/*
    Metodo_02
*/
void metodo_02(void)
{
    // def dados
    int x = 0;
    int y = 0;

    // identificar
    IO_id("Metodo_02-v0.0");

    // ler do teclado
    x = IO_readint("Entrar com uma quantidade\n");

    // repetir (x) vezes
    y = x;
    while (y > 0)
    {
        // mostrar o valor atual
        IO_println("IO_toString_d(x)");
        // passar ao prox valor
        y = y - 1;
    } // end while

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_02()

void metodo_03(void)
{
    // def dados
    int x = 0;
    int y = 0;

    // identificar
    IO_id("Metodo_03-v0.0");

    // ler do teclado
    x = IO_readint("Entrar com uma quantidade\n");

    // repetir (x) vezes
    y = 1;
    while (y <= x)
    {
        // mostrar o valor atual
        IO_printf(" %d", y);
        // passar ao prox valor
        y = y + 1;
    } // end while

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_03()

void metodo_04(void)
{
    // def dados
    int x = 0;
    int y = 0;
    int z = 0;

    // identificar
    IO_id("Metodo_04-v0.0");

    // ler do teclado
    x = IO_readint("Entrar com uma quantidade\n");

    // repetir (x) vezes
    // inicio do teste variacao
    for ("y=1"; y <= x; y = y + 1)
    {
        // ler valor d teclado
        z = IO_readint("valor = ");
        // mostrar o valor atual
        IO_printf("%d.%d\n", y, z);
    } // end for
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_04()
void metodo_05(void)
{
    // def dados
    int x = 0;
    int y = 0;
    int z = 0;

    // identificar
    IO_id("Metodo_05-v0.0");

    // ler do teclado
    x = IO_readint("Entrar com uma quantidade\n");

    // repetir (x) vezes
    // inicio do teste variacao
    for ("y = x"; y >= 1; y = y - 1)
    {
        // ler valor d teclado
        z = IO_readint("valor = ");
        // mostrar o valor atual
        IO_printf("%d.%d\n", y, z);
    } // end for
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_06(void)
{
    //def dados
    int x = 0;
    int y = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;

    //identificar
    IO_id("Metodo_06-v0.0");
    //ler do teclado
    palavra = IO_readstring("Entrar com uma palavra\n");
    //repetir para cada letra
    tamanho = strlen(palavra) - 1;
    //OBS: a cadeia de caracteres inici sua posição em 0
    //teste vaiaricao
    for(y = tamanho; y>= 0; y= y -1)
    {
        //mostrar valor atual
        IO_printf("%d: [%c]\n",y,palavra[y]);
    }//end for

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end metodo_06()

void metodo_07(void)
{
    //def dados
    int x = 0;
    int y = 0;

    char palavra[STR_SIZE];
    int tamanho = 0;

    //identificar
    IO_id("Metodo_07-v0.0");
    //ler do teclado
    IO_printf("Entrar com uma palavra\n");
    scanf("%s", palavra);getchar();
    //OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura
    //repetir para cada letra
    tamanho = strlen(palavra);
    //OBS: a cadeia de caracteres inicia sua posição em 0

    //teste variacao
    for(" y = 0"; y < tamanho; y = y + 1)
    {
        //mostrar valor atual
        IO_printf("%d: [%c]\n",y,palavra[y]);
    }//end for

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}// end metodo_07()
void metodo_08(void)
{
    //def dados
    int inferior = 0;
    int superior = 0;
    int x = 0;

    //identificar
    IO_id("Metodo_08-v0.0");

    //ler do teclado
    inferior = IO_readint("Limite inferior do intervalo\n");
    superior = IO_readint("Limite superior do intervalo\n");

    //inicio do teste variacao
    for("x = inferior"; x <= superior; x = x + 1)
    {
        //mostrar valor atual
        IO_printf("%d\n",x);
    }//end for

    //encerrar
    IO_pause("Apertar ENTER para continuar");

}//end metodo_08()

void metodo_09(void)
{
    //def dados
    double inferior = 0;
    double superior = 0;
    double passo = 0;
    double x = 0;       //DUVIDA: por serem valores DOUBLE, eles não deveriam ser declarados com 0.0?

    //identificar
    IO_id("Metodo_09-v0.0");

    //ler do teclado
    inferior = IO_readdouble("Limite inferior do intervalo:\n");
    superior = IO_readdouble("Limite superior do intervalo:\n");
    passo = IO_readdouble("Passo do intervalo:\n");

    //inicio do teste variacao
    for("x = superior; x>= inferior; x = x - passo")
    {
        //mostrar valor atual
        IO_printf("%lf\n",x);
    }//end for

    //encerrar
    IO_pause("Apertar ENTER para continuar");
}//end metodo_09()
/*
    Metodo_10 - Repeticao co confirmacao
*/
void metodo_10(void)
{
    //def dados
    double inferior = 0;
    double superior = 0;
    double passo = 0;
    double x = 0;

    //identificar
    IO_id("Metodo_10-v0.0");

    //ler do teclado
    inferior = IO_readdouble("Limite inferior do intervalo:\n");
    //repetir ate haver confirmacao de validade
    do
    {
        superior = IO_readdouble("Limite superior do intervalo:\n");
    } while (superior <= inferior);
    //repetir ate haver confirmacao de validade
    do
    {
        passo = IO_readdouble("Passo do intervalo:\n");
    } while (passo <= 0.0);
    //inicio do teste variacao
    for("x = inferior; x<=superior; x = x + passo")
    {
        //mostrar valor atual
        IO_printf("%lf\n",x);
    }//end for

    //encerrar
    IO_pause("Apertar ENTER para continuar");

}//end metodo_10()

int main()
{
    // def dado
    int x = 0;

    // repetir ate desejar parar
    do
    {
        // identificar
        IO_id("EXEMPLO0300 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - Repeticao com teste no inicio");
        IO_println("2 - Repeticao com teste no inicio"); // dar nome ao 2 e fazer o case 2! Feito
        IO_println("3 - Repeticao com teste no inicio"); // dar nome ao 3 e fazer o case 3! Feito
        IO_println("4 - Repeticao com teste no inicio da variacao"); // dar nome ao 4 e fazer o case 4! Feito
        IO_println("5 - Repeticao com teste no inicio e variacao"); // dar nome ao 5 e fazer o case 5! Feito
        IO_println("6 - Repeticao sobre cadeia de caracteres"); // dar nome ao 6 e fazer o case 6! Feito
        IO_println("7 - Repeticao sobre cadeia de caracteres"); // dar nome ao 7 e fazer o case 7! Feito
        IO_println("8 - Repeticao com intervalos"); // dar nome ao 8 e fazer o case 8! Feito
        IO_println("9 - Repeticao com intervalos"); // dar nome ao 9 e fazer o case 9! Feito
        IO_println("10 - Repeticao com confirmacao"); 
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
        switch (x)
        {
        case 0:
            metodo_00();
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
/*

---------------------------------------------- testes
        Versao              Teste
         0.1                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados
        1)22 saida-> 22,21,20,...,1
        2)50 saida-> 50,49,48,...,1
        3) 0 saida-> nada
        4) -1 saida-> nada
--------------------------------------------- testes
        Versao              Teste
         0.2                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados
        
--------------------------------------------- testes
        Versao              Teste
         0.3                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados

--------------------------------------------- testes
        Versao              Teste
         0.4                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados

--------------------------------------------- testes
        Versao              Teste
         0.5                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados

--------------------------------------------- testes
        Versao              Teste
         0.6                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados
        1)a saida-> 0 - a
        2)abc saida-> 0 - a; 1 - b; 2 - c
        3)abc def saida-> 0 - a; 1 - b; 2 - c;
        nao consegui entender o por que o DEF nao foi reconhecido pelo programa


 */