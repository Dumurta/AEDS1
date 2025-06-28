/**
   EXERCICIOS-05 - Programa - v0.0
   Exemplo de programa com recursividade.
   @author Eduardo Murta De Abreu 884985
   @version 0.0 2025-04-02
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "io.h"

/**
   mostrarMultiplosDe3 - Mostrar múltiplos de 3 recursivamente.
   @param quantidade - quantidade de múltiplos a serem mostrados
   @param atual - valor atual do múltiplo de 3
*/
void mostrarMultiplosDe3(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        // mostrar o valor atual
        IO_printf("%d\n", atual);
        // chamar recursivamente para o próximo múltiplo
        mostrarMultiplosDe3(quantidade - 1, atual + 3);
    }
}

/**
   Metodo_01 - Ler valor e mostrar múltiplos de 3.
*/
void metodo_01()
{
    // definir dado
    int quantidade = 0;

    // identificar
    IO_id("Metodo_11 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de múltiplos de 3: ");

    // chamar o procedimento recursivo
    if (quantidade > 0)
    {
        IO_printf("Múltiplos de 3:\n");
        mostrarMultiplosDe3(quantidade, 3);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   mostrarMultiplosDe3Decrescente - Mostrar múltiplos de 3 recursivamente em ordem decrescente.
   @param quantidade - quantidade de múltiplos a serem mostrados
   @param atual - valor atual do múltiplo de 3
*/
void mostrarMultiplosDe3Decrescente(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        // mostrar o valor atual
        IO_printf("%d\n", atual);
        // chamar recursivamente para o próximo múltiplo
        mostrarMultiplosDe3Decrescente(quantidade - 1, atual - 3);
    }
}

/**
   Metodo_02 - Ler valor e mostrar múltiplos de 3 em ordem decrescente.
*/
void metodo_02()
{
    // definir dado
    int quantidade = 0;

    // identificar
    IO_id("Metodo_02 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de múltiplos de 3: ");

    // chamar o procedimento recursivo
    if (quantidade > 0)
    {
        IO_printf("Múltiplos de 3 em ordem decrescente:\n");
        mostrarMultiplosDe3Decrescente(quantidade, quantidade * 3);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   mostrarInversosMultiplosDe3 - Mostrar inversos dos múltiplos de 3 recursivamente.
   @param quantidade - quantidade de valores a serem mostrados
   @param atual - valor atual do múltiplo de 3
*/
void mostrarInversosMultiplosDe3(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        // mostrar o inverso do valor atual
        IO_printf("1/%d\n", atual);
        // chamar recursivamente para o próximo múltiplo
        mostrarInversosMultiplosDe3(quantidade - 1, atual + 3);
    }
}

/**
   Metodo_03 - Ler valor e mostrar inversos dos múltiplos de 3.
*/
void metodo_03()
{
    // definir dado
    int quantidade = 0;

    // identificar
    IO_id("Metodo_03 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de inversos dos múltiplos de 3: ");

    // chamar o procedimento recursivo
    if (quantidade > 0)
    {
        IO_printf("Inversos dos múltiplos de 3:\n");
        mostrarInversosMultiplosDe3(quantidade, 1);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   mostrarInversosMultiplosDe3Decrescente - Mostrar inversos dos múltiplos de 3 recursivamente em ordem decrescente.
   @param quantidade - quantidade de valores a serem mostrados
   @param atual - valor atual do múltiplo de 3
*/
void mostrarInversosMultiplosDe3Decrescente(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        // mostrar o inverso do valor atual
        IO_printf("1/%d\n", atual);
        // chamar recursivamente para o próximo múltiplo em ordem decrescente
        mostrarInversosMultiplosDe3Decrescente(quantidade - 1, atual - 3);
    }
}

/**
   Metodo_04 - Ler valor e mostrar inversos dos múltiplos de 3 em ordem decrescente.
*/
void metodo_04()
{
    // definir dado
    int quantidade = 0;

    // identificar
    IO_id("Metodo_04 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de inversos dos múltiplos de 3: ");

    // chamar o procedimento recursivo
    if (quantidade > 0)
    {
        IO_printf("Inversos dos múltiplos de 3 em ordem decrescente:\n");
        mostrarInversosMultiplosDe3Decrescente(quantidade, quantidade * 3);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   somaImparesAPartirDe3 - Calcular a soma dos valores gerados pela adição dos primeiros ímpares positivos a partir de 3.
   @param quantidade - quantidade de números a serem somados
   @param atual - valor atual da sequência
   @return soma dos valores
*/
int somaImparesAPartirDe3(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        // somar o valor atual e chamar recursivamente para o próximo número
        return atual + somaImparesAPartirDe3(quantidade - 1, atual + (quantidade * 2 - 1));
    }
    else
    {
        return 0; // caso base
    }
}

/**
   Metodo_05 - Ler valor e calcular a soma dos valores gerados pela adição dos primeiros ímpares positivos a partir de 3.
*/
void metodo_05()
{
    // definir dado
    int quantidade = 0;
    int soma = 0;

    // identificar
    IO_id("Metodo_05 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de números a serem somados: ");

    // calcular a soma usando a função recursiva
    if (quantidade > 0)
    {
        soma = somaImparesAPartirDe3(quantidade, 3);
        IO_printf("A soma dos valores gerados é: %d\n", soma);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   somaInversosMultiplosDe3 - Calcular a soma dos inversos dos primeiros valores ímpares positivos múltiplos de 3.
   @param quantidade - quantidade de valores a serem somados
   @param atual - valor atual do múltiplo de 3
   @return soma dos inversos
*/
double somaInversosMultiplosDe3(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        // somar o inverso do valor atual e chamar recursivamente para o próximo múltiplo de 3
        return (1.0 / atual) + somaInversosMultiplosDe3(quantidade - 1, atual + 6);
    }
    else
    {
        return 0.0; // caso base
    }
}

/**
   Metodo_06 - Ler valor e calcular a soma dos inversos dos primeiros valores ímpares positivos múltiplos de 3.
*/
void metodo_06()
{
    // definir dado
    int quantidade = 0;
    double soma = 0.0;

    // identificar
    IO_id("Metodo_06 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de valores ímpares múltiplos de 3: ");

    // calcular a soma usando a função recursiva
    if (quantidade > 0)
    {
        soma = somaInversosMultiplosDe3(quantidade, 3);
        IO_printf("A soma dos inversos dos valores gerados é: %.6lf\n", soma);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   mostrarCaracteresReverso - Mostrar cada caractere de uma string separadamente, de trás para frente.
   @param cadeia - cadeia de caracteres
   @param tamanho - tamanho da cadeia
*/
void mostrarCaracteresReverso(char *cadeia, int tamanho)
{
    if (tamanho > 0)
    {
        // mostrar o último caractere
        IO_printf("%c\n", cadeia[tamanho - 1]);
        // chamar recursivamente para o restante da cadeia
        mostrarCaracteresReverso(cadeia, tamanho - 1);
    }
}

/**
   Metodo_07 - Ler uma cadeia de caracteres e mostrar cada símbolo separadamente, de trás para frente.
*/
void metodo_07()
{
    // definir dado
    char cadeia[100];

    // identificar
    IO_id("Metodo_07 - v0.0");

    // ler cadeia de caracteres
    IO_printf("Digite uma cadeia de caracteres: ");
    IO_scanf("%s", cadeia);

    // chamar o procedimento recursivo
    IO_printf("Caracteres da cadeia em ordem reversa:\n");
    mostrarCaracteresReverso(cadeia, strlen(cadeia));

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   contarDigitosPares - Contar os dígitos com valores pares em uma cadeia de caracteres.
   @param cadeia - cadeia de caracteres
   @param tamanho - tamanho da cadeia
   @return quantidade de dígitos pares
*/
int contarDigitosPares(char *cadeia, int tamanho)
{
    if (tamanho > 0)
    {
        // verificar se o último caractere é um dígito par
        char ultimo = cadeia[tamanho - 1];
        if (ultimo >= '0' && ultimo <= '9' && (ultimo - '0') % 2 == 0)
        {
            // contar o dígito par e chamar recursivamente
            return 1 + contarDigitosPares(cadeia, tamanho - 1);
        }
        else
        {
            // continuar a contagem sem incrementar
            return contarDigitosPares(cadeia, tamanho - 1);
        }
    }
    else
    {
        return 0; // caso base: tamanho 0
    }
}

/**
   Metodo_08 - Ler uma cadeia de caracteres e contar os dígitos com valores pares.
*/
void metodo_08()
{
    // definir dado
    char cadeia[100];
    int quantidade = 0;

    // identificar
    IO_id("Metodo_08 - v0.0");

    // ler cadeia de caracteres
    IO_printf("Digite uma cadeia de caracteres: ");
    IO_scanf("%s", cadeia);

    // contar os dígitos pares usando a função recursiva
    quantidade = contarDigitosPares(cadeia, strlen(cadeia));

    // exibir o resultado
    IO_printf("A quantidade de dígitos pares na cadeia é: %d\n", quantidade);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   contarMaiusculasEntreC_e_P - Contar as letras maiúsculas maiores que 'C' e menores que 'P' em uma cadeia de caracteres.
   @param cadeia - cadeia de caracteres
   @param tamanho - tamanho da cadeia
   @return quantidade de letras maiúsculas entre 'C' e 'P'
*/
int contarMaiusculasEntreC_e_P(char *cadeia, int tamanho)
{
    if (tamanho > 0)
    {
        // verificar se o último caractere é uma letra maiúscula entre 'C' e 'P'
        char ultimo = cadeia[tamanho - 1];
        if (ultimo > 'C' && ultimo < 'P' && ultimo >= 'A' && ultimo <= 'Z')
        {
            // contar a letra e chamar recursivamente
            return 1 + contarMaiusculasEntreC_e_P(cadeia, tamanho - 1);
        }
        else
        {
            // continuar a contagem sem incrementar
            return contarMaiusculasEntreC_e_P(cadeia, tamanho - 1);
        }
    }
    else
    {
        return 0; // caso base: tamanho 0
    }
}

/**
   Metodo_09 - Ler uma cadeia de caracteres e contar as letras maiúsculas maiores que 'C' e menores que 'P'.
*/
void metodo_09()
{
    // definir dado
    char cadeia[100];
    int quantidade = 0;

    // identificar
    IO_id("Metodo_09 - v0.0");

    // ler cadeia de caracteres
    IO_printf("Digite uma cadeia de caracteres: ");
    IO_scanf("%s", cadeia);

    // contar as letras maiúsculas usando a função recursiva
    quantidade = contarMaiusculasEntreC_e_P(cadeia, strlen(cadeia));

    // exibir o resultado
    IO_printf("A quantidade de letras maiúsculas entre 'C' e 'P' é: %d\n", quantidade);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
   fibonacci - Calcular o n-ésimo termo da série de Fibonacci.
   @param n - posição do termo na série
   @return n-ésimo termo da série de Fibonacci
*/
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1; // os dois primeiros termos são 1
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2); // soma dos dois anteriores
    }
}

/**
   somaFibonacciPar - Calcular a soma dos termos pares da série de Fibonacci.
   @param quantidade - quantidade de termos pares a serem somados
   @param atual - posição atual na série de Fibonacci
   @return soma dos termos pares
*/
int somaFibonacciPar(int quantidade, int atual)
{
    if (quantidade > 0)
    {
        int termo = fibonacci(atual);
        if (termo % 2 == 0)
        {
            // somar o termo par e continuar a busca
            return termo + somaFibonacciPar(quantidade - 1, atual + 1);
        }
        else
        {
            // continuar a busca sem somar
            return somaFibonacciPar(quantidade, atual + 1);
        }
    }
    else
    {
        return 0; // caso base: nenhum termo restante
    }
}

/**
   Metodo_10 - Ler valor e calcular a soma dos termos pares da série de Fibonacci.
*/
void metodo_10()
{
    // definir dado
    int quantidade = 0;
    int soma = 0;

    // identificar
    IO_id("Metodo_10 - v0.0");

    // ler valor do teclado
    quantidade = IO_readint("Digite a quantidade de termos pares da série de Fibonacci: ");

    // calcular a soma usando a função recursiva
    if (quantidade > 0)
    {
        soma = somaFibonacciPar(quantidade, 1);
        IO_printf("A soma dos %d termos pares da série de Fibonacci é: %d\n", quantidade, soma);
    }
    else
    {
        IO_printf("ERRO: Quantidade deve ser maior que zero.\n");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

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
        IO_printf("Opcao 6: Metodo_06\n");
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
