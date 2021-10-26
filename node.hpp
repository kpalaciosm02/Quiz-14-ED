#include <iostream>
using namespace std;
#ifndef NODE
#define NODE

class node{
    private:
        int key;
        node * left, * right;
    public:
        void set_key(int _key){
            key = _key;
        }
        void set_left(node * tmp){
            left = tmp;
        }
        void set_right(node * tmp){
            right = tmp;
        }
        int get_key(){
            return key;
        }
        node * get_left(){
            return left;
        }
        node * get_right(){
            return right;
        }
        node(int _key){
            key = _key;
            left = NULL;
            right = NULL;
        }
};

#endif