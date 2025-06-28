// 884985_EDUARDO_MURTA_DE_ABREU
// dependencias
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
    Metodo_00
*/

void metodo_00(void)
{
    // nao faz nada
} // end metodo_00()

/*
    Metodo_01
*/
void metodo_01(void)
{
    int n, dentro = 0, fora = 0;
    double a, b, x;

    // Ler a quantidade de valores reais
    n = IO_readint("Digite a quantidade de valores reais: ");

    // Ler os dois valores para definir o intervalo fechado [a, b]
    a = IO_readdouble("Digite o limite inferior do intervalo: ");
    b = IO_readdouble("Digite o limite superior do intervalo: ");

    // Garantir que a <= b
    if (a > b)
    {
        IO_println("Erro: O limite inferior deve ser menor ou igual ao superior.");
        return;
    }

    // Ler os valores e contar os que estão dentro e fora do intervalo
    IO_println("Digite os valores a serem testados:");
    for (int i = 0; i < n; i++)
    {
        x = IO_readdouble("");

        if (x >= a && x <= b)
        {
            dentro++;
        }
        else
        {
            fora++;
        }
    }

    // Exibir os resultados
    IO_printf("Quantidade de valores dentro do intervalo: %d\n", dentro);
    IO_printf("Quantidade de valores fora do intervalo: %d\n", fora);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para verificar se um caractere é uma letra maiúscula
bool ehMaiuscula(char c)
{
    return (c >= 'A' && c <= 'Z');
}

void metodo_02(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres
    int contador = 0;

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Percorrer a sequência e contar as letras minúsculas no intervalo ('c', 'p')
    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (sequencia[i] > 'c' && sequencia[i] < 'p' && !ehMaiuscula(sequencia[i]))
        {
            contador++;
        }
    }

    // Exibir a quantidade de letras minúsculas no intervalo desejado
    IO_printf("Quantidade de letras minúsculas maiores que 'c' e menores que 'p': %d\n", contador);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para contar letras minúsculas entre 'c' e 'p'
int contarMinusculasEntreC_P(chars sequencia)
{
    int contador = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (sequencia[i] > 'c' && sequencia[i] < 'p' && sequencia[i] >= 'a' && sequencia[i] <= 'z')
        {
            contador++;
        }
    }

    return contador;
}

void metodo_03(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função e exibir o resultado
    int quantidade = contarMinusculasEntreC_P(sequencia);
    IO_printf("Quantidade de letras minúsculas maiores que 'c' e menores que 'p': %d\n", quantidade);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para separar letras minúsculas entre 'c' e 'p'
void separarMinusculasEntreC_P(chars sequencia, chars resultado)
{
    resultado[0] = '\0'; // Inicializar a string vazia

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (sequencia[i] > 'c' && sequencia[i] < 'p' && sequencia[i] >= 'a' && sequencia[i] <= 'z')
        {
            int tamanho = strlen(resultado);
            resultado[tamanho] = sequencia[i]; // Adicionar caractere
            resultado[tamanho + 1] = '\0';     // Atualizar terminador
        }
    }
}

void metodo_04(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres
    char resultado[STR_SIZE]; // Armazena os caracteres filtrados

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função para separar os caracteres desejados
    separarMinusculasEntreC_P(sequencia, resultado);

    // Exibir o resultado
    IO_printf("Letras minúsculas entre 'c' e 'p': %s\n", resultado);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para contar letras (maiúsculas e minúsculas) entre 'c'/'C' e 'p'/'P'
int contarLetrasEntreC_P(chars sequencia)
{
    int contador = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if ((sequencia[i] > 'c' && sequencia[i] < 'p') || (sequencia[i] > 'C' && sequencia[i] < 'P'))
        {
            contador++;
        }
    }

    return contador;
}

void metodo_05(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função e exibir o resultado
    int quantidade = contarLetrasEntreC_P(sequencia);
    IO_printf("Quantidade de letras entre 'c'/'C' e 'p'/'P': %d\n", quantidade);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para separar letras (maiúsculas e minúsculas) entre 'c'/'C' e 'p'/'P'
void separarLetrasEntreC_P(chars sequencia, chars resultado)
{
    resultado[0] = '\0'; // Inicializar a string vazia

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if ((sequencia[i] > 'c' && sequencia[i] < 'p') || (sequencia[i] > 'C' && sequencia[i] < 'P'))
        {
            int tamanho = strlen(resultado);
            resultado[tamanho] = sequencia[i]; // Adicionar caractere
            resultado[tamanho + 1] = '\0';     // Atualizar terminador
        }
    }
}

