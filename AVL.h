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
    node* turningleft(node*a){
        node* b=a->rightside;
        node* t=b->leftside;
        b->leftside=a;
        a->rightside=t;
        a->height=std::max(getheight(a->leftside), getheight(a->rightside))+1;
        b->height=std::max(getheight(b->leftside), getheight(b->rightside))+1;
        return b;
    }
    node*insertuse(node* Node,std::string ky){
        if (Node== nullptr){
            return new node(ky);
        }
        if (ky < Node->ky){
            Node->leftside= insertuse(Node->leftside,ky);
        }
        else if (ky>Node->ky){
            Node->rightside= insertuse(Node->rightside,ky);
        }
        else{
            return Node;
        }
        Node->height=1+std::max(getheight(Node->leftside), getheight(Node->rightside));
        int bln= getbalance(Node);
        if(bln>1&& ky<Node->leftside->ky){
            return turningright(Node);
        }
        if(bln< -1 && ky>Node->rightside->ky){
            return turningleft(Node);
        }
        if(bln>1&&ky>Node->leftside->ky){
            Node->leftside= turningleft(Node->leftside);
            return turningright(Node);
        }
        if (bln<-1&&ky<Node->rightside->ky){
            Node->rightside= turningright(Node->rightside);
            return turningleft(Node);
        }
        return Node;
    }
    bool searchuse(node* Node,std::string ky){
        if(Node== nullptr){
            return false;
        }
        if(Node->ky==ky){
            return searchuse(Node->leftside,ky);
        }
        else{
            return searchuse(Node->rightside,ky);
        }
    }





};


#endif
