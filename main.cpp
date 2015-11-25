

#include "cities.h"
#include <iostream>
#incude <string>

int main (int argc, char* argv[])
{

    std::string fileName;
    
    std::cout << "Enter name of file: ";
    std::cin << fileName;
    
    Cities cities(fileName);
    
    return 0;

}