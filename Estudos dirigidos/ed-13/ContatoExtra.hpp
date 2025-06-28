#ifndef _CONTATOPLUS_H_
#define _CONTATOPLUS_H_

#include "ContatoEx.hpp"

class ContatoPlus : public ContatoEx
{
private:
    std::string telefones[10];
    int foneCount;
    std::string enderecoResidencial;
    std::string enderecoProfissional;

public:
    ContatoPlus() : ContatoEx()
    {
        foneCount = 0;
        for (int i = 0; i < 10; ++i)
        {
            telefones[i] = "";
        }
        enderecoResidencial = "";
        enderecoProfissional = "";
    }

    bool addFone(std::string novoFone)
    {
        if (foneCount < 10 && foneValido(novoFone))
        {
            telefones[foneCount] = novoFone;
            foneCount++;
            return true;
        }
        return false;
    }

    int getFoneCount() const
    {
        return foneCount;
    }

    std::string getFone(int index) const
    {
        if (index >= 0 && index < foneCount)
        {
            return telefones[index];
        }
        return "";
    }

    void setEnderecoResidencial(std::string endereco)
    {
        this->enderecoResidencial = endereco;
    }

    std::string getEnderecoResidencial() const
    {
        return this->enderecoResidencial;
    }

    void setEnderecoProfissional(std::string endereco)
    {
        this->enderecoProfissional = endereco;
    }

    std::string getEnderecoProfissional() const
    {
        return this->enderecoProfissional;
    }

    std::string toString() const
    {
        std::string result = "{" + getNome() + "\n";
        result += " Fones: ";
        for (int i = 0; i < foneCount; ++i)
        {
            result += telefones[i] + (i == foneCount - 1 ? "" : ", ");
        }
        if (!enderecoResidencial.empty())
        {
            result += "\n End. Residencial: " + enderecoResidencial;
        }
        if (!enderecoProfissional.empty())
        {
            result += "\n End. Profissional: " + enderecoProfissional;
        }
        result += "\n}";
        return result;
    }

    void writeToFile(std::string filename) const
    {
        std::ofstream afile(filename);
        if (afile.is_open())
        {
            afile << getNome() << std::endl;
            afile << getFoneCount() << std::endl;
            for (int i = 0; i < getFoneCount(); ++i)
            {
                afile << getFone(i) << std::endl;
            }
            afile << getEnderecoResidencial() << std::endl;
            afile << getEnderecoProfissional() << std::endl;
            afile.close();
        }
    }

    void readFromFile(std::string filename)
    {
        std::ifstream afile(filename);
        if (afile.is_open())
        {
            std::string nome_lido;
            int n_fones;
            std::string temp;
            
            std::getline(afile, nome_lido);
            setNome(nome_lido);

            afile >> n_fones;
            std::getline(afile, temp); 

            foneCount = 0;
            for(int i = 0; i < n_fones; ++i)
            {
                std::getline(afile, temp);
                addFone(temp);
            }

            std::getline(afile, enderecoResidencial);
            std::getline(afile, enderecoProfissional);

            afile.close();
        }
    }
};

#endif