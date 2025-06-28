#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void printIntArray(int n, int array[])
{
    // definir dado local
    int x = 0;

    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // mostrar valor
        IO_printf("%2d: %d\n", x, array[x]);
    } // end for
} // end printIntArray ( )
/**
   Metodo_01 - Mostrar certa quantidade de valores.
 */
void metodo_01()
{
    // definir dado
    int array[] = {1, 2, 3, 4, 5};

    // identificar
    IO_id("Metodo_01 - v0.0");

    // executar o metodo auxiliar
    printIntArray(5, array);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_01 ( )
void readIntArray(int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);

    // ler e guardar valores em arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // ler valor
        strcpy(text, STR_EMPTY);
        y = IO_readint(IO_concat(
            IO_concat(text, IO_toString_d(x)), " : "));
        // guardar valor
        array[x] = y;
    } // end for
} // end readIntArray ( )

/**
   Metodo_02.
 */
void metodo_02()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array[n];

    // identificar
    IO_id("Metodo_02 - v0.0");

    // ler dados
    readIntArray(n, array);

    // mostrar dados
    IO_printf("\n");
    printIntArray(n, array);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_02 ( )
void fprintIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0;

    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", n);

    // gravar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%d\n", array[x]);
    } // end for

    // fechar arquivo
    fclose(arquivo);
} // end fprintIntArray ( )

/**
   Metodo_03.
 */
void metodo_03()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array[n];

    // identificar
    IO_id("Metodo_03 - v0.0");

    // ler dados
    readIntArray(n, array);

    // mostrar dados
    IO_printf("\n");
    fprintIntArray("ARRAY1.TXT", n, array);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_03 ( )
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // end if

    // retornar dado lido
    return (n);
} // end freadArraySize ( )

/**
   freadIntArray         - Ler arranjo com valores inteiros.
   @param fileName - nome do arquivo
   @param n              - quantidade de valores
   @param array        - grupo de valores inteiros
 */
void freadIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);

    if (n <= 0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < n)
        {
            // ler valor
            IO_fscanf(arquivo, "%d", &y);
            // guardar valor
            array[x] = y;
            // passar ao proximo
            x = x + 1;
        } // end while
    } // end if

} // end freadIntArray ( )

/**
   Metodo_04.
 */
void metodo_04()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Metodo_04 - v0.0");

    // ler dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar dados
        IO_printf("\n");
        printIntArray(n, array);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_04 ( )
void copyIntArray(int n, int copy[], int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    else
    {
        // copiar valores em arranjo
        for (x = 0; x < n; x = x + 1)
        {
            // copiar valor
            copy[x] = array[x];
        } // end for
    } // end if
} // end copyIntArray ( )

/**
   Metodo_05.
 */
void metodo_05()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Metodo_05 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_05 ( )
int sumIntArray(int n, int array[])
{
    // definir dados locais
    int soma = 0;
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        soma = soma + array[x];
    } // end for
    // retornar resposta
    return (soma);
} // end sumIntArray ( )

/**
   Metodo_06.
 */
void metodo_06()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Metodo_06 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar a soma dos valores no arranjo
        IO_printf("\nSoma = %d\n", sumIntArray(n, array));
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_06 ( )
bool isAllZeros(int n, int array[])
{
    // definir dados locais
    bool result = true;
    int x = 0;

    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array[x] == 0);
        // passar ao proximo
        x = x + 1;
    } // end while

    // retornar resposta
    return (result);
} // end isAllZeros ( )

/**
   Metodo_07.
 */
void metodo_07()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array1[] = {0, 0, 0, 0, 0};
    int array2[] = {1, 2, 3, 4, 5};
    int array3[] = {1, 2, 0, 4, 5};

    // identificar
    IO_id("Metodo_07 - v0.0");

    // testar dados
    IO_println("\nArray1");
    printIntArray(n, array1);
    IO_printf("isAllZeros (array1) = %d", isAllZeros(n, array1));

    IO_println("\nArray2");
    printIntArray(n, array2);
    IO_printf("isAllZeros (array2) = %d", isAllZeros(n, array2));

    IO_println("\nArray3");
    printIntArray(n, array3);
    IO_printf("isAllZeros (array3) = %d", isAllZeros(n, array3));

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_07 ( )
void addIntArray(int n, int array3[],
                 int array1[], int k, int array2[])
{
    // definir dados locais
    int x = 0;

    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        array3[x] = array1[x] + k * array2[x];
    } // end for
} // end addIntArray ( )

/**
Metodo_08.
*/
void metodo_08()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Metodo_08 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        int sum[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);

        // operar soma de arranjos
        addIntArray(n, sum, array, (-2), other);

        // mostrar resultados
        IO_printf("\nSoma\n");
        printIntArray(n, sum);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_08 ( )
bool isEqual(int n, int array1[], int array2[])
{
    // definir dados locais
    bool result = true;
    int x = 0;

    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array1[x] == array2[x]);
        // passar ao proximo
        x = x + 1;
    } // end while

    // retornar resposta
    return (result);
} // end isEqual ( )

/**
   Metodo_09.
 */
void metodo_09()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Metodo_09 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);

        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));

        // modificar um valor
        other[0] = (-1) * other[0];

        // mostrar dados
        IO_printf("\nCopia alterada\n");
        printIntArray(n, other);

        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_09 ( )
bool searchArray(int value, int n, int array[])
{
    // definir dados locais
    bool result = false;
    int x = 0;

    // mostrar valores no arranjo
    x = 0;
    while (x < n && !result)
    {
        // testar valor
        result = (value == array[x]);
        // passar ao proximo
        x = x + 1;
    } // end while

    // retornar resposta
    return (result);
} // end searchArray ( )

/**
   Metodo_10.
 */
void metodo_10()
{
    // definir dados
    int n = 0;     // quantidade de valores
    int value = 0; // valor a ser procurado

    // identificar
    IO_id("Metodo_10 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);

        // mostrar resultados de procuras
        value = array[0];
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));

        value = array[n / 2];
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));

        value = array[n - 1];
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));

        value = (-1);
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_10 ( )
int main()
{
    // definir dado local
    int option = 0;

    // identificar
    IO_id("EXEMPLO0800 - Programa - v0.0");

    // repetir enquanto opcao for diferente de zero
    do
    {
        // mostrar opcoes
        IO_println("\nOpcoes:");
        IO_println(" 1 - Mostrar arranjo");
        IO_println(" 2 - Ler arranjo");
        IO_println(" 3 - Gravar arranjo");
        IO_println(" 4 - Ler e mostrar arranjo");
        IO_println(" 5 - Copiar arranjo");
        IO_println(" 6 - Somar arranjos");
        IO_println(" 7 - Testar se todos os valores sao zeros");
        IO_println(" 8 - Somar arranjos com fator");
        IO_println(" 9 - Comparar arranjos");
        IO_println("10 - Procurar valor em arranjo");
        IO_println("0 - Sair");

        // ler opcao
        option = IO_readint("Escolher: ");

        // testar a opcao
        switch (option)
        {
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
            if (option != 0)
                IO_printf("\nERRO: Opcao invalida.\n");
        } // end switch

    } while (option != 0);

    // encerrar
    return (0);
}