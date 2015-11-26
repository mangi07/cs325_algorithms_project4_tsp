

/*****************************************************************************
* Implementation File: cities.cpp                                            *
* Author: Ben R. Olson                                                       *
* Date: Nov. 25, 2015                                                        *
* Description: class implementation to load cities from text file into       *
*   a 2d vector (matrix) that represents the Euclidean distance              *
*   between each pair of cities.                                             *
*                                                                            *
*   In the input text file, each city is represented in the following format:*
*     <city number> <x-coord> <y-coord>                                      *
*   For example:                                                             *
*     2 50 23                                                                *
*   is city #2 with coordinates (50, 23) in the 2-d plane.                   *
******************************************************************************/



//#ifndef CITIES_H
//#define CITIES_H

#include "cities.h"

#include <iostream>
#include <cstdlib>
#include <vector>

#include <string>
#include <sstream>
#include <fstream>

using namespace std;


/*****************************************************************************
* The purpose of this class is to create a matrix representing distances     *
* between cities.  Each Euclidean distance calculated will be rounded to the *
* nearest integer before it is stored in the matrix.  For example (borrowing *
* from the Project4TSP.pdf assignment description), if the three cities are  *
* given by the coordinates c1= (0, 0), c2 = (1, 3), c3 = (6, 0), then the    *
* following distances are calculated:                                        *
*   (c1 to c2) = 3                                                           *
*   (c2 to c3) = 6                                                           *
*   (c3 to c1) = 6                                                           *
* and these distances are stored in the adjacency matrix as follows:         *
*   <array[index][index] distance> for each "cell" entry                     *
*   | [0][0] 0 | [0][1] 3 | [0][2] 6 |                                       *
*   | [1][0] 3 | [1][1] 0 | [1][2] 6 |                                       *
*   | [2][0] 6 | [2][1] 6 | [2][2] 0 |                                       *
******************************************************************************/

// Initialize the object with input file.
//   This will create a matrix representing
//   distances between each pair of input cities.
Cities::Cities(string inputFile)
{
    initMatrix(inputFile);
}
        
Cities::Cities()
{
    // Intentionally left blank.
}






// return the matrix
vector<vector <int> > Cities::get()
{
    // stub
    vector<vector <int> > v;
    return v;
}

// load new set of cities into the matrix
void Cities::set()
{}

            
            
// To load city coordinates from input file into struct citiesData
// Uses fstream
// Loads data into struct cityData
void Cities::parseInputFile(string inputFile)
{

    ifstream input;
    string line;
    input.open(inputFile);
    int c, x, y;        // city c with coordinates (x, y)
    coords city_coords;
    
    if (input.is_open())
    {
        while ( getline (input, line) )
        {
            stringstream(line) >> c >> x >> y;
            // test
            //cout << c << " " << x << " " << y << " " << endl;
            city_coords.x = x;
            city_coords.y = y;
            if ( c == citiesData.size() )
            {
                citiesData.push_back(city_coords);
            }
            
        }
    }

    input.close();
    
}


// To fill matrix based on city data
void Cities::initMatrix(std::string inputFile)
{
    
    Cities::parseInputFile(inputFile);
    
    int num_cities = citiesData.size();
    // initialize the matrix
    vector<vector<int>> matrix(
        num_cities,
        vector<int>(num_cities, -1)
    );
    

    
    int distance = NULL;
    coords c1, c2;           // coordinates of a city
    for (int i = 0; i < num_cities; i++)
    {
        for (int j = i; j < num_cities; j++)
        {
            c1 = citiesData[j];
            c2 = citiesData[j];
            if (i == j)
                distance = 0;
            else
                distance = Cities::calcDist(c1, c2);
            
            matrix[i][j] = distance;
            // fill in the symmetry (column i is the transpose of row i)
            matrix[j][i] = distance;
            
        }
        
    }
    
}

// receives coordinates for a pair of cities
//   and returns their Euclidean distance
int Cities::calcDist(coords c1, coords c2)
{
    return 5;
}






//#endif // CITIES_H