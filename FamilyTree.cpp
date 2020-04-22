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
    if(inputRelation.size()<6) throw invalid_argument("Input string is too short to be valid!\n");

    string test = inputRelation.substr(0,1); //check if the first character of the input string is valid
    if(!(test.compare("f")==0) && !(test.compare("m")==0) && !(test.compare("g")==0)) {throw invalid_argument("Input string invalid!\n");}

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

    //getting here means we didn't look for father, mother, grandfather or grandmother
    //so the input should start with "great-". If it doesn't, throw an error.
    //this is needed here as well as in the find2 function, as the first 6 characters might be invalid, but the rest is valid.
    if(inputRelation.substr(0,6).compare("great-")!=0) throw invalid_argument("Invalid input!\n");

    string answer = "none";
    if(this->root.dad->dad) {answer = find2(inputRelation.substr(6), this->root.dad->dad);} //substring of 6 is to get rid of "great-" part
    if (answer.compare("invalid!")!=0 && answer.compare("none")!=0 && this->root.dad->mom) {answer = find2(inputRelation.substr(6), this->root.dad->mom);}
    if (answer.compare("invalid!")!=0 && answer.compare("none")!=0 && this->root.mom->dad) {answer = find2(inputRelation.substr(6), this->root.mom->dad);}
    if (answer.compare("invalid!")!=0 && answer.compare("none")!=0 && this->root.mom->mom) {answer = find2(inputRelation.substr(6), this->root.mom->mom);}

    if(answer.compare("invalid!")==0){throw invalid_argument("Invalid input!\n");} //invalid! is an indicatior of invalid part found in the string
    if(answer.compare("none")!=0){return answer + "\n";} // if it isn't "invalid!" or "none", answer was found. Return it.
    else {throw invalid_argument("No such relation in the tree!\n");}//none of the above -> wasn't found. throw error.

    

    // return "temp2\n"; //to have something to return, for any case. Not including this caused problems in previous projects.

};

string Tree::find2(string inputRelation, Node* origin){
    if(inputRelation.substr(0,6).compare("great-")==0){ //if "great" is still within the inputed string, it is needed to go up another level in the tree
        string answer = "none";
        if(origin->dad) answer = find2(inputRelation.substr(6), origin->dad);
        if(answer.compare("none")==0 && origin->mom) answer = find2(inputRelation.substr(6), origin->mom);
        return answer;
    }
    
    //getting here means the begining of the string isn't "great-".
    //if the string doesn't start with "great-" and it isn't grandfather or grandmother, it is invalid. returning "invalid!" will indicate to throw an error.
    if(inputRelation.compare("grandfather")!=0 && inputRelation.compare("grandmother")!=0) {return "invalid!";}
    
    else{//valid string and no more "great-" in the string. check if we looked for grandfather and origin is male, or grandmother and origin is female
        if(inputRelation.compare("grandfather")==0 && origin->male) return origin->name;
        if(inputRelation.compare("grandmother")==0 && !origin->male) return origin->name;
        return "none";
    }

    
}


void Tree::remove(string inputName){};