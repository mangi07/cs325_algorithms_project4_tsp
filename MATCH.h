

/*****************************************************************************
Header File: MST_PRIM.h
Author: Ben R. Olson
Date: Dec. 2, 2015 
Description: Match vertices of odd degree using greedy modification
    of Christofide's matching heuristic.
    To be used with Cities class.  This algorithm takes a Cities object
    with edges representing an MST and finds a perfect matching of vertices
    of odd degree that is approximately minimal.
    The edges are stored in the adjacency list 
    which is a member of the Cities object.
******************************************************************************/



#ifndef MATCH_H
#define MATCH_H



#include "cities.h"
#include "MST_PRIM.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;


void MATCH (Cities& C)
{

    list<int> O;    // O will hold the set of all vertices in C
                    //   of odd degree
    
    for (int i = 0; i < C.getSize(); i++)
    {
        vector<int> adj = C.getAdj(i);
        if (adj.size() % 2 != 0)
            O.push_back(i);
    }
    
    int u;  // city number
    while ( !O.empty() )
    {
        u = O.front();
        O.pop_front();
        int min = -1;   // used in place of infinity
        int nearest;    // identifying the nearest known vertex to u
        int distance;   // holding the distance between two vertices
        
        int v;
        for (list<int>::iterator v = O.begin(); v != O.end(); ++v)
        {
            distance = C.getDistance(u, *v);
            if (distance < min || min == -1)
            {
                min = distance;
                nearest = *v;
            }
        }
        
        C.addEdge(u, nearest);
        O.remove(nearest);
    }

}



#endif