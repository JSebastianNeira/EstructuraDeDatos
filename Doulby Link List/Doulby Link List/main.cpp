//
//  main.cpp
//  Doulby Link List
//
//  Created by Sebas Neira Gzz on 07/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "DoulbyList.hpp"
using namespace std;

int main() {
    
    //Inicialización lista
    DoulbyList<int> list;
    
    list.addFirst(45);
    list.addFirst(20);
    list.addFirst(100);
    
    list.addLast(70);
    list.addLast(90);
    list.addLast(10);
    
     //Main lista
    cout << "Lista:" << endl;
    list.print();
    cout << endl;
    
    
    //Modifaciones a la lista
    
    //list.deleteData(20); FUNCIONA
    
    //list.deleteAt(1); FUNCIONA, FALTA RUNTIME_ERROR!!
    
    /*cout << "\nGet Data:" << endl;
    try {
        cout << list.getData(0) << endl;   FUNCIONA
    } catch (exception& e){
        cout << e.what() << endl;
    }*/
    
    /*cout << "\nUpdate At:" << endl;
    try {
        list.updateAt(0, 200);              FUNCIONA
    } catch (exception& e){
       cout << e.what() << endl;
    }*/
    
    /*cout << "\nUpdate Data:" << endl;
    try {
        list.updateData(20, 200);           FUNCIONA
    } catch (exception& e){
       cout << e.what() << endl;
    }*/
    
    /*cout << "\nFind Data:" << endl;
    try {
        cout << list.findData(10)<< endl;   FUNCIONA
    } catch (exception& e){
        cout << e.what() << endl;
    }*/
    //list.insertAt(6, 8);                  FUNCIONA
    //list.clear();                         FUNCIONA
    list.sort();
    
    list.print();
    cout << endl;
    list.printTail();  // Imprime de tail para atras para comprobar que los prev se estan guardando correctamente.
    
    return 0;
}
