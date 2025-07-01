/*
    MyStringEx.hpp - v1.1.0
    Author: Eduardo Murta De Abreu - 884985
*/

#ifndef _MYSTRINGEX_H_
#define _MYSTRINGEX_H_

#include "MyString.hpp"

class MyStringEx : public MyString
{
public:
    MyStringEx(std::string text = "") : MyString(text) {}

    int getInt()
    {
        int result = 0;
        int sign = 1;
        int start = 0;
        setErro(0);

        if (content.empty()) {
            setErro(1);
            return -1;
        }

        if (content[0] == '-') {
            sign = -1;
            start = 1;
        } else if (content[0] == '+') {
            start = 1;
        }

        if (start >= content.length()) {
            setErro(1);
            return -1;
        }

        for (int i = start; i < content.length(); i = i + 1)
        {
            if (content[i] >= '0' && content[i] <= '9')
            {
                result = result * 10 + (content[i] - '0');
            }
            else
            {
                setErro(1);
                return -1;
            }
        }
        return result * sign;
    }

    double getDouble()
    {
        double result = 0.0;
        double fraction = 0.0;
        double divisor = 1.0;
        int sign = 1;
        int start = 0;
        bool hasDecimal = false;
        setErro(0);

        if (content.empty()) {
            setErro(2);
            return 0.0;
        }
        
        if (content[0] == '-') {
            sign = -1;
            start = 1;
        } else if (content[0] == '+') {
            start = 1;
        }

        if (start >= content.length()) {
            setErro(2);
            return 0.0;
        }

        for (int i = start; i < content.length(); i = i + 1)
        {
            if (content[i] >= '0' && content[i] <= '9')
            {
                if (hasDecimal)
                {
                    divisor = divisor * 10.0;
                    fraction = fraction * 10.0 + (content[i] - '0');
                }
                else
                {
                    result = result * 10.0 + (content[i] - '0');
                }
            }
            else if (content[i] == '.' && !hasDecimal)
            {
                hasDecimal = true;
            }
            else
            {
                setErro(2);
                return 0.0;
            }
        }
        return (result + (fraction / divisor)) * sign;
    }

    bool getBoolean()
    {
        setErro(0);
        std::string upper = this->toUpperCase();
        if (upper == "TRUE" || upper == "T" || upper == "1")
        {
            return true;
        }
        if (upper == "FALSE" || upper == "F" || upper == "0")
        {
            return false;
        }
        setErro(3);
        return false;
    }

    bool contains(std::string subtexto)
    {
        if (subtexto.length() > content.length() || subtexto.empty())
        {
            return false;
        }
        for (int i = 0; i <= content.length() - subtexto.length(); i = i + 1)
        {
            bool match = true;
            for (int j = 0; j < subtexto.length(); j = j + 1)
            {
                if (content[i + j] != subtexto[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return true;
            }
        }
        return false;
    }

    std::string toUpperCase()
    {
        std::string result = content;
        for (int i = 0; i < result.length(); i = i + 1)
        {
            if (result[i] >= 'a' && result[i] <= 'z')
            {
                result[i] = result[i] - ('a' - 'A');
            }
        }
        return result;
    }

    std::string toLowerCase()
    {
        std::string result = content;
        for (int i = 0; i < result.length(); i = i + 1)
        {
            if (result[i] >= 'A' && result[i] <= 'Z')
            {
                result[i] = result[i] + ('a' - 'A');
            }
        }
        return result;
    }

    std::string replace(char original, char novo)
    {
        std::string result = content;
        for (int i = 0; i < result.length(); i = i + 1)
        {
            if (result[i] == original)
            {
                result[i] = novo;
            }
        }
        return result;
    }

    std::string encrypt(int key)
    {
        std::string result = content;
        for (int i = 0; i < result.length(); i = i + 1)
        {
            if (result[i] >= 'a' && result[i] <= 'z')
            {
                result[i] = 'a' + (result[i] - 'a' + key) % 26;
            }
            else if (result[i] >= 'A' && result[i] <= 'Z')
            {
                result[i] = 'A' + (result[i] - 'A' + key) % 26;
            }
        }
        return result;
    }

    std::string decrypt(int key)
    {
        std::string result = content;
        for (int i = 0; i < result.length(); i = i + 1)
        {
            if (result[i] >= 'a' && result[i] <= 'z')
            {
                result[i] = 'a' + (result[i] - 'a' - key + 26) % 26;
            }
            else if (result[i] >= 'A' && result[i] <= 'Z')
            {
                result[i] = 'A' + (result[i] - 'A' - key + 26) % 26;
            }
        }
        return result;
    }

    int split(std::string sequencia[])
    {
        int count = 0;
        std::string buffer = "";
        std::string text = content + " ";

        for (int i = 0; i < text.length(); i = i + 1)
        {
            if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n')
            {
                if (buffer.length() > 0)
                {
                    sequencia[count] = buffer;
                    count = count + 1;
                    buffer = "";
                }
            }
            else
            {
                buffer = buffer + text[i];
            }
        }
        return count;
    }
};

#endif