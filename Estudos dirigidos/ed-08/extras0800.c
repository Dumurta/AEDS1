#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

// metodo 00 para nao fazer nada
void Metodo_00()
{
    // nao faz nada
}
// Definindo constantes para o extra_02
#define MAX_PALAVRAS 100
#define TAM_PALAVRA 100

// Função para calcular divisores pares
int obterDivisoresPares(int valor, int vetor[])
{
    int contador = 0;

    for (int i = 2; i <= valor; i = i + 2)
    {
        if (valor % i == 0)
        {
            vetor[contador] = i;
            contador = contador + 1;
        }
    }

    return contador;
}

void Metodo_01()
{
    int numero = 0;
    int divisores[100]; // no máximo o próprio número, como sugerido
    int quantidade = 0;
    FILE *arquivo = NULL;

    printf("Metodo Extra 01 - Divisores pares de um numero inteiro\n\n");

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);
    if (numero <= 0)
    {
        printf("Valor invalido. Deve ser positivo.\n");
    }
    else
    {
        quantidade = obterDivisoresPares(numero, divisores);

        if (quantidade == 0)
        {
            printf("Nao ha divisores pares para esse numero.\n");
        }
        else
        {
            printf("Divisores pares de %d:\n", numero);
            for (int i = 0; i < quantidade; i = i + 1)
            {
                printf("%d ", divisores[i]);
            }
            printf("\n");

            arquivo = fopen("DIVISORES.TXT", "wt");
            if (arquivo != NULL)
            {
                fprintf(arquivo, "%d\n", quantidade); // primeira linha: quantidade
                for (int i = 0; i < quantidade; i = i + 1)
                {
                    fprintf(arquivo, "%d\n", divisores[i]);
                }
                fclose(arquivo);
                printf("Divisores gravados em DIVISORES.TXT\n");
            }
            else
            {
                printf("Erro ao criar o arquivo DIVISORES.TXT\n");
            }
        }
    }
    getchar();
    IO_pause("Aperte ENTER para continuar"); // encerrar
}

// Função para verificar se a palavra não começa nem termina com 'e' ou 'E'
int palavraValida(char *palavra)
{
    int tamanho = strlen(palavra);

    if (tamanho == 0)
        return 0;

    char inicio = palavra[0];
    char fim = palavra[tamanho - 1];

    // Verifica se começa ou termina com 'e' ou 'E'
    if ((inicio == 'e' || inicio == 'E') || (fim == 'e' || fim == 'E'))
    {
        return 0;
    }

    return 1;
}

// Função para ler palavras do arquivo e filtrar
int filtrarPalavras(char resultado[10][TAM_PALAVRA])
{
    FILE *arquivo = fopen("PALAVRAS.TXT", "rt");
    char palavra[TAM_PALAVRA];
    int contador = 0;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo PALAVRAS.TXT\n");
        return 0;
    }

    while (fscanf(arquivo, "%s", palavra) != EOF && contador < 10)
    {
        if (palavraValida(palavra))
        {
            strcpy(resultado[contador], palavra);
            contador = contador + 1;
        }
    }

    fclose(arquivo);
    return contador;
}

void Metodo_02()
{
    char palavrasFiltradas[10][TAM_PALAVRA];
    int quantidade = 0;

    printf("Metodo Extra 02 - Filtrar palavras que nao comecam nem terminam com 'e' ou 'E'\n\n");

    quantidade = filtrarPalavras(palavrasFiltradas);

    if (quantidade == 0)
    {
        printf("Nenhuma palavra valida encontrada.\n");
    }
    else
    {
        printf("Palavras encontradas:\n");
        for (int i = 0; i < quantidade; i = i + 1)
        {
            printf("%s\n", palavrasFiltradas[i]);
        }
    }
    getchar();
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
int main()
{
    // def dado
    int x = 0;

    // repetir ate desejar parar
    do
    {
        // identificar
        IO_id("EXTRAS0800 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - Extra 01");
        IO_println("2 - Extra 02");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
        switch (x)
        {
        case 0:
            Metodo_00();
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