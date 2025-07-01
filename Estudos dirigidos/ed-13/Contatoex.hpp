/*
    ContatoEx.hpp - v1.1.0
    Author: Eduardo Murta De Abreu - 884985
*/
#ifndef _CONTATOEX_H_
#define _CONTATOEX_H_

#include "Contato.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ContatoEx : public Contato
{
private:
    std::string fone2;

protected:
    bool isDigit(char c) const
    {
        return (c >= '0' && c <= '9');
    }

    bool foneValido(const std::string &telefone) const
    {
        if (telefone.empty())
        {
            return true;
        }

        if (telefone.length() != 14)
        {
            return false;
        }

        if (telefone[0] != '(' || telefone[3] != ')' || telefone[9] != '-')
        {
            return false;
        }

        for (int i = 0; i < 14; i = i + 1)
        {
            if (i == 0 || i == 3 || i == 9)
            {
                continue;
            }
            if (!isDigit(telefone[i]))
            {
                return false;
            }
        }

        return true;
    }

public:
    ContatoEx() : Contato()
    {
        this->fone2 = "";
    }

    void setFone(std::string fone)
    {
        if (foneValido(fone))
        {
            Contato::setFone(fone);
        }
        else
        {
            Erro::setErro(2);
        }
    }

    std::string toString() const
    {
        std::string result = "{" + getNome() + ", " + getFone();
        if (!fone2.empty())
        {
            result += ", " + fone2;
        }
        result += "}";
        return result;
    }

    void readName(std::string prompt)
    {
        std::string valor_lido;
        std::cout << prompt;
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore();
        }
        std::getline(std::cin, valor_lido);
        setNome(valor_lido);
    }

    void readFromFile(std::string filename)
    {
        std::ifstream afile;
        std::string nome_lido, fone1_lido, fone2_lido;

        afile.open(filename);
        if (afile.is_open())
        {
            std::getline(afile, nome_lido);
            std::getline(afile, fone1_lido);
            std::getline(afile, fone2_lido);

            setNome(nome_lido);
            setFone(fone1_lido);
            setFone2(fone2_lido);

            afile.close();
        }
        else
        {
            Erro::setErro(3);
        }
    }

    void writeToFile(std::string filename)
    {
        std::ofstream afile;
        afile.open(filename);
        if (afile.is_open())
        {
            afile << getNome() << std::endl;
            afile << getFone() << std::endl;
            afile << getFone2() << std::endl;
            afile.close();
        }
        else
        {
            Erro::setErro(3);
        }
    }

    int phones() const
    {
        int count = 0;
        if (!getFone().empty())
            count = count + 1;
        if (!fone2.empty())
            count = count + 1;
        return count;
    }

    std::string getFone2() const
    {
        return this->fone2;
    }

    void setFone2(std::string fone)
    {
        if (foneValido(fone))
        {
            this->fone2 = fone;
        }
        else
        {
            Erro::setErro(5);
        }
    }

    void alterFone2(std::string fone)
    {
        if (phones() < 2)
        {
            Erro::setErro(4);
        }
        else
        {
            setFone2(fone);
        }
    }

    void removeFone2()
    {
        if (phones() < 2)
        {
            Erro::setErro(4);
        }
        else
        {
            this->fone2 = "";
        }
    }
};

#endif