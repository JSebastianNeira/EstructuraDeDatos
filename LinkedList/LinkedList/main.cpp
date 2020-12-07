//
//  main.cpp
//  clase12
//
//  Created by Sebas Neira Gzz on 25/09/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main(){
    LinkedList<int> list;
    LinkedList<int> listVacia;
    
    list.addLast(100);
    
    list.addFirst(40);
    list.addFirst(15);
    list.addFirst(1);
    list.addLast(200);
    list.addLast(300);
    list.print();
    
    cout << "\nFind Data:" << endl;
    try {
        list.findData(1);
    } catch (exception& e){
        cout << e.what() << endl;
    }
    
    cout << "\nDelete Data:" << endl;
    if (list.deleteData(25)){
        cout << "Si se pudo borrar" << endl;
    } else {
        cout << "No se pudo borrar" << endl;
    }
    list.print();
    
    cout << "\nDelete At:" << endl;
    if (list.deleteAt(1)){
        cout << "Si se pudo borrar" << endl;
    } else {
        cout << "No se pudo borrar" << endl;
    }
    list.print();
    
    cout << "\nGet Data:" << endl;
    try {
        list.getData(1);
    } catch (exception& e){
        cout << e.what() << endl;
    }
    
    cout << "\nSobreCarga []:" << endl;
    try {
        list[1];
    } catch (exception& e){
        cout << e.what() << endl;
    }
    
    cout << "\nUpdate At:" << endl;
    try {
        list.updateAt(1, 200);
    } catch (exception& e){
       cout << e.what() << endl;
    }
    
    
    cout << "\nUpdate Data:" << endl;
    try {
        list.updateData(25, 200);
    } catch (exception& e){
       cout << e.what() << endl;
    }
    
    
    cout << "\nSobreCarga =:" << endl;
    try {
        listVacia = {1,2,3,4,5};
    } catch (exception& e){
       cout << e.what() << endl;
    }
    list.print();
    
    cout << "\nInsert At:" << endl;
    try {
        list.insertAt(4, 10);
    } catch (exception& e){
        cout << e.what() << endl;
    }
    
    list.clear();
    list.sort();
    list.duplicate();
    list.reverse();
    
    list.duplicate();
    list.print();
    
    list.removeDuplicates();
    list.print();

    
    
    return 0;
}

