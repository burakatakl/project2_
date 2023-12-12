#ifndef PROJECT2__AVL_H
#define PROJECT2__AVL_H
#include <iostream>
#include <string>
#include <algorithm>

struct node{
    std::string ky;
    node* leftside;
    node* rightside;
    int height;

    node(std::string value) : ky(value),leftside(nullptr),rightside(nullptr),height(1){}

};

class avl{
private:
    node* root;
    int getheight(node* node){
        if(node== nullptr){
            return 0;
        }
        return node ->height;
    }
    int getbalance(node* node){
        if(node == nullptr){
            return 0;
        }
        return getheight(node ->leftside)- getheight(node->rightside);
    }
    node* turningright(node* b){
        node* a=b->leftside;
        node* t=a->rightside;
        a->rightside=b;
        b->leftside=t;
        b->height=std::max(getheight(b->leftside), getheight(b->rightside))+1;
        a->height=std::max(getheight(a->leftside), getheight(a->rightside))+1;
        return a;
    }


};


#endif //PROJECT2__AVL_H
