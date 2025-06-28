#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "io.h"

#define STR_SIZE 100
#define STR_EMPTY ""

typedef int *ints;

typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
} int_Array;

typedef int_Array *ref_int_Array;

typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints *data;
    int ix, iy;
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

// Exercício 1011
int RandomIntGenerate(int inferior, int superior)
{
    return inferior + rand() % (superior - inferior + 1);
}

void method_01()
{
    int inferior, superior, n;
    ref_int_Array array = NULL;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    IO_id("Method_01 - Gerar valores aleatorios");

    // Ler limites do intervalo
    inferior = IO_readint("Limite inferior: ");
    superior = IO_readint("Limite superior: ");

    // Ler quantidade de elementos
    do
    {
        n = IO_readint("Quantidade de elementos a gerar: ");
    } while (n <= 0);

    // Criar array
    array = new_int_Array(n);

    // Gerar valores aleatórios
    if (array != NULL && array->data != NULL)
    {
        for (array->ix = 0; array->ix < array->length; array->ix++)
        {
            array->data[array->ix] = RandomIntGenerate(inferior, superior);
        }

        // Gravar no arquivo
        FILE *arquivo = fopen("DADOS.TXT", "wt");
        if (arquivo)
        {
            fprintf(arquivo, "%d\n", n);
            for (array->ix = 0; array->ix < array->length; array->ix++)
            {
                fprintf(arquivo, "%d\n", array->data[array->ix]);
            }
            fclose(arquivo);
            IO_printf("Dados gravados em DADOS.TXT\n");
        }
        else
        {
            IO_printf("ERRO: Nao foi possivel criar o arquivo.\n");
        }

        // Mostrar valores gerados
        printIntArray(*array);
    }

    // Liberar memória
    free_int_Array(array);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1012
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

int arraySearch(int valor, ref_int_Array array)
{
    int resposta = -1; // Não encontrado

    if (array != NULL && array->data != NULL)
    {
        for (array->ix = 0; array->ix < array->length; array->ix++)
        {
            if (array->data[array->ix] == valor)
            {
                resposta = array->ix;
                array->ix = array->length; // Sair do loop
            }
        }
    }

    return resposta;
}

void method_02()
{
    ref_int_Array array = NULL;
    int valor, posicao;

    IO_id("Method_02 - Procurar valor em arranjo");

    array = readArrayFromFile("DADOS.TXT");

    if (array != NULL && array->data != NULL)
    {
        valor = IO_readint("Valor a procurar: ");
        posicao = arraySearch(valor, array);

        if (posicao >= 0)
        {
            IO_printf("Valor encontrado na posicao %d\n", posicao);
        }
        else
        {
            IO_printf("Valor nao encontrado no arranjo\n");
        }

        printIntArray(*array);
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel ler o arquivo ou arquivo vazio.\n");
    }

    free_int_Array(array);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1013
int arrayCompare(ref_int_Array array1, ref_int_Array array2)
{
    int resposta = 1; // Assume que são iguais

    if (array1 == NULL || array2 == NULL ||
        array1->length != array2->length)
    {
        resposta = 0;
    }
    else
    {
        for (array1->ix = 0; array1->ix < array1->length; array1->ix++)
        {
            if (array1->data[array1->ix] != array2->data[array1->ix])
            {
                resposta = 0;
                array1->ix = array1->length; // Sair do loop
            }
        }
    }

    return resposta;
}

void method_03()
{
    ref_int_Array array1 = NULL, array2 = NULL;

    IO_id("Method_03 - Comparar dois arranjos");

    array1 = readArrayFromFile("DADOS.TXT");
    array2 = readArrayFromFile("DADOS.TXT"); // Usando o mesmo arquivo para teste

    if (array1 != NULL && array2 != NULL &&
        array1->data != NULL && array2->data != NULL)
    {

        int resultado = arrayCompare(array1, array2);

        if (resultado)
        {
            IO_printf("Os arranjos sao iguais\n");
        }
        else
        {
            IO_printf("Os arranjos sao diferentes\n");
        }

        IO_printf("\nArranjo 1:\n");
        printIntArray(*array1);
        IO_printf("\nArranjo 2:\n");
        printIntArray(*array2);
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel ler os arquivos ou arquivos vazios.\n");
    }

    free_int_Array(array1);
    free_int_Array(array2);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1014
ref_int_Array arrayAdd(ref_int_Array array1, int constante, ref_int_Array array2)
{
    ref_int_Array soma = NULL;

    if (array1 != NULL && array2 != NULL &&
        array1->length == array2->length)
    {

        soma = new_int_Array(array1->length);

        if (soma != NULL && soma->data != NULL)
        {
            for (soma->ix = 0; soma->ix < soma->length; soma->ix++)
            {
                soma->data[soma->ix] = array1->data[soma->ix] + (constante * array2->data[soma->ix]);
            }
        }
    }

    return soma;
}

void method_04()
{
    ref_int_Array array1 = NULL, array2 = NULL, soma = NULL;
    int constante;

    IO_id("Method_04 - Somar dois arranjos");

    array1 = readArrayFromFile("DADOS.TXT");
    array2 = readArrayFromFile("DADOS.TXT"); // Usando o mesmo arquivo para teste
    constante = IO_readint("Constante para multiplicar o segundo arranjo: ");

    if (array1 != NULL && array2 != NULL &&
        array1->data != NULL && array2->data != NULL)
    {

        soma = arrayAdd(array1, constante, array2);

        if (soma != NULL && soma->data != NULL)
        {
            IO_printf("\nArranjo 1:\n");
            printIntArray(*array1);
            IO_printf("\nArranjo 2 (multiplicado por %d):\n", constante);
            printIntArray(*array2);
            IO_printf("\nSoma:\n");
            printIntArray(*soma);
        }
        else
        {
            IO_printf("ERRO: Nao foi possivel somar os arranjos.\n");
        }
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel ler os arquivos ou arquivos vazios.\n");
    }

    free_int_Array(array1);
    free_int_Array(array2);
    free_int_Array(soma);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1015
int isArrayDecrescent(ref_int_Array array)
{
    int resposta = 1; // Assume que é decrescente

    if (array != NULL && array->data != NULL && array->length > 1)
    {
        for (array->ix = 1; array->ix < array->length; array->ix++)
        {
            if (array->data[array->ix - 1] < array->data[array->ix])
            {
                resposta = 0;
                array->ix = array->length; // Sair do loop
            }
        }
    }

    return resposta;
}

void method_05()
{
    ref_int_Array array = NULL;

    IO_id("Method_05 - Verificar se arranjo esta em ordem decrescente");

    array = readArrayFromFile("DADOS.TXT");

    if (array != NULL && array->data != NULL)
    {
        int resultado = isArrayDecrescent(array);

        if (resultado)
        {
            IO_printf("O arranjo esta em ordem decrescente\n");
        }
        else
        {
            IO_printf("O arranjo NAO esta em ordem decrescente\n");
        }

        printIntArray(*array);
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel ler o arquivo ou arquivo vazio.\n");
    }

    free_int_Array(array);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1016
ref_int_Matrix matrixTranspose(ref_int_Matrix matrix)
{
    ref_int_Matrix transposta = NULL;

    if (matrix != NULL && matrix->data != NULL)
    {
        transposta = new_int_Matrix(matrix->columns, matrix->rows);

        if (transposta != NULL && transposta->data != NULL)
        {
            for (transposta->ix = 0; transposta->ix < transposta->rows; transposta->ix++)
            {
                for (transposta->iy = 0; transposta->iy < transposta->columns; transposta->iy++)
                {
                    transposta->data[transposta->ix][transposta->iy] = matrix->data[transposta->iy][transposta->ix];
                }
            }
        }
    }

    return transposta;
}

void method_06()
{
    ref_int_Matrix matrix = NULL, transposta = NULL;

    IO_id("Method_06 - Obter matriz transposta");

    // Criar uma matriz de exemplo 2x3
    matrix = new_int_Matrix(2, 3);
    if (matrix != NULL && matrix->data != NULL)
    {
        matrix->data[0][0] = 1;
        matrix->data[0][1] = 2;
        matrix->data[0][2] = 3;
        matrix->data[1][0] = 4;
        matrix->data[1][1] = 5;
        matrix->data[1][2] = 6;

        transposta = matrixTranspose(matrix);

        if (transposta != NULL && transposta->data != NULL)
        {
            IO_printf("\nMatriz original:\n");
            printIntMatrix(matrix);
            IO_printf("\nMatriz transposta:\n");
            printIntMatrix(transposta);
        }
        else
        {
            IO_printf("ERRO: Nao foi possivel calcular a transposta.\n");
        }
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel criar a matriz.\n");
    }

    free_int_Matrix(matrix);
    free_int_Matrix(transposta);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1017
int matrixZero(ref_int_Matrix matrix)
{
    int resposta = 1; // Assume que é toda zero

    if (matrix != NULL && matrix->data != NULL)
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
            {
                if (matrix->data[matrix->ix][matrix->iy] != 0)
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

void method_07()
{
    ref_int_Matrix matrix = NULL;

    IO_id("Method_07 - Testar se matriz contem apenas zeros");

    // Criar matriz de exemplo
    matrix = new_int_Matrix(3, 3);
    if (matrix != NULL && matrix->data != NULL)
    {
        // Preencher com zeros para teste
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
            {
                matrix->data[matrix->ix][matrix->iy] = 0;
            }
        }
        // Alterar um valor para testar
        // matrix->data[1][1] = 1;

        int resultado = matrixZero(matrix);

        if (resultado)
        {
            IO_printf("A matriz contem apenas zeros\n");
        }
        else
        {
            IO_printf("A matriz NAO contem apenas zeros\n");
        }

        printIntMatrix(matrix);
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel criar a matriz.\n");
    }

    free_int_Matrix(matrix);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1018
int matrixCompare(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
    int resposta = 1; // Assume que são iguais

    if (matrix1 == NULL || matrix2 == NULL ||
        matrix1->rows != matrix2->rows ||
        matrix1->columns != matrix2->columns)
    {
        resposta = 0;
    }
    else
    {
        for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix++)
        {
            for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy++)
            {
                if (matrix1->data[matrix1->ix][matrix1->iy] !=
                    matrix2->data[matrix1->ix][matrix1->iy])
                {
                    resposta = 0;
                    matrix1->ix = matrix1->rows;    // Sair do loop externo
                    matrix1->iy = matrix1->columns; // Sair do loop interno
                }
            }
        }
    }

    return resposta;
}

void method_08()
{
    ref_int_Matrix matrix1 = NULL, matrix2 = NULL;

    IO_id("Method_08 - Comparar duas matrizes");

    // Criar duas matrizes idênticas para teste
    matrix1 = new_int_Matrix(2, 2);
    matrix2 = new_int_Matrix(2, 2);

    if (matrix1 != NULL && matrix2 != NULL &&
        matrix1->data != NULL && matrix2->data != NULL)
    {
        // Preencher matriz1
        matrix1->data[0][0] = 1;
        matrix1->data[0][1] = 2;
        matrix1->data[1][0] = 3;
        matrix1->data[1][1] = 4;

        // Preencher matriz2 (igual a matriz1)
        matrix2->data[0][0] = 1;
        matrix2->data[0][1] = 2;
        matrix2->data[1][0] = 3;
        matrix2->data[1][1] = 4;

        int resultado = matrixCompare(matrix1, matrix2);

        if (resultado)
        {
            IO_printf("As matrizes sao iguais\n");
        }
        else
        {
            IO_printf("As matrizes sao diferentes\n");
        }

        IO_printf("\nMatriz 1:\n");
        printIntMatrix(matrix1);
        IO_printf("\nMatriz 2:\n");
        printIntMatrix(matrix2);
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel criar as matrizes.\n");
    }

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1019
ref_int_Matrix matrixAdd(ref_int_Matrix matrix1, int constante, ref_int_Matrix matrix2)
{
    ref_int_Matrix soma = NULL;

    if (matrix1 != NULL && matrix2 != NULL &&
        matrix1->rows == matrix2->rows &&
        matrix1->columns == matrix2->columns)
    {

        soma = new_int_Matrix(matrix1->rows, matrix1->columns);

        if (soma != NULL && soma->data != NULL)
        {
            for (soma->ix = 0; soma->ix < soma->rows; soma->ix++)
            {
                for (soma->iy = 0; soma->iy < soma->columns; soma->iy++)
                {
                    soma->data[soma->ix][soma->iy] =
                        matrix1->data[soma->ix][soma->iy] +
                        (constante * matrix2->data[soma->ix][soma->iy]);
                }
            }
        }
    }

    return soma;
}

void method_09()
{
    ref_int_Matrix matrix1 = NULL, matrix2 = NULL, soma = NULL;
    int constante;

    IO_id("Method_09 - Somar duas matrizes");

    // Criar duas matrizes para teste
    matrix1 = new_int_Matrix(2, 2);
    matrix2 = new_int_Matrix(2, 2);
    constante = IO_readint("Constante para multiplicar a segunda matriz: ");

    if (matrix1 != NULL && matrix2 != NULL &&
        matrix1->data != NULL && matrix2->data != NULL)
    {
        // Preencher matriz1
        matrix1->data[0][0] = 1;
        matrix1->data[0][1] = 2;
        matrix1->data[1][0] = 3;
        matrix1->data[1][1] = 4;

        // Preencher matriz2
        matrix2->data[0][0] = 5;
        matrix2->data[0][1] = 6;
        matrix2->data[1][0] = 7;
        matrix2->data[1][1] = 8;

        soma = matrixAdd(matrix1, constante, matrix2);

        if (soma != NULL && soma->data != NULL)
        {
            IO_printf("\nMatriz 1:\n");
            printIntMatrix(matrix1);
            IO_printf("\nMatriz 2 (multiplicada por %d):\n", constante);
            printIntMatrix(matrix2);
            IO_printf("\nSoma:\n");
            printIntMatrix(soma);
        }
        else
        {
            IO_printf("ERRO: Nao foi possivel somar as matrizes.\n");
        }
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel criar as matrizes.\n");
    }

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
    free_int_Matrix(soma);
    IO_pause("Apertar ENTER para continuar");
}

// Exercício 1020
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

void method_10()
{
    ref_int_Matrix matrix1 = NULL, matrix2 = NULL, produto = NULL;

    IO_id("Method_10 - Multiplicar duas matrizes");

    // Criar duas matrizes para teste (2x3 e 3x2)
    matrix1 = new_int_Matrix(2, 3);
    matrix2 = new_int_Matrix(3, 2);

    if (matrix1 != NULL && matrix2 != NULL &&
        matrix1->data != NULL && matrix2->data != NULL)
    {
        // Preencher matriz1 (2x3)
        matrix1->data[0][0] = 1;
        matrix1->data[0][1] = 2;
        matrix1->data[0][2] = 3;
        matrix1->data[1][0] = 4;
        matrix1->data[1][1] = 5;
        matrix1->data[1][2] = 6;

        // Preencher matriz2 (3x2)
        matrix2->data[0][0] = 7;
        matrix2->data[0][1] = 8;
        matrix2->data[1][0] = 9;
        matrix2->data[1][1] = 10;
        matrix2->data[2][0] = 11;
        matrix2->data[2][1] = 12;

        produto = matrixProduct(matrix1, matrix2);

        if (produto != NULL && produto->data != NULL)
        {
            IO_printf("\nMatriz 1 (2x3):\n");
            printIntMatrix(matrix1);
            IO_printf("\nMatriz 2 (3x2):\n");
            printIntMatrix(matrix2);
            IO_printf("\nProduto (2x2):\n");
            printIntMatrix(produto);
        }
        else
        {
            IO_printf("ERRO: Nao foi possivel multiplicar as matrizes.\n");
        }
    }
    else
    {
        IO_printf("ERRO: Nao foi possivel criar as matrizes.\n");
    }

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
    free_int_Matrix(produto);
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
        printf("%s\n", " 1 - metodo 01   2 - metodo 02");
        printf("%s\n", " 3 - metodo 03   4 - metodo 04");
        printf("%s\n", " 5 - metodo 05   6 - metodo 06");
        printf("%s\n", " 7 - metodo 07   8 - metodo 08");
        printf("%s\n", " 9 - metodo 09  10 - metodo 10");
        printf("%s\n", "");

        printf("%s", "Qual a sua opcao? ");
        scanf("%d", &opcao);
        getchar();
        printf("%d", opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            method_01();
            break;
        case 2:
            method_02();
            break;
        case 3:
            method_03();
            break;
        case 4:
            method_04();
            break;
        case 5:
            method_05();
            break;
        case 6:
            method_06();
            break;
        case 7:
            method_07();
            break;
        case 8:
            method_08();
            break;
        case 9:
            method_09();
            break;
        case 10:
            method_10();
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