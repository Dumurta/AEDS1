#include <iostream>
#include <string>
#include <cmath> // Para a raiz quadrada (sqrt)

class Vetor3D
{
private:
    double x, y, z;

public:
    // Construtor padrão (cria um vetor nulo)
    Vetor3D()
    {
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
    };

    // Construtor com parâmetros
    Vetor3D(double x_inicial, double y_inicial, double z_inicial)
    {
        this->x = x_inicial;
        this->y = y_inicial;
        this->z = z_inicial;
    };
    // Método para calcular a magnitude (comprimento) do vetor
    // Fórmula: raiz_quadrada(x² + y² + z²)
    double magnitude()
    {
        double mag = 0.0;

        mag = sqrt(pow(this->x, 2.0) +
                   pow(this->y, 2.0) +
                   pow(this->z, 2.0));
        return (mag);
    }

    // Método para somar este vetor com outro e retornar o resultado
    Vetor3D soma(Vetor3D outro)
    {
        Vetor3D resultado;

        resultado.x = x + outro.x;
        resultado.y = y + outro.y;
        resultado.z = z + outro.z;

        return resultado;
    }

    // Método para converter o vetor para uma string formatada
    // Exemplo de formato: "(x, y, z)"
    std::string toString()
    {
        std::string resul = "(";
        resul += std::to_string(this->x);
        resul += ", ";
        resul += std::to_string(this->y);
        resul += ", ";
        resul += std::to_string(this->z);
        resul += ")";

        return resul;
    }
};

int main()
{
    std::cout << "--- Testando a Classe Vetor3D ---" << std::endl;
    std::cout << std::endl;

    // 1. Testando Construtores e o toString()
    std::cout << "1. Testando Construtores:" << std::endl;
    Vetor3D v1;                // Deve chamar o construtor padrão -> (0.0, 0.0, 0.0)
    Vetor3D v2(3.0, 4.0, 0.0); // Deve chamar o construtor com parâmetros

    std::cout << "Vetor v1 (criado com construtor padrão): " << v1.toString() << std::endl;
    std::cout << "Vetor v2 (criado com parâmetros):    " << v2.toString() << std::endl;
    std::cout << std::endl;

    // 2. Testando a Magnitude
    std::cout << "2. Testando magnitude():" << std::endl;
    std::cout << "Magnitude de v2: " << v2.magnitude() << std::endl; // Resultado esperado: 5
    std::cout << std::endl;

    // 3. Testando a Soma
    std::cout << "3. Testando soma():" << std::endl;
    Vetor3D v3 = v2.soma(v2);                                       // Somando v2 com ele mesmo: (3+3, 4+4, 0+0)
    std::cout << "Soma de v2 + v2: " << v3.toString() << std::endl; // Resultado esperado: (6.0, 8.0, 0.0)
    std::cout << std::endl;

    return 0;
}