#include "ContatoEx.hpp"
#include <iostream>

void pause(std::string text)
{
    std::string dummy;
    std::cout << std::endl
              << text;
    if (std::cin.peek() == '\n')
    {
        std::cin.ignore();
    }
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
}

void exercicio_01()
{
    std::cout << "\n--- Exercicio 01: Teste de Nome ---\n";
    ContatoEx pessoa;
    pessoa.readName("Digite um nome: ");
    if (pessoa.hasErro())
    {
        std::cout << "ERRO: Nome nao pode ser vazio." << std::endl;
    }
    else
    {
        std::cout << "Nome lido com sucesso: " << pessoa.getNome() << std::endl;
    }
    pause("Apertar ENTER para continuar");
}

void exercicio_02()
{
    std::cout << "\n--- Exercicio 02: Teste de Telefone ---\n";
    ContatoEx pessoa;
    std::string fone;
    std::cout << "Digite o telefone no formato (XX)XXXXX-XXXX: ";
    std::cin >> fone;
    pessoa.setFone(fone);
    if (pessoa.hasErro())
    {
        std::cout << "ERRO: O formato do telefone e invalido." << std::endl;
    }
    else
    {
        std::cout << "Telefone lido com sucesso: " << pessoa.getFone() << std::endl;
    }
    pause("Apertar ENTER para continuar");
}

