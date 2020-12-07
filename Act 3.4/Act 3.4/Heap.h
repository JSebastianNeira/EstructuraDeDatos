#ifndef Heap_h
#define Heap_h

#include "DLL.h"

template<class T>
class Heap {
private:
    DoublyLinkedList<T> heap;
    int size;
    void downSort(int index);
    void upSort();
    void swap(int a, int b);
public:
    Heap();
    Heap(DoublyLinkedList<T> list);
    T remove();
    void insert(T data);
    bool isEmpty();
    void print();
};

template<class T>
Heap<T>::Heap() {
    size = 0;
}

template<class T>
void Heap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template<class T>
void Heap<T>::downSort(int index) {
    while (index >= 1) {
        int pos = index;
        while (pos*2<=size) {
            int s1 = pos * 2;
            int s2 = pos * 2 + 1;
            int max;
            if (s2 > size) {
                max = s1;
            } else {
                heap[s1] > heap[s2] ? max = s1 : max = s2;
            }
            if (heap[max] > heap[pos]) {
                swap(pos,max);
                pos = max; // Para comparar el hijo con sus hijo
            } else {
                pos = size; // Salir del ciclo
            }
        }
        index--;
    }
}

template<class T>
Heap<T>::Heap(DoublyLinkedList<T> list) {
    if (!list.isEmpty()) {
        heap = list;
        size = heap.getSize();
        int index = size / 2;
        downSort(index);
    } else {
        size = 0;
    }
}

template<class T>
T Heap<T>::remove(){
    if(!isEmpty()){
        T aux = heap[1];
        swap(1,size);
        heap.deleteLast();
        size--;
        downSort(1);
        return aux;
    }
    throw runtime_error("El Heap esta vacio");
}

template<class T>
void Heap<T>::upSort(){
    int pos = size;
    while(pos > 1){
        int father = pos/2;
        if (heap[pos] > heap[father]){
            swap(father, pos);
            pos = father;
        } else{
            pos = 1; //para salir del ciclo
        }
    }
}

template<class T>
void Heap<T>::insert(T data){
    heap.addLast(data);
    size++;
    upSort();
}

 
template<class T>
bool Heap<T>::isEmpty() {
    return size == 0;
}

template<class T>
void Heap<T>::print() {
    heap.print();
}

#endif
