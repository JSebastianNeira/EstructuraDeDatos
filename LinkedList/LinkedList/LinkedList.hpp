//
//  LinkedList.hpp
//  clase12
//
//  Created by Sebas Neira Gzz on 25/09/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include "node.hpp"
#include <iostream>
using namespace std;

template<class T>
class LinkedList{
private:
    Node<T>* head;
    int size;
    
public:
    LinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool deleteData(T data);
    bool deleteAt(int pos);
    T getData(int pos);
    void updateAt(int pos, T data);
    void updateData(T dataBuscar, T data);
    int findData(T data);
    
    
    
    
    void insertAt(int pos, T data);
    void clear();
    void merge(int ini, int med, int fin);
    void mergeSort(int ini, int fin);
    void sort();
    void duplicate();
    void removeDuplicates();
    void reverse();
    
    

    void operator=(LinkedList<T> list);
    T& operator[](int pos);
    void operator=(initializer_list<T> list);
    
    bool isEmpty();
    void print();
    
};

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

template <class T>
T& LinkedList<T>::operator[](int pos){
    if (pos < 0 || pos >= size){
        throw out_of_range("Posición invalida");
    } else{
        Node<T>* aux = head;
        if (pos == 0){
            return aux->data;
        } else {
            for (int i = 0; i < pos; i++){
            aux = aux->next;
            }
            return aux->data;
        }
    }
}

template <class T>
void LinkedList<T>::operator=(initializer_list<T> list){
    if (!isEmpty()){
        for (T i : list){
            addLast(i);
        }
    } else{
        throw runtime_error("Error: Linked List no esta vacia");
    }
}

template <class T>
void LinkedList<T>::operator=(LinkedList<T> list){
    clear();
    for(int i = 0;i<list.size;i++){
        addLast(list[i]);
    }
}

template<class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template<class T>
void LinkedList<T>::addLast(T data){
    if(!isEmpty()){
        Node<T>* aux = head;
        while (aux->next != NULL){
            aux = aux->next;
           }
        aux->next = new Node<T>(data);
    } else {
        head = new Node<T>(data);
    }
    size++;
}

template<class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        if(head->data == data){
            Node<T>* aux = head;
            head = aux->next;
            delete aux;
            size--;
            return true;
        } else{
            if(head->next != NULL){
                Node<T>* aux = head->next;
                Node<T>* prev = head;
                
                while(aux->next != NULL){
                    if (aux->data == data){
                        prev->next = aux->next;
                        delete aux;
                        size --;
                        return true;
                    } else{
                        prev = aux;
                        aux = aux->next;
                    }
                }
                
                if (aux->data == data){
                    prev->next = aux->next;
                    delete aux;
                    size --;
                    return true;
                } else {
                    return false;
                }
                
            } else {
                return false;
            }
        }
        
    } else {
        return false;
    }
}

template<class T>
bool LinkedList<T>::deleteAt(int pos){
    if (pos >= 0 && pos < size){
        if(!isEmpty()){
            if(pos == 0){
                Node<T>* aux = head;
                head = aux->next;
                delete aux;
                size--;
                return true;
            }else {
                Node<T>* aux = head->next;
                Node<T>* prev = head;
                for (int i = 0; i < pos-1; i++){
                    prev = aux;
                    aux = aux->next;
                }
                prev->next = aux->next;
                delete aux;
                size --;
                return true;
            }
        }
    } else{
        return false;
    }
    return false; //DUDA CON ESTO
}

template<class T>
T LinkedList<T>::getData(int pos){
    if (pos < 0 || pos >= size){
        throw out_of_range("Posición invalida");
    } else{
        Node<T>* aux = head;
        if (pos == 0){
            return aux->data;
        } else {
            for (int i = 0; i < pos; i++){
            aux = aux->next;
            }
            return aux->data;
        }
    }
}

