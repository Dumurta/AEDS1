#include "io.h"  // Biblioteca personalizada
#include <ctype.h>  // Para usar a função isalnum
#include <string.h> // Para manipulação de strings
void metodo_00(void) {
    // nao faz nada
} // end metodo_00()
void metodo_01(void) {
    char linha[STR_SIZE]; // Cadeia de caracteres para armazenar a entrada
    char simbolos[STR_SIZE]; // Cadeia para armazenar os símbolos não alfanuméricos
    int j = 0;

    // Ler a linha completa do teclado
    strcpy(linha, IO_readln("Digite uma linha de texto: "));

    // Percorrer a linha e separar os símbolos não alfanuméricos
    for (int i = 0; i < strlen(linha); i++) {
        if (!isalnum(linha[i])) { // Se não for letra nem número
            simbolos[j++] = linha[i];
        }
    }
    simbolos[j] = '\0'; // Adicionar o terminador de string

    // Mostrar os símbolos encontrados
    IO_println("Símbolos não alfanuméricos encontrados:");
    IO_println(simbolos);

    // Encerrar
    IO_pause("Apertar ENTER para continuar.");  

}//end metodo_01
void metodo_02(void) {
    char linha[STR_SIZE]; // Cadeia de caracteres para armazenar a entrada
    bool apenas_simbolos = true; // Variável para verificar a condição

    // Ler a cadeia de caracteres do teclado
    strcpy(linha, IO_readln("Digite uma sequência de caracteres: "));

    // Percorrer a sequência e verificar se há letras ou números
    for (int i = 0; i < strlen(linha); i++) {
        if (isalnum(linha[i])) { // Se for letra ou número
            apenas_simbolos = false;
            break; // Interrompe a verificação assim que encontrar um alfanumérico
        }
    }

    // Exibir o resultado
    if (apenas_simbolos) {
        IO_println("A sequência contém apenas símbolos não alfanuméricos.");
    } else {
        IO_println("A sequência contém letras e/ou números.");
    }
    //encerrar
    IO_pause("Apertar ENTER para continuar.");

}//end metodo_02
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