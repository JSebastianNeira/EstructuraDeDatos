//
//  EjemploHeap.cpp
//  Heap
//
//  Created by Sebas Neira Gzz on 20/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#include "Heap.hpp"

int main(){
    
    DoulbyList<int> list;
    list ={8,5,17,19,21,28};
    
    Heap<int> heap(list);
    
    heap.print();
    return 0;
}
