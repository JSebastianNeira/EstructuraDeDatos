//
//  Node.hpp
//  Binary Tree
//
//  Created by Sebas Neira Gzz on 06/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#pragma once

#include <stdio.h>

template<class T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data);
    Node(T data, Node<T>* left, Node<T>* right);
};

template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* left, Node<T>* right){
    this->data = data;
    this->left = left;
    this->right = left;
}
