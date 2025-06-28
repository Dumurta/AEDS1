#include <stdio.h>
#include <stdlib.h>
#include "io.h"
// Função para ler somente valores positivos e pares
void lerPares(int *n, int vetor[])
{
    int tamanho = 0;
    int valor = 0;

    printf("Informe o tamanho do arranjo (maior que zero): ");
    scanf("%d", &tamanho);

    while (tamanho <= 0)
    {
        printf("Tamanho invalido. Digite novamente: ");
        scanf("%d", &tamanho);
    }

    for (int i = 0; i < tamanho; i = i + 1)
    {
        printf("Digite o valor %d (positivo e par): ", i + 1);
        scanf("%d", &valor);

        while (valor <= 0 || valor % 2 != 0)
        {
            printf("Valor invalido. Digite um valor positivo e par: ");
            scanf("%d", &valor);
        }

        vetor[i] = valor;
    }

    *n = tamanho;
}

void metodo_01()
{
    int vetor[100]; // Capacidade máxima arbitrária
    int quantidade = 0;

    IO_clrscr();
    printf("Metodo 0811 - Ler somente valores positivos e pares\n\n");

    lerPares(&quantidade, vetor);

    printf("\nValores lidos (%d):\n", quantidade);
    for (int i = 0; i < quantidade; i = i + 1)
    {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para gravar somente valores positivos e pares em um arquivo
void gravarParesPositivos(int n, int vetor[], char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "wt");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para gravacao.\n");
        return;
    }

    // Gravar a quantidade
    fprintf(arquivo, "%d\n", n);

    // Gravar os elementos
    for (int i = 0; i < n; i = i + 1)
    {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
}

// Função para ler inteiros de um arquivo, filtrando apenas os positivos e pares
int lerArquivoFiltrarPares(char *nomeEntrada, int vetor[])
{
    FILE *arquivo = fopen(nomeEntrada, "rt");
    int valor = 0;
    int contador = 0;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de leitura.\n");
        return 0;
    }

    while (fscanf(arquivo, "%d", &valor) != EOF)
    {
        if (valor > 0 && valor % 2 == 0)
        {
            vetor[contador] = valor;
            contador = contador + 1;
        }
    }

    fclose(arquivo);
    return contador;
}

// Metodo 02
void Metodo_02()
{
    int vetor[100];
    int quantidade = 0;
    char nomeEntrada[100];
    char nomeSaida[100];

    IO_clrscr();
    printf("Metodo 0812 - Ler do arquivo e gravar pares positivos\n\n");

    printf("Nome do arquivo de entrada: ");
    scanf("%s", nomeEntrada);

    printf("Nome do arquivo de saida: ");
    scanf("%s", nomeSaida);

    quantidade = lerArquivoFiltrarPares(nomeEntrada, vetor);

    if (quantidade > 0)
    {
        gravarParesPositivos(quantidade, vetor, nomeSaida);

        printf("\n%d valores positivos e pares foram gravados em '%s':\n", quantidade, nomeSaida);
        for (int i = 0; i < quantidade; i = i + 1)
        {
            printf("vetor[%d] = %d\n", i, vetor[i]);
        }
    }
    else
    {
        printf("\nNenhum valor valido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar"); // encerrar
}

// Função para gerar um número inteiro aleatório dentro de um intervalo
int gerarInt(int inferior, int superior)
{
    static int seed = 12345;          // Semente fixa
    seed = (214013 * seed + 2531011); // Fórmula para gerar pseudo-aleatórios
    return inferior + (seed % (superior - inferior));
}

void metodo_03()
{
    int vetor[100];
    int quantidade = 0;
    int inferior = 0, superior = 0;
    char nomeArquivo[] = "DADOS.TXT";

    IO_clrscr();
    printf("Metodo 0813 - Gerar valores aleatorios dentro de um intervalo e gravar em arquivo\n\n");

    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &inferior);

    printf("Informe o limite superior do intervalo: ");
    scanf("%d", &superior);

    while (superior <= inferior)
    {
        printf("Limite superior deve ser maior que o inferior. Digite novamente: ");
        scanf("%d", &superior);
    }

    printf("Informe a quantidade de valores a serem gerados: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        vetor[i] = gerarInt(inferior, superior);
    }

    gravarParesPositivos(quantidade, vetor, nomeArquivo); // Reutilizando função para gravar no arquivo

    printf("\n%d valores aleatorios foram gravados em '%s'.\n", quantidade, nomeArquivo);
    IO_pause("Aperte ENTER para continuar");
}

