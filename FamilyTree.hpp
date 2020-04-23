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
    bool male;

    Node(){
        name="";
        dad=NULL;
        mom=NULL;
        male=false;
    }

    Node(string newName){
        name=newName;
        dad=NULL;
        mom=NULL;
        male=false;
    }
    Node(string newName, bool amIAMale){
        name=newName;
        dad=NULL;
        mom=NULL;
        male=amIAMale;
    }

};

class family::Tree{
    public:
    Tree& addFather(string son, string newDad);
    Tree& addMother(string son, string newMom);
    void display();
    string relation(string inputName);
    string relation2(string inputName, Node* current);
    
    string find(string inputRelation);
    string find2(string inputRelation, Node* origin);

    void remove(string inputName);
    bool remove2(string inputName, Node* baseNode);


    Node* search(Node* currentNode, string input);
    

    Node root;

    Tree(string name){//constructor
        root=Node(name);
    }

};