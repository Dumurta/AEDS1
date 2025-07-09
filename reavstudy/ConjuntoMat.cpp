#include <iostream>

class ConjuntoMatematico
{
private:
    int *elementos;
    int tamanho;    // Quantos elementos estão atualmente no conjunto
    int capacidade; // Qual o tamanho do array 'elementos'

public:
    // Construtor: cria um conjunto vazio com uma capacidade inicial
    ConjuntoMatematico(int capacidade_inicial)
    {
        this->capacidade = capacidade_inicial;
        this->tamanho = 0;
        this->elementos = new int[capacidade_inicial];
    }

    // Destrutor: libera a memória alocada
    ~ConjuntoMatematico()
    {
        this->capacidade = 0;
        this->tamanho = 0;
        delete[] elementos;
    }

    // Método para adicionar um elemento ao conjunto
    void adiciona(int valor)
    {
        if (!pertence(valor))
        {
            if (this->tamanho == this->capacidade)
            {
                int nova_capacidade = this->capacidade * 2;
                if (nova_capacidade == 0)
                {
                    nova_capacidade = 1;
                }
                int *novos_elementos = new int[nova_capacidade];
                for (int x = 0; x < tamanho; x = x + 1)
                {
                    novos_elementos[x] = elementos[x];
                }
                delete[] this->elementos;
                this->elementos = novos_elementos;
                this->capacidade = nova_capacidade;
            }
            this->elementos[this->tamanho] = valor;
            this->tamanho++;
        }
    }

    // Método para verificar se um elemento pertence ao conjunto
    bool pertence(int valor)
    {
        bool teste = false;

        for (int x = 0; x < this->tamanho; x = x + 1)
        {
            if (this->elementos[x] == valor)
            {
                teste = true;
            }
        }
        return teste;
    }

    // Desafio Extra: Método que retorna um NOVO conjunto que é a união deste com outro
    ConjuntoMatematico uniao(ConjuntoMatematico outro);

    // Método para imprimir o conjunto de forma legível
    // Substitua sua função print() inteira por esta:
    void print()
    {
        // Vamos imprimir o estado atual para nos ajudar a depurar
        std::cout << "Estado (Tamanho: " << this->tamanho << ", Capacidade: " << this->capacidade << ") ";

        // Agora, imprime o conjunto de forma legível
        std::cout << "Conjunto: { ";

        // O laço correto que percorre APENAS os elementos válidos
        for (int x = 0; x < this->tamanho; x = x + 1)
        {
            std::cout << this->elementos[x] << " "; // Imprime o elemento e um espaço
        }

        // Fecha as chaves e pula uma linha no final
        std::cout << "}" << std::endl;
    }
};

int main()
{
    ConjuntoMatematico c1(3);
    c1.print();
    c1.adiciona(10);
    c1.print();

    return 0;
}