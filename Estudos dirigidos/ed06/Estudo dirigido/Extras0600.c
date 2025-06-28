/**
   EXTRAS-05 - Programa - v0.0
   Exemplo de programa com recursividade.
   @author Eduardo Murta De Abreu 884985
   @version 0.0 2025-04-02
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "io.h"

// -----------------------------------------------------------------------------
// Funções auxiliares

/**
   calcularFuncao - Calcular o valor da função f(x, n) = 1 + x^3 + x^5 + x^7 + ... até o n-ésimo termo.
   @param x - valor base
   @param n - número de termos
   @param expoente - expoente atual (inicia em 3)
   @return valor da função
*/
double calcularFuncao(double x, int n, int expoente)
{
    if (n > 0)
    {
        // calcular o termo atual e somar recursivamente
        return pow(x, expoente) + calcularFuncao(x, n - 1, expoente + 2);
    }
    else
    {
        return 1; // caso base: o primeiro termo é 1
    }
}

/**
   fatorial - Calcular o fatorial de um número.
   @param n - número para calcular o fatorial
   @return fatorial de n como double
*/
double fatorial(int n)
{
    if (n <= 1)
    {
        return 1.0; // caso base: fatorial de 0 ou 1 é 1
    }
    else
    {
        return n * fatorial(n - 1); // chamada recursiva
    }
}

/**
   calcularSerieE - Calcular o valor da série e = 1 + 3/2! + 5/4! + 7/8! + ... até o n-ésimo termo.
   @param n - número de termos
   @param termo - termo atual (inicia em 1)
   @param numerador - numerador atual (inicia em 3)
   @param denominador - denominador atual (inicia em 2)
   @return valor da série como double
*/
double calcularSerieE(int n, int termo, int numerador, int denominador)
{
    if (termo > n)
    {
        return 0.0; // caso base: nenhum termo restante
    }
    else
    {
        // calcular o termo atual e somar recursivamente
        return (double)numerador / fatorial(denominador) + calcularSerieE(n, termo + 1, numerador + 2, denominador * 2);
    }
}

// -----------------------------------------------------------------------------
// Métodos principais

/**
   Metodo_01 - Ler valores de x e n e calcular o valor da função f(x, n).
*/
void metodo_01()
{
    // definir dados
    double x = 0.0;
    int n = 0;
    double resultado = 0.0;

    // identificar
    IO_id("Metodo_01 - v0.0");

    // ler valores do teclado
    x = IO_readdouble("Digite o valor de x: ");
    n = IO_readint("Digite o número de termos (n): ");

    // calcular o valor da função usando a função recursiva
    if (n > 0)
    {
        resultado = calcularFuncao(x, n, 3);
        IO_printf("O valor da função f(x, n) é: %.6lf\n", resultado);
    }
    else
    {
        IO_printf("ERRO: O número de termos deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   Metodo_02 - Ler o número de termos e calcular o valor da série e.
*/
void metodo_02()
{
    // definir dados
    int n = 0;
    double resultado = 0.0;

    // identificar
    IO_id("Metodo_02 - v0.0");

    // ler o número de termos do teclado
    n = IO_readint("Digite o número de termos (n): ");

    // calcular o valor da série usando a função recursiva
    if (n > 0)
    {
        resultado = 1.0 + calcularSerieE(n, 1, 3, 2); // o primeiro termo é 1
        IO_printf("O valor da série e com %d termos é: %.6lf\n", n, resultado);
    }
    else
    {
        IO_printf("ERRO: O número de termos deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

// -----------------------------------------------------------------------------
// Função principal

int main(void)
{
    // definir dado
    int opcao = 0;

    // identificar
    IO_id("EXEMPLO05 - Programa - v0.0");

    do
    {
        // apresentar métodos
        IO_printf("Opcao 0: Sair\n");
        IO_printf("Opcao 1: Metodo_01\n");
        IO_printf("Opcao 2: Metodo_02\n");

        // ler opcao
        opcao = IO_readint("Escolha uma opcao: ");
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
        default:
            IO_printf("ERRO: Valor invalido.\n");
            break;
        }
    } while (opcao != 0);

    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return 0;
}
