//
//  Graph.h
//  Graphs
//
//  Created by Sebas Neira Gzz on 06/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include <queue>

template<class T>
class Graph {
private:
    vector < vector<T> > adjList;
    vector<T> vertices;
    int qtyVertices;
    int qtyEdges;
    int findVertex (T vertex);
    void DFSR(T vertex, vector<bool> &status);
    
public:
    Graph(vector <vector<T>> list, int qtyVertices, int qtyEdges);
    void BFS();
    void DFS();
    void print();
};


template<class T>
void Graph<T>::BFS(){
    queue<int> q;
    vector<bool> status(adjList.size(),false);
    int vertex = 0;
    q.push(vertex);
    status[vertex] = true;
    while(!q.empty()){
        vertex = q.front();
        for(auto adj:adjList[vertex]){
            int pos = findVertex(adj);
            if(!status[pos]){
                q.push(pos);
                status[pos] = true;
            }
        }
        q.pop();
        cout << vertices[vertex] << " ";
    }
    cout << endl;
}

template<class T>
Graph<T>::Graph(vector< vector<T> > list, int qtyVertices, int qtyEdges){
    this-> qtyVertices = qtyVertices;
    this-> qtyEdges = qtyEdges;
    int source = 0;
    int target = 1;
    
    // Crear vector de vertices
    for(auto edge : list){
        int pos = findVertex(edge[source]);
        if (pos < 0){ //not found
            vertices.push_back(edge[source]);
        }
        pos = findVertex(edge[target]);
        if (pos < 0){ //not found
            vertices.push_back(edge[target]);
        }
    }
    
    //Ordena el vector de vertices
    sort(vertices.begin(),vertices.end());
    
    for(auto vertex : vertices){
        vector<T> temp;
        temp.push_back(vertex);
        adjList.push_back(temp);
    }
    
    for (auto edge : list){
        int posSource = findVertex(edge[source]);
        adjList[posSource].push_back(edge[target]);
    }
}
    
template<class T>
int Graph<T>::findVertex(T vertex){
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
        if (it != vertices.end()){
            return it - vertices.begin();
        } else {
            return -1;
        }
    }

template<class T>
void Graph<T>::print(){
    for (auto vertexAdj : adjList){
        for(auto vertex : vertexAdj){
            cout << vertex << " ";
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::DFS(){
    vector<bool> status(vertices.size(),false);
    DFSR(vertices[0],status);
    cout << endl;
}

template<class T>
void Graph<T>::DFSR(T vertex, vector<bool> &status){
    int pos = findVertex(vertex);
    if(!status[pos]){
        cout << vertex << " ";
        status[pos] = true;
        for(auto adj : adjList[pos]){
            int posAdj = findVertex(adj);
            if (!status[posAdj]){
                DFSR(adj,status);
            }
        }
    }
}


#endif /* Graph_h */
