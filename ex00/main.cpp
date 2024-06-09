#include "convert.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "the number of arguments must be 2" << std::endl;
        return 0;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
