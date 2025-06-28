#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

int fatorial()
{
    int x = 1;
    int y = 1;
    int fat = 1;
    printf("Digite um numero:\n");
    scanf("%d", &x);

    for (y = 1; y <= x; y = y + 1)
    {
        fat = fat * y;
    }
    printf("O fatorial de %d = %d\n", x, fat);
    return (0);
}

void Metodo_01()
{
    IO_id("Metodo_01 - v0.0");
    fatorial();
}

void Metodo_02()
{
}

int main()
{
    // def dado
    int x = 0;

    do
    {
        // ler do teclado
        IO_println("Digite um valor de 1 a 10 para consultar os metodos");
        IO_println("0 - parar");

        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        switch (x)
        {
        case 0:
            /* code */
            break;
        case 1:
            Metodo_01();
            break;
        case 2:
            Metodo_02();
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