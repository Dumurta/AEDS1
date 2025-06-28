// EDUARDO MURTA DE ABREU 884985

// dependencias
#include <stdio.h>
#include "io.h"
/*
    Metodo_1
*/

void metodo_1()
{
    char char1, char2, char3;

    // Le os tres caracteres
    char1 = IO_readint("Entrar com o primeiro caractere");
    char2 = IO_readint("Entrar com o segundo caractere");
    char3 = IO_readint("Entrar com o terceiro caractere");

    // Verifica se o primeiro caractere esta entre o segundo e o terceiro ou e igual a um deles
    if ((char1 > char2 && char1 < char3) || (char1 < char2 && char1 > char3))
    {
        IO_printf("O primeiro caractere esta entre o segundo e o terceiro.\n");
    }
    else if (char1 == char2 || char1 == char3)
    {
        IO_printf("O primeiro caractere e igual a um dos outros dois.\n");
    }
    else
    {
        IO_printf("O primeiro caractere nao esta entre os outros dois e nao e igual a nenhum deles.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/*
    Metodo_2
*/
void metodo_2()
{
    char char1, char2, char3;

    // Le os tres caracteres
    char1 = IO_readint("Entrar com o primeiro caractere");
    char2 = IO_readint("Entrar com o segundo caractere");
    char3 = IO_readint("Entrar com o terceiro caractere");

    // Verifica se todos os caracteres sao diferentes
    if (char1 != char2 && char1 != char3 && char2 != char3)
    {
        // Verifica se o primeiro caractere esta fora do intervalo definido pelos outros dois
        if ((char1 < char2 && char1 < char3) || (char1 > char2 && char1 > char3))
        {
            IO_printf("O primeiro caractere esta fora do intervalo definido pelos outros dois.\n");
        }
        else
        {
            IO_printf("O primeiro caractere nao esta fora do intervalo.\n");
        }
    }
    else
    {
        IO_printf("Os caracteres nao sao todos diferentes entre si.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

int main(void)
{
    // definir dados
    int opcao = 0;

    // identificar
    printf("%s\n", "Exemplo0200");
    printf("\n");

    // acoes

    // repetir
    do
    {
        // para mostrar opcoes
        printf("\n%s\n", "Opcoes: ");
        printf("\n%s", "0 - Terminar");
        printf("\n%s", "1 - Metodo_01");
        printf("\n%s", "2 - Metodo_02");
        printf("\n");

        // ler a opcao do teclado
        printf("\n%s", "Opcao= ");
        scanf("%d", &opcao);
        getchar();

        // para mostrar a opcao lida
        printf("\n%s%d", "Opcao= ", opcao);

        // escolher acao dependente da opcao
        switch (opcao)
        {
        case 0: /*nao fazer nada*/
            break;
        case 1:
            metodo_1();
            break;
        case 2:
            metodo_2();
            break;
        default: // comportamento padrao
            printf("\nERRO: Opcao invalida.\n");
            break;
        } // end switch
    } while (opcao != 0);

    // encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar();
    return (0);
} // end main()