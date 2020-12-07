//
//  main.cpp
//  Binary Tree
//
//  Created by Sebas Neira Gzz on 06/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "BST.hpp"
using namespace std;

int main() {
    
    BST<int> bst;
    
    bst.insert(50);
    bst.insert(80);
    bst.insert(60);
    bst.insert(90);
    bst.insert(20);
    bst.insert(40);
    bst.insert(10);
    bst.insert(5);
    
    bst.print();
    bst.deleteNode(50);
    
    bst.print();
    
    if (bst.find(20)){
       cout<< "Si lo encontre "<< endl;
    } else{
        cout<< "No lo encontre "<< endl;
    }
    
    /*bst.visit(1);
    bst.visit(2);
    bst.visit(3);*/

    
    
}