void exercicio_03()
{
    std::cout << "\n--- Exercicio 03: Teste de Validacao Interna ---\n";
    std::cout << "A validacao do formato do telefone (Ex 03) e' usada por todos os outros testes." << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_04()
{
    std::cout << "\n--- Exercicio 04: Teste Ler de Arquivo ---\n";
    ContatoEx p_gravado;
    p_gravado.setNome("Contato Exemplo");
    p_gravado.setFone("(11)98888-8888");
    p_gravado.writeToFile("contato_teste.txt");
    std::cout << "Um contato de teste foi gravado em 'contato_teste.txt'" << std::endl;

    ContatoEx p_lido;
    p_lido.readFromFile("contato_teste.txt");
    std::cout << "Contato lido de 'contato_teste.txt': " << p_lido.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_05()
{
    std::cout << "\n--- Exercicio 05: Teste Gravar em Arquivo ---\n";
    ContatoEx pessoa;
    pessoa.setNome("Usuario Teste");
    pessoa.setFone("(22)97777-7777");
    pessoa.setFone2("(33)96666-6666");
    pessoa.writeToFile("contato_gravado.txt");
    std::cout << "O seguinte contato foi gravado em 'contato_gravado.txt': " << pessoa.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_06()
{
    std::cout << "\n--- Exercicio 06: Teste de Atributo Fone 2 ---\n";
    ContatoEx pessoa;
    pessoa.setNome("Beltrano");
    pessoa.setFone("(33)93333-3333");
    pessoa.setFone2("(44)94444-4444");
    std::cout << "Contato com dois telefones: " << pessoa.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_07()
{
    std::cout << "\n--- Exercicio 07: Teste de Quantidade de Fones ---\n";
    ContatoEx p1;
    std::cout << "Contato p1 (vazio) tem " << p1.phones() << " telefone(s)." << std::endl;

    p1.setFone("(11)91111-1111");
    std::cout << "Contato p1 (com 1 fone) tem " << p1.phones() << " telefone(s)." << std::endl;

    p1.setFone2("(22)92222-2222");
    std::cout << "Contato p1 (com 2 fones) tem " << p1.phones() << " telefone(s)." << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_08()
{
    std::cout << "\n--- Exercicio 08: Teste para Atribuir Fone 2 ---\n";
    ContatoEx pessoa;
    pessoa.setNome("Ciclano");
    pessoa.setFone("(55)95555-5555");
    std::cout << "Antes: " << pessoa.toString() << std::endl;

    pessoa.setFone2("(66)96666-6666");
    std::cout << "Depois: " << pessoa.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_09()
{
    std::cout << "\n--- Exercicio 09: Teste para Alterar Fone 2 ---\n";
    ContatoEx pessoa;
    pessoa.setNome("Josue");

    std::cout << "Tentando alterar fone 2 sem ele existir..." << std::endl;
    pessoa.alterFone2("(11)91111-1111");
    if (pessoa.getErro() == 4)
    {
        std::cout << "OK, erro 4 (fone 2 nao existe) foi capturado." << std::endl;
    }

    pessoa.resetErro();
    pessoa.setFone("(11)91111-1111");
    pessoa.setFone2("(22)92222-2222");
    std::cout << "\nAntes de alterar: " << pessoa.toString() << std::endl;
    pessoa.alterFone2("(99)99999-9999");
    std::cout << "Depois de alterar: " << pessoa.toString() << std::endl;
    pause("Apertar ENTER para continuar");
}

void exercicio_10()
{
    std::cout << "\n--- Exercicio 10: Teste para Remover Fone 2 ---\n";
    ContatoEx pessoa;
    pessoa.setNome("Moises");
    pessoa.setFone("(11)91111-1111");
    pessoa.setFone2("(22)92222-2222");

    std::cout << "Antes de remover: " << pessoa.toString() << " (fones: " << pessoa.phones() << ")" << std::endl;
    pessoa.removeFone2();
    std::cout << "Depois de remover: " << pessoa.toString() << " (fones: " << pessoa.phones() << ")" << std::endl;
    pause("Apertar ENTER para continuar");
}

int main()
{
    int x = 0;
    do
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "MENU DE TESTES DOS EXERCICIOS (01 a 10)" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "1 - Testar Leitura de Nome (Ex 01)" << std::endl;
        std::cout << "2 - Testar Leitura de Fone (Ex 02)" << std::endl;
        std::cout << "3 - Testar Validacao (Ex 03)" << std::endl;
        std::cout << "4 - Testar Ler Arquivo (Ex 04)" << std::endl;
        std::cout << "5 - Testar Gravar Arquivo (Ex 05)" << std::endl;
        std::cout << "6 - Testar Segundo Telefone (Ex 06)" << std::endl;
        std::cout << "7 - Testar Quantidade de Fones (Ex 07)" << std::endl;
        std::cout << "8 - Testar Atribuir Fone 2 (Ex 08)" << std::endl;
        std::cout << "9 - Testar Alterar Fone 2 (Ex 09)" << std::endl;
        std::cout << "10 - Testar Remover Fone 2 (Ex 10)" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> x;

        switch (x)
        {
        case 1: exercicio_01(); break;
        case 2: exercicio_02(); break;
        case 3: exercicio_03(); break;
        case 4: exercicio_04(); break;
        case 5: exercicio_05(); break;
        case 6: exercicio_06(); break;
        case 7: exercicio_07(); break;
        case 8: exercicio_08(); break;
        case 9: exercicio_09(); break;
        case 10: exercicio_10(); break;
        }
    } while (x != 0);

    std::cout << "\nPrograma encerrado." << std::endl;
    return 0;
}

/*
----------------------------------------------
END-OF-FILE: Exercicio1300.cpp
----------------------------------------------
DOCUMENTACAO DE TESTES:
Exercicio 01: Pede um nome. Se for valido, imprime "Nome lido com sucesso: [nome digitado]". Se for vazio, imprime "ERRO: Nome nao pode ser vazio.".
Exercicio 02: Pede um telefone. Se for valido, imprime "Telefone lido com sucesso: [fone digitado]". Se o formato for invalido, imprime "ERRO: O formato do telefone e invalido.".
Exercicio 03: Apenas exibe uma mensagem informativa.
Exercicio 04: Grava um contato padrao em "contato_teste.txt" e depois le o mesmo arquivo, mostrando o resultado. Saida esperada:
    Um contato de teste foi gravado em 'contato_teste.txt'
    Contato lido de 'contato_teste.txt': {Contato Exemplo, (11)98888-8888}
Exercicio 05: Cria um contato com dois telefones e o grava no arquivo "contato_gravado.txt". Saida esperada:
    O seguinte contato foi gravado em 'contato_gravado.txt': {Usuario Teste, (22)97777-7777, (33)96666-6666}
Exercicio 06: Mostra um contato com dois telefones. Saida esperada:
    Contato com dois telefones: {Beltrano, (33)93333-3333, (44)94444-4444}
Exercicio 07: Mostra a contagem de telefones em cada etapa. Saida esperada:
    Contato p1 (vazio) tem 0 telefone(s).
    Contato p1 (com 1 fone) tem 1 telefone(s).
    Contato p1 (com 2 fones) tem 2 telefone(s).
Exercicio 08: Mostra a atribuicao do segundo fone. Saida esperada:
    Antes: {Ciclano, (55)95555-5555}
    Depois: {Ciclano, (55)95555-5555, (66)96666-6666}
Exercicio 09: Testa a logica de alteracao do segundo fone. Saida esperada:
    Tentando alterar fone 2 sem ele existir...
    OK, erro 4 (fone 2 nao existe) foi capturado.
    Antes de alterar: {Josue, (11)91111-1111, (22)92222-2222}
    Depois de alterar: {Josue, (11)91111-1111, (99)99999-9999}
Exercicio 10: Testa a remocao do segundo fone. Saida esperada:
    Antes de remover: {Moises, (11)91111-1111, (22)92222-2222} (fones: 2)
    Depois de remover: {Moises, (11)91111-1111} (fones: 1)
----------------------------------------------
*/