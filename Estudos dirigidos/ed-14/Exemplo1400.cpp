/*
    Exemplo1400.cpp - v1.0.0
    Author: Eduardo Murta De Abreu - 884985
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "MyStringEx.hpp"

void pause(std::string text)
{
    std::string dummy;
    std::cout << std::endl << text;
    if (std::cin.peek() == '\n') std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl;
}

void method_01()
{
    std::cout << "\n--- Metodo 01: Teste getInt() ---\n";
    MyStringEx s1("1234"), s2("-567"), s3("abc"), s4("12a34");
    std::cout << "s1(\"1234\") -> " << s1.getInt() << " | Erro: " << s1.getErro() << std::endl;
    std::cout << "s2(\"-567\") -> " << s2.getInt() << " | Erro: " << s2.getErro() << std::endl;
    std::cout << "s3(\"abc\") -> " << s3.getInt() << " | Erro: " << s3.getErroMsg() << std::endl;
    std::cout << "s4(\"12a34\") -> " << s4.getInt() << " | Erro: " << s4.getErroMsg() << std::endl;
}

void method_02()
{
    std::cout << "\n--- Metodo 02: Teste getDouble() ---\n";
    MyStringEx s1("123.45"), s2("-56.7"), s3("1.2.3"), s4("xyz");
    std::cout << "s1(\"123.45\") -> " << s1.getDouble() << " | Erro: " << s1.getErro() << std::endl;
    std::cout << "s2(\"-56.7\") -> " << s2.getDouble() << " | Erro: " << s2.getErro() << std::endl;
    std::cout << "s3(\"1.2.3\") -> " << s3.getDouble() << " | Erro: " << s3.getErroMsg() << std::endl;
    std::cout << "s4(\"xyz\") -> " << s4.getDouble() << " | Erro: " << s4.getErroMsg() << std::endl;
}

void method_03()
{
    std::cout << "\n--- Metodo 03: Teste getBoolean() ---\n";
    MyStringEx s1("true"), s2("F"), s3("0"), s4("invalido");
    std::cout << std::boolalpha;
    std::cout << "s1(\"true\") -> " << s1.getBoolean() << " | Erro: " << s1.getErro() << std::endl;
    std::cout << "s2(\"F\") -> " << s2.getBoolean() << " | Erro: " << s2.getErro() << std::endl;
    std::cout << "s3(\"0\") -> " << s3.getBoolean() << " | Erro: " << s3.getErro() << std::endl;
    std::cout << "s4(\"invalido\") -> " << s4.getBoolean() << " | Erro: " << s4.getErroMsg() << std::endl;
}

void method_04()
{
    std::cout << "\n--- Metodo 04: Teste contains() ---\n";
    MyStringEx s1("o rato roeu a roupa");
    std::cout << std::boolalpha;
    std::cout << "s1(\"o rato roeu a roupa\") contem \"roeu\"? -> " << s1.contains("roeu") << std::endl;
    std::cout << "s1(\"o rato roeu a roupa\") contem \"gato\"? -> " << s1.contains("gato") << std::endl;
}

void method_05()
{
    std::cout << "\n--- Metodo 05: Teste toUpperCase() ---\n";
    MyStringEx s1("Teste em Minusculas");
    std::cout << "s1(\"Teste em Minusculas\") -> " << s1.toUpperCase() << std::endl;
}

void method_06()
{
    std::cout << "\n--- Metodo 06: Teste toLowerCase() ---\n";
    MyStringEx s1("TESTE EM MAIUSCULAS");
    std::cout << "s1(\"TESTE EM MAIUSCULAS\") -> " << s1.toLowerCase() << std::endl;
}

void method_07()
{
    std::cout << "\n--- Metodo 07: Teste replace() ---\n";
    MyStringEx s1("banana");
    std::cout << "s1(\"banana\").replace('a', 'o') -> " << s1.replace('a', 'o') << std::endl;
}

void method_08()
{
    std::cout << "\n--- Metodo 08: Teste encrypt() ---\n";
    MyStringEx s1("abc xyz");
    int chave = 3;
    std::cout << "s1(\"abc xyz\").encrypt("<< chave <<") -> " << s1.encrypt(chave) << std::endl;
}

void method_09()
{
    std::cout << "\n--- Metodo 09: Teste decrypt() ---\n";
    MyStringEx s1("def abc");
    int chave = 3;
    std::cout << "s1(\"def abc\").decrypt("<< chave <<") -> " << s1.decrypt(chave) << std::endl;
}

void method_10()
{
    std::cout << "\n--- Metodo 10: Teste split() ---\n";
    MyStringEx s1("um dois tres quatro");
    std::string palavras[10];
    int n = s1.split(palavras);
    std::cout << "String: \"" << s1.getContent() << "\"" << std::endl;
    std::cout << "Foram encontradas " << n << " palavras:" << std::endl;
    for(int i=0; i<n; ++i) {
        std::cout << i+1 << ": " << palavras[i] << std::endl;
    }
}


int main()
{
    int x = 0;
    do
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "MENU DE TESTES - Estudo Dirigido 14" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << " 1 - Testar getInt()" << std::endl;
        std::cout << " 2 - Testar getDouble()" << std::endl;
        std::cout << " 3 - Testar getBoolean()" << std::endl;
        std::cout << " 4 - Testar contains()" << std::endl;
        std::cout << " 5 - Testar toUpperCase()" << std::endl;
        std::cout << " 6 - Testar toLowerCase()" << std::endl;
        std::cout << " 7 - Testar replace()" << std::endl;
        std::cout << " 8 - Testar encrypt()" << std::endl;
        std::cout << " 9 - Testar decrypt()" << std::endl;
        std::cout << "10 - Testar split()" << std::endl;
        std::cout << " 0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> x;

        switch (x)
        {
        case 1: method_01(); break;
        case 2: method_02(); break;
        case 3: method_03(); break;
        case 4: method_04(); break;
        case 5: method_05(); break;
        case 6: method_06(); break;
        case 7: method_07(); break;
        case 8: method_08(); break;
        case 9: method_09(); break;
        case 10: method_10(); break;
        }
        if (x != 0) pause("Apertar ENTER para continuar");

    } while (x != 0);

    return 0;
}

/*
----------------------------------------------
END-OF-FILE: Exemplo1400.cpp
----------------------------------------------
DOCUMENTACAO DE TESTES:
Metodo 01: Saida esperada:
    s1("1234") -> 1234 | Erro: 0
    s2("-567") -> -567 | Erro: 0
    s3("abc") -> -1 | Erro: [ERRO] Conteudo nao representa um valor inteiro.
    s4("12a34") -> -1 | Erro: [ERRO] Conteudo nao representa um valor inteiro.
Metodo 02: Saida esperada:
    s1("123.45") -> 123.45 | Erro: 0
    s2("-56.7") -> -56.7 | Erro: 0
    s3("1.2.3") -> 0 | Erro: [ERRO] Conteudo nao representa um valor real.
    s4("xyz") -> 0 | Erro: [ERRO] Conteudo nao representa um valor real.
Metodo 03: Saida esperada:
    s1("true") -> true | Erro: 0
    s2("F") -> false | Erro: 0
    s3("0") -> false | Erro: 0
    s4("invalido") -> false | Erro: [ERRO] Conteudo nao representa um valor logico.
Metodo 04: Saida esperada:
    s1("o rato roeu a roupa") contem "roeu"? -> true
    s1("o rato roeu a roupa") contem "gato"? -> false
Metodo 05: Saida esperada:
    s1("Teste em Minusculas") -> TESTE EM MINUSCULAS
Metodo 06: Saida esperada:
    s1("TESTE EM MAIUSCULAS") -> teste em maiusculas
Metodo 07: Saida esperada:
    s1("banana").replace('a', 'o') -> bonono
Metodo 08: Saida esperada (chave=3):
    s1("abc xyz").encrypt(3) -> def abc
Metodo 09: Saida esperada (chave=3):
    s1("def abc").decrypt(3) -> abc xyz
Metodo 10: Saida esperada:
    String: "um dois tres quatro"
    Foram encontradas 4 palavras:
    1: um
    2: dois
    3: tres
    4: quatro
----------------------------------------------
*/