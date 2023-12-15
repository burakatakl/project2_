#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "AVL.h"
#include "BST.h"
#include <ctime>
void seedRandomizer(){
    srand(static_cast<unsigned int>(time(nullptr)));

}
std::vector<std::string>randomWords(int numw, int worldlength){
   std::vector<std::string > words;
    for (int i=0;i<numw;i++){
        std::string word;
        for (int j=0;j<worldlength;j++){
            char randomchar='a'+rand()%26;
            word+=randomchar;
        }
        words.push_back(word);
    }
    return words;
}

int main() {
    seedRandomizer();
    const int numw=10;
    const int worldlength=5;
    std::vector<std::string> randomwords= randomWords(numw,worldlength);

    std::cout<<"BST tree: ";
    auto sbst=std::chrono::high_resolution_clock::now();
    Bst bst;
    for(const auto& word:randomwords){
        bst.insert(word);
        std::cout<<word<<" ";
    }
    std::cout<<"\n";
    const auto ebst=std::chrono::high_resolution_clock::now();
    const auto durationbst=std::chrono::duration_cast<std::chrono::nanoseconds>(ebst-sbst).count();
    std::cout<<"BTS tree time: "<<durationbst;
    std::cout<<"\n";

    std::cout<<"AVL tree: ";
    const auto savl=std::chrono::high_resolution_clock ::now();
    avl avltree;
    for(const auto& word:randomwords){
        avltree.insert(word);
        std::cout<<word<<" ";
    }
    std::cout<<"\n";
    const auto eavl=std::chrono::high_resolution_clock ::now();
    const auto durationavl=std::chrono::duration_cast<std::chrono::nanoseconds>(eavl-savl).count();
    std::cout<<"AVL tree time: "<<durationavl;

    return 0;
}
