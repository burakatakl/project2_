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
        b->leftside=t;
        a->rightside=b;//rotation
        b->height=std::max(getheight(b->leftside), getheight(b->rightside))+1;
        a->height=std::max(getheight(a->leftside), getheight(a->rightside))+1;
        return a;//this funtiun for i am always uptating height
    }
    node* turningleft(node*a){
        node* b=a->rightside;
        node* t=b->leftside;
        a->rightside=t;//rotation
        b->leftside=a;
        a->height=std::max(getheight(a->leftside), getheight(a->rightside))+1;
        b->height=std::max(getheight(b->leftside), getheight(b->rightside))+1;
        return b;// and again i am uptating height
    }
    node*insertuse(node* Node,std::string ky){// i am adding standart bst tree
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
        }//uptating for height
        Node->height=1+std::max(getheight(Node->leftside), getheight(Node->rightside));
        int bln= getbalance(Node);  // i am taking balance factor
        if(bln>1&& ky<Node->leftside->ky){
            return turningright(Node);// left left sititon
        }
        if(bln< -1 && ky>Node->rightside->ky){// when is nececary my function doing rotation for blance
            return turningleft(Node);// right right
        }
        if(bln>1&&ky>Node->leftside->ky){
            Node->leftside= turningleft(Node->leftside);
            return turningright(Node); // left right
        }
        if (bln<-1&&ky<Node->rightside->ky){
            Node->rightside= turningright(Node->rightside);
            return turningleft(Node);// right left
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
public:
    avl() :root(nullptr){}
    void insert(std::string ky){
        root= insertuse(root,ky);
    }
};


#endif
