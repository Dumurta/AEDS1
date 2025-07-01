/*
    Exemplo1500.cpp - v2.0.0
    Author: Eduardo Murta De Abreu - 884985
*/

#include <iostream>

// === Implementação das Funções do Estudo Dirigido 15 ===

/**
 * Funcao auxiliar para calcular o tamanho de uma cadeia de caracteres (C-style string).
 */
int str_len(const char *s)
{
    int count = 0;
    if (s)
    {
        while (s[count] != '\0')
        {
            count = count + 1;
        }
    }
    return count;
}

/**
 * Funcao auxiliar para criar uma copia de uma string
 */
char* str_dup(const char* s)
{
    if (!s) return nullptr;
    int len = str_len(s);
    char* new_s = new char[len + 1];
    for(int i = 0; i < len; i = i + 1)
    {
        new_s[i] = s[i];
    }
    new_s[len] = '\0';
    return new_s;
}

/**
 * 01.) Funcao para acrescentar caractere ao final.
 */
char *str_push_back(char *s, char c)
{
    int old_len = str_len(s);
    char *new_s = new char[old_len + 2];
    for (int i = 0; i < old_len; i = i + 1)
    {
        new_s[i] = s[i];
    }
    new_s[old_len] = c;
    new_s[old_len + 1] = '\0';
    if (s) delete[] s;
    return new_s;
}

/**
 * 02.) Funcao para remover caractere do final.
 */
char *str_pop_back(char *s)
{
    if (!s || s[0] == '\0') return s;
    int old_len = str_len(s);
    char *new_s = new char[old_len];
    for (int i = 0; i < old_len - 1; i = i + 1)
    {
        new_s[i] = s[i];
    }
    new_s[old_len - 1] = '\0';
    delete[] s;
    return new_s;
}

/**
 * 03.) Funcao para acrescentar caractere ao inicio.
 */
char *str_push_front(char c, char *s)
{
    int old_len = str_len(s);
    char *new_s = new char[old_len + 2];
    new_s[0] = c;
    for (int i = 0; i < old_len; i = i + 1)
    {
        new_s[i + 1] = s[i];
    }
    new_s[old_len + 1] = '\0';
    if (s) delete[] s;
    return new_s;
}

/**
 * 04.) Funcao para remover caractere do inicio.
 */
char *str_pop_front(char *s)
{
    if (!s || s[0] == '\0') return s;
    int old_len = str_len(s);
    char *new_s = new char[old_len];
    for (int i = 0; i < old_len - 1; i = i + 1)
    {
        new_s[i] = s[i + 1];
    }
    new_s[old_len - 1] = '\0';
    delete[] s;
    return new_s;
}

/**
 * 05.) Funcao para inserir caractere no meio.
 */
char* str_push_mid(char *s, char c)
{
    int len = str_len(s);
    if (len < 2) return str_push_back(s, c);
    
    int mid = len / 2;
    char* new_s = new char[len + 2];

    for(int i=0; i < mid; i = i + 1) new_s[i] = s[i];
    new_s[mid] = c;
    for(int i=mid; i < len; i = i + 1) new_s[i+1] = s[i];
    new_s[len + 1] = '\0';

    if(s) delete[] s;
    return new_s;
}

/**
 * 06.) Funcao para remover caractere do meio.
 */
char* str_pop_mid(char *s)
{
    int len = str_len(s);
    if(len < 2) return str_pop_back(s);

    int mid = len / 2;
    char* new_s = new char[len];

    for(int i=0; i < mid; i = i + 1) new_s[i] = s[i];
    for(int i=mid + 1; i < len; i = i + 1) new_s[i-1] = s[i];
    new_s[len-1] = '\0';

    if(s) delete[] s;
    return new_s;
}

/**
 * 09.) Funcao para procurar pela primeira ocorrencia de certo simbolo.
 * Nota: O PDF tem um erro no prototipo (retorno char). O correto e' char*.
 */
char* str_chr(char *s, char c)
{
    if (!s) return nullptr;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == c)
        {
            return &s[i];
        }
        i = i + 1;
    }
    return nullptr;
}

