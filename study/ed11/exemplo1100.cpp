#include <iostream>
#include <limits>
#include <string>

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
}

#include "myarray.hpp"

using namespace std;

void method_00()
{
}

void method_01()
{
    Array<int> int_array(5, 0);

    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);

    int_array.print();

    int_array.free();

    pause("ENTER");
}

void method_02()
{
    // identificar
    cout << endl
         << "Method_02 - v0.0" << endl;

    Array<int> int_array(5, 0);

    int_array.read();

    int_array.print();

    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_02 ( )
/**
Method_03.
*/
void method_03()
{
    // identificar
    cout << endl
         << "Method_03 - v0.0" << endl;

    Array<int> int_array(5, 0);

    int_array.read();
    int_array.fprint("INT_ARRAY.TXT");

    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_03 ( )
/**
Method_04.
*/
void method_04()
{
    // identificar
    cout << endl
         << "Method_04 - v0.0" << endl;
    Array<int> int_array(5, 0);

    int_array.fread("INT_ARRAY.TXT");

    int_array.print();
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_04 ( )
/**
Method_05.
*/
void method_05()
{
    // identificar
    cout << endl
         << "Method_05 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_05 ( )
/**
Method_06.
*/
void method_06()
{
    // identificar
    cout << endl
         << "Method_06 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_06 ( )
/**
Method_07.
*/
void method_07()
{
    // identificar
    cout << endl
         << "Method_07 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_07 ( )
/**
Method_08.
*/
void method_08()
{
    // identificar
    cout << endl
         << "Method_08 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_08 ( )
/**
Method_09.
*/
void method_09()
{
    // identificar
    cout << endl
         << "Method_09 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_09 ( )
/**
Method_10.
*/
void method_10()
{
    // identificar
    cout << endl
         << "Method_10 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_10 ( )
// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - mostrar dados inteiros em arranjo " << endl;
        cout << " 2 - " << endl;
        cout << " 3 - " << endl;
        cout << " 4 - " << endl;
        cout << " 5 - " << endl;
        cout << " 6 - " << endl;
        cout << " 7 - " << endl;
        cout << " 8 - " << endl;
        cout << " 9 - " << endl;
        cout << "10 - " << endl;
        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
        switch (x)
        {
        case 0:
            method_00();
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
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        } // end switch
    } while (x != 0);
    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // end main