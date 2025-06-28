/*
    Exemplo1300 - v0.0 06/06/2025
    @author Eduardo Murta De Abreu
*/

#include "Contato.hpp"
#include <iostream>

void pause(std::string text)
{
    std::string dummy;
    std::cout << std::endl << text;
    if (std::cin.peek() == '\n')
    {
        std::cin.ignore();
    }
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

void method_00()
{
}

void method_01()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();
    std::cout << "\nMethod_01 - v0.0\n"
              << std::endl;
    pause("Apertar ENTER para continuar");
}

void method_02()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();
    std::cout << "\nMethod_02 - v0.0\n"
              << std::endl;
    pessoa1.setNome("Pessoa_01");
    pessoa1.setFone("111");
    pessoa3->setNome("Pessoa_03");
    pessoa3->setFone("333");
    std::cout << "pessoa1 - { " << pessoa1.getNome() << ", " << pessoa1.getFone() << " }" << std::endl;
    std::cout << "pessoa3 - { " << pessoa3->getNome() << ", " << pessoa3->getFone() << " }" << std::endl;
    pause("Apertar ENTER para continuar");
}

void method_03()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();
    std::cout << "\nMethod_03 - v0.0\n"
              << std::endl;
    pessoa1.setNome("Pessoa_01");
    pessoa1.setFone("111");
    pessoa3->setNome("Pessoa_03");
    pessoa3->setFone("333");
    std::cout << "pessoa1 - " << pessoa1.toString() << std::endl;
    std::cout << "pessoa3 - " << pessoa3->toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void method_04()
{
    Contato pessoa1("Pessoa_01", "111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("Pessoa_03", "333");
    std::cout << "\nMethod_04 - v0.0\n"
              << std::endl;
    std::cout << "pessoa1 - " << pessoa1.toString() << std::endl;
    std::cout << "pessoa3 - " << pessoa3->toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void method_05()
{
    Contato pessoa1("Pessoa_01", "111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333");
    std::cout << "\nMethod_05 - v0.0\n"
              << std::endl;
    std::cout << "pessoa1 - " << pessoa1.toString() << " (" << pessoa1.getErro() << ")" << std::endl;
    std::cout << "pessoa3 - " << pessoa3->toString() << " (" << pessoa3->getErro() << ")" << std::endl;
    pause("Apertar ENTER para continuar");
}

void method_06()
{
    Contato pessoa1("Pessoa_01", "111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333");
    std::cout << "\nMethod_06 - v0.0\n"
              << std::endl;
    if (!pessoa1.hasErro())
    {
        std::cout << "pessoa1 - " << pessoa1.toString() << std::endl;
    }
    else
    {
        std::cout << "pessoa1 tem erro (" << pessoa1.getErro() << ")" << std::endl;
    }
    if (!pessoa3->hasErro())
    {
        std::cout << "pessoa3 - " << pessoa3->toString() << std::endl;
    }
    else
    {
        std::cout << "pessoa3 tem erro (" << pessoa3->getErro() << ")" << std::endl;
    }
    pause("Apertar ENTER para continuar");
}

void method_07()
{
    Contato pessoa1("Pessoa_01", "111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333");
    std::cout << "\nMethod_07 - v0.0\n"
              << std::endl;
    pessoa2 = &pessoa1;
    if (!pessoa2->hasErro())
    {
        std::cout << "pessoa1 - " << pessoa2->toString() << std::endl;
    }
    else
    {
        std::cout << "pessoa1 tem erro (" << pessoa2->getErro() << ")" << std::endl;
    }
    pessoa2 = pessoa3;
    if (!pessoa2->hasErro())
    {
        std::cout << "pessoa3 - " << pessoa2->toString() << std::endl;
    }
    else
    {
        std::cout << "pessoa3 tem erro (" << pessoa2->getErro() << ")" << std::endl;
    }
    pause("Apertar ENTER para continuar");
}

void method_08()
{
    Contato pessoa1("Pessoa_01", "111");
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "333");
    ref_Contato pessoa4 = nullptr;
    std::cout << "\nEXEMPLO1308 - Method_08 - v0.0\n"
              << std::endl;
    pessoa2 = new Contato(pessoa1);
    if (pessoa2)
    {
        std::cout << "pessoa2 - " << pessoa2->toString() << std::endl;
    }
    else
    {
        std::cout << "pessoa2 tem erro (" << pessoa2->getErro() << ")" << std::endl;
    }
    if (pessoa3)
    {
        pessoa2 = new Contato(*pessoa3);
        if (pessoa2)
        {
            std::cout << "pessoa2 - " << pessoa2->toString() << std::endl;
        }
        else
        {
            std::cout << "pessoa2 tem erro (" << pessoa2->getErro() << ")" << std::endl;
        }
    }
    if (pessoa4)
    {
        pessoa2 = new Contato(*pessoa4);
        if (pessoa2)
        {
            std::cout << "pessoa2 - " << pessoa2->toString() << std::endl;
        }
        else
        {
            std::cout << "pessoa2 tem erro (" << pessoa4->getErro() << ")" << std::endl;
        }
    }
    pause("Apertar ENTER para continuar");
}

void method_09()
{
    Contato pessoa[3];
    int x = 0;
    std::cout << "\nMethod_09 - v0.0\n"
              << std::endl;
    pessoa[0].setNome("Pessoa_1");
    pessoa[0].setFone("111");
    pessoa[1].setNome("Pessoa_2");
    pessoa[1].setFone("222");
    pessoa[2].setNome("Pessoa_3");
    pessoa[2].setFone("333");
    for (x = 0; x < 3; x = x + 1)
    {
        std::cout << x << ": " << pessoa[x].toString() << std::endl;
    }
    pause("Apertar ENTER para continuar");
}

void method_10()
{
    Contato *pessoa[3];
    int x = 0;
    std::cout << "\nMethod_10 - v0.0\n"
              << std::endl;
    pessoa[0] = new Contato("Pessoa_1", "111");
    pessoa[1] = new Contato("Pessoa_2", "222");
    pessoa[2] = new Contato("Pessoa_3", "333");
    for (x = 0; x < 3; x = x + 1)
    {
        std::cout << x << ": " << pessoa[x]->toString() << std::endl;
    }
    pause("Apertar ENTER para continuar");
}

int main(int argc, char **argv)
{
    int x = 0;
    do
    {
        std::cout << "EXEMPLO1300 - Programa - v0.0\n"
                  << std::endl;
        std::cout << "Opcoes" << std::endl;
        std::cout << "0 - parar" << std::endl;
        std::cout << "1 - testar definicao de contatos (objetos)" << std::endl;
        std::cout << "2 - Testar atribuicoes" << std::endl;
        std::cout << "3 - Testar recuperacao de dados" << std::endl;
        std::cout << "4 - Testar construtor alternativo" << std::endl;
        std::cout << "5 - Testar construtor alternativo com erro" << std::endl;
        std::cout << "6 - Testar verificacao de erro" << std::endl;
        std::cout << "7 - Testar atribuicoes e tratamento de erro com ponteiros" << std::endl;
        std::cout << "8 - Testar construtor de copia" << std::endl;
        std::cout << "9 - Testar arranjo de objetos" << std::endl;
        std::cout << "10 - Testar arranjo de ponteiros para objetos" << std::endl;
        std::cout << std::endl
                  << "Entrar com uma opcao: ";
        std::cin >> x;
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
            std::cout << std::endl
                      << "ERRO: Valor invalido." << std::endl;
        }
    } while (x != 0);
    pause("Apertar ENTER para terminar");
    return (0);
}

