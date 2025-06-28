//
// Created by eduardo on 5/30/2025.
//

#ifndef MYMATRIX_HPP
#define MYMATRIX_HPP

//dependencias

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

template <typename T>
class Matrix {
  private:
    T optional;
    int rows;
    int columns;
    T** data;
  public:
    Matrix() {
        rows = 0;
        columns = 0;
        data = nullptr;
    } // end constructor

    Matrix(int rows, int columns, T initial) {
        bool OK = true;
        this->optional = initial;
        this->rows = rows;
        this->columns = columns;
        data = new T*[rows];
        if(data != nullptr) {
            for(int x = 0; x < rows; x++) {
                data[x] = new T[columns];
                OK = OK && (data[x] != nullptr);
                for(int y = 0; y < columns; y++) {
                    data[x][y] = initial;
                }
            }
            if(!OK) {
                data = nullptr;
            }
        }
    } // end constructor

    ~Matrix() {
        if(data != nullptr) {
            for(int x = 0; x < rows; x++) {
                delete[] data[x];
            }
            delete[] data;
            data = nullptr;
        }
    } // end destructor

    void set(int row, int column, T value) {
        if(row < 0 || row >= rows || column < 0 || column >= columns) {
            cout << "\nERROR: Invalid position.\n";
        } else {
            data[row][column] = value;
        }
    }

    T get(int row, int column) {
        T value = optional;
        if(row < 0 || row >= rows || column < 0 || column >= columns) {
            cout << "\nERROR: Invalid position.\n";
        } else {
            value = data[row][column];
        }
        return value;
    }

