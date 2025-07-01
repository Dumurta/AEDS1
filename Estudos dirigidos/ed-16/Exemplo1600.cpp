 /*
    Exemplo1600.cpp - v1.1.0
    Author: Eduardo Murta De Abreu - 884985
*/

#include <iostream>

// === Implementação das Funções do Estudo Dirigido 16 ===

int* array_new(int size, int initial_value)
{
    if (size <= 0) return nullptr;
    int* block = new int[size + 1];
    block[0] = size;
    int* array_data = block + 1;
    for(int i = 0; i < size; i = i + 1) {
        array_data[i] = initial_value;
    }
    return array_data;
}

void array_free(int* array)
{
    if(array)
    {
        delete[] (array - 1);
    }
}

/**
 * 01.) Funcao para acrescentar valor ao final.
 */
int *array_push_back(int *array, int value)
{
    int size = array ? *((int*)array - 1) : 0;
    int *block = new int[size + 2];
    block[0] = size + 1;
    int *new_array = block + 1;

    for (int i = 0; i < size; i = i + 1) { 
        new_array[i] = array[i]; 
    }
    new_array[size] = value;
    
    if (array) array_free(array);
    return new_array;
}

/**
 * 02.) Funcao para remover valor do final.
 */
int *array_pop_back(int *array)
{
    if (!array) return nullptr;
    int size = *((int*)array - 1);
    if (size <= 0) { array_free(array); return nullptr; }
    if (size == 1) { array_free(array); return nullptr; }

    int *block = new int[size];
    block[0] = size - 1;
    int *new_array = block + 1;

    for (int i = 0; i < size - 1; i = i + 1) { 
        new_array[i] = array[i]; 
    }
    
    array_free(array);
    return new_array;
}

/**
 * 03.) Funcao para acrescentar valor ao início.
 */
int* array_push_front(int value, int* array)
{
    int size = array ? *((int*)array - 1) : 0;
    int* block = new int[size + 2];
    block[0] = size + 1;
    int* new_array = block + 1;

    new_array[0] = value;
    for(int i = 0; i < size; i = i + 1) { 
        new_array[i+1] = array[i]; 
    }

    if (array) array_free(array);
    return new_array;
}

/**
 * 04.) Funcao para remover valor do início.
 */
int* array_pop_front(int* array)
{
    if (!array) return nullptr;
    int size = *((int*)array - 1);
    if (size <= 0) { array_free(array); return nullptr; }
    if (size == 1) { array_free(array); return nullptr; }

    int* block = new int[size];
    block[0] = size - 1;
    int* new_array = block + 1;

    for (int i = 0; i < size - 1; i = i + 1) { 
        new_array[i] = array[i+1]; 
    }

    array_free(array);
    return new_array;
}

/**
 * 05.) Funcao para acrescentar valor no meio.
 */
int* array_push_mid(int* array, int value)
{
    int size = array ? *((int*)array - 1) : 0;
    int mid_pos = size / 2;

    int* block = new int[size + 2];
    block[0] = size + 1;
    int* new_array = block + 1;

    for(int i=0; i < mid_pos; i = i + 1) { new_array[i] = array[i]; }
    new_array[mid_pos] = value;
    for(int i=mid_pos; i < size; i = i + 1) { new_array[i+1] = array[i]; }

    if(array) array_free(array);
    return new_array;
}

/**
 * 06.) Funcao para remover valor do meio.
 */
int* array_pop_mid(int* array)
{
    if (!array) return nullptr;
    int size = *((int*)array - 1);
    if (size <= 0) { array_free(array); return nullptr; }
    if (size == 1) { array_free(array); return nullptr; }
    
    int mid_pos = size / 2;

    int* block = new int[size];
    block[0] = size - 1;
    int* new_array = block + 1;

    for(int i=0; i < mid_pos; i = i + 1) { new_array[i] = array[i]; }
    for(int i=mid_pos + 1; i < size; i = i + 1) { new_array[i-1] = array[i]; }

    array_free(array);
    return new_array;
}


/**
 * Definicoes de tipo/classe para os proximos exercicios.
 */
typedef struct s_intArray { int length; int *data; } intArray;
typedef intArray* ref_intArray;

ref_intArray new_intArray(int size) {
    if (size < 0) size = 0;
    ref_intArray a = new intArray;
    a->length = size;
    if (size > 0) {
        a->data = new int[size];
    } else {
        a->data = nullptr;
    }
    return a;
}

void free_intArray(ref_intArray a) {
    if (a) {
        if (a->data) delete[] a->data;
        delete a;
    }
}

/**
 * 07.) Funcao para comparar arranjos de inteiros.
 */
