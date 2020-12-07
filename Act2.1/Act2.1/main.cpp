//
//  main.cpp
//  Act2.1
//
//  Created by Sebas Neira Gzz on 11/09/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int busquedaSequencial(int num, string line){
    string var1, var2;
    int count = 0;
    int ctrl = 2;
    for (int i = 0 ; i < num ; i++){
        for (i = 0; i < line.size();i+= ctrl){
            var1 = line[i];
            var2 = line[i+1];
            
            if (var1 == var2){
                count++;
            } else {
                cout << var1 << " " << count << endl;
                break;
            }
        }
    }
    return 0;
}

int busquedaBinaria(int num, string line){
    
    return 0;
}


int main() {
    int n;
    string s;
    
    cout << "num"<< endl;
    cin >> n;
    
    cout << "str"<< endl;
    cin >> s;
    
    
    busquedaSequencial(n, s);
    

    return 0;
}
