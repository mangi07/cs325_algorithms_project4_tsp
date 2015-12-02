

/*****************************************************************************
Header File: GRAPH_TRAVERSAL.h
Author: Ben R. Olson
Date: Dec. 2, 2015 
Description: Traverses a 
    To be used with Cities class.  This algorithm takes a Cities object
    with edges representing an MST and finds a perfect matching of vertices
    of odd degree that is approximately minimal.
    The edges are stored in the adjacency list 
    which is a member of the Cities object.
******************************************************************************/



#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H



#include "cities.h"
#include "MST_PRIM.h"
#include "MATCH.h"
#include <iostream>
//#include <string>
#include <stack>
#include <vector>

using namespace std;

/*

C: Euler graph of cities (vertices)
H: vector representing Hamiltonian path
d: distance of this path

This procedure modifies H and d passed in

*/
void GRAPH_TRAVERSAL (Cities& C, vector<int>& H, int& d)
{

    H.clear();
    stack<int> S;
    
    // mark each vertex unvisited
    for (int v = 0; v < C.getSize(); v++)
        C.markUnvisited(v);
    
    // first vertex visited is special, with no edges to remove
    vector<int> r_adj = C.getAdj(0);
    for ( int v: r_adj )
        S.push(v);          // push vertices, adjacent to root 0, onto the stack
    int prev = 0;           // 0 becomes the most recently visited vertex
    C.markVisited(0);
    H.push_back(0);
    
    // each subsequent vertex visitation requires an edge removal
    int u;
    while (!S.empty())
    {
        u = S.top();        // pop stack
        S.pop();
        C.removeEdge(u, prev);
        
        if (C.isVisited(u) == false)
        {
            C.markVisited(u);      // mark u as visited
            H.push_back(u);     // record the order of visitation
        
            vector<int> u_adj = C.getAdj(u);
            for ( int v: u_adj )
                S.push(v);      // push v onto stack
        }
        
        prev = u;   // needed for next iteration
    }
    
    // add r to complete the Hamiltonian cycle
    H.push_back(0);
    
    // compute the distance of the Hamiltonian cycle
    d = 0;              // cumulative distance
    int c1, c2;
    if (H.size() >= 2)
    {
        int c1 = H[0];  // we assume there are at least two cities in the graph
        int c2 = H[1];
        
        for (int i = 0; i < H.size()-1; i++)
        {
            d = d + C.getDistance(c1, c2);
            c1 = c2;
            c2 = H[i+2];
        }
    }
    
}
   

 
#endif