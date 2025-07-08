#include <iostream>
#include <cmath>
#include <iomanip>

class PolyArray
{
private:
    int n;
    int *data;

public:
    PolyArray(int n, int *data)
    {
        this->n = n;
        this->data = new int[n + 1];
        for (int i = 0; i <= n; i = i + 1)
        {
            this->data[i] = data[i];
        }
    }

    ~PolyArray()
    {
        delete[] data;
    };

    std::string to_string()
    {
        std::string resultado = "";
        for (int i = n; i >= 0; i = i - 1)
        {
            if (this->data[i] == 0)
            {
                continue;
            }

            if (this->data[i] > 0)
            {
                resultado = "+ x^";
            }
            else
            {
                resultado = "- x^";
            }
        }

        return resultado;
    }

    int eval_at(int x)
    {
    }
};

PolyArray::PolyArray(/* args */)
{
}

PolyArray::~PolyArray()
{
}

int main()
{
    return 0;
}