template<class T>
void LinkedList<T>::updateAt(int pos, T data){
    if (pos < 0 || pos >= size){
        throw out_of_range("Posición invalida");
    } else{
        if (pos == 0){
            head->data = data;
        } else {
            Node<T>* aux = head;
            for (int i = 0; i < pos; i++){
            aux = aux->next;
            }
            aux->data = data;
        }
    }
}

template<class T>
void LinkedList<T>::updateData(T dataBuscar, T data){
    Node<T>* aux = head;
    bool encontrado = false;
    for (int i = 0; i < size; i++){
        if (aux->data == dataBuscar){
            aux->data = data;
            encontrado = true;
        } else {
            aux = aux->next;
        }
    }
    
    if (!encontrado){
        throw out_of_range("El dato no se encuentra en la lista");
    } else{
        print();
    }
}

template<class T>
int LinkedList<T>::findData(T data){
    int posI = 0;
    int posF = size-1;
    int posM = (posI + posF) / 2;
    bool found = false;
    
    while (posI<=posF && !found){
        if (data < getData(posM)){
            posF = posM-1;
        } else{
            if (data > getData(posM)){
                posI = posM + 1;
            } else{
                if (data == getData(posM))
                    found = true;
            }
        }
        posM = (posI + posF) / 2;
    }
    
    if (found){
        return posM;
    } else {
        throw runtime_error("Elemento no encontrado");
    }
}


template<class T>
void LinkedList<T>::insertAt(int pos, T data){
    if (pos >= 0 && pos < size){
        if(!isEmpty()){
            if(pos == 0){
                head = new Node<T>(data, head);
                size++;
            }else {
                Node<T>* aux = head->next;
                Node<T>* prev = head;
                for (int i = 0; i < pos-1; i++){
                    prev = aux;
                    aux = aux->next;
                }
                Node<T>* nuevo = new Node<T>(data, aux);
                prev->next = nuevo;
                size ++;
            }
        }
    }
    print();
}

template<class T>
void LinkedList<T>::clear(){
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
void LinkedList<T>::merge(int ini, int mid, int fin){
    LinkedList<T> listL;
    LinkedList<T> listR;
    int pos,f1,f2,i,j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;
    
    for(i = 0; i<f1;i++){
        listL.addLast(getData(ini+i));
        listL.print();
    }
    for(j = 0; j<f2;j++){
        listR.addLast(getData(ini+j));
        listR.print();
    }
    i = 0;
    j = 0;
    
    while(i<f1 && j<f2){
        if (listL[i] <= listR[j]){
            updateAt(pos, listL[i]);
            i++;
        } else{
            updateAt(pos, listR[j]);
            j++;
        }
        pos++;
    }
    while (i<f1){
        updateAt(pos, listL[i]);
        i++;
        pos++;
    }
    while (j<f2){
        updateAt(pos, listR[j]);
        j++;
        pos++;
    }
}

template<class T>
void LinkedList<T>::mergeSort(int ini, int fin){
    if(ini < fin){
        int mid = (ini + fin)/2;
        mergeSort(ini, mid);
        mergeSort(mid+1, fin);
        
        merge(ini,mid,fin);
    }
}

template<class T>
void LinkedList<T>::sort(){
    mergeSort(0,size-1);
}

template<class T>
void LinkedList<T>::duplicate(){
    Node<T>* aux = head;
    while(aux != NULL){
        aux->next = new Node<T>(aux->data,aux->next);
        aux = aux->next->next;
        size ++;
    }
}


template<class T>
void LinkedList<T>::removeDuplicates(){
    Node<T>* aux = head;
    LinkedList<T> copy = *this;
    clear();
    for(int i = 0;i<copy.size;i++){
        if(!findData(aux->data)){
            addLast(aux->data);
        }
    }
}

template<class T>
void LinkedList<T>::reverse(){
    LinkedList<T> list;
    Node<T>* aux = head;
    
    while(aux!=NULL){
        list.addFirst(aux->data);
        aux = aux->next;
    }
    *this = list;
}




template<class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template<class T>
void LinkedList<T>::print(){
    Node<T>* aux = head;
    for (int i = 0; i < size ; i++){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
    
}




#endif /* LinkedList_hpp */
