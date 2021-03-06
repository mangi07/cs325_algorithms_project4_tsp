

#include "cities.h"
#include "MST_PRIM.h"
#include "MATCH.h"
#include "GRAPH_TRAVERSAL.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char* argv[])
{

    string fileName;
    
    cout << "Enter name of file: ";
    cin >> fileName;
    cout << endl;

/*
//TEST CASE Cities class using test.txt    
    //Cities cities(fileName);

    cout << "Testing cities functions..." << endl;
    cout << "cities.getDistance(0, 0): " << cities.getDistance(0, 0) << endl;
    cout << "cities.getDistance(0, 1): " << cities.getDistance(0, 1) << endl;
    cout << "cities.getDistance(75, 75): " << cities.getDistance(75, 75) << endl;
    
    
    cout << "cities.loadNewGroup(test.txt)..." << endl;
    cities.loadNewGroup("test.txt");
    cout << "cities.getDistance(0, 0): " << cities.getDistance(0, 0) << endl;
    cout << "cities.getDistance(0, 1): " << cities.getDistance(0, 1) << endl;
    cout << "cities.getDistance(2, 3): " << cities.getDistance(2, 3) << endl;
    cout << "cities.nearestNeighbor(1): " << cities.nearestNeighbor(1) << endl;
    cout << "cities.getSize(): " << cities.getSize() << endl;

    vector<int> adj = cities.getAdj(0);
    cout << "cities.getAdj(0).size(): " << adj.size() << endl;
    
    cout << "cities.addEdge(0, 2) " << endl;
    cities.addEdge(0, 2);
    adj = cities.getAdj(0);
    cout << "adj(0).size(): " << adj.size() << endl;
    cout << "adj[0]: " << adj[0] << endl;
    
    vector<int> adj2 = cities.getAdj(2);
    cout << "adj2.size(): " << adj2.size() << endl;
    cout << "adj2[0]: " << adj2[0] << endl;
  
    cities.addEdge(2, 3);
    cities.addEdge(3, 2);
    vector<int> c2_edges = cities.getAdj(2);
    vector<int> c3_edges = cities.getAdj(3);
    cout << c2_edges.size() << endl;
    cout << c3_edges.size() << endl;
    
    cities.removeEdge(2, 3);
    vector<int> c2_edge = cities.getAdj(2);
    vector<int> c3_edge = cities.getAdj(3);
    cout << c2_edge.size() << endl;
    cout << c3_edge.size() << endl;
    
    cout << "isVisited(2): " << cities.isVisited(2) << endl;
    cities.markVisited(2);
    cout << "isVisited(2): " << cities.isVisited(2) << endl;
    cities.markUnvisited(2);
    cout << "isVisited(2): " << cities.isVisited(2) << endl;
//END TEST CASE Cities class
    

    
    
    
//TEST CASE MST_PRIM using testMST.txt
    Cities C(fileName);
    MST_PRIM(C);
    
    // remove edge (b, f) from MST
    C.removeEdge(1, 5);
    C.removeEdge(1, -1);
    
    vector<vector<int>> adj;
    for (int i = 0; i < C.getSize(); i++)
    {
        adj.push_back(C.getAdj(i));
    }
    for (int j = 0; j < C.getSize(); j++)
    {
        cout << j << ".adj: ";
        for (int k = 0; k < adj[j].size(); k++)
            cout << adj[j][k] << " ";
        cout << endl;
    }
//END TEST CASE MST_PRIM
*/
    
    
//TEST CASE MATCH (uses MST_PRIM)
    Cities C(fileName);
    MST_PRIM(C);
    MATCH(C);
    
    vector<vector<int>> adj;
    for (int i = 0; i < C.getSize(); i++)
    {
        adj.push_back(C.getAdj(i));
    }
    for (int j = 0; j < C.getSize(); j++)
    {
        cout << j << ".adj: ";
        for (int k = 0; k < adj[j].size(); k++)
            cout << adj[j][k] << " ";
        cout << endl;
    }
    cout << "END TEST CASE MATCH." << endl << endl;
//END TEST CASE MATCH
    
//TEST CASE GRAPH_TRAVERSAL (uses results of MST_PRIM and MATCH)
    cout << "STARTING TEST CASE GRAPH_TRAVERSAL: " << endl << endl;
    int distance;
    vector<int> ham_circuit;
    // modifies ham_circuit and distance, given the set of cities and edges in C
    GRAPH_TRAVERSAL(C, ham_circuit, distance);
    
    cout << "Printing the Ham Circuit and its distance..." << endl << endl;
    cout << "ham_circuit: " << endl;
    for (int m = 0; m < ham_circuit.size(); m++)
        cout << ham_circuit[m] << endl;
    cout << endl << endl;
    cout << "Total distance travelled: " << distance << endl << endl;


//END TEST CASE GRAPH_TRAVERSAL
    
    
    return 0;

}

