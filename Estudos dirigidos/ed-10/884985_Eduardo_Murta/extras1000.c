#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

typedef int *ints;

typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
    int iy;
} int_Array;

typedef int_Array *ref_int_Array;

typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints *data;
    int ix;
    int iy;
} int_Matrix;

typedef int_Matrix *ref_int_Matrix;

// Métodos base (do arquivo original)
ref_int_Array new_int_Array(int n)
{
    ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));
    if (tmpArray == NULL)
    {
        IO_printf("\nERRO: Falta espaco.\n");
    }
    else
    {
        tmpArray->length = 0;
        tmpArray->data = NULL;
        tmpArray->ix = -1;
        if (n > 0)
        {
            tmpArray->length = n;
            tmpArray->data = (ints)malloc(n * sizeof(int));
            tmpArray->ix = 0;
        }
    }
    return tmpArray;
}

void free_int_Array(ref_int_Array tmpArray)
{
    if (tmpArray != NULL)
    {
        if (tmpArray->data != NULL)
        {
            free(tmpArray->data);
        }
        free(tmpArray);
    }
}

void printIntArray(int_Array array)
{
    if (array.data)
    {
        for (array.ix = 0; array.ix < array.length; array.ix++)
        {
            printf("%2d: %d\n", array.ix, array.data[array.ix]);
        }
    }
}

ref_int_Matrix new_int_Matrix(int rows, int columns)
{
    ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    if (tmpMatrix != NULL)
    {
        tmpMatrix->rows = 0;
        tmpMatrix->columns = 0;
        tmpMatrix->data = NULL;
        if (rows > 0 && columns > 0)
        {
            tmpMatrix->rows = rows;
            tmpMatrix->columns = columns;
            tmpMatrix->data = malloc(rows * sizeof(ints));
            if (tmpMatrix->data)
            {
                for (tmpMatrix->ix = 0; tmpMatrix->ix < tmpMatrix->rows; tmpMatrix->ix++)
                {
                    tmpMatrix->data[tmpMatrix->ix] = (ints)malloc(columns * sizeof(int));
                }
            }
        }
        tmpMatrix->ix = 0;
        tmpMatrix->iy = 0;
    }
    return tmpMatrix;
}

void free_int_Matrix(ref_int_Matrix matrix)
{
    if (matrix != NULL)
    {
        if (matrix->data != NULL)
        {
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
            {
                free(matrix->data[matrix->ix]);
            }
            free(matrix->data);
        }
        free(matrix);
    }
}

void printIntMatrix(ref_int_Matrix matrix)
{
    if (matrix != NULL && matrix->data != NULL)
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
            {
                printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
            }
            printf("\n");
        }
    }
}

ref_int_Array readArrayFromFile(chars fileName)
{
    FILE *arquivo = fopen(fileName, "rt");
    ref_int_Array array = NULL;
    int n = 0;

    if (arquivo)
    {
        fscanf(arquivo, "%d", &n);
        if (n > 0)
        {
            array = new_int_Array(n);
            if (array != NULL && array->data != NULL)
            {
                for (array->ix = 0; array->ix < array->length; array->ix++)
                {
                    fscanf(arquivo, "%d", &array->data[array->ix]);
                }
            }
        }
        fclose(arquivo);
    }
    return array;
}

ref_int_Matrix readMatrixFromFile(chars fileName)
{
    FILE *arquivo = fopen(fileName, "rt");
    ref_int_Matrix matrix = NULL;
    int rows = 0, columns = 0;

    if (arquivo)
    {
        fscanf(arquivo, "%d", &rows);
        fscanf(arquivo, "%d", &columns);
        if (rows > 0 && columns > 0)
        {
            matrix = new_int_Matrix(rows, columns);
            if (matrix != NULL && matrix->data != NULL)
            {
                for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
                {
                    for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
                    {
                        fscanf(arquivo, "%d", &matrix->data[matrix->ix][matrix->iy]);
                    }
                }
            }
        }
        fclose(arquivo);
    }
    return matrix;
}

// Exercício E1
ref_int_Array sortArrayDown(ref_int_Array array)
{
    if (array != NULL && array->data != NULL)
    {
        for (array->ix = 0; array->ix < array->length - 1; array->ix++)
        {
            for (array->iy = array->ix + 1; array->iy < array->length; array->iy++)
            {
                if (array->data[array->ix] < array->data[array->iy])
                {
                    int temp = array->data[array->ix];
                    array->data[array->ix] = array->data[array->iy];
                    array->data[array->iy] = temp;
                }
            }
        }
    }
    return array;
}

