//
//  HashTableO.h
//  Hash
//
//  Created by Sebas Neira Gzz on 27/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef HashTableQ_h
#define HashTableQ_h

#include <vector>
#include <string>
#include <math.h>
using namespace std;

class HashTableQ{
private:
    vector<string> table;
    vector<int> status; // 0- vacio, 1- ocupado, 2- borrado
    int size;
    int qty;
    int findStr(string str);
    int hashing(string str);
    bool isFull();
    int quadProbe(int index, int cont);
    
public:
    HashTableQ(int size);
    HashTableQ(vector<string> list);
    void addStr(string str);
    void deleteStr(string str);
    void print();
    
    
};

HashTableQ::HashTableQ(vector<string> list){
    qty = 0;
    size = list.size();
    vector<string> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size, 0);
    status = tempStatus;
    for(auto str : list){
        addStr(str);
    }
    
}

HashTableQ::HashTableQ(int size){
    this->size = size;
    vector<string> tempList(size);
    table = tempList;
    vector<int> tempStatus(size,0);
    status = tempStatus;
    
}

void HashTableQ::addStr(string str){
    if(!isFull()) {
        int index = hashing(str);
        if(status[index] == 0 || status[index] == 2){ //Revisar si esta vacio
            table[index] = str;
            status[index] = 1; //Ocupado
            qty++;
        } else {
            // Validar si ya existe
            int cont = 1;
            int newIndex = quadProbe(index, cont); //Cálculo del nuevo índice
            
            while(status[newIndex] == 1){ //Esta ocupado
                if(str == table[newIndex ]){ //Validar si ya existe
                    throw runtime_error("El valor ya existe en la tabla");
                }
                cont ++;
                newIndex = quadProbe(index, cont);
            }
            table[newIndex] = str;
            status[newIndex] = 1; //Ocupado
            qty++;
        }
    } else{
        throw out_of_range("La tabla ya esta llena");
    }
}

int HashTableQ::findStr(string str){
    int cont = 1;
    int index = hashing(str);
    while (status[index] != 0 && cont < size){
        if(status[index] == 1 && table[index] == str){
            return index;
        }
        index = quadProbe(index, cont);
        cont++;
    }
    return -1;
}

int HashTableQ::quadProbe(int index, int cont){
    return fmod(index + int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)), size);
}

int HashTableQ::hashing (string str){
    int len = str.length();
    int key;
    
    if (len == 1) {
        key = int(str[0]);
    } else{
        if (len == 2) {
            key = int(str[0]) + int(str[1]);
        } else {
            if (len >= 3) {
                key = int(str[1] + int(str[2]));
            }
        }
    }
    
    return key % size;
}

bool HashTableQ::isFull(){
    return qty == size;
}

void HashTableQ::print() {
    cout << "Hash Table" << endl;
    for(auto str : table){
        cout << str << endl;
    }
}

#endif /* HashTableQ_h */
