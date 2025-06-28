// 884985_EDUARDO_MURTA_DE_ABREU
// dependencias
#include "io.h"

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
    x = IO_readint("Entrar com uma quantidade/n");

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
        IO_println("1 - repeticao com teste no inicio");
        IO_println("2 - "); // dar nome ao 2 e fazer o case 2!
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
 */