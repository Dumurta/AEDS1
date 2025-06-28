#ifndef _CONTATO_H_
#define _CONTATO_H_

// dependencias
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <fstream>

#include "Erro.hpp"

// definicoes globais
using std::cin;    // para entrada
using std::cout;   // para saida
using std::endl;   // para mudar de linha
using std::setw;   // para definir espacamento
using std::string; // para cadeia de caracteres
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
using std::regex; //usar o regex no teste de telefone
/**
 * OBS: optei usar o regex apos a ultima aula do lab como teste do comando,
 *  vi que poderia se encaixar e busquei como utilizar ele para este caso.
 */

// outras dependencias
void pause(std::string text) {
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ()

/**
 * Classe para tratar contatos, derivada da classe Erro.
 */
class Contato : public Erro {
    /**
     * atributos privados.
     */
  private:
    string nome;
    string fone;

    bool testFone(std::string testar_fone){
        regex fone_padrao("^\\(\\d{2}\\)\\d{4}\\-\\d{4}$");
        
        return regex_match(testar_fone, fone_padrao);
    }

    /**
     * definicoes publicas.
     */
  public:
    /**
     * Destrutor.
     */
    ~Contato() {
    }

    /**
     * Construtor padrao.
     */
    Contato() {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais vazios
        nome = "";
        fone = "";
    } // end constructor (padrao)

    /**
     * Construtor alternativo.
     * @param nome_inicial a ser atribuido
     * @param fone_inicial a ser atribuido
     */
    Contato(std::string nome_inicial, std::string fone_inicial) {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais
        setNome(nome_inicial); // nome = nome_inicial;
        setFone(fone_inicial); // fone = fone_inicial;
    }                        // end constructor (alternativo)

    /**
     * Construtor alternativo baseado em copia.
     */
    Contato(Contato const &another) {
        // atribuir valores iniciais por copia
        setErro(0);                   // copiar erro
        setNome(another.nome); // copiar nome
        setFone(another.fone); // copiar fone
    } // end constructor (alternativo)

    // ----- metodos para acesso -----

    /**
     * Metodo para atribuir nome.
     * @param nome a ser atribuido
     */
    void setNome(std::string nome) {
        if(nome.empty()) {
            setErro(1); // nome invalido
        } else {
            this->nome = nome;
        }
    } // end setNome ()

    /**
     * Metodo para atribuir telefone.
     * @param fone a ser atribuido
     */
    void setFone(std::string fone) {
        if(fone.empty()) {
            setErro(2); // fone invalido
        } else {
            this->fone = fone;
        }
    } // end setFone ()

    /**
     * Metodo para ler nome
     * @param nome que vai receber o nome
     */
    void readName(std::string nome)
    {
        if(nome.empty())
        {
            setErro(3); //nome seria invalido
        }else{
            this->nome = nome;
        }
    }

    void readFone(std::string fone)
    {
        if(fone.empty())
        {

            setErro(4);// telefone seria invalido
        }
        else if (!testFone(fone)) {
            setErro(4); // Erro de formato
            this->fone = ""; // Limpa se for inválido
            std::cout << "Formato de telefone invalido lido: " << fone << ". Esperado: (xx)xxxx-xxxx" << std::endl;
        }
        else{
            this->fone = fone;
        }
    }
    /**
     * funcao para pedir o nome
     * @return nome 
     */
    std::string readName()
    {
        cout << "Digite o nome" << endl;
        cin >> this->nome;
        return (this->nome);
    }
    /**
     * funcao para pedir telefone
     * @return fone
     */
    std::string readFone()
    {
        cout << "Digite o telefone" << endl;
        cin >> this->fone;
        return(this->fone);
    }
    /**
     * Funcao para obter nome.
     * @return nome armazenado
     */
    std::string getNome() {
        return (this->nome);
    } // end getNome ()

    /**
     * Funcao para obter fone.
     * @return fone armazenado
     */
    std::string getFone() {
        return (this->fone);
    } // end getFone ()

    /**
     * Funcao para obter dados de uma pessoa.
     * @return dados de uma pessoa
     */
    std::string toString() {
        return ("{" + getNome() + ", " + getFone() + "}");
    } // end toString()

}; // fim da classe Contato

using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;

#endif