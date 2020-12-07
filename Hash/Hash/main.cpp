//
//  main.cpp
//  Hash
//
//  Created by Sebas Neira Gzz on 27/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "HashTableQ.h"
#include "HashTableC.h"
using namespace std;


int main() {
    vector<string> list = {"aaaa", "bbbb", "acac", "abab", "dddd", "dada", "cdcd", "eeee", "dede", "ffff", "efef"};
    
    HashTableQ hashQ(list);
    hashQ.print();
    
    cout << endl;
    HashTableC hashC(list);
    hashC.print();
    
    
    return 0;
}
