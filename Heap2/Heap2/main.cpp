//
//  main.cpp
//  Heap2
//
//  Created by Sebas Neira Gzz on 20/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "Heap.h"

template<class T>
void HeapSort(DoublyLinkedList<T> &list, string order = "ascending"){
    if(!list.isEmpty()){
        Heap<T> heapAux(list);
        list.clear();
        while (!heapAux.isEmpty()){
            T aux = heapAux.remove();
            if (order == "ascending"){
                list.addFirst(aux);
            } else {
                list.addLast(aux);
            }
            
        }
    }
}

int main() {
    DoublyLinkedList<int> list;
    
    list = {8,5,17,19,21,28};
    
    Heap<int> heap(list);
    heap.print();
    cout << endl;
    
    /*
    try{
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        cout << "The number: " << heap.remove() << " was removed from Heap" << endl;
        
    } catch (runtime_error& e){
        cout << endl << e.what() << endl << endl;
    }
    
    cout << endl << "Heap Sort Ascending" << endl;
    HeapSort(list);
    list.print();*/
    
    cout << endl << "Heap Sort Descending" << endl;
    HeapSort(list,"descending");
    list.print();
    
    heap.insert(30);
    cout << endl;
    heap.print();
    
    
   
    return 0;
}
