/*
    Method_01 - mostrar certa quantidade de valores
*/
#include "mymatrix.hpp"
#include "ioEM.hpp"
#include <iostream>
void method_00() {

}
void method_01() {
    //def dados
    Matrix <int> int_matrix(2, 2, 0);

    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);

    //identificar
    cout << "\nMethod_01 - v0.0\n" << endl;

    //mostrar dados
    int_matrix.print();

    //encerrar
    pause("Apertar ENTER para continuar");
}//end method_01()

/*
    Method_02
*/
void method_02() {
    //def dados
    Matrix <int> matrix(2, 2, 0);

    //identificar
    cout << endl << "Method_02 -v0.0" << endl;

    //ler dados
    matrix.read();

    //mostrar dados
    matrix.print();

    //encerrar
    pause("Apertar ENTER para continuar");

}//end method_02()
/*
    Method_03
*/
void method_03() {
    //def dados
    Matrix <int> matrix(2, 2, 0);

    //identificar
    cout << endl << "Method_03" << endl;

    //ler dados
    matrix.read();

    //mostrar dados
    matrix.print();

    //gravar dados
    matrix.fprint("MATRIX1.txt");

    //encerrar
    pause("Apertar ENTER para continuar");
}//end method_03()
/*

    Method_04
*/
void method_04() {
    //def dados
    Matrix <int> matrix(1, 1, 0);

    //identificar
    cout << endl << "Method_04" << endl;

    //ler dados
    matrix.fread("MATRIX1.TXT");

    //mostrar dados
    matrix.print();

    //encerrar
    pause("Apertar ENTER para continuar");
}//end method_04
/**
   Method_05.
 */
void method_05() {
    // definir dados
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);

    // identificar
    cout << endl << "Method_05 - v0.0" << endl;

    // ler dados
    int_matrix1.fread("MATRIX1.TXT");

    // mostrar dados
    cout << "\nOriginal\n" << endl;
    int_matrix1.print();

    // copiar  dados
    int_matrix2 = int_matrix1;

    // mostrar dados
    cout << "\nCopia\n" << endl;
    int_matrix2.print();

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_05 ( )
/**
   Method_06.
 */
