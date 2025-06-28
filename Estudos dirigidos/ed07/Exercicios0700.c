/*
    Exercicios 0700
    @author: Eduardo Murta De Abreu - 884985
*/
#include <math.h>
#include <stdio.h>
#include <string.h>

void metodo_01()
{
    int n;

    // Ler o valor inteiro do teclado
    IO_printf("Digite um valor inteiro: ");
    n = IO_readint("");

    // Exibir os múltiplos de 4
    IO_printf("Os primeiros %d múltiplos de 4, pares, em ordem crescente são:\n", n);
    for (int i = 1; i <= n; i = i + 1)
    {
        IO_printf("%d ", i * 4);
    }
    IO_printf("\n");
}

void metodo_02()
{
    int n;

    // Ler o valor inteiro do teclado
    IO_printf("Digite um valor inteiro: ");
    n = IO_readint("");

    // Exibir os múltiplos de 15 em ordem decrescente
    IO_printf("Os primeiros %d múltiplos de 15, pares, em ordem decrescente encerrando em 30 são:\n", n);
    for (int i = n; i >= 1; i = i - 1)
    {
        IO_printf("%d ", i * 30);
    }
    IO_printf("\n");
}

void metodo_03()
{
    int n;

    // Ler o valor inteiro do teclado
    IO_printf("Digite um valor inteiro: ");
    n = IO_readint("");

    // Exibir os valores da sequência 1, 3, 9, 27, 81...
    IO_printf("Os primeiros %d valores da sequência 1, 3, 9, 27, 81... são:\n", n);
    int valor = 1;
    for (int i = 1; i <= n; i = i + 1)
    {
        IO_printf("%d ", valor);
        valor = valor * 3; // Multiplica o valor atual por 3 para gerar o próximo número da sequência
    }
    IO_printf("\n");
}

void metodo_04()
{
    int n;

    // Ler o valor inteiro do teclado
    IO_printf("Digite um valor inteiro: ");
    n = IO_readint("");

    // Exibir os valores decrescentes da sequência ... 1/81, 1/27, 1/9, 1/3, 1
    IO_printf("Os primeiros %d valores decrescentes da sequência ... 1/81, 1/27, 1/9, 1/3, 1 são:\n", n);
    double valor = 1.0 / pow(3, n - 1); // Calcula o menor valor da sequência
    for (int i = 0; i < n; i = i + 1)
    {
        IO_printf("1/%.0f ", 1 / valor); // Exibe o valor como fração
        valor = valor * 3;               // Multiplica por 3 para gerar o próximo número da sequência
    }
    IO_printf("\n");
}

void metodo_05()
{
    int n;
    double x;

    // Ler o valor inteiro e o valor real do teclado
    IO_printf("Digite um valor inteiro (n): ");
    n = IO_readint("");
    IO_printf("Digite um valor real (x): ");
    x = IO_readdouble("");

    // Exibir os valores da sequência 1, 1/x^3, 1/x^5, 1/x^7...
    IO_printf("Os primeiros %d valores da sequência 1, 1/x^3, 1/x^5, 1/x^7... são:\n", n);
    for (int i = 0; i < n; i = i + 1)
    {
        double valor = 1.0 / pow(x, 2 * i + 1);  // Calcula o valor da sequência
        IO_printf("1/%.2f ", pow(x, 2 * i + 1)); // Exibe o valor como fração
    }
    IO_printf("\n");
}

double somaSequencia0715(int n, double x)
{
    double soma = 0.0;
    for (int i = 0; i < n; i = i + 1)
    {
        soma = soma + (1.0 / pow(x, 2 * i + 1));
    }
    return soma;
}

void metodo_06()
{
    int n;
    double x;
    FILE *arquivo = fopen("RESULTADO06.TXT", "w");

    IO_printf("Digite a quantidade de valores (n): ");
    n = IO_readint("");
    IO_printf("Digite o valor real (x): ");
    x = IO_readdouble("");

    double resultado = somaSequencia0715(n, x);
    IO_printf("Resultado da soma: %.6f\n", resultado);

    fprintf(arquivo, "Quantidade: %d, Resultado: %.6f\n", n, resultado);
    fclose(arquivo);
}

double somaInversos0714(int n)
{
    double soma = 0.0;
    double valor = 1.0 / pow(3, n - 1);
    for (int i = 0; i < n; i = i + 1)
    {
        soma = soma + valor;
        valor = valor * 3;
    }
    return soma;
}

void metodo_07()
{
    int n;
    FILE *arquivo = fopen("RESULTADO07.TXT", "w");

    IO_printf("Digite a quantidade de valores (n): ");
    n = IO_readint("");

    double resultado = somaInversos0714(n);
    IO_printf("Resultado da soma: %.6f\n", resultado);

    fprintf(arquivo, "Quantidade: %d, Resultado: %.6f\n", n, resultado);
    fclose(arquivo);
}

void fibonacciPares(int n, FILE *arquivo)
{
    int a = 0, b = 1, count = 0;
    while (count < n)
    {
        int c = a + b;
        if (c % 2 == 0)
        {
            fprintf(arquivo, "%d ", c);
            count = count + 1;
        }
        a = b;
        b = c;
    }
}

void metodo_08()
{
    int n;
    FILE *arquivo = fopen("RESULTADO08.TXT", "w");

    IO_printf("Digite a quantidade de valores pares da série de Fibonacci (n): ");
    n = IO_readint("");

    IO_printf("Os primeiros %d valores pares da série de Fibonacci foram gravados no arquivo.\n", n);
    fprintf(arquivo, "Quantidade: %d, Valores: ", n);
    fibonacciPares(n, arquivo);
    fprintf(arquivo, "\n");
    fclose(arquivo);
}

int contarMaiusculas(char *cadeia)
{
    int count = 0;
    for (int i = 0; cadeia[i] != '\0'; i = i + 1)
    {
        if (cadeia[i] >= 'A' && cadeia[i] <= 'Z')
        {
            count = count + 1;
        }
    }
    return count;
}

void metodo_09()
{
    char cadeia[100];
    FILE *arquivo = fopen("RESULTADO09.TXT", "w");

    IO_printf("Digite uma cadeia de caracteres: ");
    IO_scanf("%s", cadeia);

    int resultado = contarMaiusculas(cadeia);
    IO_printf("Quantidade de maiúsculas: %d\n", resultado);

    fprintf(arquivo, "Cadeia: %s, Maiúsculas: %d\n", cadeia, resultado);
    fclose(arquivo);
}

int contarDigitosMaioresOuIguais3(char *cadeia)
{
    int count = 0;
    for (int i = 0; cadeia[i] != '\0'; i = i + 1)
    {
        if (cadeia[i] >= '3' && cadeia[i] <= '9')
        {
            count = count + 1;
        }
    }
    return count;
}

void metodo_10()
{
    char cadeia[100];
    FILE *arquivo = fopen("RESULTADO10.TXT", "w");

    IO_printf("Digite uma cadeia de caracteres: ");
    IO_scanf("%s", cadeia);

    int resultado = contarDigitosMaioresOuIguais3(cadeia);
    IO_printf("Quantidade de dígitos >= 3: %d\n", resultado);

    fprintf(arquivo, "Cadeia: %s, Dígitos >= 3: %d\n", cadeia, resultado);
    fclose(arquivo);
}

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
        IO_printf("Opcao 4: Metodo 04\n"); // Adicionada a nova opção
        IO_printf("Opcao 5: Metodo 05\n"); // Adicionada a nova opção
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