#include "convert.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) {*this = other;}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {(void)other;return *this;}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& arg)
{
    if (arg == "-inff" || arg == "+inff" || arg == "inff" || arg == "nanf")
    {
        std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << arg << std::endl
            << "double: " << arg.substr(0, arg.size()-1) << std::endl;
            return;
    }
    if (arg == "-inf" || arg == "+inf" || arg == "inf" || arg == "nan")
    {
        std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << arg << 'f' << std::endl
            << "double: " << arg << std::endl;
        return;
    }
    if (!findType(arg))
    {
        std::cout << "char: impossible" << std::endl 
            << "int: impossible" << std::endl
            << "float: impossible" << std::endl
            << "double: impossible" << std::endl;
    }
}

int ScalarConverter::findType(const std::string& arg)
{
    if (isChar(arg))
        return 1;
    if (arg.find('.') != std::string::npos)
    {
        for (size_t i = 0; i < arg.find('.'); ++i) {
            if ((i == 0 && (arg[0] == '+' || arg[0] == '-')) || isdigit(arg[i]))
                continue;
            else
                return 0;
        }
        for (size_t i = arg.find('.') + 1; i < arg.size() ; ++i) {
            if ((i == 0 && (arg[0] == '+' || arg[0] == '-')) || arg[i] == 'e' || isdigit(arg[i]) || (i == arg.size() - 1 && arg[i] == 'f'))
                continue;
            else
                return (0);
        }
        if ((isFloat(arg) || isDouble(arg)))
            return 1;
    }
    else if (isInt(arg))
        return 1;
    return 0;
}

int ScalarConverter::isDouble(const std::string& arg)
{
    double n = atof(arg.c_str());
    if (isascii(n))
    {
        if (isprint(n))
            std::cout << "char: '" << static_cast<char>(n) << "'"  << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    long long tmp = n;
    if (IS_IN_INT_RANGE(tmp))
        std::cout << "int: " << static_cast<int>(n) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (tmp - n != 0)
    {
        std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
        std::cout << "double: " << n << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
        std::cout << "double: " << n << ".0" << std::endl;
    }
    return 1;
}

int ScalarConverter::isFloat(const std::string& arg)
{
    if (arg[arg.size() - 1] == 'f')
    {
        float n = atof(arg.c_str());
        if (isascii(n))
        {
            if (isprint(n))
                std::cout << "char: '" << static_cast<char>(n) << "'"  << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        long long tmp = n;
        if (IS_IN_INT_RANGE(tmp))
            std::cout << "int: " << static_cast<int>(n) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        if (tmp - n != 0)
        {
            std::cout << "float: " << n << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(n) << std::endl;
        }
        else
        {
            std::cout << "float: " << n << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
        }
        return 1;
    }
    return 0;
}

int ScalarConverter::isInt(const std::string& arg)
{
    for (size_t i = 0; i < arg.size(); ++i) {
        if (isdigit(arg[i]) || (arg[0] == '+' || arg[0] == '-'))
        {
            if (i != 0)
                continue;
        }
        else if (arg[i] == 'f' && i == arg.size() -1)
        {
            if(isFloat(arg))
                return 1;
        }
        else
            return 0;
    }
    if (IS_IN_INT_RANGE(atoll(arg.c_str())))
    {
        int n = atoi(arg.c_str());
        if (isascii(n))
        {
            if (isprint(n))
                std::cout << "char: '" << static_cast<char>(n) << "'"  << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
        return 1;
    }
    return 0;
}

int ScalarConverter::isChar(const std::string& arg)
{
    if (arg.size() == 1 && isascii(arg[0]) && !isdigit(arg[0]))
    {
        char a = arg[0];
        std::cout << "char: '" << a << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(a) << std::endl;
        std::cout << "float: " << static_cast<float>(a) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(a) << ".0" << std::endl;
        return 1;
    }
    return 0;
}
