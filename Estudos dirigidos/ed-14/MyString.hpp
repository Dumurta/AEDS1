/*
    MyString.hpp - v1.0.0
    Author: Eduardo Murta De Abreu - 884985
*/

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <string>
#include "Erro.hpp"

class MyString : public Erro
{
protected:
    std::string content;

public:
    MyString()
    {
        this->content = "";
    }

    MyString(std::string text)
    {
        this->content = text;
    }

    void setContent(std::string text)
    {
        this->content = text;
    }

    std::string getContent() const
    {
        return (this->content);
    }

    std::string getErroMsg() override
    {
        switch (getErro())
        {
        case 0:
            return Erro::NO_ERROR;
        case 1:
            return "[ERRO] Conteudo nao representa um valor inteiro.";
        case 2:
            return "[ERRO] Conteudo nao representa um valor real.";
        case 3:
            return "[ERRO] Conteudo nao representa um valor logico.";
        default:
            return "[ERRO] Codigo de erro desconhecido.";
        }
    }
};

#endif