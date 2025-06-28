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
void metodo_01()
{
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Letras maiusculas maiores que 'K': ");
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z' && palavra[i] > 'K')
        {
            printf("%c ", palavra[i]);
        }
    }
    printf("\n");
    // encerrar
    IO_pause("Apertar ENTER para continuar");

}

void metodo_02()
{
    char palavra[100];
    int contador = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Letras minusculas menores que 'k': ");
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (palavra[i] >= 'a' && palavra[i] < 'k')
        {
            printf("%c ", palavra[i]);
            contador++;
        }
    }
    printf("\nTotal: %d\n", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_03()
{
    char palavra[100];
    int contador = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = 0;
    while (palavra[tamanho] != '\0')
    {
        tamanho++;
    }

    printf("Letras minusculas maiores que 'K': ");
    for (int i = tamanho - 1; i >= 0; i--)
    {
        if (palavra[i] >= 'a' && palavra[i] > 'K')
        {
            printf("%c ", palavra[i]);
            contador++;
        }
    }
    printf("\nTotal: %d\n", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_04()
{
    char palavra[100];
    int contador = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = 0;
    while (palavra[tamanho] != '\0')
    {
        tamanho++;
    }

    printf("Letras minusculas maiores que 'k': ");
    for (int i = tamanho - 1; i >= 0; i--)
    {
        if (palavra[i] >= 'l' && palavra[i] <= 'z')
        {
            printf("%c ", palavra[i]);
            contador++;
        }
    }
    printf("\nTotal: %d\n", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_05()
{
    char cadeia[100];
    int contador = 0;

    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    int tamanho = 0;
    while (cadeia[tamanho] != '\0')
    {
        tamanho++;
    }

    printf("Digitos pares encontrados: ");
    for (int i = tamanho - 1; i >= 0; i--)
    {
        if (cadeia[i] >= '0' && cadeia[i] <= '9' && (cadeia[i] - '0') % 2 == 0)
        {
            printf("%c ", cadeia[i]);
            contador++;
        }
    }
    printf("\nTotal: %d\n", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_06()
{
    char cadeia[100];
    int contador = 0;

    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    int tamanho = 0;
    while (cadeia[tamanho] != '\0')
    {
        tamanho++;
    }

    printf("Caracteres que nao sao digitos impares nem letras: ");
    for (int i = 0; i < tamanho; i++)
    {
        if (!(cadeia[i] >= '0' && cadeia[i] <= '9' && (cadeia[i] - '0') % 2 != 0) && !(cadeia[i] >= 'A' && cadeia[i] <= 'Z') && !(cadeia[i] >= 'a' && cadeia[i] <= 'z'))
        {
            printf("%c ", cadeia[i]);
            contador++;
        }
    }
    printf("\nTotal: %d\n", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_07()
{
    int a, b, n, x, contador = 0;

    printf("Digite os limites do intervalo [a:b]: ");
    scanf("%d %d", &a, &b);

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &n);

    printf("Digite os %d valores:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x % 3 == 0 && x >= a && x <= b)
        {
            contador++;
        }
    }

    printf("Quantidade de valores multiplos de 3 no intervalo [%d:%d]: %d\n", a, b, contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void metodo_08(void)
{
    int a, b, n, x;
    int count = 0;

    // Ler os limites do intervalo [a:b]
    printf("Digite os limites do intervalo (a e b): ");
    scanf("%d %d", &a, &b);

    // Ler a quantidade n de valores a serem testados
    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &n);

    // Ler os valores e contar os que são múltiplos de 4, não múltiplos de 3 e pertencem ao intervalo
    printf("Digite os %d valores a serem testados:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        // Verificar se x é múltiplo de 4, não múltiplo de 3 e pertence ao intervalo [a:b]
        if (x % 4 == 0 && x % 3 != 0 && x >= a && x <= b)
        {
            count++;
        }
    }

    // Mostrar a quantidade de valores que atendem à condição
    printf("Quantidade de valores que atendem às condições: %d\n", count);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_09(void)
{
    float a, b, x;
    int n, count = 0;

    // Ler os limites do intervalo aberto (a:b)
    printf("Digite os limites do intervalo (a e b): ");
    scanf("%f %f", &a, &b);

    // Ler a quantidade n de valores a serem testados
    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &n);

    // Ler os valores e contar os que atendem às condições
    printf("Digite os %d valores a serem testados:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x);

        // Verificar se x pertence ao intervalo (a:b) e se a parte inteira de x é par e menor que 5
        if (x > a && x < b)
        {
            int parte_inteira = (int)x; // Isola a parte inteira de x
            if (parte_inteira % 2 == 0 && parte_inteira < 5)
            {
                count++;
                printf("%.2f ", x); // Mostrar o valor que atende às condições
            }
        }
    }

    // Mostrar a quantidade de valores que atendem à condição
    printf("\nQuantidade de valores que atendem às condições: %d\n", count);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}
void metodo_10(void)
{
    float a, b, x;
    int n, count = 0;

    // Ler os limites do intervalo aberto (a:b), confirmando que a e b estão entre 0 e 1
    printf("Digite os limites do intervalo (a e b), ambos maiores que 0 e menores que 1: ");
    scanf("%f %f", &a, &b);

    // Garantir que a e b estão no intervalo correto
    if (a <= 0 || b <= 0 || a >= 1 || b >= 1 || a >= b)
    {
        printf("Valores de intervalo inválidos! 'a' deve ser menor que 'b' e ambos devem estar entre 0 e 1.\n");
        return;
    }

    // Ler a quantidade n de valores a serem testados
    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &n);

    // Ler os valores e contar os que atendem às condições
    printf("Digite os %d valores a serem testados:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x);

        // Isolar a parte inteira e fracionária de x
        int parte_inteira = (int)x;                  // Parte inteira
        float parte_fracionaria = x - parte_inteira; // Parte fracionária

        // Verificar se a parte fracionária está no intervalo (a:b)
        if (parte_fracionaria > a && parte_fracionaria < b)
        {
            count++;
            printf("%.2f ", x); // Mostrar o valor que atende às condições
        }
    }

    // Mostrar a quantidade de valores que atendem à condição
    printf("\nQuantidade de valores que atendem às condições: %d\n", count);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
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