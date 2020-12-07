//
//  Heap.hpp
//  Heap
//
//  Created by Sebas Neira Gzz on 20/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include "DoulbyList.hpp"

template<class T>
class Heap{
private:
    DoulbyList<T> heap;
    int size;
    void downSort(int index);
    void swap(int a, int b);
    
public:
    Heap();
    Heap(DoulbyList<T> list);
    bool isEmpty();
    void print();
};

template<class T>
Heap<T>::Heap(){
    size = 0;
}

template<class T>
void Heap<T>::swap(int a, int b){
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template<class T>
void Heap<T>::downSort(int index){
    while(index >= 0){
        int pos = index;
        while (pos*2 <= size){
            int s1 = pos * 2 +1;
            int s2 = pos * 2 +2;
            int max;
            
            if (s2 > size){
                max = s1;
            } else {
                heap[s1] > heap[s2] ? max = s1 : max = s2;
            }
            
            if (heap[max] > heap[pos]){
                swap(pos,max);
                pos = max;
            } else{
                pos = size;
            }
        }
        index --;
    }
}

template<class T>
Heap<T>::Heap(DoulbyList<T> list){
    if(!list.isEmpty()){
        heap = list;
        size = heap.getSize();
        int index = size/2;
        downSort(index);
        
    } else {
        size = 0;
    }
}


template<class T>
bool Heap<T>::isEmpty(){
    return size == 0;
}

template<class T>
void Heap<T>::print(){
    heap.print();
}


#endif