int intArray_cmp(ref_intArray p, ref_intArray q)
{
    if (!p || !q) return 0;
    int min_len = (p->length < q->length) ? p->length : q->length;
    for (int i = 0; i < min_len; i = i + 1) {
        if (p->data[i] != q->data[i]) return p->data[i] - q->data[i];
    }
    if (p->length != q->length) return p->length - q->length;
    return 0;
}

/**
 * 08.) Funcao para juntar um arranjo ao final de outro.
 */
ref_intArray intArray_cat(ref_intArray p, ref_intArray q)
{
    if (!p || !q) return nullptr;
    int new_len = p->length + q->length;
    ref_intArray result = new_intArray(new_len);
    int k = 0;
    for (int i = 0; i < p->length; i = i + 1) {
        result->data[k] = p->data[i];
        k = k + 1;
    }
    for (int i = 0; i < q->length; i = i + 1) {
        result->data[k] = q->data[i];
        k = k + 1;
    }
    return result;
}

/**
 * 09.) Funcao para procurar pela primeira ocorrencia de valor.
 */
ref_intArray intArray_seek(ref_intArray a, int x)
{
    if (!a) return nullptr;
    int pos = -1;
    for(int i=0; i < a->length && pos == -1; i = i + 1)
    {
        if(a->data[i] == x)
        {
            pos = i;
        }
    }

    if (pos != -1)
    {
        ref_intArray sub = new_intArray(a->length - pos);
        for(int i=0; i < sub->length; i = i + 1)
        {
            sub->data[i] = a->data[pos + i];
        }
        return sub;
    }
    return nullptr;
}

/**
 * 10.) Funcao para separar sequencia de valores em arranjo.
 */
ref_intArray intArray_sub(ref_intArray a, int start, int size)
{
    if(!a || start < 0 || size < 0 || start + size > a->length)
    {
        return nullptr;
    }
    ref_intArray sub = new_intArray(size);
    for(int i=0; i < size; i = i + 1)
    {
        sub->data[i] = a->data[start + i];
    }
    return sub;
}

/**
 * E1.) Funcao para intercalar arranjos de inteiros.
 */
ref_intArray intArray_merge(ref_intArray p, ref_intArray q)
{
    if (!p || !q) return nullptr;
    ref_intArray result = new_intArray(p->length + q->length);
    int i=0, j=0, k=0;
    while(i < p->length && j < q->length)
    {
        result->data[k] = p->data[i];
        k = k + 1;
        i = i + 1;
        
        result->data[k] = q->data[j];
        k = k + 1;
        j = j + 1;
    }
    while(i < p->length) {
        result->data[k] = p->data[i];
        k = k + 1;
        i = i + 1;
    }
    while(j < q->length) {
        result->data[k] = q->data[j];
        k = k + 1;
        j = j + 1;
    }
    return result;
}

/**
 * E2.) Funcao para mesclar arranjos em ordem decrescente.
 */
