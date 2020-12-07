//
//  main.cpp
//  Graphs
//
//  Created by Sebas Neira Gzz on 06/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "GraphM.h"
#include "Graph.h"
using namespace std;

int main() {
    
    
    cout << "Matriz de adyacencias" << endl << endl;
    vector< vector<char> > list = {{'A','B'},{'A','E'},{'A','H'},{'B','A'},{'B','C'},     {'B','E'},{'C','B'},{'C','D'},{'C','E'},{'C','F'},{'D','C'},{'E','A'},{'E','B'},{'E','C'},{'E','G'},     {'E','H'},{'F','C'},{'F','J'},{'G','E'},{'G','J'},{'H','A'},{'H','E'},{'H','I'},{'H','J'},     {'I','H'},{'J','F'},{'J','G'},{'J','H'}};
    
    cout << "Lista de adyacencias"<< endl << endl;
    vector< vector<char> > list2 = {{'a','b'},{'a','c'},{'b','c'},{'d','a'},{'d','b'},{'d','c'}};
    Graph<char> graph(list2,4,6);
    graph.print();
    graph.BFS();
    graph.DFS();
    
}
