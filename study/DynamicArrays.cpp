#include <iostream>

struct vetorDinamico {
    int* dados;
    int tamanho;
    int capacidade;
};

vetorDinamico* criarVetor(int capacidade_inicial)
{
    vetorDinamico* novo_vetor = new vetorDinamico;
    /**
     * a variavel novo_vetor agora sabe o endereco da minha struct vetorDinamico
     */
    novo_vetor->dados = new int[capacidade_inicial];
    /**
     * isto significa: Aloque um array de inteiros(int) e guarde o endereco no campo dados
     * da struct
     */
    novo_vetor->tamanho = 0;
    /**
     * defino o tamanho inicial do meu array para 0
     */
    novo_vetor->capacidade = capacidade_inicial;
    /**
     * defino a capacidade do vetor para a capacidade_inicial
     */
    return novo_vetor;
    /**
     * retorno o novo vetor
     */
}
/**
 * a funcao para destruirVetor deve receber como parametro o vetor a ser
 * destruido no caso (vetorDinamico* apagarVetor)
 */
void destruirVetor( vetorDinamico* apagarVetor)
{
    delete[] apagarVetor->dados;
    delete apagarVetor;
}

void push_back(vetorDinamico* vetor, int valor)
{
    if(vetor->tamanho == vetor->capacidade)
    {
        int nova_capacidade = vetor->capacidade * 2;
        if (nova_capacidade == 0)
        {
            nova_capacidade = 1;
        }

        int* novos_dados = new int[nova_capacidade];
        for(int i = 0; i <= vetor->tamanho - 1; i = i + 1)
        {
            novos_dados[i] = vetor->dados[i];
        }
        delete[] vetor -> dados;
        vetor->dados = novos_dados;
        vetor->capacidade = nova_capacidade;
    }
    vetor->dados[vetor->tamanho] = valor;
    vetor->tamanho++;
}

void pop_back(vetorDinamico* vetor)
{
    if (vetor->tamanho > 0)
    {
        vetor->tamanho--;
    }
}

void push_front(vetorDinamico* vetor, int valor)
{
    if(vetor->tamanho == vetor->capacidade)
    {
        int nova_capacidade = vetor->capacidade * 2;
        if(nova_capacidade == 0)
        {
            nova_capacidade = 1;
        }
        int* novos_dados = new int[nova_capacidade];
        for(int i = 0; i < vetor->tamanho; i++)
        {
            novos_dados[i] = vetor->dados[i];
        }
        delete[] vetor-> dados;
        vetor->dados = novos_dados;
        vetor->capacidade = nova_capacidade;
    }
    for(int i = vetor->tamanho; i > 0; i--)
    {
        vetor->dados[i] = vetor->dados[i-1];
    }
    vetor->dados[0] = valor;
    vetor->tamanho++;
}

void pop_front(vetorDinamico* vetor)
{
    if(vetor->tamanho > 0 )
    {
        for(int i = 0; i < vetor->tamanho - 1; i++)
        {
            vetor->dados[i] = vetor->dados[i + 1];
        }
        vetor->tamanho--;
    }
}