void method_06() {
// definir dados
    Matrix <int> int_matrix(2, 2, 0);

    int_matrix.set(0, 0, 0);
    int_matrix.set(0, 1, 0);
    int_matrix.set(1, 0, 0);
    int_matrix.set(1, 1, 0);

// identificar
    cout << endl << "Method_06 - v0.0" << endl;

// mostrar dados
    int_matrix.print();

// testar  condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;

// ler dados
    int_matrix.fread("MATRIX1.TXT");

// mostrar dados
    int_matrix.print();

// testar  condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_06 ( )
/**
   Method_07.
 */
void method_07() {
// definir dados
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);

// identificar
    cout << endl << "Method_07 - v0.0" << endl;

// ler dados
    int_matrix1.fread("MATRIX1.TXT");

// mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();

// copiar  dados
    int_matrix2 = int_matrix1;

// mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();

// testar  condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;

// alterar dados
    int_matrix2.set(0, 0, (-1));

// mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();

// mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();

// testar  condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_07 ( )

/**
   Method_08.
 */
void method_08() {
// definir dados
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);
    Matrix <int> int_matrix3(1, 1, 0);

// identificar
    cout << endl << "Method_08 - v0.0" << endl;

// ler dados
    int_matrix1.fread("MATRIX1.TXT");

// mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();

// copiar  dados
    int_matrix2 = int_matrix1;

// mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();

// operar  dados
    int_matrix3 = int_matrix1 - int_matrix2;

// mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_08 ( )

/**
   Method_09.
 */
void method_09() {
// definir dados
    Matrix <int> int_matrix1(2, 2, 0);

    int_matrix1.set(0, 0, 1);
    int_matrix1.set(0, 1, 0);
    int_matrix1.set(1, 0, 0);
    int_matrix1.set(1, 1, 1);

    Matrix <int> int_matrix2(1, 1, 0);
    Matrix <int> int_matrix3(1, 1, 0);

// identificar
    cout << endl << "Method_09 - v0.0" << endl;

// ler dados
    int_matrix2.fread("MATRIX1.TXT");

// mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();

// mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();

// operar  dados
    int_matrix3 = int_matrix1 * int_matrix2;

// mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_09 ( )
/**
   Method_10.
 */
void method_10() {
// definir dados
    Matrix <int> int_matrix(3, 3, 0);
    int x = 0;
    int y = 0;

// identificar
    cout <<  endl << "Method_10 - v0.0" << endl;

// ler dados
    int_matrix.fread("MATRIX1.TXT");

// mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();

// operar  dados
    for(int x = 0; x < int_matrix.getRows(); x = x + 1) {
        for(int y = 0; y < int_matrix.getColumns(); y = y + 1) {
            int_matrix.set(x, y, int_matrix.get(x, y) * (-1));
        } // end for
    } // end for

// mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_10 ( )

/*
    Method_11
*/
void method_11() {
    // ler dimensões
    int m = readint("Digite o número de linhas: ");
    int n = readint("Digite o número de colunas: ");
    int inferior = readint("Digite o valor inferior do intervalo: ");
    int superior = readint("Digite o valor superior do intervalo: ");

    // criar matriz
    Matrix<int> matrix(m, n, 0);

    // gerar valores aleatórios
    srand((unsigned)time(NULL));
    matrix.randomIntGenerate(inferior, superior);

    // mostrar matriz
    cout << "\nMatriz gerada:\n";
    matrix.print();

    // gravar em arquivo
    matrix.fprintRandom("DADOS.TXT");
    cout << "\nArquivo DADOS.TXT gerado com sucesso!\n";

    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
    Method_12
*/
void method_12() {
    // receber nome do arquivo
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;
    int constante = readint("Digite a constante para escalar a matriz: ");

    // ler matriz do arquivo
    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    // mostrar matriz original
    cout << "\nMatriz original:\n";
    matrix1.print();

    // escalar matriz
    Matrix<int> matrix2 = matrix1.scalar(constante);

    // mostrar matriz escalada
    cout << "\nMatriz escalada por " << constante << ":\n";
    matrix2.print();

    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
    Method_13
*/
void method_13() {
    // receber nome do arquivo
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;

    // ler matriz do arquivo
    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    // mostrar matriz
    cout << "\nMatriz lida:\n";
    matrix1.print();

    // testar identidade
    bool teste = matrix1.identidade();
    cout << "\nA matriz ";
    if(!teste) cout << "NÃO ";
    cout << "é identidade." << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
    Method_14
*/
void method_14() {
    // receber nomes dos arquivos
    string nomeArquivo1, nomeArquivo2;
    cout << "Digite o nome do primeiro arquivo da matriz: ";
    cin >> nomeArquivo1;
    cout << "Digite o nome do segundo arquivo da matriz: ";
    cin >> nomeArquivo2;

    // ler matrizes dos arquivos
    Matrix<int> matrix1(1, 1, 0);
    Matrix<int> matrix2(1, 1, 0);
    matrix1.fread(nomeArquivo1);
    matrix2.fread(nomeArquivo2);

    // mostrar matrizes
    cout << "\nMatriz 1:\n";
    matrix1.print();
    cout << "\nMatriz 2:\n";
    matrix2.print();

    // testar igualdade
    bool teste = (matrix1 == matrix2);
    cout << "\nAs matrizes ";
    if(!teste) cout << "NÃO ";
    cout << "são iguais." << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
    Method_15
*/
void method_15() {
    // receber nomes dos arquivos
    string nomeArquivo1, nomeArquivo2;
    cout << "Digite o nome do primeiro arquivo da matriz: ";
    cin >> nomeArquivo1;
    cout << "Digite o nome do segundo arquivo da matriz: ";
    cin >> nomeArquivo2;

    // ler matrizes dos arquivos
    Matrix<int> matrix1(1, 1, 0);
    Matrix<int> matrix2(1, 1, 0);
    matrix1.fread(nomeArquivo1);
    matrix2.fread(nomeArquivo2);

    // mostrar matrizes
    cout << "\nMatriz 1:\n";
    matrix1.print();
    cout << "\nMatriz 2:\n";
    matrix2.print();

    // somar matrizes
    Matrix<int> soma = matrix1.add(matrix2);
    cout << "\nSoma das matrizes:\n";
    soma.print();

    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
    Method_16
*/
void method_16() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;
    int row1 = readint("Digite o índice da primeira linha: ");
    int row2 = readint("Digite o índice da segunda linha: ");
    int constante = readint("Digite a constante multiplicadora: ");

    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    cout << "\nMatriz original:\n";
    matrix1.print();

    matrix1.addRows(row1, row2, constante);

    cout << "\nMatriz após soma das linhas (linha " << row1 << " = linha " << row1 << " + " << constante << "*linha " << row2 << "):\n";
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

/*
    Method_17
*/
void method_17() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;
    int row1 = readint("Digite o índice da primeira linha: ");
    int row2 = readint("Digite o índice da segunda linha: ");
    int constante = readint("Digite a constante multiplicadora: ");

    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    cout << "\nMatriz original:\n";
    matrix1.print();

    matrix1.subtractRows(row1, row2, constante);

    cout << "\nMatriz após subtração das linhas (linha " << row1 << " = linha " << row1 << " - " << constante << "*linha " << row2 << "):\n";
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

/*
    Method_18
*/
void method_18() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;
    int procurado = readint("Digite o valor a procurar: ");

    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    cout << "\nMatriz lida:\n";
    matrix1.print();

    int linha = matrix1.searchRows(procurado);
    if(linha >= 0)
        cout << "\nO valor " << procurado << " foi encontrado na linha " << linha << "." << endl;
    else
        cout << "\nO valor " << procurado << " não foi encontrado em nenhuma linha." << endl;

    pause("Apertar ENTER para continuar");
}

/*
    Method_19
*/
void method_19() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;
    int procurado = readint("Digite o valor a procurar: ");

    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    cout << "\nMatriz lida:\n";
    matrix1.print();

    int coluna = matrix1.searchColumns(procurado);
    if(coluna >= 0)
        cout << "\nO valor " << procurado << " foi encontrado na coluna " << coluna << "." << endl;
    else
        cout << "\nO valor " << procurado << " não foi encontrado em nenhuma coluna." << endl;

    pause("Apertar ENTER para continuar");
}

/*
    Method_20
*/
void method_20() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo da matriz: ";
    cin >> nomeArquivo;

    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread(nomeArquivo);

    cout << "\nMatriz original:\n";
    matrix1.print();

    matrix1.transpose();

    cout << "\nMatriz transposta:\n";
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

int main(int argc, char** argv) {
    //definir dado
    int x = 0;      //definir variavel com valor inicial

    //repetir ate desejar parar
    do {
        //identificar
        cout << "Exemplo1101 - Programa v0.0\n" << endl;

        //mostrar opcoes
        cout << "Opcoes" << endl;
        cout << "0 - parar " << endl;
        cout << "1 - mostrar Dados inteiros em arranjo" << endl;
        cout << "2 - " << endl;
        cout << "3 - nada" << endl;
        cout << "4 - nada" << endl;
        cout << "5 - nada" << endl;
        cout << "6 - nada" << endl;
        cout << "7 - nada" << endl;
        cout << "8 - nada" << endl;
        cout << "9 - nada" << endl;
        cout << "10 - nada" << endl;
        cout << "11 - gerar matriz aleatoria e gravar em arquivo" << endl;
        cout << "12 - escalar matriz lida de arquivo" << endl;
        cout << "13 - testar se matriz eh identidade" << endl;
        cout << "14 - testar igualdade de duas matrizes" << endl;
        cout << "15 - somar duas matrizes" << endl;
        cout << "16 - somar linhas da matriz (com constante)" << endl;
        cout << "17 - subtrair linhas da matriz (com constante)" << endl;
        cout << "18 - buscar valor por linha" << endl;
        cout << "19 - buscar valor por coluna" << endl;
        cout << "20 - transpor matriz" << endl;

        //ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        //escolher acao
        switch(x) {
        case 0:
            method_00();
            break;
        case 1:
            method_01();
            break;
        case 2:
            method_02();
            break;
        case 3:
            method_03();
            break;
        case 4:
            method_04();
            break;
        case 5:
            method_05();
            break;
        case 6:
            method_06();
            break;
        case 7:
            method_07();
            break;
        case 8:
            method_08();
            break;
        case 9:
            method_09();
            break;
        case 10:
            method_10();
            break;
        case 11:
            method_11();
            break;
        case 12:
            method_12();
            break;
        case 13:
            method_13();
            break;
        case 14:
            method_14();
            break;
        case 15:
            method_15();
            break;
        case 16:
            method_16();
            break;
        case 17:
            method_17();
            break;
        case 18:
            method_18();
            break;
        case 19:
            method_19();
            break;
        case 20:
            method_20();
            break;
        default:
            cout << endl << "ERRO: Valor invalido." << endl;
        }//end switch
    } while(x != 0);

    //encerrar
    pause("Apertar ENTER para terminar");
    return(0);
}//end main