ref_intArray intArray_mergeDown(ref_intArray p, ref_intArray q)
{
    if (!p || !q) return nullptr;
    ref_intArray result = new_intArray(p->length + q->length);
    int i = 0, j = 0, k = 0;
    while(i < p->length && j < q->length)
    {
        if(p->data[i] > q->data[j])
        {
            result->data[k] = p->data[i];
            i = i + 1;
        }
        else
        {
            result->data[k] = q->data[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i < p->length) {
        result->data[k] = p->data[i];
        k = k + 1;
        i = i + 1;
    }
    while(j < q->length) {
        result->data[k] = q->data[j];
        k = k + 1;
        j = j + 1;
    }
    return result;
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

void print_raw_array(const char* label, int* array) {
    std::cout << label;
    if (!array) {
        std::cout << "[] (nullptr)" << std::endl;
        return;
    }
    int size = *((int*)array - 1);
    std::cout << "[ ";
    for (int i=0; i < size; i = i + 1) std::cout << array[i] << " ";
    std::cout << "]" << std::endl;
}

void print_intArray(const char* label, ref_intArray a) {
    std::cout << label;
    if (!a) {
        std::cout << "[] (nullptr)" << std::endl;
        return;
    }
    std::cout << "(len=" << a->length << ") [ ";
    for (int i=0; i < a->length; i = i + 1) std::cout << a->data[i] << " ";
    std::cout << "]" << std::endl;
}

void method_01() {
    std::cout << "\n--- Metodo 01: array_push_back() ---\n";
    int *a = nullptr;
    print_raw_array("Inicial: ", a);
    a = array_push_back(a, 10);
    print_raw_array("Adic. 10:", a);
    a = array_push_back(a, 20);
    print_raw_array("Adic. 20:", a);
    array_free(a);
}
void method_02() {
    std::cout << "\n--- Metodo 02: array_pop_back() ---\n";
    int *a = nullptr;
    a = array_push_back(a, 10); a = array_push_back(a, 20); a = array_push_back(a, 30);
    print_raw_array("Inicial: ", a);
    a = array_pop_back(a);
    print_raw_array("Pop 1:   ", a);
    a = array_pop_back(a);
    print_raw_array("Pop 2:   ", a);
    array_free(a);
}
void method_03() {
    std::cout << "\n--- Metodo 03: array_push_front() ---\n";
    int *a = nullptr;
    print_raw_array("Inicial: ", a);
    a = array_push_front(10, a);
    print_raw_array("Adic. 10:", a);
    a = array_push_front(20, a);
    print_raw_array("Adic. 20:", a);
    array_free(a);
}
void method_04() {
    std::cout << "\n--- Metodo 04: array_pop_front() ---\n";
    int *a = nullptr;
    a = array_push_back(a, 10); a = array_push_back(a, 20); a = array_push_back(a, 30);
    print_raw_array("Inicial: ", a);
    a = array_pop_front(a);
    print_raw_array("Pop 1:   ", a);
    a = array_pop_front(a);
    print_raw_array("Pop 2:   ", a);
    array_free(a);
}
void method_05() {
    std::cout << "\n--- Metodo 05: array_push_mid() ---\n";
    int *a = nullptr;
    a = array_push_back(a, 10); a = array_push_back(a, 40);
    print_raw_array("Inicial:     ", a);
    a = array_push_mid(a, 99);
    print_raw_array("Adic. 99 mid:", a);
    array_free(a);
}
void method_06() {
    std::cout << "\n--- Metodo 06: array_pop_mid() ---\n";
    int *a = nullptr;
    a = array_push_back(a, 10); a = array_push_back(a, 99); a = array_push_back(a, 40);
    print_raw_array("Inicial:    ", a);
    a = array_pop_mid(a);
    print_raw_array("Pop mid (99):", a);
    array_free(a);
}
void method_07() {
    std::cout << "\n--- Metodo 07: intArray_cmp() ---\n";
    ref_intArray p = new_intArray(3); p->data[0]=1; p->data[1]=2; p->data[2]=3;
    ref_intArray q = new_intArray(3); q->data[0]=1; q->data[1]=2; q->data[2]=3;
    ref_intArray r = new_intArray(4); r->data[0]=1; r->data[1]=2; r->data[2]=3; r->data[3]=4;
    print_intArray("p: ", p); print_intArray("q: ", q); print_intArray("r: ", r);
    std::cout << "cmp(p,q) -> " << intArray_cmp(p,q) << " (Iguais)\n";
    std::cout << "cmp(p,r) -> " << intArray_cmp(p,r) << " (Diferentes no tamanho)\n";
    free_intArray(p); free_intArray(q); free_intArray(r);
}
void method_08() {
    std::cout << "\n--- Metodo 08: intArray_cat() ---\n";
    ref_intArray p = new_intArray(3); p->data[0]=10; p->data[1]=20; p->data[2]=30;
    ref_intArray q = new_intArray(2); q->data[0]=40; q->data[1]=50;
    print_intArray("p: ", p); print_intArray("q: ", q);
    ref_intArray result = intArray_cat(p,q);
    print_intArray("cat(p,q): ", result);
    free_intArray(p); free_intArray(q); free_intArray(result);
}
void method_09() {
    std::cout << "\n--- Metodo 09: intArray_seek() ---\n";
    ref_intArray a = new_intArray(5); a->data[0]=10; a->data[1]=20; a->data[2]=30; a->data[3]=40; a->data[4]=50;
    print_intArray("Array 'a': ", a);
    ref_intArray result = intArray_seek(a, 30);
    print_intArray("seek(a, 30): ", result);
    free_intArray(a); free_intArray(result);
}
void method_10() {
    std::cout << "\n--- Metodo 10: intArray_sub() ---\n";
    ref_intArray a = new_intArray(5); a->data[0]=10; a->data[1]=20; a->data[2]=30; a->data[3]=40; a->data[4]=50;
    print_intArray("Array 'a': ", a);
    ref_intArray result = intArray_sub(a, 1, 3);
    print_intArray("sub(a, 1, 3):", result);
    free_intArray(a); free_intArray(result);
}
void method_E1() {
    std::cout << "\n--- Metodo E1: intArray_merge() ---\n";
    ref_intArray p = new_intArray(3); p->data[0]=1; p->data[1]=3; p->data[2]=5;
    ref_intArray q = new_intArray(4); q->data[0]=2; q->data[1]=4; q->data[2]=6; q->data[3]=8;
    print_intArray("p: ", p); print_intArray("q: ", q);
    ref_intArray result = intArray_merge(p,q);
    print_intArray("merge(p,q):", result);
    free_intArray(p); free_intArray(q); free_intArray(result);
}
void method_E2() {
    std::cout << "\n--- Metodo E2: intArray_mergeDown() ---\n";
    ref_intArray p = new_intArray(3); p->data[0]=9; p->data[1]=5; p->data[2]=1;
    ref_intArray q = new_intArray(4); q->data[0]=10; q->data[1]=8; q->data[2]=4; q->data[3]=2;
    print_intArray("p (ordenado): ", p); print_intArray("q (ordenado): ", q);
    ref_intArray result = intArray_mergeDown(p,q);
    print_intArray("mergeDown(p,q):", result);
    free_intArray(p); free_intArray(q); free_intArray(result);
}

int main()
{
    int x = 0;
    do
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "MENU DE TESTES - Estudo Dirigido 16" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << " 1 - array_push_back"   << std::endl;
        std::cout << " 2 - array_pop_back"    << std::endl;
        std::cout << " 3 - array_push_front"  << std::endl;
        std::cout << " 4 - array_pop_front"   << std::endl;
        std::cout << " 5 - array_push_mid"    << std::endl;
        std::cout << " 6 - array_pop_mid"     << std::endl;
        std::cout << " 7 - intArray_cmp"      << std::endl;
        std::cout << " 8 - intArray_cat"      << std::endl;
        std::cout << " 9 - intArray_seek"     << std::endl;
        std::cout << "10 - intArray_sub"     << std::endl;
        std::cout << "11 - intArray_merge (Extra 1)"   << std::endl;
        std::cout << "12 - intArray_mergeDown (Extra 2)" << std::endl;
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
        case 11: method_E1(); break;
        case 12: method_E2(); break;
        }
        if (x != 0) pause("Apertar ENTER para continuar");

    } while (x != 0);

    return 0;
}

/*
----------------------------------------------
END-OF-FILE: Exemplo1600.cpp
----------------------------------------------
DOCUMENTACAO DE TESTES:
Metodo 01: Saida esperada:
    Inicial: [] (nullptr)
    Adic. 10:[ 10 ]
    Adic. 20:[ 10 20 ]
Metodo 02: Saida esperada:
    Inicial: [ 10 20 30 ]
    Pop 1:   [ 10 20 ]
    Pop 2:   [ 10 ]
Metodo 03: Saida esperada:
    Inicial: [] (nullptr)
    Adic. 10:[ 10 ]
    Adic. 20:[ 20 10 ]
Metodo 04: Saida esperada:
    Inicial: [ 10 20 30 ]
    Pop 1:   [ 20 30 ]
    Pop 2:   [ 30 ]
Metodo 05: Saida esperada:
    Inicial:      [ 10 40 ]
    Adic. 99 mid:[ 10 99 40 ]
Metodo 06: Saida esperada:
    Inicial:     [ 10 99 40 ]
    Pop mid (99):[ 10 40 ]
Metodo 07: Saida esperada:
    p: (len=3) [ 1 2 3 ]
    q: (len=3) [ 1 2 3 ]
    r: (len=4) [ 1 2 3 4 ]
    cmp(p,q) -> 0
    cmp(p,r) -> -1
Metodo 08: Saida esperada:
    p: (len=3) [ 10 20 30 ]
    q: (len=2) [ 40 50 ]
    cat(p,q): (len=5) [ 10 20 30 40 50 ]
Metodo 09: Saida esperada:
    Array 'a': (len=5) [ 10 20 30 40 50 ]
    seek(a, 30): (len=3) [ 30 40 50 ]
Metodo 10: Saida esperada:
    Array 'a': (len=5) [ 10 20 30 40 50 ]
    sub(a, 1, 3):(len=3) [ 20 30 40 ]
Metodo E1: Saida esperada:
    p: (len=3) [ 1 3 5 ]
    q: (len=4) [ 2 4 6 8 ]
    merge(p,q):(len=7) [ 1 2 3 4 5 6 8 ]
Metodo E2: Saida esperada:
    p (ordenado): (len=3) [ 9 5 1 ]
    q (ordenado): (len=4) [ 10 8 4 2 ]
    mergeDown(p,q):(len=7) [ 10 9 8 5 4 2 1 ]
----------------------------------------------
*/