/**
 * 10.) Funcao para separar caracteres ate' a ocorrencia de delimitador.
 */
char* str_tok(char *s, char delimiter)
{
    if(!s) return nullptr;
    int len = 0;
    while(s[len] != '\0' && s[len] != delimiter)
    {
        len = len + 1;
    }
    char* token = new char[len + 1];
    for(int i=0; i < len; i = i + 1)
    {
        token[i] = s[i];
    }
    token[len] = '\0';
    return token;
}

/**
 * E1.) Funcao para procurar por certo prefixo.
 */
char* str_prefix(const char *prefix, const char *s)
{
    if(!prefix || !s) return nullptr;
    int len_prefix = str_len(prefix);
    int len_s = str_len(s);

    if(len_prefix > len_s) return nullptr;

    for(int i=0; i < len_prefix; i = i + 1)
    {
        if(prefix[i] != s[i]) return nullptr;
    }
    return (char*)s;
}

/**
 * E2.) Funcao para procurar por certo sufixo.
 */
char* str_suffix(const char *s, const char *suffix)
{
    if(!suffix || !s) return nullptr;
    int len_suffix = str_len(suffix);
    int len_s = str_len(s);

    if(len_suffix > len_s) return nullptr;

    int start_pos = len_s - len_suffix;
    for(int i=0; i < len_suffix; i = i + 1)
    {
        if(s[start_pos + i] != suffix[i]) return nullptr;
    }
    return (char*)&s[start_pos];
}

// === Fim da Implementação ===

void pause(std::string text)
{
    std::string dummy;
    std::cout << std::endl << text;
    if (std::cin.peek() == '\n') std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl;
}

void method_01() {
    std::cout << "\n--- Metodo 01: Teste str_push_back() ---\n";
    char *s = str_dup("");
    std::cout << "Inicial: [" << s << "]" << std::endl;
    s = str_push_back(s, 'a');
    std::cout << "push 'a': [" << s << "]" << std::endl;
    s = str_push_back(s, 'b');
    std::cout << "push 'b': [" << s << "]" << std::endl;
    delete[] s;
}

void method_02() {
    std::cout << "\n--- Metodo 02: Teste str_pop_back() ---\n";
    char *s = str_dup("abc");
    std::cout << "Inicial: [" << s << "]" << std::endl;
    s = str_pop_back(s);
    std::cout << "pop: [" << s << "]" << std::endl;
    s = str_pop_back(s);
    std::cout << "pop: [" << s << "]" << std::endl;
    delete[] s;
}

void method_03() {
    std::cout << "\n--- Metodo 03: Teste str_push_front() ---\n";
    char *s = str_dup("");
    std::cout << "Inicial: [" << s << "]" << std::endl;
    s = str_push_front('a', s);
    std::cout << "push 'a': [" << s << "]" << std::endl;
    s = str_push_front('b', s);
    std::cout << "push 'b': [" << s << "]" << std::endl;
    delete[] s;
}

void method_04() {
    std::cout << "\n--- Metodo 04: Teste str_pop_front() ---\n";
    char *s = str_dup("abc");
    std::cout << "Inicial: [" << s << "]" << std::endl;
    s = str_pop_front(s);
    std::cout << "pop: [" << s << "]" << std::endl;
    s = str_pop_front(s);
    std::cout << "pop: [" << s << "]" << std::endl;
    delete[] s;
}

void method_05() {
    std::cout << "\n--- Metodo 05: Teste str_push_mid() ---\n";
    char *s = str_dup("abcd");
    std::cout << "Inicial: [" << s << "]" << std::endl;
    s = str_push_mid(s, 'X');
    std::cout << "push 'X': [" << s << "]" << std::endl;
    delete[] s;
}

void method_06() {
    std::cout << "\n--- Metodo 06: Teste str_pop_mid() ---\n";
    char *s = str_dup("abcde");
    std::cout << "Inicial: [" << s << "]" << std::endl;
    s = str_pop_mid(s);
    std::cout << "pop mid: [" << s << "]" << std::endl;
    delete[] s;
}

