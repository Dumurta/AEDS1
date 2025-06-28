#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void gerarMultiplos()
{
    int q = 0;
    int x = 3;
    printf("Quantos multiplos de 3 serao feitos?\n");
    scanf("%d", &q);

    for (int n = 0; n < q; n = n + 1)
    {
        printf("{%d}", x);
        x = x + 3;
    }
}

void Metodo_01()
{
    IO_id("Metodo_01 v0.0");
    gerarMultiplos();

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void gerarMultiplos3()
{
    int q = 0;
    int x = 15;
    printf("Quantos multiplos de 3 e 5 serao feitos?\n");
    scanf("%d", &q);

    for (int n = 0; n < q; n = n + 1)
    {
        printf("%d,", x);
        x = x + 15;
    }
}

void Metodo_02()
{
    IO_id("Metodo_02 v0.0");
    gerarMultiplos3();
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void gerarPow()
{
    int q = 0;
    int x = 0;
    printf("Insira um valor para ser decrecido.\n");
    scanf("%d", &q);
    x = pow(4, q);
    for (int n = q; n > 0; n = n - 1)
    {
        printf("%d, ", x);
        x = x / 4;
    }
    printf("\n");
}

void Metodo_03()
{
    IO_id("Metodo_03 v0.0");
    gerarPow();
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void gerarFracoesMultiplos()
{
    int q = 0;
    int x = 3;
    printf("Quantos fracoes com denominadores multiplos de 3 serao feitos?\n");
    scanf("%d", &q);

    for (int n = 0; n < q; n = n + 1)
    {
        printf("{1/%d}", x);
        x = x + 3;
    }
}

void Metodo_04()
{
    IO_id("Metodo_04 v0.0");
    gerarMultiplos();
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void fracoesPow()
{
    int q = 0;
    double x = 0.0;
    printf("Insira um valor real para x:\n");
    scanf("%lf", &x);

    printf("Quantidade de termos da sequencia:\n");
    scanf("%d", &q);

    int inteiro = 0;
    double denominador = 0.0;

    for (int n = 0; n < q; n = n + 1)
    {
        printf("{%d, 1/%.2lf --> 1/%.1lf = (%.3lf) },", inteiro, pow(x, denominador), denominador, 1 / denominador);
        denominador = denominador + 2;
        inteiro = inteiro + 2;
    }
}

void Metodo_05()
{
    IO_id("Metodo_05 v0.0");
    gerarMultiplos();
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void calcularSomaMultiplos(int q)
{
    int soma = 0;
    int numero = 3;

    for (int contador = 0; contador < q; contador = contador + 1)
    {
        if (numero % 3 == 0 && numero % 4 != 0)
        {
            printf("%d ", numero);
            soma = soma + numero;
        }
        numero = numero + 3;
    }

    printf("\nSoma dos valores: %d\n", soma);
}

void Metodo_06()
{
    IO_id("Metodo_06 v0.0");
    int q = 0;
    printf("Digite a quantidade de termos:\n");
    scanf("%d", &q);

    printf("Valores selecionados: ");
    calcularSomaMultiplos(q);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void calcularSomaInversos(int q)
{
    double soma = 0.0;
    int numero = 4;

    for (int contador = 0; contador < q; contador = contador + 1)
    {
        if (numero % 4 == 0 && numero % 5 != 0)
        {
            printf("1/%d ", numero);
            soma = soma + (1.0 / numero);
        }
        numero = numero + 4;
    }

    printf("\nSoma dos inversos: %.4lf\n", soma);
}

void Metodo_07()
{
    IO_id("Metodo_07 v0.0");
    int q = 0;
    printf("Digite a quantidade de termos:\n");
    scanf("%d", &q);

    printf("Valores selecionados: ");
    calcularSomaInversos(q);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void calcularSomaAdicao(int q)
{
    int soma = 0;
    int numero = 5;

    for (int n = 0; n < q; n = n + 1)
    {
        printf("%d ", numero);
        soma = soma + numero;
        numero = numero + (n + 1); // soma o valor de (n + 1) ao número
    }

    printf("\nSoma da adição: %d\n", soma);
}

void Metodo_08()
{
    IO_id("Metodo_08 v0.0");
    int q = 0;
    printf("Digite a quantidade de termos:\n");
    scanf("%d", &q);

    printf("Valores selecionados: ");
    calcularSomaAdicao(q);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void calcularSomaQuadrados(int q)
{
    int soma = 0;
    int numero = 25;

    for (int n = 0; n < q; n = n + 1)
    {
        printf("%d ", numero);
        soma = soma + numero;
        numero = numero + 1;
    }

    printf("\nSoma dos quadrados: %d\n", soma);
}

void Metodo_09()
{
    IO_id("Metodo_09 v0.0");
    int q = 0;
    printf("Digite a quantidade de termos:\n");
    scanf("%d", &q);

    printf("Valores selecionados: ");
    calcularSomaQuadrados(q);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void calcularSomaInversosAdicoes(int q)
{
    double soma = 0.0;
    int numero = 13; // O número começa em 13 para a sequência conforme exemplo.

    for (int n = 0; n < q; n = n + 1)
    {
        printf("1/%d ", numero);
        soma = soma + (1.0 / numero);
        numero = numero - (n + 1); // subtraímos n+1 para que a sequência diminua conforme desejado.
    }

    printf("\nSoma dos inversos: %.4lf\n", soma);
}

void Metodo_10()
{
    IO_id("Metodo_10");
    int q = 0;
    printf("Digite a quantidade de termos:\n");
    scanf("%d", &q);

    printf("Valores selecionados: ");
    calcularSomaInversosAdicoes(q);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
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
        case 3:
            Metodo_03();
            break;
        case 4:
            Metodo_04();
            break;
        case 5:
            Metodo_05();
            break;
        case 6:
            Metodo_06();
            break;
        case 7:
            Metodo_07();
            break;
        case 8:
            Metodo_08();
            break;
        case 9:
            Metodo_09();
            break;
        case 10:
            Metodo_10();
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