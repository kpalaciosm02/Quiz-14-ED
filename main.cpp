#include "node.hpp"

node * newNode(int k){
    //Creates node
    node * Node = new node(k);
}

node * rightRotation(node * x){
    //rotates a node from a tree to make it flatter
    node * y = x->get_left();
    x->set_left(y->get_right());
    y->set_right(x);
    return y;
}

node * leftRotation(node * x){
    //rotates a node from a tree to make it flatter
    node * y = x->get_right();
    x->set_right(y->get_left());
    y->set_left(x);
    return y;
}

node * splay(node * root, int k){
    //searches through different cases to decide which rotation is needed
    if (root == NULL || root->get_key() == k)
        return root;
    if (root->get_key() > k){
        if (root->get_left() == NULL){
            return root;
        }
        if (root->get_left()->get_key() > k){
            root->get_left()->set_left(splay(root->get_left()->get_left(), k));
            root = rightRotation(root);
        }
        else if (root->get_left()->get_key() < k){
            root->get_left()->set_right(splay(root->get_left()->get_right(), k));
            if (root->get_left()->get_right() != NULL){
                root->set_left(leftRotation(root->get_left()));
            }
        }
        return (root->get_left() == NULL)? root: rightRotation(root);
    }
    else {
        if (root->get_right() == NULL){
            return root;
        }
        if (root->get_right()->get_key() > k){
            root->get_right()->set_left(splay(root->get_right()->get_left(), k));
            if (root->get_right()->get_left() != NULL){
                root->set_right(rightRotation(root->get_right()));
            }
        }
        else if (root->get_right()->get_key() < k){
            root->get_right()->set_right(splay(root->get_right()->get_right(),k));
            root = leftRotation(root);
        }
        return (root->get_right() == NULL)? root: leftRotation(root);
    }
}

node * insert(node * root, int k){
    //Inserts in a tree keeping it ordered
    if (root == NULL){
        return newNode(k);
    }
    root = splay(root, k);
    if (root->get_key() == k){
       return root; 
    }
    node * nNode = newNode(k);
    if (root->get_key() > k){
        nNode->set_right(root);
        nNode->set_left(root->get_left());
        root->set_left(NULL);
    }
    else{
        nNode->set_left(root);
        nNode->set_right(root->get_right());
        root->set_right(NULL);
    }
    return nNode;
}

void printTree(node * root){
    //prints tree (very ugly)
    if (root != NULL){
        cout << root->get_key() << "[";
        printTree(root->get_left());
        cout << "][";
        printTree(root->get_right());
        cout << "]";
    }
}

node *search(node *root, int k){
    //searches a numer in the tree and puts it on the root (reorders the tree)
    return splay(root, k);
}

int main(){
    node * root = newNode(100);
    root->set_left(newNode(50));
    printTree(root);
    cout << endl;
    root = insert(root,25);
    printTree(root);
    cout << endl;
    root = insert(root,115);
    printTree(root);
    cout << endl;
    root = insert(root,5);
    printTree(root);
    cout << endl;
    root = insert(root,7);
    printTree(root);
    cout << endl;
    root = insert(root,123);
    printTree(root);
    cout << endl << "Searching key 7: " << endl;
    root = search(root, 7);
    printTree(root);
    cout << endl << "Searching key 140: " << endl;
    root = search(root, 7);
    printTree(root);
    cout << endl;
    cout << "Tree did not change because 140 is not in it." << endl;
    return 0;
}