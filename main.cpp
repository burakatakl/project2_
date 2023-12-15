#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "AVL.h"
#include "BST.h"
#include <ctime>

std::vector<std::string>randomWords(int numw, int worldlenght){
   std::vector<std::string > words;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i=0;i<numw;i++){
        std::string word;
        for (int j=0;j<worldlenght;j++){
            char randomchar='a'+rand()%26;
            word+=randomchar;
        }
        words.push_back(word);
    }
    return words;
}

int main() {

    int numw=10;
    int worldlenght=5;
    std::vector<std::string> randomwords= randomWords(numw,worldlenght);

    std::cout<<"BST tree: ";
    auto sbst=std::chrono::high_resolution_clock::now();
    Bst bst;
    for(const auto& word:randomwords){
        bst.insert(word);
        std::cout<<word<<" ";
    }
    std::cout<<std::endl;
    auto ebst=std::chrono::high_resolution_clock::now();
    auto durationbst=std::chrono::duration_cast<std::chrono::nanoseconds>(ebst-sbst).count();
    std::cout<<"BTS tree time: "<<durationbst;
    std::cout<<std::endl;

    std::cout<<"AVL tree: ";
    auto savl=std::chrono::high_resolution_clock ::now();
    avl avltree;
    for(const auto& word:randomwords){
        avltree.insert(word);
        std::cout<<word<<" ";
    }
    std::cout<<std::endl;
    auto eavl=std::chrono::high_resolution_clock ::now();
    auto durationavl=std::chrono::duration_cast<std::chrono::nanoseconds>(eavl-savl).count();
    std::cout<<"AVL tree time: "<<durationavl;

    return 0;
}
