// EDUARDO MURTA DE ABREU 884985

// dependencias
#include <stdio.h>
#include "io.h"
/*
    Metodo_1
*/

void metodo_1(void)
{
    // def dados
    int x = 0;

    // identificar
    IO_id("\nExercicio 0211 PAR OU IMPAR v0.0");

    // ler do teclado
    x = IO_readint("Entre com um valor par ou impar: ");

    if (x % 2 == 0)
    {
        IO_printf("O numero inserido e' par ", x);
    }
    else
    {
        IO_printf("O numero inserido e' impar", x);
    } // end if
    if (x > 0)
    {
        IO_printf("\nO numero e' positivo");
    }
    else
    {
        IO_printf("\nO numero e' negativo");
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // end metodo_11()

/*
    Metodo_2
*/
void metodo_2(void)
{
    // definir dados
    int x = 0;

    // identificar
    IO_id("\n Exercicio 0212");

    // ler do teclado
    x = IO_readint("Entre com um valor para x: ");

    if (x % 2 == 0)
    {
        IO_printf("O numero inserido e' par ", x);
    }
    else
    {
        IO_printf("O numero inserido e' impar", x);
    } // end if
    if (x < -25)
    {
        IO_printf("\nO numero e' menor que -25", x);
    }
    if (x > 25)
    {
        IO_printf("\nO numero e' maior que 25", x);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/*
    Metodo_3
*/
void metodo_3(void)
{
    // def dados
    int x = 0;

    // identificar
    IO_id("\n Exercicio0213");

    // ler do teclado
    x = IO_readint("Entrar com um valor para x");

    if (20 < x && x < 55)
    {
        IO_printf("O valor esta entre o intervalo (20:55).", x);
    }
    else
    {
        IO_printf("O valor esta fora do intervalo (20:55).");
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/*
    Metodo_4
*/
void metodo_4(void)
{
    // def dados
    int x = 0;

    // identificar
    IO_id("\n Exercicio0214");

    // ler do teclado
    x = IO_readint("Entrar com um valor para x");

    if (20 <= x && x <= 55)
    {
        IO_printf("O valor esta entre o intervalo [20:55].", x);
    }
    else
    {
        IO_printf("O valor esta fora do intervalo [20:55].");
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/*
    Metodo 5
*/
void metodo_05(void)
{
    int x = 0;

    IO_id("\nExercicio0215");

    x = IO_readint("Entrar com um valor para x: ");

    int pertence_intervalo1 = (x >= 10 && x <= 30); // [10:30]
    int pertence_intervalo2 = (x > 20 && x < 40);   // (20:40)
    int pertence_intersecao = (x > 20 && x <= 30);  // Interseção [21:30]

    if (pertence_intersecao)
    {
        IO_printf("O valor pertence à intersecao dos intervalos.\n");
    }

    else if (pertence_intervalo1)
    {
        IO_printf("O valor pertence apenas ao primeiro intervalo [10:30].\n");
    }
    else if (pertence_intervalo2)
    {
        IO_printf("O valor pertence apenas ao segundo intervalo (20:40).\n");
    }
    else
    {
        IO_printf("O valor não pertence a nenhum dos intervalos.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void metodo_06()
{
    int num1, num2;

    num1 = IO_readint("Entrar com um valor para o primeiro numero");
    num2 = IO_readint("Entrar com um valor para o segundo numero");

    if (num1 % 2 != 0 && num2 % 2 == 0)
    {
        IO_printf("O primeiro numero é impar e o segundo é par.\n");
    }
    else
    {
        IO_printf("Os numeros não atendem à condição.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
/*
metodo 7
*/

void metodo_07(void)
{
    int num1, num2;

    // Lê os dois valores inteiros
    num1 = IO_readint("Insira um valor para o primeiro numero");
    num2 = IO_readint("Insira um valor para o segundo numero");

    // Verifica se o primeiro número é par e negativo
    if (num1 % 2 == 0 && num1 < 0)
    {
        IO_printf("O primeiro numero e par e negativo.\n");
    }
    else
    {
        IO_printf("O primeiro numero não e par e negativo.\n");
    }

    // Verifica se o segundo número é ímpar e positivo
    if (num2 % 2 != 0 && num2 > 0)
    {
        IO_printf("O segundo numero e impar e positivo.\n");
    }
    else
    {
        IO_printf("O segundo numero não e impar e positivo.\n");
    }

    IO_pause("Apertar ENTER para continuar");
}

void metodo_08(void)
{
    float num1, num2;

    // Le os dois valores reais
    num1 = IO_readfloat("Insira um valor para o primeiro numero");
    num2 = IO_readfloat("Insira um valor para o segundo numero");

    // Compara o primeiro numero com um quarto do segundo
    if (num1 < num2 / 4)
    {
        IO_printf("O primeiro numero e menor que um quarto do segundo.\n");
    }
    else if (num1 == num2 / 4)
    {
        IO_printf("O primeiro numero e igual a um quarto do segundo.\n");
    }
    else
    {
        IO_printf("O primeiro numero e maior que um quarto do segundo.\n");
    }

    IO_pause("Apertar ENTER para continuar");
}

/*
Metodo 9
*/
void metodo_09()
{
    float num1, num2, num3;

    // Le os tres valores reais
    num1 = IO_readfloat("Insira um valor para o primeiro numero");
    num2 = IO_readfloat("Insira um valor para o segundo numero");
    num3 = IO_readfloat("Insira um valor para o segundo numero");

    // Verifica se o primeiro e o terceiro valor sao diferentes
    if (num1 != num3)
    {
        // Verifica se o segundo valor esta entre o primeiro e o terceiro
        if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3))
        {
            IO_printf("O segundo numero esta entre o primeiro e o terceiro.\n");
        }
        else
        {
            IO_printf("O segundo numero nao esta entre o primeiro e o terceiro.\n");
        }
    }
    else
    {
        IO_printf("O primeiro e o terceiro numero sao iguais, nao e possivel fazer a verificacao.\n");
    }

    IO_pause("Apertar enter para continuar");
}

void metodo_10()
{
    float num1, num2, num3;

    // Le os tres valores reais
    num1 = IO_readfloat("Insira um valor para o primeiro numero");
    num2 = IO_readfloat("Insira um valor para o segundo numero");
    num3 = IO_readfloat("Insira um valor para o segundo numero");

    // Verifica se todos os valores sao diferentes entre si
    if (num1 != num2 && num1 != num3 && num2 != num3)
    {
        // Verifica se o segundo numero nao esta entre o primeiro e o terceiro
        if ((num2 <= num1 || num2 >= num3) && (num2 >= num1 || num2 <= num3))
        {
            IO_printf("O segundo numero nao esta entre o primeiro e o terceiro.\n");
        }
        else
        {
            IO_printf("O segundo numero esta entre o primeiro e o terceiro.\n");
        }
    }
    else
    {
        IO_printf("Nem todos os numeros sao diferentes entre si.\n");
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
        printf("\n%s", "3 - Metodo_03");
        printf("\n%s", "4 - Metodo_04");
        printf("\n%s", "5 - Metodo_05");
        printf("\n%s", "6 - Metodo_06");
        printf("\n%s", "7 - Metodo_07");
        printf("\n%s", "8 - Metodo_08");
        printf("\n%s", "9 - Metodo_09");
        printf("\n%s", "10 - Metodo_10");
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
        case 3:
            metodo_3();
            break;
        case 4:
            metodo_4();
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