

/*****************************************************************************
Header File: MST_PRIM.h
Author: Ben R. Olson
Date: Dec. 2, 2015 
Description: Prim's Minimum Spanning Tree algorithm.
    To be used with Cities class.  This algorithm takes a Cities object
    with no edges between any of the vertices and adds all the edges
    that form an MST.  The edges are stored in the adjacency list which is
    a member of the Cities object.
******************************************************************************/



#ifndef MST_PRIM_H
#define MST_PRIM_H



#include "cities.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct List_City
{
    List_City(int c): num(c)
    {
        parent = -1;
        key = -1;
    }
    List_City(){}
    int key;
    int num;
    int parent;
    
};

struct Compare_Key
{
    bool operator()(const List_City& first, const List_City& second) const
    {
        // Return true if first should go before second
        return first.key < second.key;
    }
};

void MST_PRIM (Cities& C)
{

    list<List_City> L;
    
    for (int i = 0; i < C.getSize(); i++)
        L.push_back(List_City(i));
    
    L.front().key = 0;
    L.front().parent = 0;
    
    while (!L.empty())
    {
        List_City u = L.front();
        L.pop_front();
        
        C.addEdge(u.num, u.parent);
        
        for (list<List_City>::iterator v = L.begin(); v != L.end(); ++v)
        {
            int distance = C.getDistance(u.num, v->num);
            if (distance < v->key || v->key == -1)
            {
                v->parent = u.num;
                v->key = distance;
            }
        }
        
        
        L.sort(Compare_Key());  // needed to maintain L as min priority queue
    }
}



#endif