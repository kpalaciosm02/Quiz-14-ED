#include "node.hpp"

#ifndef SPLAYTREE
#define SPLAYTREE

class splayTree{
    node * root;
    splayTree(){
        root = NULL;
    }
    splayTree(int _key){
        root = new node(_key);
    }
    void insert(int number){
        
    }
};

#endif