    void print() {
        cout << endl;
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                cout << data[x][y] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    void read() {
        cout << endl;
        for(int x = 0; x < rows; x = x + 1) {
            for(int y = 0; y < columns; y = y + 1) {
                cout << setw(2) << x << ", "
                     << setw(2) << y << " : ";
                cin >> data[ x ][ y ];
            } // end for
        } // end for
        cout << endl;
    } // end read ( )
    void fprint(string fileName) {
        ofstream afile;

        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                afile << data[x][y] << endl;
            }//end for1
        }//end for2
        afile.close();
    }//end fprintf()
    void fread(string fileName) {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open(fileName);
        afile >> m;
        afile >> n;
        if(m <= 0 || n <= 0) {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
        } else {
            // desalocar dados antigos, se existirem
            if(data != nullptr) {
                for(int x = 0; x < rows; x++) {
                    delete[] data[x];
                }
                delete[] data;
                data = nullptr;
            }
            rows = m;
            columns = n;
            data = new T*[rows];
            for(int x = 0; x < rows; x++) {
                data[x] = new T[columns];
            }
            for(int x = 0; x < rows; x++) {
                for(int y = 0; y < columns; y++) {
                    afile >> data[x][y];
                }
            }
        }
        afile.close();
    } // end fread

    Matrix& operator= (const Matrix <T> &other) {
        if(this == &other) return *this;
        // desalocar dados antigos
        if(data != nullptr) {
            for(int x = 0; x < rows; x++) {
                delete[] data[x];
            }
            delete[] data;
            data = nullptr;
        }
        if(other.rows == 0 || other.columns == 0) {
            cout << "\nERROR: Missing data.\n" << endl;
        } else {
            this->rows = other.rows;
            this->columns = other.columns;
            this->data = new T*[rows];
            for(int x = 0; x < rows; x++) {
                this->data[x] = new T[columns];
            }
            for(int x = 0; x < this->rows; x++) {
                for(int y = 0; y < this->columns; y++) {
                    data[x][y] = other.data[x][y];
                }
            }
        }
        return (*this);
    } // end operator= ()

    bool isZeros() {
        bool result = false;
        int x = 0;
        int y = 0;
        if(rows > 0 && columns > 0) {
            result = true;
            while(x < rows && result) {
                y = 0;
                while(y < columns && result) {
                    result = result && (data [ x ][ y ] == 0);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if
        return (result);
    } // end isZeros ( )
    bool operator!= (const Matrix <T> &other) {
        bool result = false;
        int    x         = 0;
        int    y         = 0;

        if(other.rows       == 0 || rows        != other.rows      ||
                other.columns == 0 || columns != other.columns) {
            cout << "\nERROR: Missing data.\n" << endl;
        } else {
            x = 0;
            while(x < rows && ! result) {
                y = 0;
                while(y < columns && ! result) {
                    result = (data [ x ][ y ] != other.data [ x ][ y ]);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if
        return (result);
    } // end operator!= ( )

    Matrix& operator- (const Matrix <T> &other) {
        static Matrix <T> result(1, 1, 0);
        int      x      = 0;
        int      y      = 0;

        if(other.rows       == 0 || rows        != other.rows ||
                other.columns == 0 || columns != other.columns) {
            cout << "\nERROR: Missing data.\n" << endl;
        } else {
            result.rows       = rows;
            result.columns = other.columns;
            result.data         = new T* [ result.rows ];
            for(int x = 0; x < result.rows; x = x + 1) {
                result.data [x] = new T  [ result.columns ];
            } // end for

            for(int x = 0; x < result.rows; x = x + 1) {
                for(int y = 0; y < result.columns; y = y + 1) {
                    result.data [ x ][ y ] = data [ x ][ y ] - other.data [ x ][ y ];
                } // end for
            } // end for
        } // end if
        return (result);
    } // end operator- ( )
    Matrix& operator* (const Matrix <T> &other) {
        static Matrix <T> result(1, 1, 0);
        int x      = 0;
        int y      = 0;
        int z      = 0;
        int sum = 0;

        if(rows <= 0 ||           columns == 0 ||
                other.rows <= 0 || other.columns == 0 ||
                columns    != other.rows) {
            cout << endl << "ERROR: Invalid data." << endl;
            result.data [ 0 ][ 0 ] = 0;
        } else {
            result.rows       = rows;
            result.columns = other.columns;
            result.data         = new T* [ result.rows ];
            for(int x = 0; x < result.rows; x = x + 1) {
                result.data [x] = new T  [ result.columns ];
            } // end for

            for(x = 0; x < result.rows; x = x + 1) {
                for(y = 0; y < result.columns; y = y + 1) {
                    sum = 0;
                    for(z = 0; z < columns; z = z + 1) {
                        sum = sum + data [ x ][ z ] *  other.data [ z ][ y ];
                    } // end for
                    result.data [ x ][ y ] = sum;
                } // end for
            } // end for
        } // end if
        return (result);
    } // end operator* ( )
    const int getRows() {
        return (rows);
    } // end getRows ( )

    const int getColumns() {
        return (columns);
    } // end getColumns ( )
    /*
        Exercicios
    */
    void randomIntGenerate(int lower, int upper) {
        // Gera valores aleatórios no intervalo [lower, upper] para toda a matriz
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                data[x][y] = lower + (rand() % (upper - lower + 1));
            }
        }
    }

    void fprintRandom(string fileName) {
        ofstream afile;
        afile.open(fileName);
        afile << (rows * columns) << endl;
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                afile << data[x][y] << endl;
            }
        }
        afile.close();
    }

    Matrix scalar(T constant) const {
        Matrix result(rows, columns, optional);
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                result.set(x, y, data[x][y] * constant);
            }
        }
        return result;
    }

    bool identidade() const {
        if(rows != columns) return false;
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                if(x == y) {
                    if(data[x][y] != 1) return false;
                } else {
                    if(data[x][y] != 0) return false;
                }
            }
        }
        return true;
    }

    bool operator==(const Matrix<T>& other) const {
        if(rows != other.rows || columns != other.columns) return false;
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                if(data[x][y] != other.data[x][y]) return false;
            }
        }
        return true;
    }

    Matrix add(const Matrix& other) const {
        if(rows != other.rows || columns != other.columns) {
            cout << "\nERROR: Matrizes de tamanhos diferentes.\n" << endl;
            return Matrix(rows, columns, 0);
        }
        Matrix result(rows, columns, 0);
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                result.set(x, y, data[x][y] + other.data[x][y]);
            }
        }
        return result;
    }

    void addRows(int row1, int row2, T constant) {
        if(row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
            cout << "\nERROR: Índices de linha inválidos.\n" << endl;
            return;
        }
        for(int y = 0; y < columns; y++) {
            data[row1][y] = data[row1][y] + constant * data[row2][y];
        }
    }

    void subtractRows(int row1, int row2, T constant) {
        if(row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
            cout << "\nERROR: Índices de linha inválidos.\n" << endl;
            return;
        }
        for(int y = 0; y < columns; y++) {
            data[row1][y] = data[row1][y] - constant * data[row2][y];
        }
    }

    int searchRows(T value) const {
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                if(data[x][y] == value) return x;
            }
        }
        return -1;
    }

    int searchColumns(T value) const {
        for(int y = 0; y < columns; y++) {
            for(int x = 0; x < rows; x++) {
                if(data[x][y] == value) return y;
            }
        }
        return -1;
    }

    void transpose() {
        if(rows == 0 || columns == 0) return;
        Matrix<T> temp(columns, rows, optional);
        for(int x = 0; x < rows; x++) {
            for(int y = 0; y < columns; y++) {
                temp.data[y][x] = data[x][y];
            }
        }
        // desalocar dados antigos
        for(int x = 0; x < rows; x++) delete[] data[x];
        delete[] data;
        // atualizar dimensões e ponteiro
        data = temp.data;
        temp.data = nullptr;
        int tmp = rows;
        rows = columns;
        columns = tmp;
    }
}; // end class

#endif //MYMATRIX_HPP
