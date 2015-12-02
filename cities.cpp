

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


#include "cities.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>    // used in removeEdge()

#include <math.h>

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







/*********************************************************************
PUBLIC MEMBERS
*********************************************************************/



// return the distance between c1 and c2
// If either of the passed in city numbers is too large,
//   this funciton returns -1
int Cities::getDistance(int c1, int c2)
{
    if (c1 >= matrix.size() || c2 >= matrix.size())
        return -1;
        
    return matrix[c1][c2];
    
}


// load new set of cities into the matrix
// must be a text file as specified on lines 11-15
void Cities::loadNewGroup(string newFile)
{
    initMatrix(newFile);
}

// get number label of nearest neighbor to u
//   (all cities are numbered and referenced by that number)
//   If u has been marked visited, this function will return -1
int Cities::nearestNeighbor(int u)
{
    if (u >= matrix.size() || citiesData[u].visited == true)
        return -1;
    
    int distance = -1;
    int v = -1;
    for (int i = 0; i < matrix[u].size(); i++){
        if (matrix[u][i] < distance || distance == -1)
        {
            if (u != i)
            {
                v = i;
                distance = matrix[u][i];
            }
        }
        
    }
    
    return v;
}

int Cities::getSize()
{
    return Cities::matrix.size();
}

// EDIT

// returns c.adj list as a vector
//   Warning: may return an empty vector if adjacency list is empty
vector<int> Cities::getAdj(int c)
{
    vector<int> adj;
    
    if (c < Cities::citiesData.size())
        adj = Cities::citiesData[c].edges;
        
    return adj;
}

// given city u, create undirected directed edge (u, v)
void Cities::addEdge(int u, int v)
{
    if (u == v)
        return;
    
    if (u < Cities::citiesData.size() && v < Cities::citiesData.size())
    {
        Cities::citiesData[u].edges.push_back(v);
        Cities::citiesData[v].edges.push_back(u);
    }
    else
    {
        cout << "Error in Cities::addEdge: invalid input" << endl;
    }
}

// remove undirected edge
//   If the edge does not exist, nothing will be modified.
void Cities::removeEdge(int u, int v)
{
    if (u < Cities::citiesData.size() && v < Cities::citiesData.size()
        && u >= 0 && v >= 0)
    {   
        // get edge lists
        vector<int> * adj_u = &Cities::citiesData[u].edges;
        vector<int> * adj_v = &Cities::citiesData[v].edges;
        
        //search for edges to remove
        for (int i = 0; i < adj_u->size(); i++)
        {
            if ((*adj_u)[i] == v)
            {
                adj_u->erase(adj_u->begin() + i);
            }
        }
        for (int j = 0; j < adj_v->size(); j++)
        {
            if ((*adj_v)[j] == u)
            {
                adj_v->erase(adj_v->begin() + j);
            }
        }

        
    }
    else
    {
        cout << "Error in Cities::addEdge: invalid input" << endl;
    }  
}

void Cities::markVisited(int c)
{
    if (c < Cities::citiesData.size() && c >= 0)
        Cities::citiesData[c].visited = true;
}

void Cities::markUnvisited(int c)
{
    if (c < Cities::citiesData.size() && c >= 0)
        Cities::citiesData[c].visited = false;
}

bool Cities::isVisited(int c)
{
    if (c < Cities::citiesData.size() && c >= 0)
        return Cities::citiesData[c].visited;
    
    cout << "Error: isVisited received invalid input" << endl;
    return false;
}

// END EDIT




/*********************************************************************
PRIVATE MEMBERS
*********************************************************************/
            
            
// To load city coordinates from input file into struct citiesData
// Uses fstream
// Loads data into struct cityData
void Cities::parseInputFile(string inputFile)
{

    ifstream input;
    string line;
    input.open(inputFile);
    int c, x, y;        // city c with coordinates (x, y)
    city city_coords;
    
    citiesData.clear(); // necessary when reinitializing matrix
    
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
void Cities::initMatrix(string inputFile)
{
    
    Cities::parseInputFile(inputFile);
    
    int num_cities = citiesData.size();
    // initialize the matrix
    vector<vector<int>> M(
        num_cities,
        vector<int>(num_cities, -1)
    );

    
    int distance = NULL;
    city c1, c2;           // coordinates of a city
    for (int i = 0; i < num_cities; i++)
    {
        for (int j = i; j < num_cities; j++)
        {
            c1 = citiesData[i];
            c2 = citiesData[j];
            if (i == j)
                distance = 0;
            else
                distance = Cities::calcDist(c1, c2);
            
            M[i][j] = distance;
            // fill in the symmetry (column i is the transpose of row i)
            M[j][i] = distance;
            
        }
        
    }
    
    matrix = M;
    
}

// receives coordinates for a pair of cities
//   and returns their Euclidean distance
//
//   This function should only be called when
//   instantiating a new Cities instance
//   or where loading a new set of cities into
//   an existing Cities instance.
int Cities::calcDist(city c1, city c2)
{
    
    // Calculate Euclidean distance
    double x_sqr = pow((c1.x - c2.x), 2);
    double y_sqr = pow((c1.y - c2.y), 2);
    int distance = (int) (sqrt(x_sqr + y_sqr) + 0.5);
    
    return distance;
    
}





