

#include "cities.h"
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[])
{

    string fileName;
    
    cout << "Enter name of file: ";
    cin >> fileName;
    cout << endl;
    
    Cities cities(fileName);
    
    return 0;

}

