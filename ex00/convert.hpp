#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>



#define IS_IN_INT_RANGE(value) ((value >= -2147483647 - 1) && (value <= 2147483647))

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter &operator=(const ScalarConverter& copy);
        ~ScalarConverter();
        static void convert(const std::string& arg);
        static int findType(const std::string& arg);
        static int isChar(const std::string& arg);
        static int isInt(const std::string &arg);
        static int isFloat(const std::string &arg);
        static int isDouble(const std::string &arg);
};


#endif