// Função para encontrar o menor valor par em um arranjo
int acharMenorPar(int n, int vetor[])
{
    int menor = -1; // Inicializar com -1 para indicar que nenhum valor foi encontrado

    for (int i = 0; i < n; i++)
    {
        if (vetor[i] % 2 == 0) // Verificar se o valor é par
        {
            if (menor == -1 || vetor[i] < menor) // Atualizar o menor valor
            {
                menor = vetor[i];
            }
        }
    }

    return menor; // Retornar o menor valor par ou -1 se não houver
}

void Metodo_04()
{
    int vetor[100];
    int quantidade = 0;
    char nomeArquivo[100];
    int menorPar = 0;

    IO_clrscr();
    printf("Metodo 0814 - Procurar o menor valor par em um arranjo\n\n");

    printf("Informe o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivo);

    // Ler os valores do arquivo
    quantidade = lerArquivoFiltrarPares(nomeArquivo, vetor);

    if (quantidade > 0)
    {
        menorPar = acharMenorPar(quantidade, vetor);

        if (menorPar != -1)
        {
            printf("\nO menor valor par encontrado foi: %d\n", menorPar);
        }
        else
        {
            printf("\nNao ha valores pares no arranjo.\n");
        }
    }
    else
    {
        printf("\nNenhum valor valido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar");
}

// Função para encontrar o maior valor ímpar e múltiplo de 3 em um arranjo
int acharMaiorImparDivisivelPorTres(int n, int vetor[])
{
    int maior = -1; // Inicializar com -1 para indicar que nenhum valor foi encontrado

    for (int i = 0; i < n; i++)
    {
        if (vetor[i] % 2 != 0 && vetor[i] % 3 == 0) // Verificar se é ímpar e múltiplo de 3
        {
            if (maior == -1 || vetor[i] > maior) // Atualizar o maior valor
            {
                maior = vetor[i];
            }
        }
    }

    return maior; // Retornar o maior valor ou -1 se não houver
}

void metodo_05()
{
    int vetor[100];
    int quantidade = 0;
    char nomeArquivo[100];
    int maiorImparDivisivelPorTres = 0;

    IO_clrscr();
    printf("Metodo 05 - Procurar o maior valor ímpar e múltiplo de 3 em um arranjo\n\n");

    printf("Informe o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivo);

    // Ler os valores do arquivo
    quantidade = lerArquivoFiltrarPares(nomeArquivo, vetor);

    if (quantidade > 0)
    {
        maiorImparDivisivelPorTres = acharMaiorImparDivisivelPorTres(quantidade, vetor);

        if (maiorImparDivisivelPorTres != -1)
        {
            printf("\nO maior valor ímpar e múltiplo de 3 encontrado foi: %d\n", maiorImparDivisivelPorTres);
        }
        else
        {
            printf("\nNao ha valores ímpares e múltiplos de 3 no arranjo.\n");
        }
    }
    else
    {
        printf("\nNenhum valor valido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar");
}

// Função para calcular a média dos valores em um arranjo
double acharMedia(int n, int vetor[])
{
    if (n == 0)
        return 0.0; // Evitar divisão por zero

    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += vetor[i];
    }

    return (double)soma / n;
}

void metodo_06()
{
    int vetor[100];
    int menoresOuIguais[100];
    int maiores[100];
    int quantidade = 0, menoresCount = 0, maioresCount = 0;
    char nomeArquivo[] = "DADOS.TXT";
    char arquivoMenores[] = "MENORES.TXT";
    char arquivoMaiores[] = "MAIORES.TXT";
    double media = 0.0;

    IO_clrscr();
    printf("Metodo 06 - Determinar a média dos valores em um arranjo e separar em arquivos\n\n");

    // Ler os valores do arquivo
    quantidade = lerArquivoFiltrarPares(nomeArquivo, vetor);

    if (quantidade > 0)
    {
        // Calcular a média
        media = acharMedia(quantidade, vetor);

        // Separar os valores em dois arranjos
        for (int i = 0; i < quantidade; i++)
        {
            if (vetor[i] <= media)
            {
                menoresOuIguais[menoresCount++] = vetor[i];
            }
            else
            {
                maiores[maioresCount++] = vetor[i];
            }
        }

        // Gravar os valores menores ou iguais à média no arquivo
        gravarParesPositivos(menoresCount, menoresOuIguais, arquivoMenores);

        // Gravar os valores maiores que a média no arquivo
        gravarParesPositivos(maioresCount, maiores, arquivoMaiores);

        printf("\nMedia calculada: %.2f\n", media);
        printf("Valores menores ou iguais à média foram gravados em '%s'.\n", arquivoMenores);
        printf("Valores maiores que a média foram gravados em '%s'.\n", arquivoMaiores);
    }
    else
    {
        printf("\nNenhum valor valido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar");
}

// Função para verificar se o arranjo está ordenado em ordem decrescente
int estaOrdenadoDecrescente(int n, int vetor[])
{
    for (int i = 0; i < n - 1; i++)
    {
        if (vetor[i] < vetor[i + 1]) // Verificar se algum valor é menor que o seguinte
        {
            return 0; // Não está ordenado
        }
    }
    return 1; // Está ordenado
}

void metodo_07()
{
    int vetor[100];
    int quantidade = 0;
    char nomeArquivo[] = "DADOS.TXT";
    int ordenado = 0;

    IO_clrscr();
    printf("Metodo 07 - Verificar se o arranjo está ordenado em ordem decrescente\n\n");

    // Ler os valores do arquivo
    quantidade = lerArquivoFiltrarPares(nomeArquivo, vetor);

    if (quantidade > 0)
    {
        // Verificar se o arranjo está ordenado em ordem decrescente
        ordenado = estaOrdenadoDecrescente(quantidade, vetor);

        if (ordenado)
        {
            printf("\nO arranjo está ordenado em ordem decrescente.\n");
        }
        else
        {
            printf("\nO arranjo NÃO está ordenado em ordem decrescente.\n");
        }
    }
    else
    {
        printf("\nNenhum valor válido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar");
}

// Função para verificar se um valor existe no arranjo a partir de uma posição inicial
int acharValor(int procurado, int inicio, int n, int vetor[])
{
    for (int i = inicio; i < n; i++)
    {
        if (vetor[i] == procurado) // Verificar se o valor é encontrado
        {
            return 1; // Valor encontrado
        }
    }
    return 0; // Valor não encontrado
}

void metodo_08()
{
    int vetor[100];
    int quantidade = 0;
    char nomeArquivo[] = "DADOS.TXT";
    int procurado = 0;
    int inicio = 0;
    int existe = 0;

    IO_clrscr();
    printf("Metodo 08 - Procurar por determinado valor em arranjo\n\n");

    // Ler os valores do arquivo
    quantidade = lerArquivoFiltrarPares(nomeArquivo, vetor);

    if (quantidade > 0)
    {
        printf("Informe o valor a ser procurado: ");
        scanf("%d", &procurado);

        printf("Informe a posição inicial para começar a procura (0 a %d): ", quantidade - 1);
        scanf("%d", &inicio);

        // Validar a posição inicial
        if (inicio < 0 || inicio >= quantidade)
        {
            printf("\nPosição inicial inválida.\n");
        }
        else
        {
            // Verificar se o valor existe no arranjo
            existe = acharValor(procurado, inicio, quantidade, vetor);

            if (existe)
            {
                printf("\nO valor %d foi encontrado no arranjo a partir da posição %d.\n", procurado, inicio);
            }
            else
            {
                printf("\nO valor %d NÃO foi encontrado no arranjo a partir da posição %d.\n", procurado, inicio);
            }
        }
    }
    else
    {
        printf("\nNenhum valor válido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar");
}

// Função para encontrar a posição de um valor no arranjo a partir de uma posição inicial
int acharPosicao(int procurado, int inicio, int n, int vetor[])
{
    for (int i = inicio; i < n; i++)
    {
        if (vetor[i] == procurado) // Verificar se o valor é encontrado
        {
            return i; // Retornar a posição onde o valor foi encontrado
        }
    }
    return -1; // Retornar -1 se o valor não for encontrado
}

void metodo_09()
{
    int vetor[100];
    int quantidade = 0;
    char nomeArquivo[] = "DADOS.TXT";
    int procurado = 0;
    int inicio = 0;
    int posicao = -1;

    IO_clrscr();
    printf("Metodo 09 - Procurar a posição de um valor no arranjo\n\n");

    // Ler os valores do arquivo
    quantidade = lerArquivoFiltrarPares(nomeArquivo, vetor);

    if (quantidade > 0)
    {
        printf("Informe o valor a ser procurado: ");
        scanf("%d", &procurado);

        printf("Informe a posição inicial para começar a procura (0 a %d): ", quantidade - 1);
        scanf("%d", &inicio);

        // Validar a posição inicial
        if (inicio < 0 || inicio >= quantidade)
        {
            printf("\nPosição inicial inválida.\n");
        }
        else
        {
            // Procurar a posição do valor no arranjo
            posicao = acharPosicao(procurado, inicio, quantidade, vetor);

            if (posicao != -1)
            {
                printf("\nO valor %d foi encontrado na posição %d do arranjo.\n", procurado, posicao);
            }
            else
            {
                printf("\nO valor %d NÃO foi encontrado no arranjo a partir da posição %d.\n", procurado, inicio);
            }
        }
    }
    else
    {
        printf("\nNenhum valor válido foi encontrado no arquivo.\n");
    }

    IO_pause("Aperte ENTER para continuar");
}
// Função para contar quantas vezes um valor aparece no arranjo a partir de uma posição
int acharQuantos(int procurado, int inicio, int n, int vetor[])
{
    int contador = 0;

    for (int i = inicio; i < n; i = i + 1)
    {
        if (vetor[i] == procurado)
        {
            contador = contador + 1;
        }
    }

    return contador;
}

// Função para ler dados do arquivo DADOS.TXT
int lerArquivo(char *nomeArquivo, int vetor[])
{
    FILE *arquivo = fopen(nomeArquivo, "rt");
    int quantidade = 0;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    fscanf(arquivo, "%d", &quantidade); // primeira linha: quantidade de dados

    for (int i = 0; i < quantidade; i = i + 1)
    {
        fscanf(arquivo, "%d", &vetor[i]);
    }

    fclose(arquivo);
    return quantidade;
}

void metodo_10()
{
    int vetor[100];
    int quantidade = 0;
    int procurado = 0;
    int inicio = 0;
    int total = 0;

    printf("Metodo 0820 - Contar quantas vezes um valor aparece\n\n");

    quantidade = lerArquivo("DADOS.TXT", vetor);

    if (quantidade <= 0)
    {
        printf("Nao ha dados no arquivo ou leitura falhou.\n");
    }
    else
    {
        printf("Valor a ser procurado: ");
        scanf("%d", &procurado);

        printf("Posicao inicial da busca (0 a %d): ", quantidade - 1);
        scanf("%d", &inicio);

        if (inicio < 0 || inicio >= quantidade)
        {
            printf("Posicao inicial invalida.\n");
        }
        else
        {
            total = acharQuantos(procurado, inicio, quantidade, vetor);
            printf("O valor %d foi encontrado %d vez(es) a partir da posicao %d.\n", procurado, total, inicio);
        }
    }

    IO_pause("Aperte ENTER para continuar"); // encerrar
}
int main()
{
    // definir dado local
    int option = 0;

    // identificar
    IO_id("EXERCICIO0800 - Programa - v0.0");

    // repetir enquanto opcao for diferente de zero
    do
    {
        // mostrar opcoes
        IO_println("\n");
        IO_println(" 0 - parar");
        IO_println(" 1 - metodo_01");
        IO_println(" 2 - metodo_02");
        IO_println(" 3 - metodo_03");
        IO_println(" 4 - metodo_04");
        IO_println(" 5 - metodo_05");
        IO_println(" 6 - metodo_06");
        IO_println(" 7 - metodo_07");
        IO_println(" 8 - metodo_08");
        IO_println(" 9 - metodo_09");
        IO_println("10 - metodo_10");

        // ler opcao
        option = IO_readint("\nOpcao: ");

        // testar a opcao
        switch (option)
        {
        case 0:
            break;
        case 1:
            metodo_01();
            break;
        case 2:
            Metodo_02();
            break;
        case 3:
            metodo_03();
            break;
        case 4:
            Metodo_04();
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
            IO_pause("\nERRO: Opcao invalida.\nApertar ENTER para continuar.");
            break;
        } // end switch

    } while (option != 0);

    // encerrar
    return (0);
} // end main ( )