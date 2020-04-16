#pragma once 
 
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace family{
	struct Node;
	class Tree;
}

struct family::Node{
    string name;
    Node* dad;
    Node* mom;
    int male;
};

class family::Tree{
    public:
    Tree& addFather(string son, string newDad);
    Tree& addMother(string son, string newMom);
    void display();
    string relation(string inputName);
    string find(string inputName);
    void remove(string inputName);

    

    Node root;

    Tree(string name){//constructor
        // place holder
    }

};