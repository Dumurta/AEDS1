// 999999_AED1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void  print   ( char *text )
{
    printf   ( "%s"  , text );    
}
void  println ( char *text )
{
    printf   ( "%s\n", text );    
}
void  pause   ( char *text )
{
    printf   ( "%s\n", text );    
    getchar( );
}
void   flush      ( void )
{
    char    x = '0';
    do
    {       x = getchar ( );     }
    while ( x != '\n' );
}
int    readint    ( char *text )
{
    int     x = 0;
    printf  ( "%s" , text );
    scanf   ( "%d" , &x   );   flush ( );
    return  ( x );
}
double readdouble ( char *text )
{
    double  x = 0.0;
    printf  ( "%s" , text );
    scanf   ( "%lf", &x   );   flush ( );
    return  ( x );
}
bool   readbool   ( char *text )
{
    int     x = 0;
    printf  ( "%s" , text );
    scanf   ( "%d" , &x   );   flush ( );
    return  ( x != 0 );
}
char   readchar   ( char *text )
{
    char    x = '0';
    char    y = '0';
    printf  ( "%s" , text );
    scanf   ( "%c" , &x   );   
    do
    {       y = getchar ( );      }
    while ( y != '\n' );
    return  ( x );
}
