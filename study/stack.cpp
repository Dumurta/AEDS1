#include <iostream>

typedef struct s_intStack
{
    int length;
    int *data;
} intStack;

typedef intStack *ref_intStack;

ref_intStack intStack_push(ref_intStack stack, int value)
{
    if (stack == nullptr)
    {
        stack = new intStack;
        stack->length = 0;
        stack->data = nullptr;
    }
    int tamanho_antigo = stack->length;

    int *novos_dados = new int[tamanho_antigo + 1];

    for (int i = 0; i < tamanho_antigo; i++)
    {
        novos_dados[i] = stack->data[i];
    }

    novos_dados[tamanho_antigo] = value;

    if (stack->data != nullptr)
    {
        delete[] stack->data;
    }
    stack->data = novos_dados;
    stack->length = tamanho_antigo + 1;
    return stack;
}

ref_intStack intStack_pop(ref_intStack stack)
{
    if (stack == nullptr || stack->length == 0)
    {
        return nullptr;
    }
    if (stack->length = 1)
    {
        delete[] stack->data;
        stack->data = nullptr;
        stack->length = 0;
        return stack;
    }
    int tamanho_antigo = stack->length;

    int *novos_dados = new int[tamanho_antigo - 1];

    for (int i = 0; i < tamanho_antigo - 1; i++)
    {
        novos_dados[i] = stack->data[i];
    }
    delete[] stack->data;
    stack->data = novos_dados;
    stack->length--;

    return stack;
}