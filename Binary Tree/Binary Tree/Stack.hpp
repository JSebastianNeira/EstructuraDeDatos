//
//  Stack.hpp
//  Binary Tree
//
//  Created by Sebas Neira Gzz on 16/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "Node.hpp"
#include <iostream>
using namespace std;

template<class T>
class StackedList{
private:
    Node<T>* head;
    int size;
    
public:
    StackedList();
    T pop();
    void push(T data);
    T top();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
StackedList<T>::StackedList(){
    head = NULL;
    size = 0;
}


template<class T>
T StackedList<T>::pop(){
     if(!isEmpty()){
            T value = head->data;
            head = head->next;
            size--;
            return value;
        } else {
            throw runtime_error("La lista no contiene elementos");
        }
    }

template<class T>
void StackedList<T>::push(T data){
    head = new Node<T>(data, head);
    size++;
}

template<class T>
T StackedList<T>::top(){
    return head->data;
}

template<class T>
int StackedList<T>::getSize(){
    return size;
}


template<class T>
void StackedList<T>::clear(){
    Node<T>* aux = head;
    Node<T>* prev = head;
    while(aux != NULL){
        prev = aux;
        aux = aux->next;
        delete prev;
        size--;
    }
}
    
template<class T>
void StackedList<T>::print(){
    Node<T>* aux = head;
    for (int i = 0; i < size ; i++){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;

}

template<class T>
bool StackedList<T>::isEmpty(){
    return size == 0;
}



#endif /* Stack_h */
