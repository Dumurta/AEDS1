// 884985_Eduardo_Murta_De_Abreu

#include "io.h"     // deve ficar na mesma pasta do programa
#include <iso646.h> // dependencia: not, and, or, xor

/*
    Metodo para testar operadores logicos
*/
void method_01(void)
{
   // definir dado
   bool p = true;
   bool q = false;
   bool r = false;

   // mostrar mensagem com formato
   printf("%s\n", "884985_Eduardo_Murta_De_Abreu");
   // identificar
   printf("%s\n", "\nMetodo_01\n");

   printf("     p = %d\n", p);
   printf("     q = %d\n", q);
   printf("\n");

   printf("\nNegacao\n");
   r = !p; // NOT - logical negation
   printf(" !   p = %d\n", r);
   r = !q; // NOT - logical complement
   printf(" !   q = %d\n", r);
   r = not p; // NOT - logical negation
   printf("not  p = %d\n", r);
   printf("\n");

   printf("\nConjuncao\n");
   printf("0 && 0 = %d\n", (0 && 0));
   printf("0 && 1 = %d\n", (0 && 1));
   printf("1 && 0 = %d\n", (1 && 0));
   printf("1 && 1 = %d\n", (1 && 1));
   printf("\n");

   printf("\nDisjuncao\n");
   printf("0 || 0 = %d\n", (0 || 0));
   printf("0 || 1 = %d\n", (0 || 1));
   printf("1 || 0 = %d\n", (1 || 0));
   printf("1 || 1 = %d\n", (1 || 1));
   printf("\n");

   printf("\nDisjuncao exclusiva\n");
   printf("0 ^  0 = %d\n", (0 ^ 0));
   printf("0 ^  1 = %d\n", (0 ^ 1));
   printf("1 ^  0 = %d\n", (1 ^ 0));
   printf("1 ^  1 = %d\n", (1 ^ 1));
   printf("\n");

   printf("\nOperacoes logicas\n");
   r = p && q; // AND - logical conjunction
   printf("p &&  q = %d\n", r);
   r = p and q; // AND - logical conjunction
   printf("p and q = %d\n", r);
   r = p || q; // OR  - logical disjunction
   printf("p ||  q = %d\n", r);
   r = p or q; // AND - logical conjunction
   printf("p or  q = %d\n", r);
   printf("\n");

   r = p ^ q; // XOR - logical exclusive disjunction
   printf("p  ^  q = %d\n", r);
   r = p xor q; // XOR - logical exclusive disjunction
   printf("p xor q = %d\n", r);
   r = p ^ p; // XOR - logical exclusive disjunction
   printf("p  ^  p = %d\n", r);
   r = p xor p; // XOR - logical exclusive disjunction
   printf("p xor p = %d\n", r);
   printf("\n");

   // encerrar
   printf("%s\n", "Apertar ENTER para continuar.");
   getchar();
}

/*
 */
