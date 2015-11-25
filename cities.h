

/*****************************************************************************
* Header File: cities.h                                                      *
* Author: Ben R. Olson                                                       *
* Date: Nov. 25, 2015                                                        *
* Description: class declaration to load cities from text file into          *
*   a 2d vector (matrix) that represents the Euclidean distance              *
*   between each pair of cities.                                             *
*                                                                            *
*   In the input text file, each city is represented in the following format:*
*     <city number> <x-coord> <y-coord>                                      *
*   For example:                                                             *
*     2 50 23                                                                *
*   is city #2 with coordinates (50, 23) in the 2-d plane.                   *
/*****************************************************************************/



#ifndef CITIES_H
#define CITIES_H


#include <iostream>
#include <cstdlib>
#include <vector>



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
class Cities
{
    
    public:
    
        // Initialize the object with input file.
        //   This will create a matrix representing
        //   distances between each pair of input cities.
        Cities(std::string inputFile);
        Cities();
        
        vector<vector <int> > get();        // return the matrix
        void set();                         // load new set of cities into the matrix
        
        
    private:            
                    
        // To load city coordinates from input file
        void parseInputFile(std::string inputFile);
        struct coords
        {
            int x;
            int y;
        };
        vector<coords> citiesData;
        
        // To fill matrix based on city data
        void initMatrix(std::string inputFile);
        int calcDist(coords c1, coords c2); // receives coordinates for a pair of cities
                                            //   and returns their Euclidean distance
        
        
}




#endif // CITIES_H