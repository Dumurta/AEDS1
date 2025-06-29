/*
    Erro.hpp - v1.0.0
    Author: Eduardo Murta De Abreu - 884985
*/

#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

class Erro
{
private:
    int erro;

protected:
    void setErro(int codigo)
    {
        this->erro = codigo;
    }

public:
    ~Erro() {}

    Erro()
    {
        this->erro = 0;
    }

    static const std::string NO_ERROR;

    int getErro()
    {
        return (this->erro);
    }

    bool hasError()
    {
        return (this->erro != 0);
    }

    virtual std::string getErroMsg()
    {
        return (NO_ERROR);
    }
};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif