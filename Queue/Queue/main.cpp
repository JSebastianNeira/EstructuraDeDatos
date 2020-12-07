//
//  main.cpp
//  Queue
//
//  Created by Sebas Neira Gzz on 01/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "QueuedList.h"

int main() {
    QueuedList<int> list;
    
    list.enqueue(10);
    list.enqueue(20);
    list.enqueue(30);
    list.print();
    
    list.dequeue();
    list.print();
    
    list.enqueue(40);
    list.print();
    
    
    cout << list.front() << endl;
    cout << list.back() << endl;
    
    cout << list.getSize()<< endl;
    //list.clear();
    list.print();
    
    
    return 0;
}
