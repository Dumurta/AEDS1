#include "ContatoExtra.hpp"
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

void teste_E1_Multiplos_Fones()
{
    std::cout << "\n--- Exercicio Extra 1: Multiplos Telefones ---\n";
    ContatoPlus p1;
    p1.setNome("Contato Multi-Fone");
    
    p1.addFone("(11)91111-1111");
    p1.addFone("(22)92222-2222");
    p1.addFone("(33)93333-3333");

    std::cout << "Contato com " << p1.getFoneCount() << " telefones:" << std::endl;
    std::cout << p1.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void teste_E2_Enderecos()
{
    std::cout << "\n--- Exercicio Extra 2: Enderecos ---\n";
    ContatoPlus p1;
    p1.setNome("Contato com Enderecos");
    p1.addFone("(44)94444-4444");
    
    p1.setEnderecoResidencial("Rua das Flores, 123");
    p1.setEnderecoProfissional("Av. Principal, 456 - Sala 10");

    std::cout << "Contato com enderecos:" << std::endl;
    std::cout << p1.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void teste_E1_E2_Arquivo()
{
    std::cout << "\n--- Teste de Arquivo para ContatoPlus ---\n";
    ContatoPlus p_gravar;
    p_gravar.setNome("Super Contato");
    p_gravar.addFone("(11)91111-1111");
    p_gravar.addFone("(22)92222-2222");
    p_gravar.setEnderecoResidencial("Rua A, 1");
    p_gravar.setEnderecoProfissional("Rua B, 2");

    p_gravar.writeToFile("contatoplus.txt");
    std::cout << "Contato gravado em 'contatoplus.txt':" << std::endl;
    std::cout << p_gravar.toString() << std::endl;

    ContatoPlus p_ler;
    p_ler.readFromFile("contatoplus.txt");
    std::cout << "\nContato lido de 'contatoplus.txt':" << std::endl;
    std::cout << p_ler.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}


int main()
{
    int x = 0;
    do
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "MENU DE TESTES DOS EXERCICIOS EXTRAS" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "1 - Testar Multiplos Telefones (E1)" << std::endl;
        std::cout << "2 - Testar Enderecos (E2)" << std::endl;
        std::cout << "3 - Testar Leitura/Gravacao de Arquivo (E1+E2)" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> x;

        switch (x)
        {
        case 1:
            teste_E1_Multiplos_Fones();
            break;
        case 2:
            teste_E2_Enderecos();
            break;
        case 3:
            teste_E1_E2_Arquivo();
            break;
        }
    } while (x != 0);

    std::cout << "\nPrograma encerrado." << std::endl;
    return 0;
}

/*
----------------------------------------------
END-OF-FILE: exerciciosEX1300.cpp
----------------------------------------------
DOCUMENTACAO DE TESTES:
Teste 1: Cria um contato e adiciona 3 telefones. Saida esperada:
    {Contato Multi-Fone
     Fones: (11)91111-1111, (22)92222-2222, (33)93333-3333
    }
Teste 2: Cria um contato com 1 telefone e 2 enderecos. Saida esperada:
    {Contato com Enderecos
     Fones: (44)94444-4444
     End. Residencial: Rua das Flores, 123
     End. Profissional: Av. Principal, 456 - Sala 10
    }
Teste 3: Grava um contato completo em "contatoplus.txt" e depois le o mesmo arquivo para outro objeto, mostrando os dois. A saida dos dois objetos deve ser identica.
----------------------------------------------
*/