void method_E1()
{
    ref_int_Array array = NULL;

    IO_id("Method_E1 - Ordenar arranjo em ordem decrescente");

    array = readArrayFromFile("DADOS1.TXT");

    if (array != NULL && array->data != NULL)
    {
        IO_printf("\nArranjo original:\n");
        printIntArray(*array);

        sortArrayDown(array);

        IO_printf("\nArranjo ordenado:\n");
        printIntArray(*array);
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel ler o arquivo ou arquivo vazio.\n");
    }

    free_int_Array(array);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício E2
ref_int_Matrix matrixProduct(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
    ref_int_Matrix produto = NULL;

    if (matrix1 != NULL && matrix2 != NULL &&
        matrix1->columns == matrix2->rows)
    {

        produto = new_int_Matrix(matrix1->rows, matrix2->columns);

        if (produto != NULL && produto->data != NULL)
        {
            for (produto->ix = 0; produto->ix < produto->rows; produto->ix++)
            {
                for (produto->iy = 0; produto->iy < produto->columns; produto->iy++)
                {
                    produto->data[produto->ix][produto->iy] = 0;
                    for (int k = 0; k < matrix1->columns; k++)
                    {
                        produto->data[produto->ix][produto->iy] +=
                            matrix1->data[produto->ix][k] * matrix2->data[k][produto->iy];
                    }
                }
            }
        }
    }

    return produto;
}

int identityMatrix(ref_int_Matrix matrix)
{
    int resposta = 1; // Assume que é identidade

    if (matrix == NULL || matrix->data == NULL ||
        matrix->rows != matrix->columns)
    {
        resposta = 0;
    }
    else
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
            {
                if (matrix->ix == matrix->iy && matrix->data[matrix->ix][matrix->iy] != 1)
                {
                    resposta = 0;
                    matrix->ix = matrix->rows;    // Sair do loop externo
                    matrix->iy = matrix->columns; // Sair do loop interno
                }
                else if (matrix->ix != matrix->iy && matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    resposta = 0;
                    matrix->ix = matrix->rows;    // Sair do loop externo
                    matrix->iy = matrix->columns; // Sair do loop interno
                }
            }
        }
    }

    return resposta;
}

void method_E2()
{
    ref_int_Matrix matrix1 = NULL, matrix2 = NULL, product = NULL;

    IO_id("Method_E2 - Verificar se produto de matrizes é identidade");

    matrix1 = readMatrixFromFile("DADOS1.TXT");
    matrix2 = readMatrixFromFile("DADOS2.TXT");

    if (matrix1 != NULL && matrix2 != NULL &&
        matrix1->data != NULL && matrix2->data != NULL)
    {

        product = matrixProduct(matrix1, matrix2);

        if (product != NULL && product->data != NULL)
        {
            IO_printf("\nMatriz 1:\n");
            printIntMatrix(matrix1);
            IO_printf("\nMatriz 2:\n");
            printIntMatrix(matrix2);
            IO_printf("\nProduto:\n");
            printIntMatrix(product);

            int resultado = identityMatrix(product);
            IO_printf("\nO produto %s a matriz identidade\n",
                      resultado ? "é" : "não é");
        }
        else
        {
            IO_printf("ERRO: Nao foi possivel multiplicar as matrizes.\n");
        }
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel ler os arquivos ou arquivos vazios.\n");
    }

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
    free_int_Matrix(product);
    IO_pause("Apertar ENTER para continuar");
}

int main(void)
{
    int opcao = 0;

    do
    {
        printf("\n"); // para saltar linha
        printf("%s\n", "Matricula: 884985 Nome: Eduardo Murta De Abreu");

        printf("%s\n", "Opcoes:");
        printf("%s\n", " 0 - parar");
        printf("%s\n", " E1 - Ordenar arranjo decrescente");
        printf("%s\n", " E2 - Verificar produto como identidade");
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
            method_E1();
            break;
        case 2:
            method_E2();
            break;
        default:
            printf("\n%s\n\n", "ERRO: Opcao invalida.");
            break;
        }
    } while (opcao != 0);

    printf("\n%s\n\n", "Apertar ENTER para terminar.");
    getchar();
    return 0;
}