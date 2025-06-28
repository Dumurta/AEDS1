// 884985_EDUARDO_MURTA_DE_ABREU
#include <stdio.h>
#include <stdbool.h>
#include "mylib.h"
void metodo_01()
{
    // definir dados com valores iniciais
    int x = 0;
    char c = '0';
    double d = 0.0;
    bool b = false;
    // identificar
    printf("%s\n", "884985_EDUARDO_MURTA_DE_ABREU");
    // acoes
    // mostrar valores iniciais
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%d\n", "b = ", b);
    printf("\n");
    // alterar valores iniciais
    // por atribuicao de constantes
    x = 50;
    c = 'A';
    d = 97.0;
    b = true;
    // mostrar valores alterados
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // encerrar
    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
}

void metodo_02(void)
{
    // definir dados com valores iniciais
    int x = 0;
    char c = '0';
    double d = 0.0;
    bool b = false;
    // identificar
    printf("%s\n", "884985_EDUARDO_MURTA_DE_ABREU");
    // acoes
    // mostrar valores iniciais
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%d\n", "b = ", b);
    printf("\n");
    // alterar valores iniciais
    // por atribuicao de constantes
    x = 50;
    c = 'A';
    d = 97.0;
    b = true;
    // mostrar valores alterados
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // alterar valores iniciais
    // por atribuicao de operacoes com constantes
    x = 1 + 50;
    c = 1 + 'A';
    d = 1 + 97.0;
    b = 1 + true;
    // mostrar valores alterados
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // alterar valores
    // por operacoes aritmeticas
    // com conversoes explicitas
    x = 1 + 50;
    c = (char)(1 + (int)'A');
    d = (double)1 + 97.0;
    b = (bool)(1 + (int)true);
    // mostrar valores alterados
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // encerrar
    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
}

void metodo_03(void)
{
    // definir dados com valores iniciais
    int x = 0;
    char c = '0';
    double d = 0.0;
    bool b = false;
    // identificar
    printf("%s\n", "884985_EDUARDO_MURTA_DE_ABREU");
    // acoes
    // mostrar valores iniciais
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%d\n", "b = ", b);
    printf("\n");
    // alterar valores iniciais
    // por atribuicao de constantes
    x = 50;
    c = 'A';
    d = 97.0;
    b = true;
    // mostrar valores alterados
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // alterar valores iniciais
    // por operacoes aritmeticas
    // com conversoes explicitas
    // em funcoes
    x = 1 + 50;
    c = (char)(1 + f_caractere_para_inteiro('A'));
    d = f_inteiro_para_real(1) + 97.0;
    b = f_inteiro_para_logico(1 + (int)true);
    printf("%s%d (%c)\n", "x = ", x, f_inteiro_para_caractere(x));
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // encerrar
    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
}

void metodo_04(void)
{
    // definir dados com valores iniciais
    int x = 0;
    char c = '0';
    double d = 0.0;
    bool b = false;
    // identificar
    printf("%s\n", "884985_EDUARDO_MURTA_DE_ABREU");
    // acoes
    // mostrar valores iniciais
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%d\n", "b = ", b);
    printf("\n");
    // alterar valores iniciais
    // por atribuicao de valores lidos
    // por funcoes
    x = readint("x = ");
    c = readchar("c = ");
    d = readdouble("d = ");
    b = readbool("b = ");
    printf("\n");
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // encerrar
    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
}

void metodo_05(void)
{
    // definir dados com valores iniciais
    int x = 0;
    char c = '0';
    double d = 0.0;
    bool b = false;
    // identificar
    printf("%s\n", "884985_EDUARDO_MURTA_DE_ABREU");
    // acoes
    // mostrar valores iniciais
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%d\n", "b = ", b);
    printf("\n");
    // Alterar valores iniciais por atribuição de valores lidos
    x = readint("x = ");
    c = readchar("c = ");
    d = readdouble("d = ");
    b = readbool("b = ");
    printf("\n");
    // mostrar os valores
    printf("%s%d\n", "x = ", x);
    printf("%s%c (%d)\n", "c = ", c, c);
    printf("%s%lf\n", "d = ", d);
    printf("%s%i\n", "b = ", b);
    printf("\n");
    // encerrar
    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
}

int main(void)
{
    // definir dados
    int opcao = 0;

    // identificar
    printf("%s\n", "Exemplo0200");
    printf("\n");

    // acoes

    // repetir
    do
    {
        // para mostrar opcoes
        printf("\n%s\n", "Opcoes: ");
        printf("\n%s", "0 - Terminar");
        printf("\n%s", "1 - Metodo_01");
        printf("\n%s", "2 - Metodo_02");
        printf("\n%s", "3 - Metodo_03");
        printf("\n%s", "4 - Metodo_04");
        printf("\n%s", "5 - Metodo_05");

        printf("\n");

        // ler a opcao do teclado
        printf("\n%s", "Opcao= ");
        scanf("%d", &opcao);
        getchar();

        // para mostrar a opcao lida
        printf("\n%s%d", "Opcao= ", opcao);

        // escolher acao dependente da opcao
        switch (opcao)
        {
        case 0: /*nao fazer nada*/
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
        default: // comportamento padrao
            printf("\nERRO: Opcao invalida.\n");
            break;
        } // end switch
    } while (opcao != 0);

    // encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar();
    return (0);
} // end main()