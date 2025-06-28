// 999999_AED1
#include "io.h"

/*
*/
void method_01 ( void )
{
 // definir
    int n = 0; // quantidade de dados
 // identificar
    printf("%s\n", "\nMetodo_01\n");
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       while ( n > 0 )
       {
        // mostrar o controle
           printf ( "3. n = %d\n", n );
        // passar ao proximo
           n = n - 1;
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_02 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
 // identificar
    printf ( "%s\n", "\nMetodo_02\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // copiar o dado
       x = n;           // valor inicial
    // repetir
       while ( x > 0 )  // teste
       {
        // mostrar o controle
           printf ( "3. x = %d\n", x );
        // passar ao proximo
           x = x - 1;   // variacao
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_03 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
 // identificar
    printf ( "%s\n", "\nMetodo_03\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // copiar o dado
       x = 0;           // valor inicial
    // repetir
       while ( x < n )  // teste
       {
        // mostrar o controle
           printf ( "3. x = %d\n", x );
        // passar ao proximo
           x = x + 1;   // variacao
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_04 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
 // identificar
    printf ( "%s\n", "\nMetodo_04\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x = 0;     // valor inicial
             x < n;     // teste
             x = x + 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "3. x = %d\n", x );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_05 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
 // identificar
    printf ( "%s\n", "\nMetodo_05\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x = n;     // valor inicial
             x > 0;     // teste
             x = x - 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "3. x = %d\n", x );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_06 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0;
 // identificar
    printf ( "%s\n", "\nMetodo_06\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // guardar valor inicial
       y = 0;
    // repetir
       for ( 
             x = n;     // valor inicial
             x > 0;     // teste
             x = x - 1  // variacao
           )
       {
        // alterar o valor
           y = y + 1;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_07 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0;
 // identificar
    printf ( "%s\n", "\nMetodo_07\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // guardar valor inicial
       y = 1;
    // repetir
       for ( 
             x = n;     // valor inicial
             x > 0;     // teste
             x = x - 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
        // alterar o valor
           y = y + 1;
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_08 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // independente
 // identificar
    printf ( "%s\n", "\nMetodo_08\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // guardar valor inicial
       y = n;
    // repetir
       for ( 
             x  = 1;     // valor inicial
             x <= n;     // teste
             x  = x + 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
        // alterar o valor
           y = y - 1;
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_09 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // independente
 // identificar
    printf ( "%s\n", "\nMetodo_09\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // guardar valor inicial
       y = n;
    // repetir
       for ( 
             x  = 1;     // valor inicial
             x <= n;     // teste
             x  = x + 1  // variacao
           )
       {
        // alterar o valor
           y = y - 1;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_10 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // dependente
 // identificar
    printf ( "%s\n", "\nMetodo_10\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = 1;     // valor inicial
             x <= n;     // teste
             x  = x + 1  // variacao
           )
       {
        // alterar o valor
           y = x;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_11 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // dependente
 // identificar
    printf ( "%s\n", "\nMetodo_11\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = 1;     // valor inicial
             x <= n;     // teste
             x  = x + 1  // variacao
           )
       {
        // alterar o valor
           y = (n+1)-x;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_12 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // dependente
 // identificar
    printf ( "%s\n", "\nMetodo_12\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x = n;     // valor inicial
             x > 0;     // teste
             x = x - 1  // variacao
           )
       {
        // alterar o valor
           y = (n+1)-x;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_13 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // dependente
 // identificar
    printf ( "%s\n", "\nMetodo_13\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x = n;     // valor inicial
             x > 0;     // teste
             x = x - 1  // variacao
           )
       {
        // alterar o valor
           y = x;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_14 ( void )
{
 // definir
    int n = 0; // quantidade de dados
    int x = 0; // controle
    int y = 0; // dependente
 // identificar
    printf ( "%s\n", "\nMetodo_14\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // obter a quantidade de dados
       n = readint ( "Quantos dados? " );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x = n;     // valor inicial
             x > 0;     // teste
             x = x - 1  // variacao
           )
       {
        // alterar o valor
           y = x-1;
        // mostrar o controle
           printf ( "%d\t\%d\n", x,y );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_15 ( void )
{
 // definir
    int  n = 0; // quantidade de dados
    int  x = 0; // controle
    char y [80] = ""; // vazio
 // identificar
    printf ( "%s\n", "\nMetodo_15\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // atribuir valor
       strcpy ( y, "abcde" );
    // obter a quantidade de dados
       n = strlen( y );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x = 0;     // valor inicial
             x < n;     // teste
             x = x + 1  // variacao
           )
       {
        // mostrar o controle
        // controle de posicao direto
           printf ( "%d\t%c\n", 
                      x, y[x] );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_16 ( void )
{
 // definir
    int  n = 0; // quantidade de dados
    int  x = 0; // controle
    char y [80] = ""; // vazio
 // identificar
    printf ( "%s\n", "\nMetodo_16\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // atribuir valor
       strcpy ( y, "abcde" );
    // obter a quantidade de dados
       n = strlen( y );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = n-1;   // valor inicial
             x >= 0;     // teste
             x  = x - 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "%d\t%c\n", 
                      x, y[x] );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_17 ( void )
{
 // definir
    int  n = 0; // quantidade de dados
    int  x = 0; // controle
    char y [80] = ""; // vazio
 // identificar
    printf ( "%s\n", "\nMetodo_17\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // atribuir valor
       strcpy ( y, "abcde" );
    // obter a quantidade de dados
       n = strlen( y );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = n;     // valor inicial
             x  > 0;     // teste
             x  = x - 1  // variacao
           )
       {
        // mostrar o controle
        // OBS.: controle de posicao indireto
           printf ( "%d\t%c\n", 
                      x, y[x-1] );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_18 ( void )
{
 // definir
    int  n = 0; // quantidade de dados
    int  x = 0; // controle
    char y [80] = ""; // vazio
 // identificar
    printf ( "%s\n", "\nMetodo_18\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // ler cadeia de caracteres
       printf ( "Qual a palavra? " );
       scanf  ( "%s", y ); getchar ( );
    // OBS.: Para cadeias de caracteres
    //       NAO usar & !
    // mostrar dado lido
       printf ( "[%s]\n", y );
    // obter a quantidade de dados
       n = strlen( y );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = n - 1; // valor inicial
             x >= 0;     // teste
             x  = x - 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "%d\t%c\n", 
                      x, y[x] );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_19 ( void )
{
 // definir
    int  n = 0; // quantidade de dados
    int  x = 0; // controle
    char y [80] = ""; // vazio
 // identificar
    printf ( "%s\n", "\nMetodo_19\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // ler cadeia de caracteres
       printf ( "Qual a palavra? " );
       scanf  ( "%s", y ); getchar ( );
    // OBS.: Para cadeias de caracteres
    //       NAO usar & !
    // mostrar dado lido
       printf ( "[%s]\n", y );
    // obter a quantidade de dados
       n = strlen( y );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = 0;     // valor inicial
             x <= n - 1; // teste
             x  = x + 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "%d\t%c\n", 
                      x, y[x] );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

/*
*/
void method_20 ( void )
{
 // definir
    int   n = 0;    // quantidade de dados
    int   x = 0;    // controle
    char* y = NULL; // NADA
 // identificar
    printf ( "%s\n", "\nMetodo_20\n" );
 // acoes
    // mostrar o controle
       printf ( "1. n = %d\n\n", n );
    // ler cadeia de caracteres
       y = readstring ( "Qual a palavra? " );
    // mostrar dado lido
       printf ( "[%s]\n", y );
    // obter a quantidade de dados
       n = strlen( y );
    // mostrar o controle
       printf ( "2. n = %d\n\n", n );
    // repetir
       for ( 
             x  = 0;     // valor inicial
             x  < n;     // teste
             x  = x + 1  // variacao
           )
       {
        // mostrar o controle
           printf ( "%d\t%c\n", 
                      x, y[x] );
       }
 // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

// ---

/*
   Acao principal.
*/
int main ( void )
{
    // definir dados
    int opcao = 0;
    // identificar
    printf("\n%s\n\n", "999999_AED1");
    // acoes
       // repetir
       do
       {
        // ler opcao do teclado
        printf ( "%s", "Qual a opcao? " );
        scanf  ( "%d", &opcao ); getchar( );
        // mostrar valor lido
        printf ( "%s%d\n", "opcao = ", opcao );
        // escolher opcao
        switch ( opcao )
        {
           case  0: /* nada */     break;
           case  1: method_01 ( ); break;
           case  2: method_02 ( ); break;
           case  3: method_03 ( ); break;
           case  4: method_04 ( ); break;
           case  5: method_05 ( ); break;
           case  6: method_06 ( ); break;
           case  7: method_07 ( ); break;
           case  8: method_08 ( ); break;
           case  9: method_09 ( ); break;
           case 10: method_10 ( ); break;
           case 11: method_11 ( ); break;
           case 12: method_12 ( ); break;
           case 13: method_13 ( ); break;
           case 14: method_14 ( ); break;
           case 15: method_15 ( ); break;
           case 16: method_16 ( ); break;
           case 17: method_17 ( ); break;
           case 18: method_18 ( ); break;
           case 19: method_19 ( ); break;
           case 20: method_20 ( ); break;
           default: printf ( "\n%s\n",
                           "ERRO: Opcao invalida.\n\n" );
            break;
        }
       } while ( opcao != 0 );
    // encerrar
    printf("%s\n", "\nApertar ENTER para terminar\n");
    getchar( );
	return ( 0 );
}
/*
    Teste e anotacoes
*/
