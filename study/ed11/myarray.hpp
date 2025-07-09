/*

*/

#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>

using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

template <typename T>

class Array
{
private:
    T optional;
    int length;
    T *data;

public:
    Array(int n, T initial)
    {
        optional = initial;
        length = 0;
        data = nullptr;

        if (n > 0)
        {
            length = n; // n fornece o tamanho do array q eu criei.
            data = new T[length];
        }
    } // end constructor

    void free()
    {
        if (data != nullptr)
        {
            delete[] data;
            data = nullptr;
        }
    }

    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        }
    }

    void read()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : ";
            cin >> data[x];
        }
        cout << endl;
    }

    T get(int position)
    {
        T value = optional;

        if (0 <= position && position < length)
        {
            value = data[position];
        }

        return (value);
    }

    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : "
                 << setw(9) << data[x]
                 << endl;
        } // end for
        cout << endl;
    }

    void fprint(string fileName)
    {
        ofstream afile;

        afile.open(fileName);
        afile << length << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            afile << data[x] << endl;
        }
        afile.close();
    }

    void fread(string fileName)
    {
        ifstream afile;
        afile.open(fileName);
        int n = 0;
        afile >> n;
        if (n < 0)
        {
            cout << "ERROR";
        }
        else
        {
            length = n;

            data = new T[n];

            for (int x = 0; x < length; x = x + 1)
            {
                afile >> data[x];
            }
            afile.close();
        }
    }
};

#endif