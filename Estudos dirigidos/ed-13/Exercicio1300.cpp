/**
 * @author Eduardo Murta De Abreu
 * @file Exercicio1300.cpp
 */
#include "Contato.hpp"

using namespace std;

void method_00()
{
    //nao faz nada
}

void exercicio_01()
{
    Contato pessoa1;

    pessoa1.readName("Pessoa_01");
    cout    << "Pessoa1 - " << pessoa1.readName() << endl;
    getchar();
    pause("Apertar ENTER para continuar");
}
void exercicio_02()
{
    Contato pessoa2;
    pessoa2.readName("Pessoa_02");
    cout   << pessoa2.readName() << endl;
    pessoa2.readFone("Pessoa_02");
    cout   << pessoa2.readFone() << endl;
    getchar();
    pause("Aperte ENTER para continuar");
}
void exercicio_03()
{
    Contato pessoa3;
    pessoa3.readName("Pessoa_02");
    cout   << pessoa3.readName() << endl;
    pessoa3.readFone("Pessoa_02");
    cout   << pessoa3.readFone() << endl;
    getchar();
    pause("Aperte ENTER para continuar");
}

int main()
{
    exercicio_03();
    return 0;
    
}