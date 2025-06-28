#ifndef _ERRO_H_
#define _ERRO_H_

class Erro
{
private:
    int erro;

protected:
    void setErro(int codigo)
    {
        erro = codigo;
    }

public:
    ~Erro()
    {
    }

    Erro()
    {
        erro = 0;
    }

    int getErro()
    {
        return (erro);
    }

    bool hasErro()
    {
        return (getErro() != 0);
    }

    void resetErro()
    {
        this->erro = 0;
    }
};

#endif