void metodo_06(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres
    char resultado[STR_SIZE]; // Armazena os caracteres filtrados

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função para separar os caracteres desejados
    separarLetrasEntreC_P(sequencia, resultado);

    // Exibir o resultado
    IO_printf("Letras entre 'c'/'C' e 'p'/'P': %s\n", resultado);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para contar os dígitos pares em uma cadeia de caracteres
int contarDigitosPares(chars sequencia)
{
    int contador = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (sequencia[i] >= '0' && sequencia[i] <= '9')
        {                                           // Verifica se é um dígito
            int digito = (int)(sequencia[i] - '0'); // Converte o caractere para inteiro
            if (digito % 2 == 0)
            { // Verifica se é par
                contador++;
            }
        }
    }

    return contador;
}

void metodo_07(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função e exibir o resultado
    int quantidade = contarDigitosPares(sequencia);
    IO_printf("Quantidade de dígitos pares na sequência: %d\n", quantidade);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para separar e armazenar símbolos não alfanuméricos
void separarSimbolosNaoAlfanumericos(chars sequencia, chars resultado)
{
    resultado[0] = '\0'; // Inicializar a string vazia
    int tamanho = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        char c = sequencia[i];

        // Verificar se o caractere não é letra (A-Z, a-z) nem número (0-9)
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
        {
            resultado[tamanho] = c; // Adicionar caractere ao resultado
            tamanho++;
            resultado[tamanho] = '\0'; // Atualizar terminador
        }
    }
}

void metodo_08(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres
    char resultado[STR_SIZE]; // Armazena os caracteres filtrados

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função para separar os símbolos
    separarSimbolosNaoAlfanumericos(sequencia, resultado);

    // Exibir os símbolos encontrados
    IO_printf("Símbolos não alfanuméricos encontrados: %s\n", resultado);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para verificar se um caractere é uma letra
bool ehLetra(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Função para verificar se um caractere é um dígito
bool ehDigito(char c)
{
    return (c >= '0' && c <= '9');
}

// Função para separar e armazenar apenas símbolos alfanuméricos
void separarAlfanumericos(chars sequencia, chars resultado)
{
    resultado[0] = '\0'; // Inicializar a string vazia
    int tamanho = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (ehLetra(sequencia[i]) || ehDigito(sequencia[i]))
        {                                      // Se for letra ou número
            resultado[tamanho] = sequencia[i]; // Adicionar caractere ao resultado
            tamanho++;
            resultado[tamanho] = '\0'; // Atualizar terminador
        }
    }
}

void metodo_09(void)
{
    char sequencia[STR_SIZE]; // Armazena a sequência de caracteres
    char resultado[STR_SIZE]; // Armazena os caracteres filtrados

    // Ler a sequência de caracteres do teclado
    strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

    // Chamar a função para separar os caracteres alfanuméricos
    separarAlfanumericos(sequencia, resultado);

    // Exibir os caracteres alfanuméricos encontrados
    IO_printf("Símbolos alfanuméricos encontrados: %s\n", resultado);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para verificar se um caractere é uma letra
bool ehLetra(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Função para verificar se um caractere é um dígito
bool ehDigito(char c)
{
    return (c >= '0' && c <= '9');
}

// Função para contar os símbolos alfanuméricos (letras e dígitos) em uma cadeia
int contarAlfanumericos(chars sequencia)
{
    int contador = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (ehLetra(sequencia[i]) || ehDigito(sequencia[i]))
        {
            contador++;
        }
    }

    return contador;
}

void metodo_10(void)
{
    int n, total = 0;

    // Ler a quantidade de cadeias de caracteres
    n = IO_readint("Digite a quantidade de cadeias de caracteres: ");

    for (int i = 0; i < n; i++)
    {
        char sequencia[STR_SIZE]; // Armazena a cadeia lida

        // Ler a cadeia de caracteres do teclado
        strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

        // Contar os símbolos alfanuméricos na cadeia atual
        int quantidade = contarAlfanumericos(sequencia);

        // Exibir o resultado para a sequência atual
        IO_printf("Quantidade de símbolos alfanuméricos na sequência %d: %d\n", i + 1, quantidade);

        // Acumular o total
        total += quantidade;
    }

    // Exibir o total acumulado
    IO_printf("Total acumulado de símbolos alfanuméricos: %d\n", total);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}

int main()
{
    // def dado
    int x = 0;

    // repetir ate desejar parar
    do
    {
        // identificar
        IO_id("EXEMPLO0300 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - Metodo_01");
        IO_println("2 - Metodo_02");
        IO_println("3 - Metodo_03");
        IO_println("4 - Metodo_04");
        IO_println("5 - Metodo_05");
        IO_println("6 - Metodo_06");
        IO_println("7 - Metodo_07");
        IO_println("8 - Metodo_08");
        IO_println("9 - Metodo_09");
        IO_println("10 - Metodo_10");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
        switch (x)
        {
        case 0:
            metodo_00();
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
            IO_pause(IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat(IO_toString_d(x), ")")));
        } // end switch

    } while (x != 0);

    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // end main
/*

---------------------------------------------- testes
        Versao              Teste
         0.1                  01. ( OK )
        Sem problemas nessa versao inicial.

---------------------------------------------- Valores testados
 */