void method_09() {
    std::cout << "\n--- Metodo 09: Teste str_chr() ---\n";
    char s[] = "abacaxi";
    std::cout << "String: [" << s << "], procurando 'c'" << std::endl;
    char* found = str_chr(s, 'c');
    if (found) std::cout << "Encontrado, o resto da string e: [" << found << "]" << std::endl;
    else std::cout << "Nao encontrado." << std::endl;
}

void method_10() {
    std::cout << "\n--- Metodo 10: Teste str_tok() ---\n";
    char s[] = "primeiro.segundo";
    std::cout << "String: [" << s << "], delimitador '.'" << std::endl;
    char* token = str_tok(s, '.');
    std::cout << "Token: [" << token << "]" << std::endl;
    delete[] token;
}

void method_E1() {
    std::cout << "\n--- Metodo E1: Teste str_prefix() ---\n";
    char s[] = "prefixo_teste";
    std::cout << "String [" << s << "] comeca com \"prefixo\"? -> " << (str_prefix("prefixo", s) ? "Sim" : "Nao") << std::endl;
    std::cout << "String [" << s << "] comeca com \"outro\"? -> " << (str_prefix("outro", s) ? "Sim" : "Nao") << std::endl;
}

void method_E2() {
    std::cout << "\n--- Metodo E2: Teste str_suffix() ---\n";
    char s[] = "teste_sufixo";
    std::cout << "String [" << s << "] termina com \"sufixo\"? -> " << (str_suffix(s, "sufixo") ? "Sim" : "Nao") << std::endl;
    std::cout << "String [" << s << "] termina com \"outro\"? -> " << (str_suffix(s, "outro") ? "Sim" : "Nao") << std::endl;
}

int main()
{
    int x = 0;
    do
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "MENU DE TESTES - Estudo Dirigido 15" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << " 1 - str_push_back (Ex 01)" << std::endl;
        std::cout << " 2 - str_pop_back (Ex 02)" << std::endl;
        std::cout << " 3 - str_push_front (Ex 03)" << std::endl;
        std::cout << " 4 - str_pop_front (Ex 04)" << std::endl;
        std::cout << " 5 - str_push_mid (Ex 05)" << std::endl;
        std::cout << " 6 - str_pop_mid (Ex 06)" << std::endl;
        std::cout << " 9 - str_chr (Ex 09)" << std::endl;
        std::cout << "10 - str_tok (Ex 10)" << std::endl;
        std::cout << "11 - str_prefix (Extra E1)" << std::endl;
        std::cout << "12 - str_suffix (Extra E2)" << std::endl;
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
        case 9: method_09(); break;
        case 10: method_10(); break;
        case 11: method_E1(); break;
        case 12: method_E2(); break;
        }
        if (x != 0) pause("Apertar ENTER para continuar");

    } while (x != 0);

    return 0;
}

/*
----------------------------------------------
END-OF-FILE: Exemplo1500.cpp
----------------------------------------------
DOCUMENTACAO DE TESTES:
Metodo 01: Saida esperada:
    Inicial: []
    push 'a': [a]
    push 'b': [ab]
Metodo 02: Saida esperada:
    Inicial: [abc]
    pop: [ab]
    pop: [a]
Metodo 03: Saida esperada:
    Inicial: []
    push 'a': [a]
    push 'b': [ba]
Metodo 04: Saida esperada:
    Inicial: [abc]
    pop: [bc]
    pop: [c]
Metodo 05: Saida esperada:
    Inicial: [abcd]
    push 'X': [abXcd]
Metodo 06: Saida esperada:
    Inicial: [abcde]
    pop mid: [abde]
Metodo 09: Saida esperada:
    String: [abacaxi], procurando 'c'
    Encontrado, o resto da string e: [caxi]
Metodo 10: Saida esperada:
    String: [primeiro.segundo], delimitador '.'
    Token: [primeiro]
Metodo E1: Saida esperada:
    String [prefixo_teste] comeca com "prefixo"? -> Sim
    String [prefixo_teste] comeca com "outro"? -> Nao
Metodo E2: Saida esperada:
    String [teste_sufixo] termina com "sufixo"? -> Sim
    String [teste_sufixo] termina com "outro"? -> Nao
----------------------------------------------
*/