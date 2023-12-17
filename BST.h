#ifndef PROJECT2__BST_H
#define PROJECT2__BST_H
#include <iostream>
#include <string>

struct Node{
    Node* left;
    Node*right;
    std::string ky;

    Node(std::string vl):ky(vl),left(nullptr),right(nullptr){}
};
class Bst{
private:
    Node* root;
    Node*insertuse(Node* node,std::string ky){// this is helper funtion to search for specific key in BTS
        if(node== nullptr){
            return new Node(ky);
        }
        else if (ky>node->ky){
            node->right= insertuse(node->right,ky);
        }
        return node;
    }
    bool searchuse(Node*node,std::string ky){ // in my funtion this is the helper function search for specific key
        if (node== nullptr){
            return false;
        }
        if(node->ky==ky){
            return true;
        }
        else if(ky<node->ky){
            return searchuse(node->left,ky);
        }
        else{
            return searchuse(node->right,ky);
        }
    }
public:
    Bst():root(nullptr){}
    void insert(std::string ky){
        root= insertuse(root,ky);
    }
    bool search (std::string ky){
        return searchuse(root,ky);
    }
};



#endif
