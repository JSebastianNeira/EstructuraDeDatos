//
//  node.hpp
//  clase12
//
//  Created by Sebas Neira Gzz on 25/09/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#pragma once

#include <stdio.h>

template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node(T data);
    Node(T data, Node<T>* next);
};

template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}