void method_02(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_02\n");
   // acoes
   // obter    o dado (por atribuicao de constante)
   lado = 5;
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // calcular o resultado
   area = lado * lado;
   // mostrar  o resultado
   printf("%s%d\n", "area = ", area);
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_03(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_03\n");
   // acoes
   // obter    o dado (por atribuicao de constante)
   lado = 5;
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // calcular o resultado (conversoes implicitas)
   area = pow(lado, 2);
   // mostrar  o resultado
   printf("%s%d\n", "area = ", area);
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_04(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_04\n");
   // acoes
   // obter    o dado (por atribuicao de constante)
   lado = 5;
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // calcular o resultado (conversoes explicitas)
   area = (int)pow((double)lado, 2.0);
   // mostrar  o resultado
   printf("%s%d\n", "area = ", area);
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_05(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_05\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // calcular o resultado
   area = lado * lado;
   // mostrar  o resultado
   printf("%s%d\n", "area = ", area);
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_06(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_06\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // testar   o dado
   if (lado >= 0)
   {
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
      // calcular o resultado
      area = lado * lado;
   }
   // mostrar  o resultado
   printf("%s%d\n", "area = ", area);
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_07(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_07\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // testar   o dado
   if (lado >= 0)
   {
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_08(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_08\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // testar   o dado
   if (lado >= 0)
   {
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_09(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
                 // identificar
   printf("%s\n", "\nMetodo_09\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado
   if (lado < 0)
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   else
   {
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_10(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_10\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado (e guardar)
   teste = (lado < 0);
   if (teste)
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   else
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_11(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_11\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado (e guardar)
   teste = (lado < 0);
   if (!teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_12(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_12\n");
   // acoes
   // obter    o dado (por leitura)
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado   (e guardar)
   teste = !(lado < 0);
   if (teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_13(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_13\n");
   // acoes
   // obter    o dado
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado  (e guardar)
   teste = (lado >= 0);
   if (teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_14(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_14\n");
   // acoes
   // obter    o dado
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado (e guardar)
   teste = (lado > 0) || (lado == 0);
   if (teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_15(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_15\n");
   // acoes
   // obter    o dado
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado  (e guardar)
   teste = (lado == 0) || (lado > 0);
   if (teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_16(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_16\n");
   // acoes
   // obter    o dado
   lado = readint("Qual o valor do lado? ");
   // mostrar  o dado
   printf("%s%d\n", "lado = ", lado);
   // testar   o dado  (e guardar)
   teste = (lado == 0) || (lado > 0);
   if (teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_17(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_17\n");
   // acoes
   // repetir ate' ler valor positivo
   do
   {
      // obter    o dado
      lado = readint("Qual o valor do lado? ");
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
      // testar   o dado (e guardar)
      teste = (lado < 0);
   } while (teste);
   if (!teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_18(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_18\n");
   // acoes
   // repetir ate' ler valor positivo
   do
   {
      // obter    o dado
      lado = readint("Qual o valor do lado? ");
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
      // testar   o dado (e guardar)
      teste = (lado >= 0);
   } while (!teste);
   if (teste)
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_19(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_19\n");
   // acoes
   // repetir ate' ler valor positivo
   do
   {
      // obter    o dado
      lado = readint("Qual o valor do lado? ");
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
   } while (lado < 0);
   if (!(lado < 0))
   {
      // calcular o resultado
      area = lado * lado;
      // mostrar  o resultado
      printf("%s%d\n", "area = ", area);
   }
   else
   {
      // mostrar  o resultado
      printf("%s%d (nao calculado)\n", "area = ", area);
   }
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

/*
 */
void method_20(void)
{
   // definir
   int lado = 0; // dado
   int area = 0; // resultado
   bool teste = false;
   // identificar
   printf("%s\n", "\nMetodo_20\n");
   // acoes
   // repetir ate' ler valor positivo
   do
   {
      // obter    o dado
      lado = readint("Qual o valor do lado? ");
      // mostrar  o dado
      printf("%s%d\n", "lado = ", lado);
   } while (lado < 0);
   // calcular o resultado
   area = lado * lado;
   // mostrar  o resultado
   printf("%s%d\n", "area = ", area);
   // encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar();
}

// ---

/*
   Acao principal.
*/
int main(void)
{
   // definir dados
   int opcao = 0;
   // identificar
   printf("\n%s\n\n", "884985_EDUARDO_MURTA_DE_ABREU");
   // acoes
   // repetir
   do
   {
      // ler opcao do teclado
      printf("%s", "Qual a opcao? ");
      scanf("%d", &opcao);
      getchar();
      // mostrar valor lido
      printf("%s%d\n", "opcao = ", opcao);
      // escolher opcao
      switch (opcao)
      {
      case 0: /* nada */
         break;
      case 1:
         method_01();
         break;
      case 2:
         method_02();
         break;
      case 3:
         method_03();
         break;
      case 4:
         method_04();
         break;
      case 5:
         method_05();
         break;
      case 6:
         method_06();
         break;
      case 7:
         method_07();
         break;
      case 8:
         method_08();
         break;
      case 9:
         method_09();
         break;
      case 10:
         method_10();
         break;
      case 11:
         method_11();
         break;
      case 12:
         method_12();
         break;
      case 13:
         method_13();
         break;
      case 14:
         method_14();
         break;
      case 15:
         method_15();
         break;
      case 16:
         method_16();
         break;
      case 17:
         method_17();
         break;
      case 18:
         method_18();
         break;
      case 19:
         method_19();
         break;
      case 20:
         method_20();
         break;
      default:
         printf("\n%s\n",
                "ERRO: Opcao invalida.\n\n");
         break;
      }
   } while (opcao != 0);
   // encerrar
   printf("%s\n", "\nApertar ENTER para terminar\n");
   getchar();
   return (0);
}
/*
    Teste e anotacoes
*/