/*
----------------------------------------------
END-OF-FILE: Exemplo1300.cpp
----------------------------------------------
DOCUMENTACAO DE TESTES:
Method 01: Apenas cria objetos e encerra. Nao ha saida alem do menu.
Method 02: Saida esperada:
    pessoa1 - { Pessoa_01, 111 }
    pessoa3 - { Pessoa_03, 333 }
Method 03: Saida esperada:
    pessoa1 - {Pessoa_01, 111}
    pessoa3 - {Pessoa_03, 333}
Method 04: Saida esperada:
    pessoa1 - {Pessoa_01, 111}
    pessoa3 - {Pessoa_03, 333}
Method 05: Saida esperada:
    pessoa1 - {Pessoa_01, 111} (0)
    pessoa3 - {, 333} (1)
Method 06: Saida esperada:
    pessoa1 - {Pessoa_01, 111}
    pessoa3 tem erro (1)
Method 07: Saida esperada:
    pessoa1 - {Pessoa_01, 111}
    pessoa3 tem erro (1)
Method 08: Saida esperada:
    pessoa2 - {Pessoa_01, 111}
    pessoa2 - {, 333}
Method 09: Saida esperada:
    0: {Pessoa_1, 111}
    1: {Pessoa_2, 222}
    2: {Pessoa_3, 333}
Method 10: Saida esperada:
    0: {Pessoa_1, 111}
    1: {Pessoa_2, 222}
    2: {Pessoa_3, 333}
----------------------------------------------
*/