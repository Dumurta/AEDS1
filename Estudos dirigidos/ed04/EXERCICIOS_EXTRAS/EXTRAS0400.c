#include "io.h"     // Biblioteca personalizada
#include <string.h> // Para manipulação de strings
void metodo_00(void)
{
    // nao faz nada
} // end metodo_00()
// Função para verificar se um caractere é alfanumérico ou espaço em branco
bool ehAlfanumericoOuEspaco(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') || (c == ' ');
}

// Função para contar os símbolos alfanuméricos e espaços em uma cadeia
int contarAlfanumericosEEspacos(chars sequencia)
{
    int contador = 0;

    for (int i = 0; i < strlen(sequencia); i++)
    {
        if (ehAlfanumericoOuEspaco(sequencia[i]))
        {
            contador++;
        }
    }

    return contador;
}

void metodo_01(void)
{
    int n, total = 0;

    // Ler a quantidade de cadeias de caracteres
    n = IO_readint("Digite a quantidade de cadeias de caracteres: ");

    for (int i = 0; i < n; i = i = +1)
    {
        char sequencia[STR_SIZE]; // Armazena a cadeia lida

        // Ler a cadeia de caracteres do teclado
        strcpy(sequencia, IO_readln("Digite uma sequência de caracteres: "));

        // Contar os símbolos alfanuméricos e espaços
        int quantidade = contarAlfanumericosEEspacos(sequencia);

        // Exibir o resultado para a sequência atual
        IO_printf("Quantidade de símbolos alfanuméricos e espaços na sequência %d: %d\n", i + 1, quantidade);

        // Acumular o total apenas se houver mais de 3 símbolos
        if (quantidade > 3)
        {
            total += quantidade;
        }
    }

    // Exibir o total acumulado de cadeias com mais de três símbolos
    IO_printf("Total acumulado de símbolos em cadeias com mais de três símbolos: %d\n", total);

    // Encerrar
    IO_pause("Aperte ENTER para continuar"); // encerrar
}
// Função para contar a quantidade de dígitos em uma cadeia de caracteres
int contarDigitos(chars sequencia)
{
    int contador = 0;

    for (int i = 0; i < strlen(sequencia); i = i + 1)
    {
        if (sequencia[i] >= '0' && sequencia[i] <= '9')
        { // Verifica se é um dígito
            contador++;
        }
    }

    return contador;
}

void metodo_02(void)
{
    char sequencia1[STR_SIZE], sequencia2[STR_SIZE]; // Armazena as cadeias de caracteres
    int qtdDigitos1, qtdDigitos2;

    // Ler as duas cadeias de caracteres do teclado
    strcpy(sequencia1, IO_readln("Digite a primeira sequência de caracteres: "));
    strcpy(sequencia2, IO_readln("Digite a segunda sequência de caracteres: "));

    // Contar os dígitos em cada sequência
    qtdDigitos1 = contarDigitos(sequencia1);
    qtdDigitos2 = contarDigitos(sequencia2);

    // Exibir os resultados
    IO_printf("Quantidade de dígitos na primeira sequência: %d\n", qtdDigitos1);
    IO_printf("Quantidade de dígitos na segunda sequência: %d\n", qtdDigitos2);

    // Determinar e exibir qual sequência tem mais dígitos
    if (qtdDigitos1 > qtdDigitos2)
    {
        IO_println("A primeira sequência tem mais dígitos.");
    }
    else if (qtdDigitos2 > qtdDigitos1)
    {
        IO_println("A segunda sequência tem mais dígitos.");
    }
    else
    {
        IO_println("Ambas as sequências têm a mesma quantidade de dígitos.");
    }

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
        IO_id("EXTRASO0300 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - Parar");
        IO_println("1 - Metodo_01");
        IO_println("2 - Metodo_02");
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