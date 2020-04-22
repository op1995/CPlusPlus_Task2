#include "FamilyTree.hpp"

using namespace std;
using namespace family;

Node* search(Node* currentNode, string input){
    if (currentNode->name.compare(input)==0){return currentNode;}
    else{
        Node* answer = NULL;
        if (currentNode->dad){ //if he has a dad
            answer = search(currentNode->dad, input);
        }
        if (!answer && currentNode->mom){ //if the answer wasn't found yet, and he has a mom
            answer = search(currentNode->mom, input);
        }
        return answer;
    }

}

Tree& Tree::addFather(string son, string newDad){
    Node* target = search(&(this->root), son);
    if(!target){throw invalid_argument("Son not found in the tree!");}
    if(target->dad){throw invalid_argument("Son already has a father!");}
    target->dad=new Node(newDad, true);
    // target->dad->name=newDad;
    // target->dad->dad=NULL;
    // target->dad->mom=NULL;

    return *this;

};

Tree& Tree::addMother(string son, string newMom){
    Node* target = search(&(this->root), son);
    if(!target){throw invalid_argument("Son not found in the tree!");}
    if(target->dad){throw invalid_argument("Son already has a mother!");}
    target->mom=new Node(newMom, false);
    // target->mom->name=newMom;
    // target->mom->dad=NULL;
    // target->mom->mom=NULL;

    return *this;

};

void Tree::display(){};


string Tree::relation(string inputName){

    if(root.name.compare(inputName)==0){return "Me";}

    if(!root.dad && !root.mom){return "unrelated";}
    if(root.dad && root.dad->name.compare(inputName)==0){return "father\n";}//father case
    if(root.mom && root.mom->name.compare(inputName)==0){return "mother\n";}//mother case

    if(!root.dad->dad && !root.dad->dad && !root.mom->dad && !root.mom->mom){return "unrelared\n";} //if no further family exists, end it all

    if(root.dad->dad && root.dad->dad->name.compare(inputName)==0){return "grandfather\n";}
    if(root.dad->mom && root.dad->mom->name.compare(inputName)==0){return "grandmother\n";}
    if(root.mom->dad && root.mom->dad->name.compare(inputName)==0){return "grandfather\n";}
    if(root.mom->mom && root.mom->mom->name.compare(inputName)==0){return "grandmother\n";} //private cases of grandfather and grandmother

    string temp = "unrelated"; //now check up the tree for each ancestor
    if(root.dad->dad) {temp = relation2(inputName, root.dad->dad);}
    if(temp.compare("unrelated")==0 && root.dad->mom){temp = relation2(inputName, root.dad->mom);}
    if(temp.compare("unrelated")==0 && root.mom->dad){temp = relation2(inputName, root.mom->dad);}
    if(temp.compare("unrelated")==0 && root.mom->dad){temp = relation2(inputName, root.mom->dad);}

    if(temp.compare("unrelated")!=0) return "great-" + temp + "\n";
    else return "unrelated\n";
};

string relation2(string inputName, Node* current){
    if(!current->dad && !current->mom) return "unrelated";
    if(current->dad && current->dad->name.compare(inputName)==0){return "grandfather";}
    if(current->mom && current->mom->name.compare(inputName)==0){return "grandmother";}
    
    string temp = "unrelated";
    if(current->dad) temp = relation2(inputName, current->dad);
    if(temp.compare("unrelated")==0 && current->mom) temp = relation2(inputName, current->mom);

    if(!temp.compare("unrelated")==0) return "great-" + temp;
    else return temp;

}


string Tree::find(string inputRelation){
    if(!this->root.dad && !this->root.mom){throw invalid_argument("Tree only has root. No relations will be in it, so there isn't anything to find.\n");}
    if(inputRelation.compare("father")==0){
        if(!this->root.dad) throw invalid_argument("No such relation in the tree!\n");
        else return this->root.dad->name+"\n";
    }
    if(inputRelation.compare("mother")==0){
        if(!this->root.mom) throw invalid_argument("No such relation in the tree!\n");
        else return this->root.mom->name+"\n";
    }
    if(inputRelation.compare("grandfather")==0){
        if(this->root.dad && this->root.dad->dad) {return this->root.dad->dad->name+"\n";}
        else if (this->root.mom && this->root.mom->dad) {return this->root.mom->dad->name+"\n";}
        else throw invalid_argument("No such relation in the tree!\n");
    }
    if(inputRelation.compare("grandmother")==0){
        if(this->root.dad && this->root.dad->mom) {return this->root.dad->mom->name+"\n";}
        else if (this->root.mom && this->root.mom->mom) {return this->root.mom->mom->name+"\n";}
        else throw invalid_argument("No such relation in the tree!\n");
    }





    // Node* answerNode = find2(inputName, &this->root);
    // if(answerNode) return answerNode->name;
    // else throw invalid_argument("No such relation in the tree!");

    return "temp2\n"; //to have something to return, for any case. Not including this caused problems in previous projects.

};

string Tree::find2(string inputRelation, Node* origin){
    
}


void Tree::remove(string inputName){};