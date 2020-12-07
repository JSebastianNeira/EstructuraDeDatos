//
//  main.cpp
//  Stack
//
//  Created by Sebas Neira Gzz on 01/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "StackedList.h"

int main() {
    StackedList<int> list;
    list.push(10);
    list.push(11);
    list.push(15);
    
    
    
    list.print();
    
    list.pop();
    list.print();
    
    list.getSize();
    
    list.top();
    
    list.clear();
    
    list.print();
    
    
    return 0;
}
