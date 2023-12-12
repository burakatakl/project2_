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



#endif //PROJECT2__AVL_H
