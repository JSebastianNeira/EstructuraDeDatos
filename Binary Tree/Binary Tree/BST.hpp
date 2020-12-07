//
//  BST.hpp
//  Binary Tree
//
//  Created by Sebas Neira Gzz on 06/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
using namespace std;

template<class T>
class BST{
private:
    Node<T>* root;
    void printTree(Node<T>*aux, int level);
    int howManyChilds(Node<T>* aux);
    void preOrder(Node<T>*aux);
    void inOrder(Node<T>*aux);
    void postOrder(Node<T>*aux);
    void levelByLevel();
    
    
public:
    BST();
    void visit(int order);
    void insert(T data);
    void deleteNode(T data);
    Node<T>* findNode(Node<T>*aux, T data);
    void ancestors(T data);
    int whatLevelAmI(T data);
    int height(Node<T>* node);
    int heightBST();
    int childs(Node<T>* node);
    bool find(T data);
    bool isEmpty();
    void print();
    
};

template<class T>
BST<T>::BST(){
    root = NULL;
}

template<class T>
void BST<T>:: insert(T data){
    if (isEmpty()){
        root = new Node<T>(data);
    } else{
        Node<T>* aux = root;
        
        while (aux != NULL){
            if(data < aux->data){
                if(aux->left == NULL){
                    aux->left = new Node<T>(data);
                    return;
                } else{
                    aux = aux->left;
                }
            } else {
                if (aux->right == NULL){
                    aux->right = new Node<T>(data);
                    return;
                } else{
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
int BST<T>::howManyChilds(Node<T>* aux){
    int childs = 0;
    aux->left != NULL ? childs++ : childs=childs;
    aux->right != NULL ? childs++ : childs=childs;
    
    return childs;
}

template <class T>
Node<T>* BST<T>::findNode(Node<T>* aux,T data){
    
    if(aux->data == data){
        return aux;
    }
    
    if (data < aux->data){
        aux = findNode(aux->left, data);
    } else{
        aux = findNode(aux->right, data);
    }
    
    return aux;
}

template <class T>
bool BST<T>::find(T data){
    Node<T>* aux = root;
    Node<T>* node = NULL;
    
    node = findNode(aux, data);
    
    if (node->data == data) {
        return true;
    }
    
    return false;
}


template<class T>
void BST<T>::deleteNode(T data){
    if(!isEmpty()){
        Node<T>* father = root;
        Node<T>* aux = father;
        bool found = false;
        
        while(aux != NULL && !found){
            if(data == aux->data){
                found = true;
            } else{
                father = aux;
                data < aux->data ? aux = aux->left : aux = aux->right;
            }
            
            if (found){
                switch (howManyChilds(aux)) {
                    case 0:{
                        if(aux == root){
                            delete aux;
                            root = NULL;
                        } else{
                            data < father->data ? father->left = NULL : father->right = NULL;
                            delete aux;
                        }}
                        break;
                    case 1:{
                        if (aux == root){
                            root->left != NULL ? root = root->left : root = root->right;
                        } else{
                            if(data < father->data){
                                aux->left != NULL ? father->left = aux->left : father->right = aux->right;
                            } else{
                                aux->left != NULL ? father->right = aux->left : father->left = aux->right;
                            }
                        }
                        delete aux;}
                        break;
                    case 2:{
                        Node<T>* father = aux;
                        Node<T>* max = aux->left;
                        
                        if(max->right == NULL){
                            aux->data = max->data;
                            father->left = max->left;
                            delete max;
                        } else{
                            bool found = false;
                            while(!found){
                                if(max->right == NULL){
                                    found = true;
                                } else{
                                    father = max;
                                    max = max->right;
                                }
                            }
                            aux->data = max->data;
                            father->right = max->left;
                            delete max;
                        }}
                        break;
                        
                    default:
                        break;
                }
            }
        }
    }
}


template<class T>
void BST<T>:: preOrder(Node<T> *aux){
    if (aux != NULL){
        cout << aux->data << " ";
        preOrder(aux->left);
        preOrder(aux->right);
    }
}

template<class T>
void BST<T>:: inOrder(Node<T> *aux){
    if (aux != NULL){
        inOrder(aux->left);
        cout << aux->data << " ";
        inOrder(aux->right);
    }
}

template<class T>
void BST<T>:: postOrder(Node<T> *aux){
    if (aux != NULL){
        postOrder(aux->left);
        postOrder(aux->right);
        cout << aux->data << " ";
    }
}

template<class T>
void BST<T>:: levelByLevel(){
    if(!isEmpty()){
        QueuedList<Node<T>> queue;
        queue.enqueue(root);
        while (!queue.isEmpty()){
            Node<T>* aux = queue.dequeue();
            cout << aux->data << " ";
            if(aux->left != NULL){
                queue.enqueue(aux->left);
            }
            if(aux->right != NULL){
                queue.enqueue(aux->right);
            }
        }
    }
}

template<class T>
void BST<T>:: visit(int order){
    switch(order){
        case 1:
            preOrder(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 4:
            levelByLevel();
            break;
        case 5:
            height(root);
            break;
    }
    cout << endl;
}


template<class T>
void BST<T>:: printTree(Node<T>*aux, int level){
    if(aux != NULL){
        printTree(aux->right,level+1);
        for (int i = 0; i<level;i++){
            cout << "   ";
        }
        cout << aux->data << endl;
        printTree(aux->left, level+1);
    }
}

template<class T>
int BST<T>::height(Node<T>* node){
    int h = 0;
    int l,r;
    if(node != NULL){
        h++;
        l = height(node->left);
        r = height(node->right);
        (l > r) ? h += l : h += r;
    }
    return h;
}


template<class T>
int BST<T>:: heightBST(){
    return height(root);
}



template<class T>
void BST<T>::ancestors(T data){
    if(!isEmpty()){
        Node<T>* aux = root;
        StackedList<T> stack;
        if(aux->data != data){
            bool notFound = false;
            while(aux->data != data && notFound){
                stack.push(aux->data);
                if(data < aux->data){
                    if(aux->left == NULL){
                        notFound = true;
                    } else{
                        aux = aux->left;
                    }
                } else{
                    if(aux->right == NULL){
                        notFound = true;
                    } else{
                        aux = aux->right;
                    }
                }
            }
            if(!notFound){
                while(!stack.isEmpty()){
                    try{
                        T data = stack.pop();
                        cout << data << " ";
                    } catch (runtime_error& e){
                        cout << e.what() << endl;
                    }
                }
            }
        } else{
            cout << data << "has no ancestors" << endl;
        }
    } else{
        cout << "The BST is empty" << endl;
    }
}

template<class T>
int BST<T>::whatLevelAmI(T data){
    int level = 0;
    if (!isEmpty()){
        Node<T>* aux = root;
        if(aux->data != data){
            bool notFound = false;
            while(aux->data != data && !notFound){
                level ++;
                if(data < aux->data){
                    if(aux->left == NULL){
                        notFound = true;
                    } else {
                        aux = aux->left;
                    }
                } else{
                    if(aux->right == NULL){
                        notFound = true;
                    } else{
                        aux = aux->right;
                    }
                }
            }
            if(!notFound){
                level++;
            } else{
                level = -1;
            }
        } else{
            level = -1;
        }
    } else{
        level = -1;
    }
    return level;
}


template<class T>
void BST<T>:: print(){
    int level = 0;
    Node<T> * aux = root;
    cout << endl;
    printTree(aux,level);
    cout << endl;
}


template<class T>
bool BST<T>:: isEmpty(){
    return root == NULL;
}

#endif /* BST_h */
