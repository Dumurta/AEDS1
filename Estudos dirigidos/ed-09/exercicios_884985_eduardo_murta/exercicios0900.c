#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

void readPositiveDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    for (int i = 0; i < rows; i = i + 1)
    {
        for (int j = 0; j < cols; j = j + 1)
        {
            do
            {
                printf("Digite um valor >= 0 para matrix[%d][%d]: ", i, j);
                scanf("%lf", &matrix[i][j]);
            } while (matrix[i][j] < 0.0);
        }
    }
}

void printDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    printf("Matriz:\n");
    for (int i = 0; i < rows; i = i + 1)
    {
        for (int j = 0; j < cols; j = j + 1)
        {
            printf("%6.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fprintDoubleMatrix(const char *filename, int rows, int cols, double matrix[MAX][MAX])
{
    FILE *file = fopen(filename, "wt");
    if (file != NULL)
    {
        fprintf(file, "%d %d\n", rows, cols);
        for (int i = 0; i < rows; i = i + 1)
        {
            for (int j = 0; j < cols; j = j + 1)
            {
                fprintf(file, "%lf\n", matrix[i][j]);
            }
        }
        fclose(file);
    }
}

void freadDoubleMatrix(const char *filename, int *rows, int *cols, double matrix[MAX][MAX])
{
    FILE *file = fopen(filename, "rt");
    if (file != NULL)
    {
        fscanf(file, "%d %d", rows, cols);
        for (int i = 0; i < *rows; i = i + 1)
        {
            for (int j = 0; j < *cols; j = j + 1)
            {
                fscanf(file, "%lf", &matrix[i][j]);
            }
        }
        fclose(file);
    }
}

void printDiagonalDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    if (rows == cols)
    {
        printf("Diagonal principal:\n");
        for (int i = 0; i < rows; i = i + 1)
        {
            printf("%6.2lf ", matrix[i][i]);
        }
        printf("\n");
    }
}

void printSDiagonalDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    if (rows == cols)
    {
        printf("Diagonal secundaria:\n");
        for (int i = 0; i < rows; i = i + 1)
        {
            printf("%6.2lf ", matrix[i][cols - 1 - i]);
        }
        printf("\n");
    }
}

void printLDTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    if (rows == cols)
    {
        printf("Abaixo da diagonal principal:\n");
        for (int i = 1; i < rows; i = i + 1)
        {
            for (int j = 0; j < i; j = j + 1)
            {
                printf("%6.2lf ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void printLUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    if (rows == cols)
    {
        printf("Acima da diagonal principal:\n");
        for (int i = 0; i < rows - 1; i = i + 1)
        {
            for (int j = i + 1; j < cols; j = j + 1)
            {
                printf("%6.2lf ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void printSLDTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    if (rows == cols)
    {
        printf("Abaixo/na diagonal secundaria:\n");
        for (int i = 0; i < rows; i = i + 1)
        {
            for (int j = 0; j < cols; j = j + 1)
            {
                if (i + j >= cols - 1)
                {
                    printf("%6.2lf ", matrix[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void printSLUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    if (rows == cols)
    {
        printf("Acima/na diagonal secundaria:\n");
        for (int i = 0; i < rows; i = i + 1)
        {
            for (int j = 0; j < cols; j = j + 1)
            {
                if (i + j <= cols - 1)
                {
                    printf("%6.2lf ", matrix[i][j]);
                }
            }
        }
        printf("\n");
    }
}

bool allZerosLTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    bool result = true;
    if (rows == cols)
    {
        for (int i = 1; i < rows && result; i = i + 1)
        {
            for (int j = 0; j < i; j = j + 1)
            {
                if (matrix[i][j] != 0.0)
                {
                    result = false;
                }
            }
        }
    }
    return result;
}

bool allNotZerosUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX])
{
    bool result = true;
    if (rows == cols)
    {
        for (int i = 0; i < rows - 1 && result; i = i + 1)
        {
            for (int j = i + 1; j < cols; j = j + 1)
            {
                if (matrix[i][j] == 0.0)
                {
                    result = false;
                }
            }
        }
    }
    return result;
}

void IO_pause(const char *text)
{
    char x;
    printf("\n%s\n", text);
    scanf("%c", &x);
    getchar();
}

// ---------------- MÉTODOS ------------------

void metodo_01(void)
{
    double matrix[MAX][MAX];
    int rows = 0, cols = 0;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &rows);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &cols);

    if (rows > 0 && cols > 0)
    {
        readPositiveDoubleMatrix(rows, cols, matrix);
        printDoubleMatrix(rows, cols, matrix);
    }
    else
    {
        printf("ERRO: dimensoes invalidas.\n");
    }

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_02(void)
{
    double matrix[MAX][MAX];
    int rows = 3, cols = 3;
    const char *filename = "MATRIX_01.TXT";

    readPositiveDoubleMatrix(rows, cols, matrix);
    fprintDoubleMatrix(filename, rows, cols, matrix);

    double other[MAX][MAX];
    int r = 0, c = 0;

    freadDoubleMatrix(filename, &r, &c, other);
    printDoubleMatrix(r, c, other);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_03(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);
    printDiagonalDoubleMatrix(3, 3, matrix);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_04(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);
    printSDiagonalDoubleMatrix(3, 3, matrix);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_05(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);
    printLDTriangleDoubleMatrix(3, 3, matrix);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_06(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);
    printLUTriangleDoubleMatrix(3, 3, matrix);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_07(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);
    printSLDTriangleDoubleMatrix(3, 3, matrix);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_08(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);
    printSLUTriangleDoubleMatrix(3, 3, matrix);

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_09(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);

    if (allZerosLTriangleDoubleMatrix(3, 3, matrix))
    {
        printf("Todos os valores abaixo da diagonal principal sao zeros.\n");
    }
    else
    {
        printf("Nem todos os valores abaixo da diagonal principal sao zeros.\n");
    }

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

void metodo_10(void)
{
    double matrix[MAX][MAX];
    readPositiveDoubleMatrix(3, 3, matrix);

    if (allNotZerosUTriangleDoubleMatrix(3, 3, matrix))
    {
        printf("Todos os valores acima da diagonal principal sao nao nulos.\n");
    }
    else
    {
        printf("Ha valores nulos acima da diagonal principal.\n");
    }

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

int main(void)
{
    // definir dados/resultados
    int opcao = 0;

    // repetir ate' desejar parar
    do
    {
        // identificar
        printf("\n"); // para saltar linha
        printf("%s\n", "Exemplo0900 - v.0.0");
        printf("%s\n", "Matricula: 999999 Nome: Eduardo Murta De Abreu");

        // mostrar opcoes
        printf("%s\n", "Opcoes:");
        printf("%s\n", " 0 - parar");
        printf("%s\n", " 1 - metodo 01   2 - metodo 02");
        printf("%s\n", " 3 - metodo 03   4 - metodo 04");
        printf("%s\n", " 5 - metodo 05   6 - metodo 06");
        printf("%s\n", " 7 - metodo 07   8 - metodo 08");
        printf("%s\n", " 9 - metodo 09  10 - metodo 10");
        printf("%s\n", ""); // para saltar linha

        // ler opcao
        printf("%s", "Qual a sua opcao? ");
        scanf("%d", &opcao);
        getchar();
        printf("%d", opcao);

        // escolher acao
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
            printf("\n%s\n\n", "ERRO: Opcao invalida.");
            break;
        } // fim escolher
    } while (opcao != 0);

    // encerrar execucao
    printf("\n%s\n\n", "Apertar ENTER para terminar.");
    getchar();

} // end main ( )