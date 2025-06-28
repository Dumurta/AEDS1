/*
    Exercicios 0700
    @author: Eduardo Murta De Abreu - 884985
*/
#include <stdio.h>
#include <string.h>

// Método 07E1: Gravar divisores ímpares em ordem decrescente
void metodo_07E1()
{
    int n;
    FILE *arquivo = fopen("RESULTADO07E1.TXT", "w");

    // Ler o valor inteiro do teclado
    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    // Gravar divisores ímpares em ordem decrescente
    fprintf(arquivo, "Divisores ímpares de %d em ordem decrescente:\n", n);
    for (int i = n; i >= 1; i = i - 1)
    {
        if (n % i == 0 && i % 2 != 0)
        { // Verifica se é divisor e ímpar
            fprintf(arquivo, "%d ", i);
        }
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);

    printf("Divisores ímpares gravados no arquivo 'RESULTADO07E1.TXT'.\n");
}

// Função para contar palavras que começam com 'c' ou 'C' e têm no máximo 12 caracteres
int contarPalavrasC(FILE *arquivo)
{
    char palavra[100];
    int count = 0;

    while (fscanf(arquivo, "%s", palavra) != EOF)
    {
        if ((palavra[0] == 'c' || palavra[0] == 'C') && strlen(palavra) <= 12)
        {
            count = count + 1;
        }
    }
    return count;
}

// Método 07E2: Contar palavras que começam com 'c' ou 'C' e têm no máximo 12 caracteres
void metodo_07E2()
{
    FILE *entrada = fopen("ENTRADA07E2.TXT", "r");
    FILE *saida = fopen("RESULTADO07E2.TXT", "w");

    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo 'ENTRADA07E2.TXT'. Certifique-se de que ele existe.\n");
        return;
    }

    int resultado = contarPalavrasC(entrada);
    fprintf(saida, "Quantidade de palavras que começam com 'c' ou 'C' e têm no máximo 12 caracteres: %d\n", resultado);

    fclose(entrada);
    fclose(saida);

    printf("Resultado gravado no arquivo 'RESULTADO07E2.TXT'.\n");
}

int main()
{
    int opcao = 0;

    do
    {
        printf("Opções:\n");
        printf("0 - Sair\n");
        printf("1 - Metodo 07E1\n");
        printf("2 - Metodo 07E2\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Encerrando o programa.\n");
            break;
        case 1:
            metodo_07E1();
            break;
        case 2:
            metodo_07E2();
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}