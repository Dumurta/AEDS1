// EDUARDO MURTA DE ABREU 884985

// dependencias
#include <stdio.h>
#include "io.h"

/*
    Metodo 01
*/

void metodo_01(void)
{
    // definir dados
    int x = 0;

    // identificar
    IO_id("\nMetodo_01 - programa -v0.0");

    // ler do teclado
    x = IO_readint("Entrar com um valor inteiro");

    // testar valor
    if (x == 0)
    {
        IO_printf("%s(%d)\n", "Valor igual a zero", x);
    }
    if (x != 0)
    {
        IO_printf("%s(%d)\n", "Valor diferente de zero", x);
    } // end if

    // encerrar
    IO_pause("\nApertar ENTER para continuar.\n");
} // end metodo 01

/*
    Method_02
*/
void metodo_02(void)
{
    // definir dado
    int x = 0;

    // identificar
    IO_id("\nMetodo_02 - Programa v0.0");

    // ler do teclaod
    x = IO_readint("Entrar com um valor inteiro: ");

    // testar valor
    if (x == 0)
    {
        IO_printf("%s(%d)\n", "Valor igual a zero", x);
    }
    else
    {
        IO_printf("%s(%d)\n", "Valor diferente de zero", x);
    } // end if else

    // encerrar
    IO_pause("Apertar ENTER para continuar"); // DUVIDA: o comando IO_pause determina uma pausa em um loop ou ele equivale ao return(0)?
}
void metodo_03(void)
{
    // definir dado
    int x = 0;

    // identificar
    IO_id("\nMetodo 03-Programa v0.0");

    // ler do teclado
    x = IO_readint("Entrar com um valor inteiro: ");

    // testar valor
    if (x == 0)
    {
        IO_printf("%s(%d)\n", "Valor igual a zero", x);
    }
    else
    {
        IO_printf("%s(%d)\n", "Valor diferente de zero", x);
        if (x > 0)
        {
            IO_printf("%s(%d)\n", "Valor maior que zero", x);
        }
        else
        {
            IO_printf("%s(%d)\n", "Valor menor que zero", x);
        }
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo 03

/*
Metodo 4
*/

void metodo_04(void)
{
    // definir dado
    double x = 0.0;

    // identificar
    IO_id("\nMetodo 04-Programa v0.1");

    // ler do teclado
    x = IO_readdouble("Entrar com um valor real: ");

    // testar valor
    if (1.0 <= x && x <= 10.0)
    {
        IO_printf("%s(%lf)\n", "Valor pertence ao intervalo [1:10]", x);
    }
    else
    {
        IO_printf("%s(%lf)\n", "Valor fora do intervalo [1:10]", x);
        if (x < 1.0) // DUVIDA: nesse caso aqui, eu poderia utilizar o elif ao inves de colocar outro if e outro else?
        {
            IO_printf("%s(%lf)\n", "Valor abaixo do intervalo [1:10]", x);
        }
        else
        {
            IO_printf("%s(%lf)\n", "Valor acima do intervalo [1:10]", x);
        } // end if
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_04()

void metodo_05(void)
{
    // definir dado
    char x = '_';

    // identificar
    IO_id("\nMetodo_05 - Programa - v0.0");

    // ler do teclado
    x = IO_readchar("Entrar com um caractere: ");

    // testar valor
    if (('a' <= x) && (x <= 'z'))
    {
        IO_printf("%s(%c)\n", "Letra minuscula", x);
    }
    else
    {
        IO_printf("%s(%c)\n", "Nao e letra minuscula", x);
        if (('A' <= x) && (x <= 'Z'))
        {
            IO_printf("%s(%c)\n", "Letra maiscula", x);
        }
        else
        {
            if (('0' <= x) && (x <= '9'))
            {
                IO_printf("%s(%c)\n", "Algarismo", x);
            }
            else
            {
                IO_printf("%s(%c)\n", "Valor diferente de algarismo");
            } // end if
        } // end if
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // end metodo_05()

void metodo_06(void)
{
    // def dado
    char x = '_';

    // identificar
    IO_id("\nMetodo_06 - Programa v0.0");

    // ler do teclado
    x = IO_readchar("Entrar com um caractere: ");

    // testar valor
    if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
    {
        IO_printf("%s(%c)\n", "Letra", x);
    }
    else
    {
        IO_printf("%s(%c)\n", "valor diferente de letra", x);
    } // end if

    // encerrar
    IO_pause("Aperte ENTER para continuar");

} // end metodo_06()

/*
    Metodo_07
*/
void metodo_07(void)
{
    // definir dado
    char x = '_';

    // identificar
    IO_id("\nMetodo_07 - Programa v0.1");

    // ler do teclado
    x = IO_readchar("Entrar com um caractere: ");

    // testar valor
    if (!(('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')))
    {
        IO_printf("%s(%c)\n", "Valor diferente de letra", x);
    }
    else
    {
        IO_printf("%s(%c)\n", "Letra", x);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_07()

/*
    Method_08
*/
void metodo_08(void)
{
    // def dados
    char x = '_';

    // identificar
    IO_id("Metodo_08 v0.1");

    // ler do teclado
    x = IO_readchar("Entrar com um caractere ['0','A','a']: ");

    // testar valor
    switch (x)
    {
    case '0':
        IO_printf("%s(%c=%d)\n", "Valor igual do simbolo zero", x, x);
        break;
    case 'A':
        IO_printf("%s(%c=%d)\n", "Valor igual a letra A", x, x);
        break;
    case 'a':
        IO_printf("%s(%c=%d)\n", "Valor igual a letra a", x, x);
        break;

    default:
        IO_printf("%s(%c=%d)\n", "Valor diferente das opcoes['0','A','a']", x, x);
    } // end switch

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_08

/*
    Metodo_09
*/

void metodo_09(void)
{
    // definir dado
    int x = 0;

    // identificar
    IO_id("Metodo_09 - V0.1");

    // ler do teclado
    x = IO_readint("Entrar com um inteiro [0,1,2,3]: ");

    // testar valor
    switch (x)
    {
    case 0:
        IO_printf("%s(%d)\n", "Valor igual a zero", x);
        break;
    case 1:
        IO_printf("%s(%d)\n", "Valor igual a um", x);
        break;
    case 2:
        IO_printf("%s(%d)\n", "Valor igual a dois", x);
        break;
    case 3:
        IO_printf("%s(%d)\n", "Valor igual a tres", x);
        break;
    default:
        IO_printf("%s(%d)\n", "Valor diferente das opcoes [0,1,2,3]", x);
        break;
    } // end switch

    // encerrrar
    IO_pause("Apertar ENTER para continuar");

} // end metodo_09()

/*
    Metodo_10
*/
void metodo_10(void)
{
    // definir dado
    int x = 0;

    // identificar
    IO_id("Method_09 - Programa - v0.0");

    // ler do teclado
    x = IO_readint("Entrar com um inteiro [0,1,2,3]: ");

    // testar valor
    switch (x)
    {
    case 0:
        IO_println(IO_concat("Valor igual a zero (",
                             IO_concat(IO_toString_d(x), ")\n")));
        break;
    case 1:
        IO_println(IO_concat("Valor igual a um (",
                             IO_concat(IO_toString_d(x), ")\n")));
        break;
    case 2:
        IO_println(IO_concat("Valor igual a dois (",
                             IO_concat(IO_toString_d(x), ")\n")));
        break;
    case 3:
        IO_println(IO_concat("Valor igual a tres (",
                             IO_concat(IO_toString_d(x), ")\n")));
        break;
    default: // se nao for alguma das opcoes anteriores
        IO_println(IO_concat("Valor diferente das opcoes [0,1,2,3] (",
                             IO_concat(IO_toString_d(x), ")")));
    } // end switch

    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // end method_10 ( )

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

/*
    versao      data
     0.0         8/3

    versao      teste
     0.0         0.0
     Nesta primeira versao estou tendo alguns problemas no terminal pois quando compilo e executo o programa
     e o programa mostra ao usuario o printf da opcao para o usuario determinar o valor para a variavel, a variavel ja vem
     com alguns numeros aleatorios nela, mas que nao foram inseridos em momento algum. Nao consegui corrigir isso.

    versao      teste
     0.1         0.1
     Nesta versao consegui consertar o problema que tive na primeira versao, dei uma olhada na funcao int main (), e la
     ao inves de colocar scanf eu havia colocado printf, logo nao havia como o usuario escolher uma opcao.

    versao      teste
     0.2         0.1
     Nao tive problemas nessa versao os valores retornados sao os previstos e nao houve erros significativos.
    versao      teste
     0.3         0.1
     Nao tive problemas nessa versao
   versao      teste
     0.4        0.1
     Nao tive problemas nessa versao
    versao      teste
     0.5         0.1
     Nao tive problemas nessa versao
    versao      teste
     0.6         0.1
     Nao tive problemas nessa versao, A entrada de dados funcionou quase per feitamente, o unico problema que notei foi que
     ao inserir valores em que eu tivesse mais de uma casa decimal e o numero terminasse em 0, o programa nao retorna o 0
     por exemplo: ao inserir 10, o programa me retorna apenas "Nao e' letra(1)"
    Versao      teste
     0.7         0.1
     Nao tive problemas nessa versao

*/