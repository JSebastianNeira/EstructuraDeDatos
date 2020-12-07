//
//  main.cpp
//  GraphsWeighted
//
//  Created by Sebas Neira Gzz on 13/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include "GraphM.h"
#include "Graph.h"

int main() {
    vector< vector<int> > list = {{0,3,4}, {0,4,8}, {1,6,5}, {2,6,9}, {3,7,8}, {4,2,3}, {5,1,9}, {5,6,7}, {5,7,8}, {7,5,9}};
    Graph<int> graph(list);
    
    cout << endl << "Lista de Adyacencias" << endl << endl;
    graph.print();
    
    cout << endl << "Shortest Path" << endl << endl;
    graph.shortestPath(0);
    
    cout << endl << "BFS" << endl << endl;
    graph.BFS(0);
    
    cout << endl << "DFS" << endl << endl;
    graph.DFS(0);
    
    return 0;
}
