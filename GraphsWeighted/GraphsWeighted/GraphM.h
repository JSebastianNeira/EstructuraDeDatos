//
//  GraphM.h
//  Graphs
//
//  Created by Sebas Neira Gzz on 06/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef GraphM_h
#define GraphM_h
#include <vector>
#include <queue>
using namespace std;

template<class T>
class GraphM{
private:
    vector< vector<bool> > adjMatrix;
    vector<T> vertices;
    int qtyVertices;
    int qtyEdges;
    int findVertex(T vertex);
    void DFSR(T vertex, vector<bool> &status);
    
public:
    GraphM(vector< vector<T> > list, int qtyVertices, int qtyEdges);
    void print();
    void BFS();
    void DFS();
    
};

 
template<class T>
GraphM<T>::GraphM(vector< vector<T> > list, int qtyVertices, int qtyEdges){
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
    
    //Crear una matriz con puros falsos
    for(int i = 0; i < vertices.size();i++){
        vector<bool> temp;
        for(int j = 0 ; j < vertices.size(); j++){
            temp.push_back(false);
            
        }
        
        adjMatrix.push_back(temp);
    }
    
    for (auto edge : list){
        int posSource = findVertex(edge[source]);
        int posTarget = findVertex(edge[target]);
        adjMatrix[posSource][posTarget] = true;
    }
}
    
template<class T>
int GraphM<T>::findVertex(T vertex){
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
        if (it != vertices.end()){
            return it - vertices.begin();
        } else {
            return -1;
        }
    }

template<class T>
void GraphM<T>::print(){
    cout << " " ;
    for(auto vertex : vertices){
        cout << vertex << " ";
    }
    cout << endl;
    
    for(int i = 0; i < adjMatrix.size(); i++){
        cout << vertices[i] << " ";
        for (auto edge : adjMatrix[i]){
            if (edge){
                cout << "T ";
            } else {
                cout << "F ";
            }
        }
        cout << endl;
    }
}

template<class T>
void GraphM<T>::BFS(){
    queue<int> q;
    vector<bool> status(vertices.size(),false);
    int vertex = 0;
    q.push(vertex);
    status[vertex] = true;
    while(!q.empty()){
        vertex = q.front();
        for(int adj  = 0; adj<vertices.size();adj++){
            if(adjMatrix[vertex][adj]){
                if(!status[adj]){
                    q.push(adj);
                    status[adj] = true;
                }
            }
        }
        q.pop();
    }
    cout << endl;
}

template<class T>
void GraphM<T>::DFS(){
    vector<bool> status(vertices.size(),false);
    DFSR(vertices[0],status);
    cout << endl;
}

template<class T>
void GraphM<T>::DFSR(T vertex, vector<bool> &status){
    int pos = findVertex(vertex);
    if(!status[pos]){
        cout << vertex << " ";
        status[pos] = true;
        for(int adj = 0; adj < vertices.size(); adj++){
            if(adjMatrix[pos][adj]){
                if(!status[adj]){
                    DFSR(vertices[adj],status);
                }
            }
        }
    }
}


#endif /* GraphM_h */
