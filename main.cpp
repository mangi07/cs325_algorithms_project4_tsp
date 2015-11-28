

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
    cout << "Testing cities functions..." << endl;
    cout << "cities.getDistance(0, 0): " << cities.getDistance(0, 0) << endl;
    cout << "cities.getDistance(0, 1): " << cities.getDistance(0, 1) << endl;
    cout << "cities.getDistance(75, 75): " << cities.getDistance(75, 75) << endl;
    
    
    cout << "cities.loadNewGroup(test.txt)..." << endl;
    cities.loadNewGroup("test.txt");
    cout << "cities.getDistance(0, 0): " << cities.getDistance(0, 0) << endl;
    cout << "cities.getDistance(0, 1): " << cities.getDistance(0, 1) << endl;
    cout << "cities.getDistance(75, 75): " << cities.getDistance(75, 75) << endl;
    
    
    return 0;

}

