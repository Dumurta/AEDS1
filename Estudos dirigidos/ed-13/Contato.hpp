#ifndef CONTATO_H_
#define _CONTATO_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Erro.hpp"

class Contato : public Erro
{
private:
    std::string nome;
    std::string fone;

public:
    ~Contato()
    {
    }

    Contato()
    {
        setErro(0);
        nome = "";
        fone = "";
    }

    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        setErro(0);
        setNome(nome_inicial);
        setFone(fone_inicial);
    }

    Contato(Contato const &another)
    {
        setErro(0);
        setNome(another.nome);
        setFone(another.fone);
    }

    void setNome(std::string nome)
    {
        if (nome.empty())
        {
            setErro(1);
        }
        else
        {
            this->nome = nome;
        }
    }

    void setFone(std::string fone)
    {
        if (fone.empty())
        {
            setErro(2);
        }
        else
        {
            this->fone = fone;
        }
    }

    std::string getNome() const
    {
        return (this->nome);
    }

    std::string getFone() const
    {
        return (this->fone);
    }

    std::string toString() const
    {
        return ("{" + getNome() + ", " + getFone() + "}");
    }
};

using ref_Contato = Contato *;

#endif