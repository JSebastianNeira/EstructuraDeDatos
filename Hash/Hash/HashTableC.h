//
//  HashTableC.h
//  Hash
//
//  Created by Sebas Neira Gzz on 01/12/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef HashTableC_h
#define HashTableC_h

#include <vector>
#include <string>
#include <math.h>
using namespace std;

class HashTableC{
private:
    vector< vector<string> > table;
    int size;
    int qty;
    int hashing(string str);
    bool alreadyExists(vector<string> collisions, string str);
    bool isFull();
    
public:
    HashTableC(int size);
    HashTableC(vector<string> list);
    void addStr(string str);
    void deleteStr(string str);
    bool findStr(string str);
    void print();
    
    
};

HashTableC::HashTableC(int size){
    this->size = size;
    qty = 0;
    vector< vector<string> > tempTable(size);
    table = tempTable;
    
}

HashTableC::HashTableC(vector<string> list){
    qty = 0;
    size = list.size();
    vector< vector<string> > tempTable(size);
    table = tempTable;
    for(auto str : list){
        addStr(str);
    }
}



void HashTableC::addStr(string str){
    if(!isFull()) {
        int index = hashing(str);
        if(!alreadyExists(table[index], str)){
            table[index].push_back(str);
            qty++;
        }
    } else{
        throw out_of_range("La tabla ya esta llena");
    }
}

                       
bool HashTableC::alreadyExists(vector<string> collisions, string str) {
    typename vector<string>:: iterator it;
    it = find(collisions.begin(), collisions.end(), str);
    if(it != collisions.end()) {
        return true;
    } else {
        return false;
    }
}

bool HashTableC::findStr(string str){
    int index = hashing(str);
    return alreadyExists(table[index], str);
}



int HashTableC::hashing (string str){
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

bool HashTableC::isFull(){
    return qty == size;
}

void HashTableC::print() {
    cout << "Hash Table" << endl;
    for(int i =0; i< size; i++){
        cout << i << ": ";
        for(auto str : table[i]) {
            cout << str << " ";
        }
        cout << endl;
    }
}

#endif /* HashTableC_h */
