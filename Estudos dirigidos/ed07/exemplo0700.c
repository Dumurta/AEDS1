/*
    Exercicios 0700
    @author: Eduardo Murta De Abreu - 884985
    writeINTS - gravar em arquivo texto certa quantidade de valores
    Duvida: pra que serve o @param @param x que tem em todo ED, anotado apenas pra lembrar na aula
    @param fileName - nome do arquivo
    @param x - quantidade de valores
*/
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void writeInts(chars fileName, int x)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;
    // repetir para a quantidade de dados
    for (y = 1; y <= x; y = y + 1)
    {
        // gravar valor
        fprintf(arquivo, "%d\n", y);
    } // end for
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // end writeInts ( )

/*
    Metodo_01 - mostra certa quantidade de valores
*/
void metodo_01()
{
    // identificar
    IO_id("Metodo_01 - v0.0");
    // executar metodo auxiliar
    writeInts("DADOS1.txt", 10);

    // encerrar
    IO_pause("Apertar ENTER para continuar...");
} // end metodo_01
void readInts(chars fileName)
{
    // def dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;

    // tentar ler o primeiro
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados
    while (!feof(arquivo))
    {
        // mostrar valor lido
        IO_printf("%d\n", x);
        // ler proximo valor
        fscanf(arquivo, "%d", &x);
    } // end while
    // fechar arquivo(recomendavel para a leitura)
    fclose(arquivo);
} // end readints
/*
    Metodo_02
*/
void metodo_02()
{
    // identificar
    IO_id("Metodo_02 - v0.0");

    // executar o metodo auxiliar
    readInts("DADOS1.TXT");

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_02()
void writeDoubles(chars fileName, int x)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;
    // gravar quantidade de valores
    IO_fprintf(arquivo, "%d\n", x);
    // repetir para a quantidade de dados
    for (y = 1; y <= x; y = y + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%lf\n", (0.1 * y));
    } // end for
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // end writeDoubles ( )
/*
    Metodo_03
*/
void metodo_03()
{
    // identificar
    IO_id("Metodo_03 - v0.0");
    // executar o metodo auxiliar
    writeDoubles("DADOS2.txt", 10);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_03()
void readDoubles(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;
    int y = 1;
    double z = 0.0;
    // tentar ler a quantidade de dados
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados e
    // quantidade nao tiver sido alcancada
    while (!feof(arquivo) && y <= x)
    {
        // tentar ler
        fscanf(arquivo, "%lf", &z);
        // mostrar valor
        printf("%2d: %lf\n", y, z);
        // passar ao proximo
        y = y + 1;
    } // end while
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // end readDoubles ( )
/**
 Method_04.
*/
void metodo_04()
{
    // identificar
    IO_id("Method_04 - v0.0");
    // executar o metodo auxiliar
    readDoubles("DADOS2.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )
void writeTEXT(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    chars linha = IO_new_chars(STR_SIZE);

    // repetir ate desejar parar
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"): \n");
    do
    {
        // ler do teclado
        strcpy(linha, IO_readln(""));
        // gravar valor
        IO_fprintf(arquivo, "%s\n", linha);
    } while (strcmp("PARAR", linha) != 0);

    // fechar arquivo (indispensavel para gravacao)
    fclose(arquivo);
} // end writeText()

/*
    Metodo_05
*/
void metodo_05()
{
    // identificar
    IO_id("Metodo_05 - v0.0");
    // executar metodo auxiliar
    writeTEXT("DADOS3.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end metodo_05()
void readText(chars fileName)
{
    // def dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    // tentar ler o primeiro
    strcpy(linha, IO_freadln(arquivo));
    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0)
    {
        // mostrar valor
        printf("%s\n", linha);
        // tentar ler o proximo
        strcpy(linha, IO_freadln(arquivo));
    } // end while
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // end readText ( )
/**
 Method_06.
*/
void metodo_06()
{
    // identificar
    IO_id("Metodo_06 - v0.0");
    // executar o metodo auxiliar
    readText("DADOS3.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )
void copyText(chars fileOut, chars fileIn)
{
    // definir dados
    FILE *saida = fopen(fileOut, "wt");
    FILE *entrada = fopen(fileIn, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int contador = 0;
    // ler da origem
    strcpy(linha, IO_freadln(entrada));
    // repetir enquanto houver dados
    while (!feof(entrada))
    {
        // contar linha lida
        contador = contador + 1;
        // gravar no destino,
        // EXCEPCIONALMENTE sem a ultima linha, nesse caso
        if (strcmp("PARAR", linha) != 0)
        {
            IO_fprintln(saida, linha);
        } // end if
        // ler da origem
        strcpy(linha, IO_freadln(entrada));
    } // end while
    // informar total de linhas copiadas
    IO_printf("Lines read = %d\n", contador);
    // fechar arquivos
    fclose(saida);
    fclose(entrada);
} // end copyText ( )
/**
 Method_07.
*/
void metodo_07()
{
    // identificar
    IO_id("Method_07 - v0.0");
    // executar o metodo auxiliar
    copyText("DADOS4.TXT", "DADOS3.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )
void appendText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "at");
    chars linha = IO_new_chars(STR_SIZE);
    // repetir ate' desejar parar
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
    do
    {
        // ler do teclado
        strcpy(linha, IO_readln(""));
        // gravar valor
        IO_fprintln(arquivo, linha);
    } while (strcmp("PARAR", linha) != 0);
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // end appendText ( )
/**
 Method_08.
*/
void metodo_08()
{
    // identificar
    IO_id("EXEMPLO0710 - Method_08 - v0.0");
    // executar o metodo auxiliar
    appendText("DADOS4.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_08 ( )
void readWords(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    // tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));
    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0)
    {
        // mostrar valor
        printf("%s\n", linha);
        // tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    } // end while
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // end readWords ( )
/**
 Method_09.
*/
void metodo_09()
{
    // identificar
    IO_id("Method_09 - v0.0");
    // executar o metodo auxiliar
    readWords("DADOS4.TXT");
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )
bool searchWord(chars fileName, chars word)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    // tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));
    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp(word, linha) != 0)
    {
        // tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    } // end while
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);

    // retornar resultado
    return (strcmp(word, linha) == 0);
} // end ifarchdWord ( )
/**
 Method_10.
*/
void metodo_10()
{
    // identificar
    IO_id("Method_10 - v0.0");
    // procurar palavra
    IO_printf("Procurar (\"%s\") = %d\n", "pqr", searchWord("DADOS4.TXT", "pqr"));
    IO_printf("Procurar (\"%s\") = %d\n", "pqs", searchWord("DADOS4.TXT", "pqs"));
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_10 ( )

int main(void)
{
    // def da do
    int opcao = 0;
    // identificar
    IO_id("EXEMPLO07 - Programa - v0.0");

    do
    {
        // apresentar metodos
        IO_printf("Opcao 0: Sair\n");
        IO_printf("Opcao 1: Metodo 01\n");
        IO_printf("Opcao 2: Metodo 02\n");
        IO_printf("Opcao 3: Metodo 03\n");
        IO_printf("Opcao 4: Metodo 04\n");
        IO_printf("Opcao 5: Metodo 05\n");
        IO_printf("Opcao 6: Metodo 06\n");
        IO_printf("Opcao 7: Metodo 07\n");
        IO_printf("Opcao 8: Metodo 08\n");
        IO_printf("Opcao 9: Metodo 09\n");
        IO_printf("Opcao 10: Metodo 10\n");
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