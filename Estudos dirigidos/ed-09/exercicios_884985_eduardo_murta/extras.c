#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void IO_pause(const char *text)
{
    printf("\n%s", text);
    getchar();
}

// Função para gravar matriz real em arquivo
void fprintDoubleMatrix(const char *filename, int rows, int cols, double matrix[rows][cols])
{
    FILE *file = fopen(filename, "wt");
    if (file != NULL)
    {
        fprintf(file, "%d %d\n", rows, cols);
        for (int i = 0; i < rows; i = i + 1)
        {
            for (int j = 0; j < cols; j = j + 1)
            {
                fprintf(file, "%.2lf ", matrix[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else
    {
        printf("ERRO: Nao foi possivel criar o arquivo.\n");
    }
}

// Função para mostrar a matriz na tela
void printDoubleMatrix(int rows, int cols, double matrix[rows][cols])
{
    for (int i = 0; i < rows; i = i + 1)
    {
        for (int j = 0; j < cols; j = j + 1)
        {
            printf("%5.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Metodo_11 - 09E1
void metodo_11()
{
    int rows = 0, cols = 0;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &rows);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100)
    {
        printf("Dimensoes invalidas!\n");
        IO_pause("Aperte ENTER para continuar");
        return;
    }

    double matrix[rows][cols];

    for (int i = 0; i < rows; i = i + 1)
    {
        for (int j = 0; j < cols; j = j + 1)
        {
            matrix[i][j] = 1 + j + i * cols;
        }
    }

    printf("\nMatriz gerada (09E1):\n");
    printDoubleMatrix(rows, cols, matrix);
    fprintDoubleMatrix("MATRIZ_09E1.TXT", rows, cols, matrix);

    IO_pause("Aperte ENTER para continuar");
}

// Metodo_12 - 09E2
void metodo_12()
{
    int rows = 0, cols = 0;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &rows);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100)
    {
        printf("Dimensoes invalidas!\n");
        IO_pause("Aperte ENTER para continuar");
        return;
    }

    double matrix[rows][cols];
    int valor = rows * cols;

    for (int i = 0; i < rows; i = i + 1)
    {
        for (int j = 0; j < cols; j = j + 1)
        {
            matrix[i][j] = valor;
            valor = valor - 1;
        }
    }

    printf("\nMatriz gerada (09E2):\n");
    printDoubleMatrix(rows, cols, matrix);
    fprintDoubleMatrix("MATRIZ_09E2.TXT", rows, cols, matrix);

    IO_pause("Aperte ENTER para continuar");
}

// Main para testes
int main()
{
    int opcao = 0;

    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("11 - Metodo_11 (09E1)\n");
        printf("12 - Metodo_12 (09E2)\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do teclado

        switch (opcao)
        {
        case 11:
            metodo_11();
            break;
        case 12:
            metodo_12();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
